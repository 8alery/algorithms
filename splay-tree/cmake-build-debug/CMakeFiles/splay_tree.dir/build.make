# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = "/Users/valery/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/191.7141.37/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/valery/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/191.7141.37/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/valery/LearningProjects/algorithms/splay-tree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/valery/LearningProjects/algorithms/splay-tree/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/splay_tree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/splay_tree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/splay_tree.dir/flags.make

CMakeFiles/splay_tree.dir/main.cpp.o: CMakeFiles/splay_tree.dir/flags.make
CMakeFiles/splay_tree.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/valery/LearningProjects/algorithms/splay-tree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/splay_tree.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/splay_tree.dir/main.cpp.o -c /Users/valery/LearningProjects/algorithms/splay-tree/main.cpp

CMakeFiles/splay_tree.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/splay_tree.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/valery/LearningProjects/algorithms/splay-tree/main.cpp > CMakeFiles/splay_tree.dir/main.cpp.i

CMakeFiles/splay_tree.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/splay_tree.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/valery/LearningProjects/algorithms/splay-tree/main.cpp -o CMakeFiles/splay_tree.dir/main.cpp.s

# Object files for target splay_tree
splay_tree_OBJECTS = \
"CMakeFiles/splay_tree.dir/main.cpp.o"

# External object files for target splay_tree
splay_tree_EXTERNAL_OBJECTS =

splay_tree: CMakeFiles/splay_tree.dir/main.cpp.o
splay_tree: CMakeFiles/splay_tree.dir/build.make
splay_tree: CMakeFiles/splay_tree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/valery/LearningProjects/algorithms/splay-tree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable splay_tree"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/splay_tree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/splay_tree.dir/build: splay_tree

.PHONY : CMakeFiles/splay_tree.dir/build

CMakeFiles/splay_tree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/splay_tree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/splay_tree.dir/clean

CMakeFiles/splay_tree.dir/depend:
	cd /Users/valery/LearningProjects/algorithms/splay-tree/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/valery/LearningProjects/algorithms/splay-tree /Users/valery/LearningProjects/algorithms/splay-tree /Users/valery/LearningProjects/algorithms/splay-tree/cmake-build-debug /Users/valery/LearningProjects/algorithms/splay-tree/cmake-build-debug /Users/valery/LearningProjects/algorithms/splay-tree/cmake-build-debug/CMakeFiles/splay_tree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/splay_tree.dir/depend

