# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/clion-2018.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion-2018.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/valery/CLionProjects/build_heap

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/valery/CLionProjects/build_heap/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/build_heap.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/build_heap.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/build_heap.dir/flags.make

CMakeFiles/build_heap.dir/main.cpp.o: CMakeFiles/build_heap.dir/flags.make
CMakeFiles/build_heap.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/valery/CLionProjects/build_heap/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/build_heap.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/build_heap.dir/main.cpp.o -c /home/valery/CLionProjects/build_heap/main.cpp

CMakeFiles/build_heap.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/build_heap.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/valery/CLionProjects/build_heap/main.cpp > CMakeFiles/build_heap.dir/main.cpp.i

CMakeFiles/build_heap.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/build_heap.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/valery/CLionProjects/build_heap/main.cpp -o CMakeFiles/build_heap.dir/main.cpp.s

CMakeFiles/build_heap.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/build_heap.dir/main.cpp.o.requires

CMakeFiles/build_heap.dir/main.cpp.o.provides: CMakeFiles/build_heap.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/build_heap.dir/build.make CMakeFiles/build_heap.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/build_heap.dir/main.cpp.o.provides

CMakeFiles/build_heap.dir/main.cpp.o.provides.build: CMakeFiles/build_heap.dir/main.cpp.o


# Object files for target build_heap
build_heap_OBJECTS = \
"CMakeFiles/build_heap.dir/main.cpp.o"

# External object files for target build_heap
build_heap_EXTERNAL_OBJECTS =

build_heap: CMakeFiles/build_heap.dir/main.cpp.o
build_heap: CMakeFiles/build_heap.dir/build.make
build_heap: CMakeFiles/build_heap.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/valery/CLionProjects/build_heap/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable build_heap"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/build_heap.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/build_heap.dir/build: build_heap

.PHONY : CMakeFiles/build_heap.dir/build

CMakeFiles/build_heap.dir/requires: CMakeFiles/build_heap.dir/main.cpp.o.requires

.PHONY : CMakeFiles/build_heap.dir/requires

CMakeFiles/build_heap.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/build_heap.dir/cmake_clean.cmake
.PHONY : CMakeFiles/build_heap.dir/clean

CMakeFiles/build_heap.dir/depend:
	cd /home/valery/CLionProjects/build_heap/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/valery/CLionProjects/build_heap /home/valery/CLionProjects/build_heap /home/valery/CLionProjects/build_heap/cmake-build-debug /home/valery/CLionProjects/build_heap/cmake-build-debug /home/valery/CLionProjects/build_heap/cmake-build-debug/CMakeFiles/build_heap.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/build_heap.dir/depend
