# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lixiaoxing/文档/weProject/wt-open-server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lixiaoxing/文档/weProject/wt-open-server/build

# Include any dependencies generated for this target.
include CMakeFiles/gay_server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/gay_server.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/gay_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gay_server.dir/flags.make

CMakeFiles/gay_server.dir/src/server.cpp.o: CMakeFiles/gay_server.dir/flags.make
CMakeFiles/gay_server.dir/src/server.cpp.o: ../src/server.cpp
CMakeFiles/gay_server.dir/src/server.cpp.o: CMakeFiles/gay_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lixiaoxing/文档/weProject/wt-open-server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gay_server.dir/src/server.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gay_server.dir/src/server.cpp.o -MF CMakeFiles/gay_server.dir/src/server.cpp.o.d -o CMakeFiles/gay_server.dir/src/server.cpp.o -c /home/lixiaoxing/文档/weProject/wt-open-server/src/server.cpp

CMakeFiles/gay_server.dir/src/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gay_server.dir/src/server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lixiaoxing/文档/weProject/wt-open-server/src/server.cpp > CMakeFiles/gay_server.dir/src/server.cpp.i

CMakeFiles/gay_server.dir/src/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gay_server.dir/src/server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lixiaoxing/文档/weProject/wt-open-server/src/server.cpp -o CMakeFiles/gay_server.dir/src/server.cpp.s

# Object files for target gay_server
gay_server_OBJECTS = \
"CMakeFiles/gay_server.dir/src/server.cpp.o"

# External object files for target gay_server
gay_server_EXTERNAL_OBJECTS =

../bin/gay_server: CMakeFiles/gay_server.dir/src/server.cpp.o
../bin/gay_server: CMakeFiles/gay_server.dir/build.make
../bin/gay_server: CMakeFiles/gay_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lixiaoxing/文档/weProject/wt-open-server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/gay_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gay_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gay_server.dir/build: ../bin/gay_server
.PHONY : CMakeFiles/gay_server.dir/build

CMakeFiles/gay_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gay_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gay_server.dir/clean

CMakeFiles/gay_server.dir/depend:
	cd /home/lixiaoxing/文档/weProject/wt-open-server/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lixiaoxing/文档/weProject/wt-open-server /home/lixiaoxing/文档/weProject/wt-open-server /home/lixiaoxing/文档/weProject/wt-open-server/build /home/lixiaoxing/文档/weProject/wt-open-server/build /home/lixiaoxing/文档/weProject/wt-open-server/build/CMakeFiles/gay_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gay_server.dir/depend

