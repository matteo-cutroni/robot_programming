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
include CMakeFiles/linalg.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/linalg.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/linalg.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/linalg.dir/flags.make

CMakeFiles/linalg.dir/src/linalg/mat_f_test.cpp.o: CMakeFiles/linalg.dir/flags.make
CMakeFiles/linalg.dir/src/linalg/mat_f_test.cpp.o: ../src/linalg/mat_f_test.cpp
CMakeFiles/linalg.dir/src/linalg/mat_f_test.cpp.o: CMakeFiles/linalg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/linalg.dir/src/linalg/mat_f_test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/linalg.dir/src/linalg/mat_f_test.cpp.o -MF CMakeFiles/linalg.dir/src/linalg/mat_f_test.cpp.o.d -o CMakeFiles/linalg.dir/src/linalg/mat_f_test.cpp.o -c /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise/src/linalg/mat_f_test.cpp

CMakeFiles/linalg.dir/src/linalg/mat_f_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linalg.dir/src/linalg/mat_f_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise/src/linalg/mat_f_test.cpp > CMakeFiles/linalg.dir/src/linalg/mat_f_test.cpp.i

CMakeFiles/linalg.dir/src/linalg/mat_f_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linalg.dir/src/linalg/mat_f_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise/src/linalg/mat_f_test.cpp -o CMakeFiles/linalg.dir/src/linalg/mat_f_test.cpp.s

CMakeFiles/linalg.dir/src/linalg/mat_f.cpp.o: CMakeFiles/linalg.dir/flags.make
CMakeFiles/linalg.dir/src/linalg/mat_f.cpp.o: ../src/linalg/mat_f.cpp
CMakeFiles/linalg.dir/src/linalg/mat_f.cpp.o: CMakeFiles/linalg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/linalg.dir/src/linalg/mat_f.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/linalg.dir/src/linalg/mat_f.cpp.o -MF CMakeFiles/linalg.dir/src/linalg/mat_f.cpp.o.d -o CMakeFiles/linalg.dir/src/linalg/mat_f.cpp.o -c /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise/src/linalg/mat_f.cpp

CMakeFiles/linalg.dir/src/linalg/mat_f.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linalg.dir/src/linalg/mat_f.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise/src/linalg/mat_f.cpp > CMakeFiles/linalg.dir/src/linalg/mat_f.cpp.i

CMakeFiles/linalg.dir/src/linalg/mat_f.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linalg.dir/src/linalg/mat_f.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise/src/linalg/mat_f.cpp -o CMakeFiles/linalg.dir/src/linalg/mat_f.cpp.s

CMakeFiles/linalg.dir/src/linalg/vec_f_test.cpp.o: CMakeFiles/linalg.dir/flags.make
CMakeFiles/linalg.dir/src/linalg/vec_f_test.cpp.o: ../src/linalg/vec_f_test.cpp
CMakeFiles/linalg.dir/src/linalg/vec_f_test.cpp.o: CMakeFiles/linalg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/linalg.dir/src/linalg/vec_f_test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/linalg.dir/src/linalg/vec_f_test.cpp.o -MF CMakeFiles/linalg.dir/src/linalg/vec_f_test.cpp.o.d -o CMakeFiles/linalg.dir/src/linalg/vec_f_test.cpp.o -c /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise/src/linalg/vec_f_test.cpp

CMakeFiles/linalg.dir/src/linalg/vec_f_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linalg.dir/src/linalg/vec_f_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise/src/linalg/vec_f_test.cpp > CMakeFiles/linalg.dir/src/linalg/vec_f_test.cpp.i

CMakeFiles/linalg.dir/src/linalg/vec_f_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linalg.dir/src/linalg/vec_f_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise/src/linalg/vec_f_test.cpp -o CMakeFiles/linalg.dir/src/linalg/vec_f_test.cpp.s

CMakeFiles/linalg.dir/src/linalg/vec_f.cpp.o: CMakeFiles/linalg.dir/flags.make
CMakeFiles/linalg.dir/src/linalg/vec_f.cpp.o: ../src/linalg/vec_f.cpp
CMakeFiles/linalg.dir/src/linalg/vec_f.cpp.o: CMakeFiles/linalg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/linalg.dir/src/linalg/vec_f.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/linalg.dir/src/linalg/vec_f.cpp.o -MF CMakeFiles/linalg.dir/src/linalg/vec_f.cpp.o.d -o CMakeFiles/linalg.dir/src/linalg/vec_f.cpp.o -c /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise/src/linalg/vec_f.cpp

CMakeFiles/linalg.dir/src/linalg/vec_f.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linalg.dir/src/linalg/vec_f.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise/src/linalg/vec_f.cpp > CMakeFiles/linalg.dir/src/linalg/vec_f.cpp.i

CMakeFiles/linalg.dir/src/linalg/vec_f.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linalg.dir/src/linalg/vec_f.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise/src/linalg/vec_f.cpp -o CMakeFiles/linalg.dir/src/linalg/vec_f.cpp.s

# Object files for target linalg
linalg_OBJECTS = \
"CMakeFiles/linalg.dir/src/linalg/mat_f_test.cpp.o" \
"CMakeFiles/linalg.dir/src/linalg/mat_f.cpp.o" \
"CMakeFiles/linalg.dir/src/linalg/vec_f_test.cpp.o" \
"CMakeFiles/linalg.dir/src/linalg/vec_f.cpp.o"

# External object files for target linalg
linalg_EXTERNAL_OBJECTS =

linalg: CMakeFiles/linalg.dir/src/linalg/mat_f_test.cpp.o
linalg: CMakeFiles/linalg.dir/src/linalg/mat_f.cpp.o
linalg: CMakeFiles/linalg.dir/src/linalg/vec_f_test.cpp.o
linalg: CMakeFiles/linalg.dir/src/linalg/vec_f.cpp.o
linalg: CMakeFiles/linalg.dir/build.make
linalg: CMakeFiles/linalg.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable linalg"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/linalg.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/linalg.dir/build: linalg
.PHONY : CMakeFiles/linalg.dir/build

CMakeFiles/linalg.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/linalg.dir/cmake_clean.cmake
.PHONY : CMakeFiles/linalg.dir/clean

CMakeFiles/linalg.dir/depend:
	cd /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise/build /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise/build /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02_cpp_intro/exercise/build/CMakeFiles/linalg.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/linalg.dir/depend
