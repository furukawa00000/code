# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.0.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.0.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/furukawa/research/structured_indoor_modeling/code/calibration

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/furukawa/research/structured_indoor_modeling/code/calibration

# Include any dependencies generated for this target.
include CMakeFiles/render_ply_to_panorama_cli.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/render_ply_to_panorama_cli.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/render_ply_to_panorama_cli.dir/flags.make

CMakeFiles/render_ply_to_panorama_cli.dir/render_ply_to_panorama_cli.cc.o: CMakeFiles/render_ply_to_panorama_cli.dir/flags.make
CMakeFiles/render_ply_to_panorama_cli.dir/render_ply_to_panorama_cli.cc.o: render_ply_to_panorama_cli.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/furukawa/research/structured_indoor_modeling/code/calibration/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/render_ply_to_panorama_cli.dir/render_ply_to_panorama_cli.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/render_ply_to_panorama_cli.dir/render_ply_to_panorama_cli.cc.o -c /Users/furukawa/research/structured_indoor_modeling/code/calibration/render_ply_to_panorama_cli.cc

CMakeFiles/render_ply_to_panorama_cli.dir/render_ply_to_panorama_cli.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/render_ply_to_panorama_cli.dir/render_ply_to_panorama_cli.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/furukawa/research/structured_indoor_modeling/code/calibration/render_ply_to_panorama_cli.cc > CMakeFiles/render_ply_to_panorama_cli.dir/render_ply_to_panorama_cli.cc.i

CMakeFiles/render_ply_to_panorama_cli.dir/render_ply_to_panorama_cli.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/render_ply_to_panorama_cli.dir/render_ply_to_panorama_cli.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/furukawa/research/structured_indoor_modeling/code/calibration/render_ply_to_panorama_cli.cc -o CMakeFiles/render_ply_to_panorama_cli.dir/render_ply_to_panorama_cli.cc.s

CMakeFiles/render_ply_to_panorama_cli.dir/render_ply_to_panorama_cli.cc.o.requires:
.PHONY : CMakeFiles/render_ply_to_panorama_cli.dir/render_ply_to_panorama_cli.cc.o.requires

CMakeFiles/render_ply_to_panorama_cli.dir/render_ply_to_panorama_cli.cc.o.provides: CMakeFiles/render_ply_to_panorama_cli.dir/render_ply_to_panorama_cli.cc.o.requires
	$(MAKE) -f CMakeFiles/render_ply_to_panorama_cli.dir/build.make CMakeFiles/render_ply_to_panorama_cli.dir/render_ply_to_panorama_cli.cc.o.provides.build
.PHONY : CMakeFiles/render_ply_to_panorama_cli.dir/render_ply_to_panorama_cli.cc.o.provides

CMakeFiles/render_ply_to_panorama_cli.dir/render_ply_to_panorama_cli.cc.o.provides.build: CMakeFiles/render_ply_to_panorama_cli.dir/render_ply_to_panorama_cli.cc.o

CMakeFiles/render_ply_to_panorama_cli.dir/transformation.cc.o: CMakeFiles/render_ply_to_panorama_cli.dir/flags.make
CMakeFiles/render_ply_to_panorama_cli.dir/transformation.cc.o: transformation.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/furukawa/research/structured_indoor_modeling/code/calibration/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/render_ply_to_panorama_cli.dir/transformation.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/render_ply_to_panorama_cli.dir/transformation.cc.o -c /Users/furukawa/research/structured_indoor_modeling/code/calibration/transformation.cc

CMakeFiles/render_ply_to_panorama_cli.dir/transformation.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/render_ply_to_panorama_cli.dir/transformation.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/furukawa/research/structured_indoor_modeling/code/calibration/transformation.cc > CMakeFiles/render_ply_to_panorama_cli.dir/transformation.cc.i

CMakeFiles/render_ply_to_panorama_cli.dir/transformation.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/render_ply_to_panorama_cli.dir/transformation.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/furukawa/research/structured_indoor_modeling/code/calibration/transformation.cc -o CMakeFiles/render_ply_to_panorama_cli.dir/transformation.cc.s

CMakeFiles/render_ply_to_panorama_cli.dir/transformation.cc.o.requires:
.PHONY : CMakeFiles/render_ply_to_panorama_cli.dir/transformation.cc.o.requires

CMakeFiles/render_ply_to_panorama_cli.dir/transformation.cc.o.provides: CMakeFiles/render_ply_to_panorama_cli.dir/transformation.cc.o.requires
	$(MAKE) -f CMakeFiles/render_ply_to_panorama_cli.dir/build.make CMakeFiles/render_ply_to_panorama_cli.dir/transformation.cc.o.provides.build
.PHONY : CMakeFiles/render_ply_to_panorama_cli.dir/transformation.cc.o.provides

CMakeFiles/render_ply_to_panorama_cli.dir/transformation.cc.o.provides.build: CMakeFiles/render_ply_to_panorama_cli.dir/transformation.cc.o

CMakeFiles/render_ply_to_panorama_cli.dir/depthmap_refiner.cc.o: CMakeFiles/render_ply_to_panorama_cli.dir/flags.make
CMakeFiles/render_ply_to_panorama_cli.dir/depthmap_refiner.cc.o: depthmap_refiner.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/furukawa/research/structured_indoor_modeling/code/calibration/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/render_ply_to_panorama_cli.dir/depthmap_refiner.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/render_ply_to_panorama_cli.dir/depthmap_refiner.cc.o -c /Users/furukawa/research/structured_indoor_modeling/code/calibration/depthmap_refiner.cc

CMakeFiles/render_ply_to_panorama_cli.dir/depthmap_refiner.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/render_ply_to_panorama_cli.dir/depthmap_refiner.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/furukawa/research/structured_indoor_modeling/code/calibration/depthmap_refiner.cc > CMakeFiles/render_ply_to_panorama_cli.dir/depthmap_refiner.cc.i

CMakeFiles/render_ply_to_panorama_cli.dir/depthmap_refiner.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/render_ply_to_panorama_cli.dir/depthmap_refiner.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/furukawa/research/structured_indoor_modeling/code/calibration/depthmap_refiner.cc -o CMakeFiles/render_ply_to_panorama_cli.dir/depthmap_refiner.cc.s

CMakeFiles/render_ply_to_panorama_cli.dir/depthmap_refiner.cc.o.requires:
.PHONY : CMakeFiles/render_ply_to_panorama_cli.dir/depthmap_refiner.cc.o.requires

CMakeFiles/render_ply_to_panorama_cli.dir/depthmap_refiner.cc.o.provides: CMakeFiles/render_ply_to_panorama_cli.dir/depthmap_refiner.cc.o.requires
	$(MAKE) -f CMakeFiles/render_ply_to_panorama_cli.dir/build.make CMakeFiles/render_ply_to_panorama_cli.dir/depthmap_refiner.cc.o.provides.build
.PHONY : CMakeFiles/render_ply_to_panorama_cli.dir/depthmap_refiner.cc.o.provides

CMakeFiles/render_ply_to_panorama_cli.dir/depthmap_refiner.cc.o.provides.build: CMakeFiles/render_ply_to_panorama_cli.dir/depthmap_refiner.cc.o

# Object files for target render_ply_to_panorama_cli
render_ply_to_panorama_cli_OBJECTS = \
"CMakeFiles/render_ply_to_panorama_cli.dir/render_ply_to_panorama_cli.cc.o" \
"CMakeFiles/render_ply_to_panorama_cli.dir/transformation.cc.o" \
"CMakeFiles/render_ply_to_panorama_cli.dir/depthmap_refiner.cc.o"

# External object files for target render_ply_to_panorama_cli
render_ply_to_panorama_cli_EXTERNAL_OBJECTS =

render_ply_to_panorama_cli: CMakeFiles/render_ply_to_panorama_cli.dir/render_ply_to_panorama_cli.cc.o
render_ply_to_panorama_cli: CMakeFiles/render_ply_to_panorama_cli.dir/transformation.cc.o
render_ply_to_panorama_cli: CMakeFiles/render_ply_to_panorama_cli.dir/depthmap_refiner.cc.o
render_ply_to_panorama_cli: CMakeFiles/render_ply_to_panorama_cli.dir/build.make
render_ply_to_panorama_cli: /usr/local/lib/libopencv_videostab.2.4.9.dylib
render_ply_to_panorama_cli: /usr/local/lib/libopencv_video.2.4.9.dylib
render_ply_to_panorama_cli: /usr/local/lib/libopencv_ts.a
render_ply_to_panorama_cli: /usr/local/lib/libopencv_superres.2.4.9.dylib
render_ply_to_panorama_cli: /usr/local/lib/libopencv_stitching.2.4.9.dylib
render_ply_to_panorama_cli: /usr/local/lib/libopencv_photo.2.4.9.dylib
render_ply_to_panorama_cli: /usr/local/lib/libopencv_ocl.2.4.9.dylib
render_ply_to_panorama_cli: /usr/local/lib/libopencv_objdetect.2.4.9.dylib
render_ply_to_panorama_cli: /usr/local/lib/libopencv_nonfree.2.4.9.dylib
render_ply_to_panorama_cli: /usr/local/lib/libopencv_ml.2.4.9.dylib
render_ply_to_panorama_cli: /usr/local/lib/libopencv_legacy.2.4.9.dylib
render_ply_to_panorama_cli: /usr/local/lib/libopencv_imgproc.2.4.9.dylib
render_ply_to_panorama_cli: /usr/local/lib/libopencv_highgui.2.4.9.dylib
render_ply_to_panorama_cli: /usr/local/lib/libopencv_gpu.2.4.9.dylib
render_ply_to_panorama_cli: /usr/local/lib/libopencv_flann.2.4.9.dylib
render_ply_to_panorama_cli: /usr/local/lib/libopencv_features2d.2.4.9.dylib
render_ply_to_panorama_cli: /usr/local/lib/libopencv_core.2.4.9.dylib
render_ply_to_panorama_cli: /usr/local/lib/libopencv_contrib.2.4.9.dylib
render_ply_to_panorama_cli: /usr/local/lib/libopencv_calib3d.2.4.9.dylib
render_ply_to_panorama_cli: /usr/local/lib/libceres.1.9.0.dylib
render_ply_to_panorama_cli: /usr/local/lib/libopencv_nonfree.2.4.9.dylib
render_ply_to_panorama_cli: /usr/local/lib/libopencv_ocl.2.4.9.dylib
render_ply_to_panorama_cli: /usr/local/lib/libopencv_gpu.2.4.9.dylib
render_ply_to_panorama_cli: /usr/local/lib/libopencv_photo.2.4.9.dylib
render_ply_to_panorama_cli: /usr/local/lib/libopencv_objdetect.2.4.9.dylib
render_ply_to_panorama_cli: /usr/local/lib/libopencv_legacy.2.4.9.dylib
render_ply_to_panorama_cli: /usr/local/lib/libopencv_video.2.4.9.dylib
render_ply_to_panorama_cli: /usr/local/lib/libopencv_ml.2.4.9.dylib
render_ply_to_panorama_cli: /usr/local/lib/libopencv_calib3d.2.4.9.dylib
render_ply_to_panorama_cli: /usr/local/lib/libopencv_features2d.2.4.9.dylib
render_ply_to_panorama_cli: /usr/local/lib/libopencv_highgui.2.4.9.dylib
render_ply_to_panorama_cli: /usr/local/lib/libopencv_imgproc.2.4.9.dylib
render_ply_to_panorama_cli: /usr/local/lib/libopencv_flann.2.4.9.dylib
render_ply_to_panorama_cli: /usr/local/lib/libopencv_core.2.4.9.dylib
render_ply_to_panorama_cli: /usr/local/lib/libglog.dylib
render_ply_to_panorama_cli: CMakeFiles/render_ply_to_panorama_cli.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable render_ply_to_panorama_cli"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/render_ply_to_panorama_cli.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/render_ply_to_panorama_cli.dir/build: render_ply_to_panorama_cli
.PHONY : CMakeFiles/render_ply_to_panorama_cli.dir/build

CMakeFiles/render_ply_to_panorama_cli.dir/requires: CMakeFiles/render_ply_to_panorama_cli.dir/render_ply_to_panorama_cli.cc.o.requires
CMakeFiles/render_ply_to_panorama_cli.dir/requires: CMakeFiles/render_ply_to_panorama_cli.dir/transformation.cc.o.requires
CMakeFiles/render_ply_to_panorama_cli.dir/requires: CMakeFiles/render_ply_to_panorama_cli.dir/depthmap_refiner.cc.o.requires
.PHONY : CMakeFiles/render_ply_to_panorama_cli.dir/requires

CMakeFiles/render_ply_to_panorama_cli.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/render_ply_to_panorama_cli.dir/cmake_clean.cmake
.PHONY : CMakeFiles/render_ply_to_panorama_cli.dir/clean

CMakeFiles/render_ply_to_panorama_cli.dir/depend:
	cd /Users/furukawa/research/structured_indoor_modeling/code/calibration && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/furukawa/research/structured_indoor_modeling/code/calibration /Users/furukawa/research/structured_indoor_modeling/code/calibration /Users/furukawa/research/structured_indoor_modeling/code/calibration /Users/furukawa/research/structured_indoor_modeling/code/calibration /Users/furukawa/research/structured_indoor_modeling/code/calibration/CMakeFiles/render_ply_to_panorama_cli.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/render_ply_to_panorama_cli.dir/depend

