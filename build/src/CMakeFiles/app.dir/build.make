# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /home/marvin/Documents/projects/ravenengine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marvin/Documents/projects/ravenengine/build

# Include any dependencies generated for this target.
include src/CMakeFiles/app.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/app.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/app.dir/flags.make

src/CMakeFiles/app.dir/Animation.cpp.o: src/CMakeFiles/app.dir/flags.make
src/CMakeFiles/app.dir/Animation.cpp.o: ../src/Animation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marvin/Documents/projects/ravenengine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/app.dir/Animation.cpp.o"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/app.dir/Animation.cpp.o -c /home/marvin/Documents/projects/ravenengine/src/Animation.cpp

src/CMakeFiles/app.dir/Animation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/Animation.cpp.i"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/Documents/projects/ravenengine/src/Animation.cpp > CMakeFiles/app.dir/Animation.cpp.i

src/CMakeFiles/app.dir/Animation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/Animation.cpp.s"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/Documents/projects/ravenengine/src/Animation.cpp -o CMakeFiles/app.dir/Animation.cpp.s

src/CMakeFiles/app.dir/AnimTest.cpp.o: src/CMakeFiles/app.dir/flags.make
src/CMakeFiles/app.dir/AnimTest.cpp.o: ../src/AnimTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marvin/Documents/projects/ravenengine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/app.dir/AnimTest.cpp.o"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/app.dir/AnimTest.cpp.o -c /home/marvin/Documents/projects/ravenengine/src/AnimTest.cpp

src/CMakeFiles/app.dir/AnimTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/AnimTest.cpp.i"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/Documents/projects/ravenengine/src/AnimTest.cpp > CMakeFiles/app.dir/AnimTest.cpp.i

src/CMakeFiles/app.dir/AnimTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/AnimTest.cpp.s"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/Documents/projects/ravenengine/src/AnimTest.cpp -o CMakeFiles/app.dir/AnimTest.cpp.s

src/CMakeFiles/app.dir/ComposedObject.cpp.o: src/CMakeFiles/app.dir/flags.make
src/CMakeFiles/app.dir/ComposedObject.cpp.o: ../src/ComposedObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marvin/Documents/projects/ravenengine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/app.dir/ComposedObject.cpp.o"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/app.dir/ComposedObject.cpp.o -c /home/marvin/Documents/projects/ravenengine/src/ComposedObject.cpp

src/CMakeFiles/app.dir/ComposedObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/ComposedObject.cpp.i"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/Documents/projects/ravenengine/src/ComposedObject.cpp > CMakeFiles/app.dir/ComposedObject.cpp.i

src/CMakeFiles/app.dir/ComposedObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/ComposedObject.cpp.s"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/Documents/projects/ravenengine/src/ComposedObject.cpp -o CMakeFiles/app.dir/ComposedObject.cpp.s

src/CMakeFiles/app.dir/Controler.cpp.o: src/CMakeFiles/app.dir/flags.make
src/CMakeFiles/app.dir/Controler.cpp.o: ../src/Controler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marvin/Documents/projects/ravenengine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/app.dir/Controler.cpp.o"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/app.dir/Controler.cpp.o -c /home/marvin/Documents/projects/ravenengine/src/Controler.cpp

src/CMakeFiles/app.dir/Controler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/Controler.cpp.i"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/Documents/projects/ravenengine/src/Controler.cpp > CMakeFiles/app.dir/Controler.cpp.i

src/CMakeFiles/app.dir/Controler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/Controler.cpp.s"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/Documents/projects/ravenengine/src/Controler.cpp -o CMakeFiles/app.dir/Controler.cpp.s

src/CMakeFiles/app.dir/CubeTest.cpp.o: src/CMakeFiles/app.dir/flags.make
src/CMakeFiles/app.dir/CubeTest.cpp.o: ../src/CubeTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marvin/Documents/projects/ravenengine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/app.dir/CubeTest.cpp.o"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/app.dir/CubeTest.cpp.o -c /home/marvin/Documents/projects/ravenengine/src/CubeTest.cpp

src/CMakeFiles/app.dir/CubeTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/CubeTest.cpp.i"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/Documents/projects/ravenengine/src/CubeTest.cpp > CMakeFiles/app.dir/CubeTest.cpp.i

src/CMakeFiles/app.dir/CubeTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/CubeTest.cpp.s"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/Documents/projects/ravenengine/src/CubeTest.cpp -o CMakeFiles/app.dir/CubeTest.cpp.s

src/CMakeFiles/app.dir/loadObject.cpp.o: src/CMakeFiles/app.dir/flags.make
src/CMakeFiles/app.dir/loadObject.cpp.o: ../src/loadObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marvin/Documents/projects/ravenengine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/app.dir/loadObject.cpp.o"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/app.dir/loadObject.cpp.o -c /home/marvin/Documents/projects/ravenengine/src/loadObject.cpp

src/CMakeFiles/app.dir/loadObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/loadObject.cpp.i"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/Documents/projects/ravenengine/src/loadObject.cpp > CMakeFiles/app.dir/loadObject.cpp.i

src/CMakeFiles/app.dir/loadObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/loadObject.cpp.s"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/Documents/projects/ravenengine/src/loadObject.cpp -o CMakeFiles/app.dir/loadObject.cpp.s

src/CMakeFiles/app.dir/loadShader.cpp.o: src/CMakeFiles/app.dir/flags.make
src/CMakeFiles/app.dir/loadShader.cpp.o: ../src/loadShader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marvin/Documents/projects/ravenengine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/app.dir/loadShader.cpp.o"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/app.dir/loadShader.cpp.o -c /home/marvin/Documents/projects/ravenengine/src/loadShader.cpp

src/CMakeFiles/app.dir/loadShader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/loadShader.cpp.i"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/Documents/projects/ravenengine/src/loadShader.cpp > CMakeFiles/app.dir/loadShader.cpp.i

src/CMakeFiles/app.dir/loadShader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/loadShader.cpp.s"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/Documents/projects/ravenengine/src/loadShader.cpp -o CMakeFiles/app.dir/loadShader.cpp.s

src/CMakeFiles/app.dir/main.cpp.o: src/CMakeFiles/app.dir/flags.make
src/CMakeFiles/app.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marvin/Documents/projects/ravenengine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/CMakeFiles/app.dir/main.cpp.o"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/app.dir/main.cpp.o -c /home/marvin/Documents/projects/ravenengine/src/main.cpp

src/CMakeFiles/app.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/main.cpp.i"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/Documents/projects/ravenengine/src/main.cpp > CMakeFiles/app.dir/main.cpp.i

src/CMakeFiles/app.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/main.cpp.s"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/Documents/projects/ravenengine/src/main.cpp -o CMakeFiles/app.dir/main.cpp.s

src/CMakeFiles/app.dir/Mesh.cpp.o: src/CMakeFiles/app.dir/flags.make
src/CMakeFiles/app.dir/Mesh.cpp.o: ../src/Mesh.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marvin/Documents/projects/ravenengine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/CMakeFiles/app.dir/Mesh.cpp.o"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/app.dir/Mesh.cpp.o -c /home/marvin/Documents/projects/ravenengine/src/Mesh.cpp

src/CMakeFiles/app.dir/Mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/Mesh.cpp.i"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/Documents/projects/ravenengine/src/Mesh.cpp > CMakeFiles/app.dir/Mesh.cpp.i

src/CMakeFiles/app.dir/Mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/Mesh.cpp.s"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/Documents/projects/ravenengine/src/Mesh.cpp -o CMakeFiles/app.dir/Mesh.cpp.s

src/CMakeFiles/app.dir/Model.cpp.o: src/CMakeFiles/app.dir/flags.make
src/CMakeFiles/app.dir/Model.cpp.o: ../src/Model.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marvin/Documents/projects/ravenengine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object src/CMakeFiles/app.dir/Model.cpp.o"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/app.dir/Model.cpp.o -c /home/marvin/Documents/projects/ravenengine/src/Model.cpp

src/CMakeFiles/app.dir/Model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/Model.cpp.i"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/Documents/projects/ravenengine/src/Model.cpp > CMakeFiles/app.dir/Model.cpp.i

src/CMakeFiles/app.dir/Model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/Model.cpp.s"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/Documents/projects/ravenengine/src/Model.cpp -o CMakeFiles/app.dir/Model.cpp.s

src/CMakeFiles/app.dir/NPCSimple.cpp.o: src/CMakeFiles/app.dir/flags.make
src/CMakeFiles/app.dir/NPCSimple.cpp.o: ../src/NPCSimple.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marvin/Documents/projects/ravenengine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object src/CMakeFiles/app.dir/NPCSimple.cpp.o"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/app.dir/NPCSimple.cpp.o -c /home/marvin/Documents/projects/ravenengine/src/NPCSimple.cpp

src/CMakeFiles/app.dir/NPCSimple.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/NPCSimple.cpp.i"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/Documents/projects/ravenengine/src/NPCSimple.cpp > CMakeFiles/app.dir/NPCSimple.cpp.i

src/CMakeFiles/app.dir/NPCSimple.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/NPCSimple.cpp.s"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/Documents/projects/ravenengine/src/NPCSimple.cpp -o CMakeFiles/app.dir/NPCSimple.cpp.s

src/CMakeFiles/app.dir/Player.cpp.o: src/CMakeFiles/app.dir/flags.make
src/CMakeFiles/app.dir/Player.cpp.o: ../src/Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marvin/Documents/projects/ravenengine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object src/CMakeFiles/app.dir/Player.cpp.o"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/app.dir/Player.cpp.o -c /home/marvin/Documents/projects/ravenengine/src/Player.cpp

src/CMakeFiles/app.dir/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/Player.cpp.i"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/Documents/projects/ravenengine/src/Player.cpp > CMakeFiles/app.dir/Player.cpp.i

src/CMakeFiles/app.dir/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/Player.cpp.s"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/Documents/projects/ravenengine/src/Player.cpp -o CMakeFiles/app.dir/Player.cpp.s

src/CMakeFiles/app.dir/rpy.cpp.o: src/CMakeFiles/app.dir/flags.make
src/CMakeFiles/app.dir/rpy.cpp.o: ../src/rpy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marvin/Documents/projects/ravenengine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object src/CMakeFiles/app.dir/rpy.cpp.o"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/app.dir/rpy.cpp.o -c /home/marvin/Documents/projects/ravenengine/src/rpy.cpp

src/CMakeFiles/app.dir/rpy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/rpy.cpp.i"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/Documents/projects/ravenengine/src/rpy.cpp > CMakeFiles/app.dir/rpy.cpp.i

src/CMakeFiles/app.dir/rpy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/rpy.cpp.s"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/Documents/projects/ravenengine/src/rpy.cpp -o CMakeFiles/app.dir/rpy.cpp.s

src/CMakeFiles/app.dir/Solid.cpp.o: src/CMakeFiles/app.dir/flags.make
src/CMakeFiles/app.dir/Solid.cpp.o: ../src/Solid.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marvin/Documents/projects/ravenengine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object src/CMakeFiles/app.dir/Solid.cpp.o"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/app.dir/Solid.cpp.o -c /home/marvin/Documents/projects/ravenengine/src/Solid.cpp

src/CMakeFiles/app.dir/Solid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/Solid.cpp.i"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/Documents/projects/ravenengine/src/Solid.cpp > CMakeFiles/app.dir/Solid.cpp.i

src/CMakeFiles/app.dir/Solid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/Solid.cpp.s"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/Documents/projects/ravenengine/src/Solid.cpp -o CMakeFiles/app.dir/Solid.cpp.s

src/CMakeFiles/app.dir/View.cpp.o: src/CMakeFiles/app.dir/flags.make
src/CMakeFiles/app.dir/View.cpp.o: ../src/View.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marvin/Documents/projects/ravenengine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object src/CMakeFiles/app.dir/View.cpp.o"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/app.dir/View.cpp.o -c /home/marvin/Documents/projects/ravenengine/src/View.cpp

src/CMakeFiles/app.dir/View.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/View.cpp.i"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/Documents/projects/ravenengine/src/View.cpp > CMakeFiles/app.dir/View.cpp.i

src/CMakeFiles/app.dir/View.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/View.cpp.s"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/Documents/projects/ravenengine/src/View.cpp -o CMakeFiles/app.dir/View.cpp.s

src/CMakeFiles/app.dir/WorldObject.cpp.o: src/CMakeFiles/app.dir/flags.make
src/CMakeFiles/app.dir/WorldObject.cpp.o: ../src/WorldObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marvin/Documents/projects/ravenengine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object src/CMakeFiles/app.dir/WorldObject.cpp.o"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/app.dir/WorldObject.cpp.o -c /home/marvin/Documents/projects/ravenengine/src/WorldObject.cpp

src/CMakeFiles/app.dir/WorldObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/WorldObject.cpp.i"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/Documents/projects/ravenengine/src/WorldObject.cpp > CMakeFiles/app.dir/WorldObject.cpp.i

src/CMakeFiles/app.dir/WorldObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/WorldObject.cpp.s"
	cd /home/marvin/Documents/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/Documents/projects/ravenengine/src/WorldObject.cpp -o CMakeFiles/app.dir/WorldObject.cpp.s

# Object files for target app
app_OBJECTS = \
"CMakeFiles/app.dir/Animation.cpp.o" \
"CMakeFiles/app.dir/AnimTest.cpp.o" \
"CMakeFiles/app.dir/ComposedObject.cpp.o" \
"CMakeFiles/app.dir/Controler.cpp.o" \
"CMakeFiles/app.dir/CubeTest.cpp.o" \
"CMakeFiles/app.dir/loadObject.cpp.o" \
"CMakeFiles/app.dir/loadShader.cpp.o" \
"CMakeFiles/app.dir/main.cpp.o" \
"CMakeFiles/app.dir/Mesh.cpp.o" \
"CMakeFiles/app.dir/Model.cpp.o" \
"CMakeFiles/app.dir/NPCSimple.cpp.o" \
"CMakeFiles/app.dir/Player.cpp.o" \
"CMakeFiles/app.dir/rpy.cpp.o" \
"CMakeFiles/app.dir/Solid.cpp.o" \
"CMakeFiles/app.dir/View.cpp.o" \
"CMakeFiles/app.dir/WorldObject.cpp.o"

# External object files for target app
app_EXTERNAL_OBJECTS =

src/app: src/CMakeFiles/app.dir/Animation.cpp.o
src/app: src/CMakeFiles/app.dir/AnimTest.cpp.o
src/app: src/CMakeFiles/app.dir/ComposedObject.cpp.o
src/app: src/CMakeFiles/app.dir/Controler.cpp.o
src/app: src/CMakeFiles/app.dir/CubeTest.cpp.o
src/app: src/CMakeFiles/app.dir/loadObject.cpp.o
src/app: src/CMakeFiles/app.dir/loadShader.cpp.o
src/app: src/CMakeFiles/app.dir/main.cpp.o
src/app: src/CMakeFiles/app.dir/Mesh.cpp.o
src/app: src/CMakeFiles/app.dir/Model.cpp.o
src/app: src/CMakeFiles/app.dir/NPCSimple.cpp.o
src/app: src/CMakeFiles/app.dir/Player.cpp.o
src/app: src/CMakeFiles/app.dir/rpy.cpp.o
src/app: src/CMakeFiles/app.dir/Solid.cpp.o
src/app: src/CMakeFiles/app.dir/View.cpp.o
src/app: src/CMakeFiles/app.dir/WorldObject.cpp.o
src/app: src/CMakeFiles/app.dir/build.make
src/app: src/CMakeFiles/app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/marvin/Documents/projects/ravenengine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Linking CXX executable app"
	cd /home/marvin/Documents/projects/ravenengine/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/app.dir/build: src/app

.PHONY : src/CMakeFiles/app.dir/build

src/CMakeFiles/app.dir/clean:
	cd /home/marvin/Documents/projects/ravenengine/build/src && $(CMAKE_COMMAND) -P CMakeFiles/app.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/app.dir/clean

src/CMakeFiles/app.dir/depend:
	cd /home/marvin/Documents/projects/ravenengine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marvin/Documents/projects/ravenengine /home/marvin/Documents/projects/ravenengine/src /home/marvin/Documents/projects/ravenengine/build /home/marvin/Documents/projects/ravenengine/build/src /home/marvin/Documents/projects/ravenengine/build/src/CMakeFiles/app.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/app.dir/depend

