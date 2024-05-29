cmake_minimum_required(VERSION 3.15)
cmake_policy(SET CMP0091 NEW)
cmake_policy(SET CMP0042 NEW)

project(rtsp_client)

add_definitions(-DNAPI_VERSION=9)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Include Node-API wrappers
execute_process(
        COMMAND node -p "require('node-addon-api').include"
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE NODE_ADDON_API_DIR
)
string(REGEX REPLACE "[\r\n\"]" "" NODE_ADDON_API_DIR ${NODE_ADDON_API_DIR})

include_directories(${CMAKE_JS_INC} ${CMAKE_SOURCE_DIR}/vcpkg/installed/arm64-osx/include ${NODE_ADDON_API_DIR})

set(HEADER_FILES
        "src/rtsp_client.h"
)
set(SOURCE_FILES
        "src/rtsp_client.cc"
        "src/addon.cc"
)

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${CMAKE_JS_SRC})
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")
target_link_libraries(
        ${PROJECT_NAME}
        ${CMAKE_JS_LIB}
        ${CMAKE_SOURCE_DIR}/vcpkg/installed/arm64-osx/lib/libliveMedia.a
        ${CMAKE_SOURCE_DIR}/vcpkg/installed/arm64-osx/lib/libBasicUsageEnvironment.a
        ${CMAKE_SOURCE_DIR}/vcpkg/installed/arm64-osx/lib/libUsageEnvironment.a
)

if (MSVC AND CMAKE_JS_NODELIB_DEF AND CMAKE_JS_NODELIB_TARGET)
    # Generate node.lib
    execute_process(COMMAND ${CMAKE_AR} /def:${CMAKE_JS_NODELIB_DEF} /out:${CMAKE_JS_NODELIB_TARGET} ${CMAKE_STATIC_LINKER_FLAGS})
endif ()