# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise/build

# Include any dependencies generated for this target.
include CMakeFiles/vec_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/vec_test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/vec_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/vec_test.dir/flags.make

CMakeFiles/vec_test.dir/src/linalg/vec_f_test.cpp.o: CMakeFiles/vec_test.dir/flags.make
CMakeFiles/vec_test.dir/src/linalg/vec_f_test.cpp.o: ../src/linalg/vec_f_test.cpp
CMakeFiles/vec_test.dir/src/linalg/vec_f_test.cpp.o: CMakeFiles/vec_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/vec_test.dir/src/linalg/vec_f_test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/vec_test.dir/src/linalg/vec_f_test.cpp.o -MF CMakeFiles/vec_test.dir/src/linalg/vec_f_test.cpp.o.d -o CMakeFiles/vec_test.dir/src/linalg/vec_f_test.cpp.o -c /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise/src/linalg/vec_f_test.cpp

CMakeFiles/vec_test.dir/src/linalg/vec_f_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vec_test.dir/src/linalg/vec_f_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise/src/linalg/vec_f_test.cpp > CMakeFiles/vec_test.dir/src/linalg/vec_f_test.cpp.i

CMakeFiles/vec_test.dir/src/linalg/vec_f_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vec_test.dir/src/linalg/vec_f_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise/src/linalg/vec_f_test.cpp -o CMakeFiles/vec_test.dir/src/linalg/vec_f_test.cpp.s

CMakeFiles/vec_test.dir/src/linalg/vec_f.cpp.o: CMakeFiles/vec_test.dir/flags.make
CMakeFiles/vec_test.dir/src/linalg/vec_f.cpp.o: ../src/linalg/vec_f.cpp
CMakeFiles/vec_test.dir/src/linalg/vec_f.cpp.o: CMakeFiles/vec_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/vec_test.dir/src/linalg/vec_f.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/vec_test.dir/src/linalg/vec_f.cpp.o -MF CMakeFiles/vec_test.dir/src/linalg/vec_f.cpp.o.d -o CMakeFiles/vec_test.dir/src/linalg/vec_f.cpp.o -c /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise/src/linalg/vec_f.cpp

CMakeFiles/vec_test.dir/src/linalg/vec_f.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vec_test.dir/src/linalg/vec_f.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise/src/linalg/vec_f.cpp > CMakeFiles/vec_test.dir/src/linalg/vec_f.cpp.i

CMakeFiles/vec_test.dir/src/linalg/vec_f.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vec_test.dir/src/linalg/vec_f.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise/src/linalg/vec_f.cpp -o CMakeFiles/vec_test.dir/src/linalg/vec_f.cpp.s

# Object files for target vec_test
vec_test_OBJECTS = \
"CMakeFiles/vec_test.dir/src/linalg/vec_f_test.cpp.o" \
"CMakeFiles/vec_test.dir/src/linalg/vec_f.cpp.o"

# External object files for target vec_test
vec_test_EXTERNAL_OBJECTS =

vec_test: CMakeFiles/vec_test.dir/src/linalg/vec_f_test.cpp.o
vec_test: CMakeFiles/vec_test.dir/src/linalg/vec_f.cpp.o
vec_test: CMakeFiles/vec_test.dir/build.make
vec_test: CMakeFiles/vec_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable vec_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vec_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/vec_test.dir/build: vec_test
.PHONY : CMakeFiles/vec_test.dir/build

CMakeFiles/vec_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/vec_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/vec_test.dir/clean

CMakeFiles/vec_test.dir/depend:
	cd /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise/build /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise/build /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise/build/CMakeFiles/vec_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/vec_test.dir/depend

