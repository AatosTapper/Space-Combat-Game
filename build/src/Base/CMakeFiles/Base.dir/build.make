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
include src/Base/CMakeFiles/Base.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/Base/CMakeFiles/Base.dir/compiler_depend.make

# Include the progress variables for this target.
include src/Base/CMakeFiles/Base.dir/progress.make

# Include the compile flags for this target's objects.
include src/Base/CMakeFiles/Base.dir/flags.make

src/Base/CMakeFiles/Base.dir/Base.cpp.o: src/Base/CMakeFiles/Base.dir/flags.make
src/Base/CMakeFiles/Base.dir/Base.cpp.o: /Users/aatos/VSCode\ C++/project-management-test/Space-Combat-Game/src/Base/Base.cpp
src/Base/CMakeFiles/Base.dir/Base.cpp.o: src/Base/CMakeFiles/Base.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/aatos/VSCode C++/project-management-test/Space-Combat-Game/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/Base/CMakeFiles/Base.dir/Base.cpp.o"
	cd "/Users/aatos/VSCode C++/project-management-test/Space-Combat-Game/build/src/Base" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/Base/CMakeFiles/Base.dir/Base.cpp.o -MF CMakeFiles/Base.dir/Base.cpp.o.d -o CMakeFiles/Base.dir/Base.cpp.o -c "/Users/aatos/VSCode C++/project-management-test/Space-Combat-Game/src/Base/Base.cpp"

src/Base/CMakeFiles/Base.dir/Base.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Base.dir/Base.cpp.i"
	cd "/Users/aatos/VSCode C++/project-management-test/Space-Combat-Game/build/src/Base" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/aatos/VSCode C++/project-management-test/Space-Combat-Game/src/Base/Base.cpp" > CMakeFiles/Base.dir/Base.cpp.i

src/Base/CMakeFiles/Base.dir/Base.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Base.dir/Base.cpp.s"
	cd "/Users/aatos/VSCode C++/project-management-test/Space-Combat-Game/build/src/Base" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/aatos/VSCode C++/project-management-test/Space-Combat-Game/src/Base/Base.cpp" -o CMakeFiles/Base.dir/Base.cpp.s

# Object files for target Base
Base_OBJECTS = \
"CMakeFiles/Base.dir/Base.cpp.o"

# External object files for target Base
Base_EXTERNAL_OBJECTS =

src/Base/libBase.a: src/Base/CMakeFiles/Base.dir/Base.cpp.o
src/Base/libBase.a: src/Base/CMakeFiles/Base.dir/build.make
src/Base/libBase.a: src/Base/CMakeFiles/Base.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/aatos/VSCode C++/project-management-test/Space-Combat-Game/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libBase.a"
	cd "/Users/aatos/VSCode C++/project-management-test/Space-Combat-Game/build/src/Base" && $(CMAKE_COMMAND) -P CMakeFiles/Base.dir/cmake_clean_target.cmake
	cd "/Users/aatos/VSCode C++/project-management-test/Space-Combat-Game/build/src/Base" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Base.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/Base/CMakeFiles/Base.dir/build: src/Base/libBase.a
.PHONY : src/Base/CMakeFiles/Base.dir/build

src/Base/CMakeFiles/Base.dir/clean:
	cd "/Users/aatos/VSCode C++/project-management-test/Space-Combat-Game/build/src/Base" && $(CMAKE_COMMAND) -P CMakeFiles/Base.dir/cmake_clean.cmake
.PHONY : src/Base/CMakeFiles/Base.dir/clean

src/Base/CMakeFiles/Base.dir/depend:
	cd "/Users/aatos/VSCode C++/project-management-test/Space-Combat-Game/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/aatos/VSCode C++/project-management-test/Space-Combat-Game" "/Users/aatos/VSCode C++/project-management-test/Space-Combat-Game/src/Base" "/Users/aatos/VSCode C++/project-management-test/Space-Combat-Game/build" "/Users/aatos/VSCode C++/project-management-test/Space-Combat-Game/build/src/Base" "/Users/aatos/VSCode C++/project-management-test/Space-Combat-Game/build/src/Base/CMakeFiles/Base.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/Base/CMakeFiles/Base.dir/depend

