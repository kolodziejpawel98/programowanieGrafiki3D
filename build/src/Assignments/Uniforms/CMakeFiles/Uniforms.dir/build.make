# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /snap/cmake/955/bin/cmake

# The command to remove a file.
RM = /snap/cmake/955/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pablo/Desktop/geometria3Dcwiczenia

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pablo/Desktop/geometria3Dcwiczenia/build

# Include any dependencies generated for this target.
include src/Assignments/Uniforms/CMakeFiles/Uniforms.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/Assignments/Uniforms/CMakeFiles/Uniforms.dir/compiler_depend.make

# Include the progress variables for this target.
include src/Assignments/Uniforms/CMakeFiles/Uniforms.dir/progress.make

# Include the compile flags for this target's objects.
include src/Assignments/Uniforms/CMakeFiles/Uniforms.dir/flags.make

src/Assignments/Uniforms/CMakeFiles/Uniforms.dir/main.cpp.o: src/Assignments/Uniforms/CMakeFiles/Uniforms.dir/flags.make
src/Assignments/Uniforms/CMakeFiles/Uniforms.dir/main.cpp.o: ../src/Assignments/Uniforms/main.cpp
src/Assignments/Uniforms/CMakeFiles/Uniforms.dir/main.cpp.o: src/Assignments/Uniforms/CMakeFiles/Uniforms.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pablo/Desktop/geometria3Dcwiczenia/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/Assignments/Uniforms/CMakeFiles/Uniforms.dir/main.cpp.o"
	cd /home/pablo/Desktop/geometria3Dcwiczenia/build/src/Assignments/Uniforms && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/Assignments/Uniforms/CMakeFiles/Uniforms.dir/main.cpp.o -MF CMakeFiles/Uniforms.dir/main.cpp.o.d -o CMakeFiles/Uniforms.dir/main.cpp.o -c /home/pablo/Desktop/geometria3Dcwiczenia/src/Assignments/Uniforms/main.cpp

src/Assignments/Uniforms/CMakeFiles/Uniforms.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Uniforms.dir/main.cpp.i"
	cd /home/pablo/Desktop/geometria3Dcwiczenia/build/src/Assignments/Uniforms && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pablo/Desktop/geometria3Dcwiczenia/src/Assignments/Uniforms/main.cpp > CMakeFiles/Uniforms.dir/main.cpp.i

src/Assignments/Uniforms/CMakeFiles/Uniforms.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Uniforms.dir/main.cpp.s"
	cd /home/pablo/Desktop/geometria3Dcwiczenia/build/src/Assignments/Uniforms && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pablo/Desktop/geometria3Dcwiczenia/src/Assignments/Uniforms/main.cpp -o CMakeFiles/Uniforms.dir/main.cpp.s

src/Assignments/Uniforms/CMakeFiles/Uniforms.dir/app.cpp.o: src/Assignments/Uniforms/CMakeFiles/Uniforms.dir/flags.make
src/Assignments/Uniforms/CMakeFiles/Uniforms.dir/app.cpp.o: ../src/Assignments/Uniforms/app.cpp
src/Assignments/Uniforms/CMakeFiles/Uniforms.dir/app.cpp.o: src/Assignments/Uniforms/CMakeFiles/Uniforms.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pablo/Desktop/geometria3Dcwiczenia/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/Assignments/Uniforms/CMakeFiles/Uniforms.dir/app.cpp.o"
	cd /home/pablo/Desktop/geometria3Dcwiczenia/build/src/Assignments/Uniforms && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/Assignments/Uniforms/CMakeFiles/Uniforms.dir/app.cpp.o -MF CMakeFiles/Uniforms.dir/app.cpp.o.d -o CMakeFiles/Uniforms.dir/app.cpp.o -c /home/pablo/Desktop/geometria3Dcwiczenia/src/Assignments/Uniforms/app.cpp

src/Assignments/Uniforms/CMakeFiles/Uniforms.dir/app.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Uniforms.dir/app.cpp.i"
	cd /home/pablo/Desktop/geometria3Dcwiczenia/build/src/Assignments/Uniforms && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pablo/Desktop/geometria3Dcwiczenia/src/Assignments/Uniforms/app.cpp > CMakeFiles/Uniforms.dir/app.cpp.i

src/Assignments/Uniforms/CMakeFiles/Uniforms.dir/app.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Uniforms.dir/app.cpp.s"
	cd /home/pablo/Desktop/geometria3Dcwiczenia/build/src/Assignments/Uniforms && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pablo/Desktop/geometria3Dcwiczenia/src/Assignments/Uniforms/app.cpp -o CMakeFiles/Uniforms.dir/app.cpp.s

# Object files for target Uniforms
Uniforms_OBJECTS = \
"CMakeFiles/Uniforms.dir/main.cpp.o" \
"CMakeFiles/Uniforms.dir/app.cpp.o"

# External object files for target Uniforms
Uniforms_EXTERNAL_OBJECTS = \
"/home/pablo/Desktop/geometria3Dcwiczenia/build/CMakeFiles/glad.dir/src/3rdParty/glad/glad_4_1/glad/src/gl.c.o"

src/Assignments/Uniforms/Uniforms: src/Assignments/Uniforms/CMakeFiles/Uniforms.dir/main.cpp.o
src/Assignments/Uniforms/Uniforms: src/Assignments/Uniforms/CMakeFiles/Uniforms.dir/app.cpp.o
src/Assignments/Uniforms/Uniforms: CMakeFiles/glad.dir/src/3rdParty/glad/glad_4_1/glad/src/gl.c.o
src/Assignments/Uniforms/Uniforms: src/Assignments/Uniforms/CMakeFiles/Uniforms.dir/build.make
src/Assignments/Uniforms/Uniforms: _deps/glfw-build/src/libglfw3.a
src/Assignments/Uniforms/Uniforms: src/Application/libapplication.a
src/Assignments/Uniforms/Uniforms: /usr/lib/x86_64-linux-gnu/libGLX.so
src/Assignments/Uniforms/Uniforms: /usr/lib/x86_64-linux-gnu/libOpenGL.so
src/Assignments/Uniforms/Uniforms: _deps/glfw-build/src/libglfw3.a
src/Assignments/Uniforms/Uniforms: /usr/lib/x86_64-linux-gnu/librt.so
src/Assignments/Uniforms/Uniforms: /usr/lib/x86_64-linux-gnu/libm.so
src/Assignments/Uniforms/Uniforms: src/Assignments/Uniforms/CMakeFiles/Uniforms.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pablo/Desktop/geometria3Dcwiczenia/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Uniforms"
	cd /home/pablo/Desktop/geometria3Dcwiczenia/build/src/Assignments/Uniforms && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Uniforms.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/Assignments/Uniforms/CMakeFiles/Uniforms.dir/build: src/Assignments/Uniforms/Uniforms
.PHONY : src/Assignments/Uniforms/CMakeFiles/Uniforms.dir/build

src/Assignments/Uniforms/CMakeFiles/Uniforms.dir/clean:
	cd /home/pablo/Desktop/geometria3Dcwiczenia/build/src/Assignments/Uniforms && $(CMAKE_COMMAND) -P CMakeFiles/Uniforms.dir/cmake_clean.cmake
.PHONY : src/Assignments/Uniforms/CMakeFiles/Uniforms.dir/clean

src/Assignments/Uniforms/CMakeFiles/Uniforms.dir/depend:
	cd /home/pablo/Desktop/geometria3Dcwiczenia/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pablo/Desktop/geometria3Dcwiczenia /home/pablo/Desktop/geometria3Dcwiczenia/src/Assignments/Uniforms /home/pablo/Desktop/geometria3Dcwiczenia/build /home/pablo/Desktop/geometria3Dcwiczenia/build/src/Assignments/Uniforms /home/pablo/Desktop/geometria3Dcwiczenia/build/src/Assignments/Uniforms/CMakeFiles/Uniforms.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/Assignments/Uniforms/CMakeFiles/Uniforms.dir/depend
