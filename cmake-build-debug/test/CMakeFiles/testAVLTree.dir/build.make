# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CLion 2017.2.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CLion 2017.2.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Laptop\CLionProjects\blatt-7-aufgabe-1-team

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Laptop\CLionProjects\blatt-7-aufgabe-1-team\cmake-build-debug

# Include any dependencies generated for this target.
include test/CMakeFiles/testAVLTree.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/testAVLTree.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/testAVLTree.dir/flags.make

test/CMakeFiles/testAVLTree.dir/main.cpp.obj: test/CMakeFiles/testAVLTree.dir/flags.make
test/CMakeFiles/testAVLTree.dir/main.cpp.obj: test/CMakeFiles/testAVLTree.dir/includes_CXX.rsp
test/CMakeFiles/testAVLTree.dir/main.cpp.obj: ../test/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Laptop\CLionProjects\blatt-7-aufgabe-1-team\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/testAVLTree.dir/main.cpp.obj"
	cd /d C:\Users\Laptop\CLionProjects\blatt-7-aufgabe-1-team\cmake-build-debug\test && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\testAVLTree.dir\main.cpp.obj -c C:\Users\Laptop\CLionProjects\blatt-7-aufgabe-1-team\test\main.cpp

test/CMakeFiles/testAVLTree.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testAVLTree.dir/main.cpp.i"
	cd /d C:\Users\Laptop\CLionProjects\blatt-7-aufgabe-1-team\cmake-build-debug\test && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Laptop\CLionProjects\blatt-7-aufgabe-1-team\test\main.cpp > CMakeFiles\testAVLTree.dir\main.cpp.i

test/CMakeFiles/testAVLTree.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testAVLTree.dir/main.cpp.s"
	cd /d C:\Users\Laptop\CLionProjects\blatt-7-aufgabe-1-team\cmake-build-debug\test && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Laptop\CLionProjects\blatt-7-aufgabe-1-team\test\main.cpp -o CMakeFiles\testAVLTree.dir\main.cpp.s

test/CMakeFiles/testAVLTree.dir/main.cpp.obj.requires:

.PHONY : test/CMakeFiles/testAVLTree.dir/main.cpp.obj.requires

test/CMakeFiles/testAVLTree.dir/main.cpp.obj.provides: test/CMakeFiles/testAVLTree.dir/main.cpp.obj.requires
	$(MAKE) -f test\CMakeFiles\testAVLTree.dir\build.make test/CMakeFiles/testAVLTree.dir/main.cpp.obj.provides.build
.PHONY : test/CMakeFiles/testAVLTree.dir/main.cpp.obj.provides

test/CMakeFiles/testAVLTree.dir/main.cpp.obj.provides.build: test/CMakeFiles/testAVLTree.dir/main.cpp.obj


test/CMakeFiles/testAVLTree.dir/testAVLTree.cpp.obj: test/CMakeFiles/testAVLTree.dir/flags.make
test/CMakeFiles/testAVLTree.dir/testAVLTree.cpp.obj: test/CMakeFiles/testAVLTree.dir/includes_CXX.rsp
test/CMakeFiles/testAVLTree.dir/testAVLTree.cpp.obj: ../test/testAVLTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Laptop\CLionProjects\blatt-7-aufgabe-1-team\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/testAVLTree.dir/testAVLTree.cpp.obj"
	cd /d C:\Users\Laptop\CLionProjects\blatt-7-aufgabe-1-team\cmake-build-debug\test && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\testAVLTree.dir\testAVLTree.cpp.obj -c C:\Users\Laptop\CLionProjects\blatt-7-aufgabe-1-team\test\testAVLTree.cpp

test/CMakeFiles/testAVLTree.dir/testAVLTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testAVLTree.dir/testAVLTree.cpp.i"
	cd /d C:\Users\Laptop\CLionProjects\blatt-7-aufgabe-1-team\cmake-build-debug\test && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Laptop\CLionProjects\blatt-7-aufgabe-1-team\test\testAVLTree.cpp > CMakeFiles\testAVLTree.dir\testAVLTree.cpp.i

test/CMakeFiles/testAVLTree.dir/testAVLTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testAVLTree.dir/testAVLTree.cpp.s"
	cd /d C:\Users\Laptop\CLionProjects\blatt-7-aufgabe-1-team\cmake-build-debug\test && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Laptop\CLionProjects\blatt-7-aufgabe-1-team\test\testAVLTree.cpp -o CMakeFiles\testAVLTree.dir\testAVLTree.cpp.s

test/CMakeFiles/testAVLTree.dir/testAVLTree.cpp.obj.requires:

.PHONY : test/CMakeFiles/testAVLTree.dir/testAVLTree.cpp.obj.requires

test/CMakeFiles/testAVLTree.dir/testAVLTree.cpp.obj.provides: test/CMakeFiles/testAVLTree.dir/testAVLTree.cpp.obj.requires
	$(MAKE) -f test\CMakeFiles\testAVLTree.dir\build.make test/CMakeFiles/testAVLTree.dir/testAVLTree.cpp.obj.provides.build
.PHONY : test/CMakeFiles/testAVLTree.dir/testAVLTree.cpp.obj.provides

test/CMakeFiles/testAVLTree.dir/testAVLTree.cpp.obj.provides.build: test/CMakeFiles/testAVLTree.dir/testAVLTree.cpp.obj


test/CMakeFiles/testAVLTree.dir/__/AVLTree/AVLTree.cpp.obj: test/CMakeFiles/testAVLTree.dir/flags.make
test/CMakeFiles/testAVLTree.dir/__/AVLTree/AVLTree.cpp.obj: test/CMakeFiles/testAVLTree.dir/includes_CXX.rsp
test/CMakeFiles/testAVLTree.dir/__/AVLTree/AVLTree.cpp.obj: ../AVLTree/AVLTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Laptop\CLionProjects\blatt-7-aufgabe-1-team\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object test/CMakeFiles/testAVLTree.dir/__/AVLTree/AVLTree.cpp.obj"
	cd /d C:\Users\Laptop\CLionProjects\blatt-7-aufgabe-1-team\cmake-build-debug\test && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\testAVLTree.dir\__\AVLTree\AVLTree.cpp.obj -c C:\Users\Laptop\CLionProjects\blatt-7-aufgabe-1-team\AVLTree\AVLTree.cpp

test/CMakeFiles/testAVLTree.dir/__/AVLTree/AVLTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testAVLTree.dir/__/AVLTree/AVLTree.cpp.i"
	cd /d C:\Users\Laptop\CLionProjects\blatt-7-aufgabe-1-team\cmake-build-debug\test && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Laptop\CLionProjects\blatt-7-aufgabe-1-team\AVLTree\AVLTree.cpp > CMakeFiles\testAVLTree.dir\__\AVLTree\AVLTree.cpp.i

test/CMakeFiles/testAVLTree.dir/__/AVLTree/AVLTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testAVLTree.dir/__/AVLTree/AVLTree.cpp.s"
	cd /d C:\Users\Laptop\CLionProjects\blatt-7-aufgabe-1-team\cmake-build-debug\test && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Laptop\CLionProjects\blatt-7-aufgabe-1-team\AVLTree\AVLTree.cpp -o CMakeFiles\testAVLTree.dir\__\AVLTree\AVLTree.cpp.s

test/CMakeFiles/testAVLTree.dir/__/AVLTree/AVLTree.cpp.obj.requires:

.PHONY : test/CMakeFiles/testAVLTree.dir/__/AVLTree/AVLTree.cpp.obj.requires

test/CMakeFiles/testAVLTree.dir/__/AVLTree/AVLTree.cpp.obj.provides: test/CMakeFiles/testAVLTree.dir/__/AVLTree/AVLTree.cpp.obj.requires
	$(MAKE) -f test\CMakeFiles\testAVLTree.dir\build.make test/CMakeFiles/testAVLTree.dir/__/AVLTree/AVLTree.cpp.obj.provides.build
.PHONY : test/CMakeFiles/testAVLTree.dir/__/AVLTree/AVLTree.cpp.obj.provides

test/CMakeFiles/testAVLTree.dir/__/AVLTree/AVLTree.cpp.obj.provides.build: test/CMakeFiles/testAVLTree.dir/__/AVLTree/AVLTree.cpp.obj


# Object files for target testAVLTree
testAVLTree_OBJECTS = \
"CMakeFiles/testAVLTree.dir/main.cpp.obj" \
"CMakeFiles/testAVLTree.dir/testAVLTree.cpp.obj" \
"CMakeFiles/testAVLTree.dir/__/AVLTree/AVLTree.cpp.obj"

# External object files for target testAVLTree
testAVLTree_EXTERNAL_OBJECTS =

test/testAVLTree.exe: test/CMakeFiles/testAVLTree.dir/main.cpp.obj
test/testAVLTree.exe: test/CMakeFiles/testAVLTree.dir/testAVLTree.cpp.obj
test/testAVLTree.exe: test/CMakeFiles/testAVLTree.dir/__/AVLTree/AVLTree.cpp.obj
test/testAVLTree.exe: test/CMakeFiles/testAVLTree.dir/build.make
test/testAVLTree.exe: googletest-build/googlemock/gtest/libgtestd.a
test/testAVLTree.exe: googletest-build/googlemock/libgmockd.a
test/testAVLTree.exe: test/CMakeFiles/testAVLTree.dir/linklibs.rsp
test/testAVLTree.exe: test/CMakeFiles/testAVLTree.dir/objects1.rsp
test/testAVLTree.exe: test/CMakeFiles/testAVLTree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Laptop\CLionProjects\blatt-7-aufgabe-1-team\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable testAVLTree.exe"
	cd /d C:\Users\Laptop\CLionProjects\blatt-7-aufgabe-1-team\cmake-build-debug\test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\testAVLTree.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/testAVLTree.dir/build: test/testAVLTree.exe

.PHONY : test/CMakeFiles/testAVLTree.dir/build

test/CMakeFiles/testAVLTree.dir/requires: test/CMakeFiles/testAVLTree.dir/main.cpp.obj.requires
test/CMakeFiles/testAVLTree.dir/requires: test/CMakeFiles/testAVLTree.dir/testAVLTree.cpp.obj.requires
test/CMakeFiles/testAVLTree.dir/requires: test/CMakeFiles/testAVLTree.dir/__/AVLTree/AVLTree.cpp.obj.requires

.PHONY : test/CMakeFiles/testAVLTree.dir/requires

test/CMakeFiles/testAVLTree.dir/clean:
	cd /d C:\Users\Laptop\CLionProjects\blatt-7-aufgabe-1-team\cmake-build-debug\test && $(CMAKE_COMMAND) -P CMakeFiles\testAVLTree.dir\cmake_clean.cmake
.PHONY : test/CMakeFiles/testAVLTree.dir/clean

test/CMakeFiles/testAVLTree.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Laptop\CLionProjects\blatt-7-aufgabe-1-team C:\Users\Laptop\CLionProjects\blatt-7-aufgabe-1-team\test C:\Users\Laptop\CLionProjects\blatt-7-aufgabe-1-team\cmake-build-debug C:\Users\Laptop\CLionProjects\blatt-7-aufgabe-1-team\cmake-build-debug\test C:\Users\Laptop\CLionProjects\blatt-7-aufgabe-1-team\cmake-build-debug\test\CMakeFiles\testAVLTree.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/testAVLTree.dir/depend

