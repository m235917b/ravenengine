# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_SOURCE_DIR = /home/marvin/projects/ravenengine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marvin/projects/ravenengine/build

# Include any dependencies generated for this target.
include src/CMakeFiles/game.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/game.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/game.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/game.dir/flags.make

src/CMakeFiles/game.dir/Animation.cpp.o: src/CMakeFiles/game.dir/flags.make
src/CMakeFiles/game.dir/Animation.cpp.o: /home/marvin/projects/ravenengine/src/Animation.cpp
src/CMakeFiles/game.dir/Animation.cpp.o: src/CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/marvin/projects/ravenengine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/game.dir/Animation.cpp.o"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/game.dir/Animation.cpp.o -MF CMakeFiles/game.dir/Animation.cpp.o.d -o CMakeFiles/game.dir/Animation.cpp.o -c /home/marvin/projects/ravenengine/src/Animation.cpp

src/CMakeFiles/game.dir/Animation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/Animation.cpp.i"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/projects/ravenengine/src/Animation.cpp > CMakeFiles/game.dir/Animation.cpp.i

src/CMakeFiles/game.dir/Animation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/Animation.cpp.s"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/projects/ravenengine/src/Animation.cpp -o CMakeFiles/game.dir/Animation.cpp.s

src/CMakeFiles/game.dir/AnimTest.cpp.o: src/CMakeFiles/game.dir/flags.make
src/CMakeFiles/game.dir/AnimTest.cpp.o: /home/marvin/projects/ravenengine/src/AnimTest.cpp
src/CMakeFiles/game.dir/AnimTest.cpp.o: src/CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/marvin/projects/ravenengine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/game.dir/AnimTest.cpp.o"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/game.dir/AnimTest.cpp.o -MF CMakeFiles/game.dir/AnimTest.cpp.o.d -o CMakeFiles/game.dir/AnimTest.cpp.o -c /home/marvin/projects/ravenengine/src/AnimTest.cpp

src/CMakeFiles/game.dir/AnimTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/AnimTest.cpp.i"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/projects/ravenengine/src/AnimTest.cpp > CMakeFiles/game.dir/AnimTest.cpp.i

src/CMakeFiles/game.dir/AnimTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/AnimTest.cpp.s"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/projects/ravenengine/src/AnimTest.cpp -o CMakeFiles/game.dir/AnimTest.cpp.s

src/CMakeFiles/game.dir/ComposedObject.cpp.o: src/CMakeFiles/game.dir/flags.make
src/CMakeFiles/game.dir/ComposedObject.cpp.o: /home/marvin/projects/ravenengine/src/ComposedObject.cpp
src/CMakeFiles/game.dir/ComposedObject.cpp.o: src/CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/marvin/projects/ravenengine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/game.dir/ComposedObject.cpp.o"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/game.dir/ComposedObject.cpp.o -MF CMakeFiles/game.dir/ComposedObject.cpp.o.d -o CMakeFiles/game.dir/ComposedObject.cpp.o -c /home/marvin/projects/ravenengine/src/ComposedObject.cpp

src/CMakeFiles/game.dir/ComposedObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/ComposedObject.cpp.i"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/projects/ravenengine/src/ComposedObject.cpp > CMakeFiles/game.dir/ComposedObject.cpp.i

src/CMakeFiles/game.dir/ComposedObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/ComposedObject.cpp.s"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/projects/ravenengine/src/ComposedObject.cpp -o CMakeFiles/game.dir/ComposedObject.cpp.s

src/CMakeFiles/game.dir/Controler.cpp.o: src/CMakeFiles/game.dir/flags.make
src/CMakeFiles/game.dir/Controler.cpp.o: /home/marvin/projects/ravenengine/src/Controler.cpp
src/CMakeFiles/game.dir/Controler.cpp.o: src/CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/marvin/projects/ravenengine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/game.dir/Controler.cpp.o"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/game.dir/Controler.cpp.o -MF CMakeFiles/game.dir/Controler.cpp.o.d -o CMakeFiles/game.dir/Controler.cpp.o -c /home/marvin/projects/ravenengine/src/Controler.cpp

src/CMakeFiles/game.dir/Controler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/Controler.cpp.i"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/projects/ravenengine/src/Controler.cpp > CMakeFiles/game.dir/Controler.cpp.i

src/CMakeFiles/game.dir/Controler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/Controler.cpp.s"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/projects/ravenengine/src/Controler.cpp -o CMakeFiles/game.dir/Controler.cpp.s

src/CMakeFiles/game.dir/CubeTest.cpp.o: src/CMakeFiles/game.dir/flags.make
src/CMakeFiles/game.dir/CubeTest.cpp.o: /home/marvin/projects/ravenengine/src/CubeTest.cpp
src/CMakeFiles/game.dir/CubeTest.cpp.o: src/CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/marvin/projects/ravenengine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/game.dir/CubeTest.cpp.o"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/game.dir/CubeTest.cpp.o -MF CMakeFiles/game.dir/CubeTest.cpp.o.d -o CMakeFiles/game.dir/CubeTest.cpp.o -c /home/marvin/projects/ravenengine/src/CubeTest.cpp

src/CMakeFiles/game.dir/CubeTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/CubeTest.cpp.i"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/projects/ravenengine/src/CubeTest.cpp > CMakeFiles/game.dir/CubeTest.cpp.i

src/CMakeFiles/game.dir/CubeTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/CubeTest.cpp.s"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/projects/ravenengine/src/CubeTest.cpp -o CMakeFiles/game.dir/CubeTest.cpp.s

src/CMakeFiles/game.dir/loadObject.cpp.o: src/CMakeFiles/game.dir/flags.make
src/CMakeFiles/game.dir/loadObject.cpp.o: /home/marvin/projects/ravenengine/src/loadObject.cpp
src/CMakeFiles/game.dir/loadObject.cpp.o: src/CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/marvin/projects/ravenengine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/game.dir/loadObject.cpp.o"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/game.dir/loadObject.cpp.o -MF CMakeFiles/game.dir/loadObject.cpp.o.d -o CMakeFiles/game.dir/loadObject.cpp.o -c /home/marvin/projects/ravenengine/src/loadObject.cpp

src/CMakeFiles/game.dir/loadObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/loadObject.cpp.i"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/projects/ravenengine/src/loadObject.cpp > CMakeFiles/game.dir/loadObject.cpp.i

src/CMakeFiles/game.dir/loadObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/loadObject.cpp.s"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/projects/ravenengine/src/loadObject.cpp -o CMakeFiles/game.dir/loadObject.cpp.s

src/CMakeFiles/game.dir/loadShader.cpp.o: src/CMakeFiles/game.dir/flags.make
src/CMakeFiles/game.dir/loadShader.cpp.o: /home/marvin/projects/ravenengine/src/loadShader.cpp
src/CMakeFiles/game.dir/loadShader.cpp.o: src/CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/marvin/projects/ravenengine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/game.dir/loadShader.cpp.o"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/game.dir/loadShader.cpp.o -MF CMakeFiles/game.dir/loadShader.cpp.o.d -o CMakeFiles/game.dir/loadShader.cpp.o -c /home/marvin/projects/ravenengine/src/loadShader.cpp

src/CMakeFiles/game.dir/loadShader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/loadShader.cpp.i"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/projects/ravenengine/src/loadShader.cpp > CMakeFiles/game.dir/loadShader.cpp.i

src/CMakeFiles/game.dir/loadShader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/loadShader.cpp.s"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/projects/ravenengine/src/loadShader.cpp -o CMakeFiles/game.dir/loadShader.cpp.s

src/CMakeFiles/game.dir/main.cpp.o: src/CMakeFiles/game.dir/flags.make
src/CMakeFiles/game.dir/main.cpp.o: /home/marvin/projects/ravenengine/src/main.cpp
src/CMakeFiles/game.dir/main.cpp.o: src/CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/marvin/projects/ravenengine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/CMakeFiles/game.dir/main.cpp.o"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/game.dir/main.cpp.o -MF CMakeFiles/game.dir/main.cpp.o.d -o CMakeFiles/game.dir/main.cpp.o -c /home/marvin/projects/ravenengine/src/main.cpp

src/CMakeFiles/game.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/main.cpp.i"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/projects/ravenengine/src/main.cpp > CMakeFiles/game.dir/main.cpp.i

src/CMakeFiles/game.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/main.cpp.s"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/projects/ravenengine/src/main.cpp -o CMakeFiles/game.dir/main.cpp.s

src/CMakeFiles/game.dir/Mesh.cpp.o: src/CMakeFiles/game.dir/flags.make
src/CMakeFiles/game.dir/Mesh.cpp.o: /home/marvin/projects/ravenengine/src/Mesh.cpp
src/CMakeFiles/game.dir/Mesh.cpp.o: src/CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/marvin/projects/ravenengine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/CMakeFiles/game.dir/Mesh.cpp.o"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/game.dir/Mesh.cpp.o -MF CMakeFiles/game.dir/Mesh.cpp.o.d -o CMakeFiles/game.dir/Mesh.cpp.o -c /home/marvin/projects/ravenengine/src/Mesh.cpp

src/CMakeFiles/game.dir/Mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/Mesh.cpp.i"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/projects/ravenengine/src/Mesh.cpp > CMakeFiles/game.dir/Mesh.cpp.i

src/CMakeFiles/game.dir/Mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/Mesh.cpp.s"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/projects/ravenengine/src/Mesh.cpp -o CMakeFiles/game.dir/Mesh.cpp.s

src/CMakeFiles/game.dir/Model.cpp.o: src/CMakeFiles/game.dir/flags.make
src/CMakeFiles/game.dir/Model.cpp.o: /home/marvin/projects/ravenengine/src/Model.cpp
src/CMakeFiles/game.dir/Model.cpp.o: src/CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/marvin/projects/ravenengine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object src/CMakeFiles/game.dir/Model.cpp.o"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/game.dir/Model.cpp.o -MF CMakeFiles/game.dir/Model.cpp.o.d -o CMakeFiles/game.dir/Model.cpp.o -c /home/marvin/projects/ravenengine/src/Model.cpp

src/CMakeFiles/game.dir/Model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/Model.cpp.i"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/projects/ravenengine/src/Model.cpp > CMakeFiles/game.dir/Model.cpp.i

src/CMakeFiles/game.dir/Model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/Model.cpp.s"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/projects/ravenengine/src/Model.cpp -o CMakeFiles/game.dir/Model.cpp.s

src/CMakeFiles/game.dir/NPCSimple.cpp.o: src/CMakeFiles/game.dir/flags.make
src/CMakeFiles/game.dir/NPCSimple.cpp.o: /home/marvin/projects/ravenengine/src/NPCSimple.cpp
src/CMakeFiles/game.dir/NPCSimple.cpp.o: src/CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/marvin/projects/ravenengine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object src/CMakeFiles/game.dir/NPCSimple.cpp.o"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/game.dir/NPCSimple.cpp.o -MF CMakeFiles/game.dir/NPCSimple.cpp.o.d -o CMakeFiles/game.dir/NPCSimple.cpp.o -c /home/marvin/projects/ravenengine/src/NPCSimple.cpp

src/CMakeFiles/game.dir/NPCSimple.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/NPCSimple.cpp.i"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/projects/ravenengine/src/NPCSimple.cpp > CMakeFiles/game.dir/NPCSimple.cpp.i

src/CMakeFiles/game.dir/NPCSimple.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/NPCSimple.cpp.s"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/projects/ravenengine/src/NPCSimple.cpp -o CMakeFiles/game.dir/NPCSimple.cpp.s

src/CMakeFiles/game.dir/Player.cpp.o: src/CMakeFiles/game.dir/flags.make
src/CMakeFiles/game.dir/Player.cpp.o: /home/marvin/projects/ravenengine/src/Player.cpp
src/CMakeFiles/game.dir/Player.cpp.o: src/CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/marvin/projects/ravenengine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object src/CMakeFiles/game.dir/Player.cpp.o"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/game.dir/Player.cpp.o -MF CMakeFiles/game.dir/Player.cpp.o.d -o CMakeFiles/game.dir/Player.cpp.o -c /home/marvin/projects/ravenengine/src/Player.cpp

src/CMakeFiles/game.dir/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/Player.cpp.i"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/projects/ravenengine/src/Player.cpp > CMakeFiles/game.dir/Player.cpp.i

src/CMakeFiles/game.dir/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/Player.cpp.s"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/projects/ravenengine/src/Player.cpp -o CMakeFiles/game.dir/Player.cpp.s

src/CMakeFiles/game.dir/rpy.cpp.o: src/CMakeFiles/game.dir/flags.make
src/CMakeFiles/game.dir/rpy.cpp.o: /home/marvin/projects/ravenengine/src/rpy.cpp
src/CMakeFiles/game.dir/rpy.cpp.o: src/CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/marvin/projects/ravenengine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object src/CMakeFiles/game.dir/rpy.cpp.o"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/game.dir/rpy.cpp.o -MF CMakeFiles/game.dir/rpy.cpp.o.d -o CMakeFiles/game.dir/rpy.cpp.o -c /home/marvin/projects/ravenengine/src/rpy.cpp

src/CMakeFiles/game.dir/rpy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/rpy.cpp.i"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/projects/ravenengine/src/rpy.cpp > CMakeFiles/game.dir/rpy.cpp.i

src/CMakeFiles/game.dir/rpy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/rpy.cpp.s"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/projects/ravenengine/src/rpy.cpp -o CMakeFiles/game.dir/rpy.cpp.s

src/CMakeFiles/game.dir/Solid.cpp.o: src/CMakeFiles/game.dir/flags.make
src/CMakeFiles/game.dir/Solid.cpp.o: /home/marvin/projects/ravenengine/src/Solid.cpp
src/CMakeFiles/game.dir/Solid.cpp.o: src/CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/marvin/projects/ravenengine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object src/CMakeFiles/game.dir/Solid.cpp.o"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/game.dir/Solid.cpp.o -MF CMakeFiles/game.dir/Solid.cpp.o.d -o CMakeFiles/game.dir/Solid.cpp.o -c /home/marvin/projects/ravenengine/src/Solid.cpp

src/CMakeFiles/game.dir/Solid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/Solid.cpp.i"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/projects/ravenengine/src/Solid.cpp > CMakeFiles/game.dir/Solid.cpp.i

src/CMakeFiles/game.dir/Solid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/Solid.cpp.s"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/projects/ravenengine/src/Solid.cpp -o CMakeFiles/game.dir/Solid.cpp.s

src/CMakeFiles/game.dir/View.cpp.o: src/CMakeFiles/game.dir/flags.make
src/CMakeFiles/game.dir/View.cpp.o: /home/marvin/projects/ravenengine/src/View.cpp
src/CMakeFiles/game.dir/View.cpp.o: src/CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/marvin/projects/ravenengine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object src/CMakeFiles/game.dir/View.cpp.o"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/game.dir/View.cpp.o -MF CMakeFiles/game.dir/View.cpp.o.d -o CMakeFiles/game.dir/View.cpp.o -c /home/marvin/projects/ravenengine/src/View.cpp

src/CMakeFiles/game.dir/View.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/View.cpp.i"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/projects/ravenengine/src/View.cpp > CMakeFiles/game.dir/View.cpp.i

src/CMakeFiles/game.dir/View.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/View.cpp.s"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/projects/ravenengine/src/View.cpp -o CMakeFiles/game.dir/View.cpp.s

src/CMakeFiles/game.dir/WorldObject.cpp.o: src/CMakeFiles/game.dir/flags.make
src/CMakeFiles/game.dir/WorldObject.cpp.o: /home/marvin/projects/ravenengine/src/WorldObject.cpp
src/CMakeFiles/game.dir/WorldObject.cpp.o: src/CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/marvin/projects/ravenengine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object src/CMakeFiles/game.dir/WorldObject.cpp.o"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/game.dir/WorldObject.cpp.o -MF CMakeFiles/game.dir/WorldObject.cpp.o.d -o CMakeFiles/game.dir/WorldObject.cpp.o -c /home/marvin/projects/ravenengine/src/WorldObject.cpp

src/CMakeFiles/game.dir/WorldObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/WorldObject.cpp.i"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/projects/ravenengine/src/WorldObject.cpp > CMakeFiles/game.dir/WorldObject.cpp.i

src/CMakeFiles/game.dir/WorldObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/WorldObject.cpp.s"
	cd /home/marvin/projects/ravenengine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/projects/ravenengine/src/WorldObject.cpp -o CMakeFiles/game.dir/WorldObject.cpp.s

# Object files for target game
game_OBJECTS = \
"CMakeFiles/game.dir/Animation.cpp.o" \
"CMakeFiles/game.dir/AnimTest.cpp.o" \
"CMakeFiles/game.dir/ComposedObject.cpp.o" \
"CMakeFiles/game.dir/Controler.cpp.o" \
"CMakeFiles/game.dir/CubeTest.cpp.o" \
"CMakeFiles/game.dir/loadObject.cpp.o" \
"CMakeFiles/game.dir/loadShader.cpp.o" \
"CMakeFiles/game.dir/main.cpp.o" \
"CMakeFiles/game.dir/Mesh.cpp.o" \
"CMakeFiles/game.dir/Model.cpp.o" \
"CMakeFiles/game.dir/NPCSimple.cpp.o" \
"CMakeFiles/game.dir/Player.cpp.o" \
"CMakeFiles/game.dir/rpy.cpp.o" \
"CMakeFiles/game.dir/Solid.cpp.o" \
"CMakeFiles/game.dir/View.cpp.o" \
"CMakeFiles/game.dir/WorldObject.cpp.o"

# External object files for target game
game_EXTERNAL_OBJECTS =

src/game: src/CMakeFiles/game.dir/Animation.cpp.o
src/game: src/CMakeFiles/game.dir/AnimTest.cpp.o
src/game: src/CMakeFiles/game.dir/ComposedObject.cpp.o
src/game: src/CMakeFiles/game.dir/Controler.cpp.o
src/game: src/CMakeFiles/game.dir/CubeTest.cpp.o
src/game: src/CMakeFiles/game.dir/loadObject.cpp.o
src/game: src/CMakeFiles/game.dir/loadShader.cpp.o
src/game: src/CMakeFiles/game.dir/main.cpp.o
src/game: src/CMakeFiles/game.dir/Mesh.cpp.o
src/game: src/CMakeFiles/game.dir/Model.cpp.o
src/game: src/CMakeFiles/game.dir/NPCSimple.cpp.o
src/game: src/CMakeFiles/game.dir/Player.cpp.o
src/game: src/CMakeFiles/game.dir/rpy.cpp.o
src/game: src/CMakeFiles/game.dir/Solid.cpp.o
src/game: src/CMakeFiles/game.dir/View.cpp.o
src/game: src/CMakeFiles/game.dir/WorldObject.cpp.o
src/game: src/CMakeFiles/game.dir/build.make
src/game: src/CMakeFiles/game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/marvin/projects/ravenengine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Linking CXX executable game"
	cd /home/marvin/projects/ravenengine/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/game.dir/build: src/game
.PHONY : src/CMakeFiles/game.dir/build

src/CMakeFiles/game.dir/clean:
	cd /home/marvin/projects/ravenengine/build/src && $(CMAKE_COMMAND) -P CMakeFiles/game.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/game.dir/clean

src/CMakeFiles/game.dir/depend:
	cd /home/marvin/projects/ravenengine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marvin/projects/ravenengine /home/marvin/projects/ravenengine/src /home/marvin/projects/ravenengine/build /home/marvin/projects/ravenengine/build/src /home/marvin/projects/ravenengine/build/src/CMakeFiles/game.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/game.dir/depend

