# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.29.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.29.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/gyeongho/workspace/napi/rtsp_client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gyeongho/workspace/napi/rtsp_client/build

# Include any dependencies generated for this target.
include CMakeFiles/rtsp_client.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/rtsp_client.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/rtsp_client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rtsp_client.dir/flags.make

CMakeFiles/rtsp_client.dir/src/addon.cc.o: CMakeFiles/rtsp_client.dir/flags.make
CMakeFiles/rtsp_client.dir/src/addon.cc.o: /Users/gyeongho/workspace/napi/rtsp_client/src/addon.cc
CMakeFiles/rtsp_client.dir/src/addon.cc.o: CMakeFiles/rtsp_client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/gyeongho/workspace/napi/rtsp_client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rtsp_client.dir/src/addon.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/rtsp_client.dir/src/addon.cc.o -MF CMakeFiles/rtsp_client.dir/src/addon.cc.o.d -o CMakeFiles/rtsp_client.dir/src/addon.cc.o -c /Users/gyeongho/workspace/napi/rtsp_client/src/addon.cc

CMakeFiles/rtsp_client.dir/src/addon.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/rtsp_client.dir/src/addon.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gyeongho/workspace/napi/rtsp_client/src/addon.cc > CMakeFiles/rtsp_client.dir/src/addon.cc.i

CMakeFiles/rtsp_client.dir/src/addon.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/rtsp_client.dir/src/addon.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gyeongho/workspace/napi/rtsp_client/src/addon.cc -o CMakeFiles/rtsp_client.dir/src/addon.cc.s

CMakeFiles/rtsp_client.dir/src/GyeongHoRtspClient.cc.o: CMakeFiles/rtsp_client.dir/flags.make
CMakeFiles/rtsp_client.dir/src/GyeongHoRtspClient.cc.o: /Users/gyeongho/workspace/napi/rtsp_client/src/GyeongHoRtspClient.cc
CMakeFiles/rtsp_client.dir/src/GyeongHoRtspClient.cc.o: CMakeFiles/rtsp_client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/gyeongho/workspace/napi/rtsp_client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/rtsp_client.dir/src/GyeongHoRtspClient.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/rtsp_client.dir/src/GyeongHoRtspClient.cc.o -MF CMakeFiles/rtsp_client.dir/src/GyeongHoRtspClient.cc.o.d -o CMakeFiles/rtsp_client.dir/src/GyeongHoRtspClient.cc.o -c /Users/gyeongho/workspace/napi/rtsp_client/src/GyeongHoRtspClient.cc

CMakeFiles/rtsp_client.dir/src/GyeongHoRtspClient.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/rtsp_client.dir/src/GyeongHoRtspClient.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gyeongho/workspace/napi/rtsp_client/src/GyeongHoRtspClient.cc > CMakeFiles/rtsp_client.dir/src/GyeongHoRtspClient.cc.i

CMakeFiles/rtsp_client.dir/src/GyeongHoRtspClient.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/rtsp_client.dir/src/GyeongHoRtspClient.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gyeongho/workspace/napi/rtsp_client/src/GyeongHoRtspClient.cc -o CMakeFiles/rtsp_client.dir/src/GyeongHoRtspClient.cc.s

# Object files for target rtsp_client
rtsp_client_OBJECTS = \
"CMakeFiles/rtsp_client.dir/src/addon.cc.o" \
"CMakeFiles/rtsp_client.dir/src/GyeongHoRtspClient.cc.o"

# External object files for target rtsp_client
rtsp_client_EXTERNAL_OBJECTS =

Release/rtsp_client.node: CMakeFiles/rtsp_client.dir/src/addon.cc.o
Release/rtsp_client.node: CMakeFiles/rtsp_client.dir/src/GyeongHoRtspClient.cc.o
Release/rtsp_client.node: CMakeFiles/rtsp_client.dir/build.make
Release/rtsp_client.node: /Users/gyeongho/workspace/napi/rtsp_client/myRtspClient/myRtspClient/include/../libmyRtspClient.a
Release/rtsp_client.node: CMakeFiles/rtsp_client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/gyeongho/workspace/napi/rtsp_client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library Release/rtsp_client.node"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rtsp_client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rtsp_client.dir/build: Release/rtsp_client.node
.PHONY : CMakeFiles/rtsp_client.dir/build

CMakeFiles/rtsp_client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rtsp_client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rtsp_client.dir/clean

CMakeFiles/rtsp_client.dir/depend:
	cd /Users/gyeongho/workspace/napi/rtsp_client/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gyeongho/workspace/napi/rtsp_client /Users/gyeongho/workspace/napi/rtsp_client /Users/gyeongho/workspace/napi/rtsp_client/build /Users/gyeongho/workspace/napi/rtsp_client/build /Users/gyeongho/workspace/napi/rtsp_client/build/CMakeFiles/rtsp_client.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/rtsp_client.dir/depend
