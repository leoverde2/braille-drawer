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
CMAKE_SOURCE_DIR = /home/ubuntu/projects/braille-drawer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/projects/braille-drawer/build

# Include any dependencies generated for this target.
include CMakeFiles/braille_core.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/braille_core.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/braille_core.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/braille_core.dir/flags.make

CMakeFiles/braille_core.dir/braille_core_autogen/mocs_compilation.cpp.o: CMakeFiles/braille_core.dir/flags.make
CMakeFiles/braille_core.dir/braille_core_autogen/mocs_compilation.cpp.o: braille_core_autogen/mocs_compilation.cpp
CMakeFiles/braille_core.dir/braille_core_autogen/mocs_compilation.cpp.o: CMakeFiles/braille_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/projects/braille-drawer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/braille_core.dir/braille_core_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/braille_core.dir/braille_core_autogen/mocs_compilation.cpp.o -MF CMakeFiles/braille_core.dir/braille_core_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/braille_core.dir/braille_core_autogen/mocs_compilation.cpp.o -c /home/ubuntu/projects/braille-drawer/build/braille_core_autogen/mocs_compilation.cpp

CMakeFiles/braille_core.dir/braille_core_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/braille_core.dir/braille_core_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/projects/braille-drawer/build/braille_core_autogen/mocs_compilation.cpp > CMakeFiles/braille_core.dir/braille_core_autogen/mocs_compilation.cpp.i

CMakeFiles/braille_core.dir/braille_core_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/braille_core.dir/braille_core_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/projects/braille-drawer/build/braille_core_autogen/mocs_compilation.cpp -o CMakeFiles/braille_core.dir/braille_core_autogen/mocs_compilation.cpp.s

CMakeFiles/braille_core.dir/src/braille_canvas.cpp.o: CMakeFiles/braille_core.dir/flags.make
CMakeFiles/braille_core.dir/src/braille_canvas.cpp.o: ../src/braille_canvas.cpp
CMakeFiles/braille_core.dir/src/braille_canvas.cpp.o: CMakeFiles/braille_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/projects/braille-drawer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/braille_core.dir/src/braille_canvas.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/braille_core.dir/src/braille_canvas.cpp.o -MF CMakeFiles/braille_core.dir/src/braille_canvas.cpp.o.d -o CMakeFiles/braille_core.dir/src/braille_canvas.cpp.o -c /home/ubuntu/projects/braille-drawer/src/braille_canvas.cpp

CMakeFiles/braille_core.dir/src/braille_canvas.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/braille_core.dir/src/braille_canvas.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/projects/braille-drawer/src/braille_canvas.cpp > CMakeFiles/braille_core.dir/src/braille_canvas.cpp.i

CMakeFiles/braille_core.dir/src/braille_canvas.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/braille_core.dir/src/braille_canvas.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/projects/braille-drawer/src/braille_canvas.cpp -o CMakeFiles/braille_core.dir/src/braille_canvas.cpp.s

CMakeFiles/braille_core.dir/src/braille_dot.cpp.o: CMakeFiles/braille_core.dir/flags.make
CMakeFiles/braille_core.dir/src/braille_dot.cpp.o: ../src/braille_dot.cpp
CMakeFiles/braille_core.dir/src/braille_dot.cpp.o: CMakeFiles/braille_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/projects/braille-drawer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/braille_core.dir/src/braille_dot.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/braille_core.dir/src/braille_dot.cpp.o -MF CMakeFiles/braille_core.dir/src/braille_dot.cpp.o.d -o CMakeFiles/braille_core.dir/src/braille_dot.cpp.o -c /home/ubuntu/projects/braille-drawer/src/braille_dot.cpp

CMakeFiles/braille_core.dir/src/braille_dot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/braille_core.dir/src/braille_dot.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/projects/braille-drawer/src/braille_dot.cpp > CMakeFiles/braille_core.dir/src/braille_dot.cpp.i

CMakeFiles/braille_core.dir/src/braille_dot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/braille_core.dir/src/braille_dot.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/projects/braille-drawer/src/braille_dot.cpp -o CMakeFiles/braille_core.dir/src/braille_dot.cpp.s

CMakeFiles/braille_core.dir/src/braille_text_box.cpp.o: CMakeFiles/braille_core.dir/flags.make
CMakeFiles/braille_core.dir/src/braille_text_box.cpp.o: ../src/braille_text_box.cpp
CMakeFiles/braille_core.dir/src/braille_text_box.cpp.o: CMakeFiles/braille_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/projects/braille-drawer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/braille_core.dir/src/braille_text_box.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/braille_core.dir/src/braille_text_box.cpp.o -MF CMakeFiles/braille_core.dir/src/braille_text_box.cpp.o.d -o CMakeFiles/braille_core.dir/src/braille_text_box.cpp.o -c /home/ubuntu/projects/braille-drawer/src/braille_text_box.cpp

CMakeFiles/braille_core.dir/src/braille_text_box.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/braille_core.dir/src/braille_text_box.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/projects/braille-drawer/src/braille_text_box.cpp > CMakeFiles/braille_core.dir/src/braille_text_box.cpp.i

CMakeFiles/braille_core.dir/src/braille_text_box.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/braille_core.dir/src/braille_text_box.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/projects/braille-drawer/src/braille_text_box.cpp -o CMakeFiles/braille_core.dir/src/braille_text_box.cpp.s

CMakeFiles/braille_core.dir/src/braille_view.cpp.o: CMakeFiles/braille_core.dir/flags.make
CMakeFiles/braille_core.dir/src/braille_view.cpp.o: ../src/braille_view.cpp
CMakeFiles/braille_core.dir/src/braille_view.cpp.o: CMakeFiles/braille_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/projects/braille-drawer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/braille_core.dir/src/braille_view.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/braille_core.dir/src/braille_view.cpp.o -MF CMakeFiles/braille_core.dir/src/braille_view.cpp.o.d -o CMakeFiles/braille_core.dir/src/braille_view.cpp.o -c /home/ubuntu/projects/braille-drawer/src/braille_view.cpp

CMakeFiles/braille_core.dir/src/braille_view.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/braille_core.dir/src/braille_view.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/projects/braille-drawer/src/braille_view.cpp > CMakeFiles/braille_core.dir/src/braille_view.cpp.i

CMakeFiles/braille_core.dir/src/braille_view.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/braille_core.dir/src/braille_view.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/projects/braille-drawer/src/braille_view.cpp -o CMakeFiles/braille_core.dir/src/braille_view.cpp.s

CMakeFiles/braille_core.dir/src/file.cpp.o: CMakeFiles/braille_core.dir/flags.make
CMakeFiles/braille_core.dir/src/file.cpp.o: ../src/file.cpp
CMakeFiles/braille_core.dir/src/file.cpp.o: CMakeFiles/braille_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/projects/braille-drawer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/braille_core.dir/src/file.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/braille_core.dir/src/file.cpp.o -MF CMakeFiles/braille_core.dir/src/file.cpp.o.d -o CMakeFiles/braille_core.dir/src/file.cpp.o -c /home/ubuntu/projects/braille-drawer/src/file.cpp

CMakeFiles/braille_core.dir/src/file.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/braille_core.dir/src/file.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/projects/braille-drawer/src/file.cpp > CMakeFiles/braille_core.dir/src/file.cpp.i

CMakeFiles/braille_core.dir/src/file.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/braille_core.dir/src/file.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/projects/braille-drawer/src/file.cpp -o CMakeFiles/braille_core.dir/src/file.cpp.s

CMakeFiles/braille_core.dir/src/image_menu.cpp.o: CMakeFiles/braille_core.dir/flags.make
CMakeFiles/braille_core.dir/src/image_menu.cpp.o: ../src/image_menu.cpp
CMakeFiles/braille_core.dir/src/image_menu.cpp.o: CMakeFiles/braille_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/projects/braille-drawer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/braille_core.dir/src/image_menu.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/braille_core.dir/src/image_menu.cpp.o -MF CMakeFiles/braille_core.dir/src/image_menu.cpp.o.d -o CMakeFiles/braille_core.dir/src/image_menu.cpp.o -c /home/ubuntu/projects/braille-drawer/src/image_menu.cpp

CMakeFiles/braille_core.dir/src/image_menu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/braille_core.dir/src/image_menu.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/projects/braille-drawer/src/image_menu.cpp > CMakeFiles/braille_core.dir/src/image_menu.cpp.i

CMakeFiles/braille_core.dir/src/image_menu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/braille_core.dir/src/image_menu.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/projects/braille-drawer/src/image_menu.cpp -o CMakeFiles/braille_core.dir/src/image_menu.cpp.s

CMakeFiles/braille_core.dir/src/main.cpp.o: CMakeFiles/braille_core.dir/flags.make
CMakeFiles/braille_core.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/braille_core.dir/src/main.cpp.o: CMakeFiles/braille_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/projects/braille-drawer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/braille_core.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/braille_core.dir/src/main.cpp.o -MF CMakeFiles/braille_core.dir/src/main.cpp.o.d -o CMakeFiles/braille_core.dir/src/main.cpp.o -c /home/ubuntu/projects/braille-drawer/src/main.cpp

CMakeFiles/braille_core.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/braille_core.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/projects/braille-drawer/src/main.cpp > CMakeFiles/braille_core.dir/src/main.cpp.i

CMakeFiles/braille_core.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/braille_core.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/projects/braille-drawer/src/main.cpp -o CMakeFiles/braille_core.dir/src/main.cpp.s

CMakeFiles/braille_core.dir/src/mainwindow.cpp.o: CMakeFiles/braille_core.dir/flags.make
CMakeFiles/braille_core.dir/src/mainwindow.cpp.o: ../src/mainwindow.cpp
CMakeFiles/braille_core.dir/src/mainwindow.cpp.o: CMakeFiles/braille_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/projects/braille-drawer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/braille_core.dir/src/mainwindow.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/braille_core.dir/src/mainwindow.cpp.o -MF CMakeFiles/braille_core.dir/src/mainwindow.cpp.o.d -o CMakeFiles/braille_core.dir/src/mainwindow.cpp.o -c /home/ubuntu/projects/braille-drawer/src/mainwindow.cpp

CMakeFiles/braille_core.dir/src/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/braille_core.dir/src/mainwindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/projects/braille-drawer/src/mainwindow.cpp > CMakeFiles/braille_core.dir/src/mainwindow.cpp.i

CMakeFiles/braille_core.dir/src/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/braille_core.dir/src/mainwindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/projects/braille-drawer/src/mainwindow.cpp -o CMakeFiles/braille_core.dir/src/mainwindow.cpp.s

CMakeFiles/braille_core.dir/src/state.cpp.o: CMakeFiles/braille_core.dir/flags.make
CMakeFiles/braille_core.dir/src/state.cpp.o: ../src/state.cpp
CMakeFiles/braille_core.dir/src/state.cpp.o: CMakeFiles/braille_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/projects/braille-drawer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/braille_core.dir/src/state.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/braille_core.dir/src/state.cpp.o -MF CMakeFiles/braille_core.dir/src/state.cpp.o.d -o CMakeFiles/braille_core.dir/src/state.cpp.o -c /home/ubuntu/projects/braille-drawer/src/state.cpp

CMakeFiles/braille_core.dir/src/state.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/braille_core.dir/src/state.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/projects/braille-drawer/src/state.cpp > CMakeFiles/braille_core.dir/src/state.cpp.i

CMakeFiles/braille_core.dir/src/state.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/braille_core.dir/src/state.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/projects/braille-drawer/src/state.cpp -o CMakeFiles/braille_core.dir/src/state.cpp.s

CMakeFiles/braille_core.dir/src/tools.cpp.o: CMakeFiles/braille_core.dir/flags.make
CMakeFiles/braille_core.dir/src/tools.cpp.o: ../src/tools.cpp
CMakeFiles/braille_core.dir/src/tools.cpp.o: CMakeFiles/braille_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/projects/braille-drawer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/braille_core.dir/src/tools.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/braille_core.dir/src/tools.cpp.o -MF CMakeFiles/braille_core.dir/src/tools.cpp.o.d -o CMakeFiles/braille_core.dir/src/tools.cpp.o -c /home/ubuntu/projects/braille-drawer/src/tools.cpp

CMakeFiles/braille_core.dir/src/tools.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/braille_core.dir/src/tools.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/projects/braille-drawer/src/tools.cpp > CMakeFiles/braille_core.dir/src/tools.cpp.i

CMakeFiles/braille_core.dir/src/tools.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/braille_core.dir/src/tools.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/projects/braille-drawer/src/tools.cpp -o CMakeFiles/braille_core.dir/src/tools.cpp.s

# Object files for target braille_core
braille_core_OBJECTS = \
"CMakeFiles/braille_core.dir/braille_core_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/braille_core.dir/src/braille_canvas.cpp.o" \
"CMakeFiles/braille_core.dir/src/braille_dot.cpp.o" \
"CMakeFiles/braille_core.dir/src/braille_text_box.cpp.o" \
"CMakeFiles/braille_core.dir/src/braille_view.cpp.o" \
"CMakeFiles/braille_core.dir/src/file.cpp.o" \
"CMakeFiles/braille_core.dir/src/image_menu.cpp.o" \
"CMakeFiles/braille_core.dir/src/main.cpp.o" \
"CMakeFiles/braille_core.dir/src/mainwindow.cpp.o" \
"CMakeFiles/braille_core.dir/src/state.cpp.o" \
"CMakeFiles/braille_core.dir/src/tools.cpp.o"

# External object files for target braille_core
braille_core_EXTERNAL_OBJECTS =

libbraille_core.a: CMakeFiles/braille_core.dir/braille_core_autogen/mocs_compilation.cpp.o
libbraille_core.a: CMakeFiles/braille_core.dir/src/braille_canvas.cpp.o
libbraille_core.a: CMakeFiles/braille_core.dir/src/braille_dot.cpp.o
libbraille_core.a: CMakeFiles/braille_core.dir/src/braille_text_box.cpp.o
libbraille_core.a: CMakeFiles/braille_core.dir/src/braille_view.cpp.o
libbraille_core.a: CMakeFiles/braille_core.dir/src/file.cpp.o
libbraille_core.a: CMakeFiles/braille_core.dir/src/image_menu.cpp.o
libbraille_core.a: CMakeFiles/braille_core.dir/src/main.cpp.o
libbraille_core.a: CMakeFiles/braille_core.dir/src/mainwindow.cpp.o
libbraille_core.a: CMakeFiles/braille_core.dir/src/state.cpp.o
libbraille_core.a: CMakeFiles/braille_core.dir/src/tools.cpp.o
libbraille_core.a: CMakeFiles/braille_core.dir/build.make
libbraille_core.a: CMakeFiles/braille_core.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/projects/braille-drawer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX static library libbraille_core.a"
	$(CMAKE_COMMAND) -P CMakeFiles/braille_core.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/braille_core.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/braille_core.dir/build: libbraille_core.a
.PHONY : CMakeFiles/braille_core.dir/build

CMakeFiles/braille_core.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/braille_core.dir/cmake_clean.cmake
.PHONY : CMakeFiles/braille_core.dir/clean

CMakeFiles/braille_core.dir/depend:
	cd /home/ubuntu/projects/braille-drawer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/projects/braille-drawer /home/ubuntu/projects/braille-drawer /home/ubuntu/projects/braille-drawer/build /home/ubuntu/projects/braille-drawer/build /home/ubuntu/projects/braille-drawer/build/CMakeFiles/braille_core.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/braille_core.dir/depend

