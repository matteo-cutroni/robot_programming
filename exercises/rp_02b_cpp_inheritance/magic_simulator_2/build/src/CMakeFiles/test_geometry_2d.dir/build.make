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
CMAKE_SOURCE_DIR = /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02b_cpp_inheritance/magic_simulator_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02b_cpp_inheritance/magic_simulator_2/build

# Include any dependencies generated for this target.
include src/CMakeFiles/test_geometry_2d.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/test_geometry_2d.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/test_geometry_2d.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/test_geometry_2d.dir/flags.make

src/CMakeFiles/test_geometry_2d.dir/test_geometry_2d.cpp.o: src/CMakeFiles/test_geometry_2d.dir/flags.make
src/CMakeFiles/test_geometry_2d.dir/test_geometry_2d.cpp.o: ../src/test_geometry_2d.cpp
src/CMakeFiles/test_geometry_2d.dir/test_geometry_2d.cpp.o: src/CMakeFiles/test_geometry_2d.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02b_cpp_inheritance/magic_simulator_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/test_geometry_2d.dir/test_geometry_2d.cpp.o"
	cd /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02b_cpp_inheritance/magic_simulator_2/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/test_geometry_2d.dir/test_geometry_2d.cpp.o -MF CMakeFiles/test_geometry_2d.dir/test_geometry_2d.cpp.o.d -o CMakeFiles/test_geometry_2d.dir/test_geometry_2d.cpp.o -c /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02b_cpp_inheritance/magic_simulator_2/src/test_geometry_2d.cpp

src/CMakeFiles/test_geometry_2d.dir/test_geometry_2d.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_geometry_2d.dir/test_geometry_2d.cpp.i"
	cd /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02b_cpp_inheritance/magic_simulator_2/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02b_cpp_inheritance/magic_simulator_2/src/test_geometry_2d.cpp > CMakeFiles/test_geometry_2d.dir/test_geometry_2d.cpp.i

src/CMakeFiles/test_geometry_2d.dir/test_geometry_2d.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_geometry_2d.dir/test_geometry_2d.cpp.s"
	cd /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02b_cpp_inheritance/magic_simulator_2/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02b_cpp_inheritance/magic_simulator_2/src/test_geometry_2d.cpp -o CMakeFiles/test_geometry_2d.dir/test_geometry_2d.cpp.s

# Object files for target test_geometry_2d
test_geometry_2d_OBJECTS = \
"CMakeFiles/test_geometry_2d.dir/test_geometry_2d.cpp.o"

# External object files for target test_geometry_2d
test_geometry_2d_EXTERNAL_OBJECTS =

src/test_geometry_2d: src/CMakeFiles/test_geometry_2d.dir/test_geometry_2d.cpp.o
src/test_geometry_2d: src/CMakeFiles/test_geometry_2d.dir/build.make
src/test_geometry_2d: src/libsimple_sim_library.so
src/test_geometry_2d: /usr/local/lib/libopencv_gapi.so.4.8.0
src/test_geometry_2d: /usr/local/lib/libopencv_highgui.so.4.8.0
src/test_geometry_2d: /usr/local/lib/libopencv_ml.so.4.8.0
src/test_geometry_2d: /usr/local/lib/libopencv_objdetect.so.4.8.0
src/test_geometry_2d: /usr/local/lib/libopencv_photo.so.4.8.0
src/test_geometry_2d: /usr/local/lib/libopencv_stitching.so.4.8.0
src/test_geometry_2d: /usr/local/lib/libopencv_video.so.4.8.0
src/test_geometry_2d: /usr/local/lib/libopencv_videoio.so.4.8.0
src/test_geometry_2d: /usr/local/lib/libopencv_calib3d.so.4.8.0
src/test_geometry_2d: /usr/local/lib/libopencv_dnn.so.4.8.0
src/test_geometry_2d: /usr/local/lib/libopencv_features2d.so.4.8.0
src/test_geometry_2d: /usr/local/lib/libopencv_flann.so.4.8.0
src/test_geometry_2d: /usr/local/lib/libopencv_imgcodecs.so.4.8.0
src/test_geometry_2d: /usr/local/lib/libopencv_imgproc.so.4.8.0
src/test_geometry_2d: /usr/local/lib/libopencv_core.so.4.8.0
src/test_geometry_2d: src/CMakeFiles/test_geometry_2d.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02b_cpp_inheritance/magic_simulator_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_geometry_2d"
	cd /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02b_cpp_inheritance/magic_simulator_2/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_geometry_2d.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/test_geometry_2d.dir/build: src/test_geometry_2d
.PHONY : src/CMakeFiles/test_geometry_2d.dir/build

src/CMakeFiles/test_geometry_2d.dir/clean:
	cd /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02b_cpp_inheritance/magic_simulator_2/build/src && $(CMAKE_COMMAND) -P CMakeFiles/test_geometry_2d.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/test_geometry_2d.dir/clean

src/CMakeFiles/test_geometry_2d.dir/depend:
	cd /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02b_cpp_inheritance/magic_simulator_2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02b_cpp_inheritance/magic_simulator_2 /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02b_cpp_inheritance/magic_simulator_2/src /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02b_cpp_inheritance/magic_simulator_2/build /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02b_cpp_inheritance/magic_simulator_2/build/src /home/matteo/Desktop/robotprogramming_2023_24/exercises/rp_02b_cpp_inheritance/magic_simulator_2/build/src/CMakeFiles/test_geometry_2d.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/test_geometry_2d.dir/depend
