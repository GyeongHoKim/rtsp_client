cmake_minimum_required(VERSION 3.15)
cmake_policy(SET CMP0091 NEW)
cmake_policy(SET CMP0042 NEW)

project(rtsp_client)

add_definitions(-DNAPI_VERSION=9)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(MYRTSPCLIENT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/myRtspClient/myRtspClient/include)

if (WIN32)
    set(VCPKG_DIR C:/dev/vcpkg/installed/x64-windows)
elseif (APPLE)
    set(VCPKG_DIR ./vcpkg/installed/arm64-osx)
endif ()

# Include Node-API wrappers
execute_process(
        COMMAND node -p "require('node-addon-api').include"
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE NODE_ADDON_API_DIR
)
string(REGEX REPLACE "[\r\n\"]" "" NODE_ADDON_API_DIR ${NODE_ADDON_API_DIR})

include_directories(${CMAKE_JS_INC} ${NODE_ADDON_API_DIR} ${MYRTSPCLIENT_INCLUDE_DIR})

set(HEADER_FILES
        "src/GyeongHoRtspClient.h"
)
set(SOURCE_FILES
        "src/addon.cc"
        "src/GyeongHoRtspClient.cc"
)

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${CMAKE_JS_SRC})
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")

if (WIN32)
    target_link_libraries(
            ${PROJECT_NAME}
            ${CMAKE_JS_LIB}
            ${MYRTSPCLIENT_INCLUDE_DIR}/../libmyRtspClient.lib
    )
elseif (APPLE)
    target_link_libraries(
            ${PROJECT_NAME}
            ${CMAKE_JS_LIB}
            ${MYRTSPCLIENT_INCLUDE_DIR}/../libmyRtspClient.a
    )
endif ()

if (MSVC AND CMAKE_JS_NODELIB_DEF AND CMAKE_JS_NODELIB_TARGET)
    # Generate node.lib
    execute_process(COMMAND ${CMAKE_AR} /def:${CMAKE_JS_NODELIB_DEF} /out:${CMAKE_JS_NODELIB_TARGET} ${CMAKE_STATIC_LINKER_FLAGS})
endif ()