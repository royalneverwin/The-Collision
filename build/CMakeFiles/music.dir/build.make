# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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
CMAKE_SOURCE_DIR = C:\Users\szp\Desktop\code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\szp\Desktop\code\build

# Include any dependencies generated for this target.
include CMakeFiles/music.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/music.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/music.dir/flags.make

CMakeFiles/music.dir/src/main.cpp.obj: CMakeFiles/music.dir/flags.make
CMakeFiles/music.dir/src/main.cpp.obj: CMakeFiles/music.dir/includes_CXX.rsp
CMakeFiles/music.dir/src/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\szp\Desktop\code\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/music.dir/src/main.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\music.dir\src\main.cpp.obj -c C:\Users\szp\Desktop\code\src\main.cpp

CMakeFiles/music.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/music.dir/src/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\szp\Desktop\code\src\main.cpp > CMakeFiles\music.dir\src\main.cpp.i

CMakeFiles/music.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/music.dir/src/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\szp\Desktop\code\src\main.cpp -o CMakeFiles\music.dir\src\main.cpp.s

CMakeFiles/music.dir/src/page/page.cpp.obj: CMakeFiles/music.dir/flags.make
CMakeFiles/music.dir/src/page/page.cpp.obj: CMakeFiles/music.dir/includes_CXX.rsp
CMakeFiles/music.dir/src/page/page.cpp.obj: ../src/page/page.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\szp\Desktop\code\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/music.dir/src/page/page.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\music.dir\src\page\page.cpp.obj -c C:\Users\szp\Desktop\code\src\page\page.cpp

CMakeFiles/music.dir/src/page/page.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/music.dir/src/page/page.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\szp\Desktop\code\src\page\page.cpp > CMakeFiles\music.dir\src\page\page.cpp.i

CMakeFiles/music.dir/src/page/page.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/music.dir/src/page/page.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\szp\Desktop\code\src\page\page.cpp -o CMakeFiles\music.dir\src\page\page.cpp.s

CMakeFiles/music.dir/src/object/object.cpp.obj: CMakeFiles/music.dir/flags.make
CMakeFiles/music.dir/src/object/object.cpp.obj: CMakeFiles/music.dir/includes_CXX.rsp
CMakeFiles/music.dir/src/object/object.cpp.obj: ../src/object/object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\szp\Desktop\code\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/music.dir/src/object/object.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\music.dir\src\object\object.cpp.obj -c C:\Users\szp\Desktop\code\src\object\object.cpp

CMakeFiles/music.dir/src/object/object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/music.dir/src/object/object.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\szp\Desktop\code\src\object\object.cpp > CMakeFiles\music.dir\src\object\object.cpp.i

CMakeFiles/music.dir/src/object/object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/music.dir/src/object/object.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\szp\Desktop\code\src\object\object.cpp -o CMakeFiles\music.dir\src\object\object.cpp.s

# Object files for target music
music_OBJECTS = \
"CMakeFiles/music.dir/src/main.cpp.obj" \
"CMakeFiles/music.dir/src/page/page.cpp.obj" \
"CMakeFiles/music.dir/src/object/object.cpp.obj"

# External object files for target music
music_EXTERNAL_OBJECTS =

music.exe: CMakeFiles/music.dir/src/main.cpp.obj
music.exe: CMakeFiles/music.dir/src/page/page.cpp.obj
music.exe: CMakeFiles/music.dir/src/object/object.cpp.obj
music.exe: CMakeFiles/music.dir/build.make
music.exe: ../lib/libraylib.dll.a
music.exe: CMakeFiles/music.dir/linklibs.rsp
music.exe: CMakeFiles/music.dir/objects1.rsp
music.exe: CMakeFiles/music.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\szp\Desktop\code\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable music.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\music.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/music.dir/build: music.exe

.PHONY : CMakeFiles/music.dir/build

CMakeFiles/music.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\music.dir\cmake_clean.cmake
.PHONY : CMakeFiles/music.dir/clean

CMakeFiles/music.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\szp\Desktop\code C:\Users\szp\Desktop\code C:\Users\szp\Desktop\code\build C:\Users\szp\Desktop\code\build C:\Users\szp\Desktop\code\build\CMakeFiles\music.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/music.dir/depend

