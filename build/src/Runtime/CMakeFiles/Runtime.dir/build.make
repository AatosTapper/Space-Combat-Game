# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/aatos/VSCode C++/project-management-test/Space-Combat-Game"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/aatos/VSCode C++/project-management-test/Space-Combat-Game/build"

# Include any dependencies generated for this target.
include src/Runtime/CMakeFiles/Runtime.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/Runtime/CMakeFiles/Runtime.dir/compiler_depend.make

# Include the progress variables for this target.
include src/Runtime/CMakeFiles/Runtime.dir/progress.make

# Include the compile flags for this target's objects.
include src/Runtime/CMakeFiles/Runtime.dir/flags.make

src/Runtime/CMakeFiles/Runtime.dir/Runtime.cpp.o: src/Runtime/CMakeFiles/Runtime.dir/flags.make
src/Runtime/CMakeFiles/Runtime.dir/Runtime.cpp.o: /Users/aatos/VSCode\ C++/project-management-test/Space-Combat-Game/src/Runtime/Runtime.cpp
src/Runtime/CMakeFiles/Runtime.dir/Runtime.cpp.o: src/Runtime/CMakeFiles/Runtime.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/aatos/VSCode C++/project-management-test/Space-Combat-Game/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/Runtime/CMakeFiles/Runtime.dir/Runtime.cpp.o"
	cd "/Users/aatos/VSCode C++/project-management-test/Space-Combat-Game/build/src/Runtime" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/Runtime/CMakeFiles/Runtime.dir/Runtime.cpp.o -MF CMakeFiles/Runtime.dir/Runtime.cpp.o.d -o CMakeFiles/Runtime.dir/Runtime.cpp.o -c "/Users/aatos/VSCode C++/project-management-test/Space-Combat-Game/src/Runtime/Runtime.cpp"

src/Runtime/CMakeFiles/Runtime.dir/Runtime.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Runtime.dir/Runtime.cpp.i"
	cd "/Users/aatos/VSCode C++/project-management-test/Space-Combat-Game/build/src/Runtime" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/aatos/VSCode C++/project-management-test/Space-Combat-Game/src/Runtime/Runtime.cpp" > CMakeFiles/Runtime.dir/Runtime.cpp.i

src/Runtime/CMakeFiles/Runtime.dir/Runtime.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Runtime.dir/Runtime.cpp.s"
	cd "/Users/aatos/VSCode C++/project-management-test/Space-Combat-Game/build/src/Runtime" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/aatos/VSCode C++/project-management-test/Space-Combat-Game/src/Runtime/Runtime.cpp" -o CMakeFiles/Runtime.dir/Runtime.cpp.s

# Object files for target Runtime
Runtime_OBJECTS = \
"CMakeFiles/Runtime.dir/Runtime.cpp.o"

# External object files for target Runtime
Runtime_EXTERNAL_OBJECTS =

src/Runtime/libRuntime.a: src/Runtime/CMakeFiles/Runtime.dir/Runtime.cpp.o
src/Runtime/libRuntime.a: src/Runtime/CMakeFiles/Runtime.dir/build.make
src/Runtime/libRuntime.a: src/Runtime/CMakeFiles/Runtime.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/aatos/VSCode C++/project-management-test/Space-Combat-Game/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libRuntime.a"
	cd "/Users/aatos/VSCode C++/project-management-test/Space-Combat-Game/build/src/Runtime" && $(CMAKE_COMMAND) -P CMakeFiles/Runtime.dir/cmake_clean_target.cmake
	cd "/Users/aatos/VSCode C++/project-management-test/Space-Combat-Game/build/src/Runtime" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Runtime.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/Runtime/CMakeFiles/Runtime.dir/build: src/Runtime/libRuntime.a
.PHONY : src/Runtime/CMakeFiles/Runtime.dir/build

src/Runtime/CMakeFiles/Runtime.dir/clean:
	cd "/Users/aatos/VSCode C++/project-management-test/Space-Combat-Game/build/src/Runtime" && $(CMAKE_COMMAND) -P CMakeFiles/Runtime.dir/cmake_clean.cmake
.PHONY : src/Runtime/CMakeFiles/Runtime.dir/clean

src/Runtime/CMakeFiles/Runtime.dir/depend:
	cd "/Users/aatos/VSCode C++/project-management-test/Space-Combat-Game/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/aatos/VSCode C++/project-management-test/Space-Combat-Game" "/Users/aatos/VSCode C++/project-management-test/Space-Combat-Game/src/Runtime" "/Users/aatos/VSCode C++/project-management-test/Space-Combat-Game/build" "/Users/aatos/VSCode C++/project-management-test/Space-Combat-Game/build/src/Runtime" "/Users/aatos/VSCode C++/project-management-test/Space-Combat-Game/build/src/Runtime/CMakeFiles/Runtime.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/Runtime/CMakeFiles/Runtime.dir/depend

