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
CMAKE_SOURCE_DIR = /Users/valery/LearningProjects/algorithms/avl-tree-with-sum

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/valery/LearningProjects/algorithms/avl-tree-with-sum/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/avl_tree_with_sum.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/avl_tree_with_sum.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/avl_tree_with_sum.dir/flags.make

CMakeFiles/avl_tree_with_sum.dir/main.cpp.o: CMakeFiles/avl_tree_with_sum.dir/flags.make
CMakeFiles/avl_tree_with_sum.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/valery/LearningProjects/algorithms/avl-tree-with-sum/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/avl_tree_with_sum.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/avl_tree_with_sum.dir/main.cpp.o -c /Users/valery/LearningProjects/algorithms/avl-tree-with-sum/main.cpp

CMakeFiles/avl_tree_with_sum.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/avl_tree_with_sum.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/valery/LearningProjects/algorithms/avl-tree-with-sum/main.cpp > CMakeFiles/avl_tree_with_sum.dir/main.cpp.i

CMakeFiles/avl_tree_with_sum.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/avl_tree_with_sum.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/valery/LearningProjects/algorithms/avl-tree-with-sum/main.cpp -o CMakeFiles/avl_tree_with_sum.dir/main.cpp.s

# Object files for target avl_tree_with_sum
avl_tree_with_sum_OBJECTS = \
"CMakeFiles/avl_tree_with_sum.dir/main.cpp.o"

# External object files for target avl_tree_with_sum
avl_tree_with_sum_EXTERNAL_OBJECTS =

avl_tree_with_sum: CMakeFiles/avl_tree_with_sum.dir/main.cpp.o
avl_tree_with_sum: CMakeFiles/avl_tree_with_sum.dir/build.make
avl_tree_with_sum: CMakeFiles/avl_tree_with_sum.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/valery/LearningProjects/algorithms/avl-tree-with-sum/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable avl_tree_with_sum"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/avl_tree_with_sum.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/avl_tree_with_sum.dir/build: avl_tree_with_sum

.PHONY : CMakeFiles/avl_tree_with_sum.dir/build

CMakeFiles/avl_tree_with_sum.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/avl_tree_with_sum.dir/cmake_clean.cmake
.PHONY : CMakeFiles/avl_tree_with_sum.dir/clean

CMakeFiles/avl_tree_with_sum.dir/depend:
	cd /Users/valery/LearningProjects/algorithms/avl-tree-with-sum/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/valery/LearningProjects/algorithms/avl-tree-with-sum /Users/valery/LearningProjects/algorithms/avl-tree-with-sum /Users/valery/LearningProjects/algorithms/avl-tree-with-sum/cmake-build-debug /Users/valery/LearningProjects/algorithms/avl-tree-with-sum/cmake-build-debug /Users/valery/LearningProjects/algorithms/avl-tree-with-sum/cmake-build-debug/CMakeFiles/avl_tree_with_sum.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/avl_tree_with_sum.dir/depend
