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
CMAKE_SOURCE_DIR = /home/valery/CLionProjects/binary_search

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/valery/CLionProjects/binary_search/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/binary_search.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/binary_search.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/binary_search.dir/flags.make

CMakeFiles/binary_search.dir/main.cpp.o: CMakeFiles/binary_search.dir/flags.make
CMakeFiles/binary_search.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/valery/CLionProjects/binary_search/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/binary_search.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/binary_search.dir/main.cpp.o -c /home/valery/CLionProjects/binary_search/main.cpp

CMakeFiles/binary_search.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/binary_search.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/valery/CLionProjects/binary_search/main.cpp > CMakeFiles/binary_search.dir/main.cpp.i

CMakeFiles/binary_search.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/binary_search.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/valery/CLionProjects/binary_search/main.cpp -o CMakeFiles/binary_search.dir/main.cpp.s

CMakeFiles/binary_search.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/binary_search.dir/main.cpp.o.requires

CMakeFiles/binary_search.dir/main.cpp.o.provides: CMakeFiles/binary_search.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/binary_search.dir/build.make CMakeFiles/binary_search.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/binary_search.dir/main.cpp.o.provides

CMakeFiles/binary_search.dir/main.cpp.o.provides.build: CMakeFiles/binary_search.dir/main.cpp.o


# Object files for target binary_search
binary_search_OBJECTS = \
"CMakeFiles/binary_search.dir/main.cpp.o"

# External object files for target binary_search
binary_search_EXTERNAL_OBJECTS =

binary_search: CMakeFiles/binary_search.dir/main.cpp.o
binary_search: CMakeFiles/binary_search.dir/build.make
binary_search: CMakeFiles/binary_search.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/valery/CLionProjects/binary_search/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable binary_search"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/binary_search.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/binary_search.dir/build: binary_search

.PHONY : CMakeFiles/binary_search.dir/build

CMakeFiles/binary_search.dir/requires: CMakeFiles/binary_search.dir/main.cpp.o.requires

.PHONY : CMakeFiles/binary_search.dir/requires

CMakeFiles/binary_search.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/binary_search.dir/cmake_clean.cmake
.PHONY : CMakeFiles/binary_search.dir/clean

CMakeFiles/binary_search.dir/depend:
	cd /home/valery/CLionProjects/binary_search/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/valery/CLionProjects/binary_search /home/valery/CLionProjects/binary_search /home/valery/CLionProjects/binary_search/cmake-build-debug /home/valery/CLionProjects/binary_search/cmake-build-debug /home/valery/CLionProjects/binary_search/cmake-build-debug/CMakeFiles/binary_search.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/binary_search.dir/depend

