# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\filip\OneDrive\Pulpit\6sem\pdm\TS_parser_S0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\filip\OneDrive\Pulpit\6sem\pdm\TS_parser_S0\build

# Include any dependencies generated for this target.
include CMakeFiles/TS-PARSER.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TS-PARSER.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TS-PARSER.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TS-PARSER.dir/flags.make

CMakeFiles/TS-PARSER.dir/tsTransportStream.cpp.obj: CMakeFiles/TS-PARSER.dir/flags.make
CMakeFiles/TS-PARSER.dir/tsTransportStream.cpp.obj: C:/Users/filip/OneDrive/Pulpit/6sem/pdm/TS_parser_S0/tsTransportStream.cpp
CMakeFiles/TS-PARSER.dir/tsTransportStream.cpp.obj: CMakeFiles/TS-PARSER.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\filip\OneDrive\Pulpit\6sem\pdm\TS_parser_S0\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TS-PARSER.dir/tsTransportStream.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TS-PARSER.dir/tsTransportStream.cpp.obj -MF CMakeFiles\TS-PARSER.dir\tsTransportStream.cpp.obj.d -o CMakeFiles\TS-PARSER.dir\tsTransportStream.cpp.obj -c C:\Users\filip\OneDrive\Pulpit\6sem\pdm\TS_parser_S0\tsTransportStream.cpp

CMakeFiles/TS-PARSER.dir/tsTransportStream.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TS-PARSER.dir/tsTransportStream.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\filip\OneDrive\Pulpit\6sem\pdm\TS_parser_S0\tsTransportStream.cpp > CMakeFiles\TS-PARSER.dir\tsTransportStream.cpp.i

CMakeFiles/TS-PARSER.dir/tsTransportStream.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TS-PARSER.dir/tsTransportStream.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\filip\OneDrive\Pulpit\6sem\pdm\TS_parser_S0\tsTransportStream.cpp -o CMakeFiles\TS-PARSER.dir\tsTransportStream.cpp.s

CMakeFiles/TS-PARSER.dir/TS_parser.cpp.obj: CMakeFiles/TS-PARSER.dir/flags.make
CMakeFiles/TS-PARSER.dir/TS_parser.cpp.obj: C:/Users/filip/OneDrive/Pulpit/6sem/pdm/TS_parser_S0/TS_parser.cpp
CMakeFiles/TS-PARSER.dir/TS_parser.cpp.obj: CMakeFiles/TS-PARSER.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\filip\OneDrive\Pulpit\6sem\pdm\TS_parser_S0\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TS-PARSER.dir/TS_parser.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TS-PARSER.dir/TS_parser.cpp.obj -MF CMakeFiles\TS-PARSER.dir\TS_parser.cpp.obj.d -o CMakeFiles\TS-PARSER.dir\TS_parser.cpp.obj -c C:\Users\filip\OneDrive\Pulpit\6sem\pdm\TS_parser_S0\TS_parser.cpp

CMakeFiles/TS-PARSER.dir/TS_parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TS-PARSER.dir/TS_parser.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\filip\OneDrive\Pulpit\6sem\pdm\TS_parser_S0\TS_parser.cpp > CMakeFiles\TS-PARSER.dir\TS_parser.cpp.i

CMakeFiles/TS-PARSER.dir/TS_parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TS-PARSER.dir/TS_parser.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\filip\OneDrive\Pulpit\6sem\pdm\TS_parser_S0\TS_parser.cpp -o CMakeFiles\TS-PARSER.dir\TS_parser.cpp.s

# Object files for target TS-PARSER
TS__PARSER_OBJECTS = \
"CMakeFiles/TS-PARSER.dir/tsTransportStream.cpp.obj" \
"CMakeFiles/TS-PARSER.dir/TS_parser.cpp.obj"

# External object files for target TS-PARSER
TS__PARSER_EXTERNAL_OBJECTS =

TS-PARSER.exe: CMakeFiles/TS-PARSER.dir/tsTransportStream.cpp.obj
TS-PARSER.exe: CMakeFiles/TS-PARSER.dir/TS_parser.cpp.obj
TS-PARSER.exe: CMakeFiles/TS-PARSER.dir/build.make
TS-PARSER.exe: CMakeFiles/TS-PARSER.dir/linkLibs.rsp
TS-PARSER.exe: CMakeFiles/TS-PARSER.dir/objects1.rsp
TS-PARSER.exe: CMakeFiles/TS-PARSER.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\filip\OneDrive\Pulpit\6sem\pdm\TS_parser_S0\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable TS-PARSER.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\TS-PARSER.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TS-PARSER.dir/build: TS-PARSER.exe
.PHONY : CMakeFiles/TS-PARSER.dir/build

CMakeFiles/TS-PARSER.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\TS-PARSER.dir\cmake_clean.cmake
.PHONY : CMakeFiles/TS-PARSER.dir/clean

CMakeFiles/TS-PARSER.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\filip\OneDrive\Pulpit\6sem\pdm\TS_parser_S0 C:\Users\filip\OneDrive\Pulpit\6sem\pdm\TS_parser_S0 C:\Users\filip\OneDrive\Pulpit\6sem\pdm\TS_parser_S0\build C:\Users\filip\OneDrive\Pulpit\6sem\pdm\TS_parser_S0\build C:\Users\filip\OneDrive\Pulpit\6sem\pdm\TS_parser_S0\build\CMakeFiles\TS-PARSER.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/TS-PARSER.dir/depend

