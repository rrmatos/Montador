# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rafael/trabalho1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rafael/trabalho1/build

# Include any dependencies generated for this target.
include CMakeFiles/Montador.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Montador.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Montador.dir/flags.make

CMakeFiles/Montador.dir/src/Montador.cpp.o: CMakeFiles/Montador.dir/flags.make
CMakeFiles/Montador.dir/src/Montador.cpp.o: ../src/Montador.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rafael/trabalho1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Montador.dir/src/Montador.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Montador.dir/src/Montador.cpp.o -c /home/rafael/trabalho1/src/Montador.cpp

CMakeFiles/Montador.dir/src/Montador.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Montador.dir/src/Montador.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rafael/trabalho1/src/Montador.cpp > CMakeFiles/Montador.dir/src/Montador.cpp.i

CMakeFiles/Montador.dir/src/Montador.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Montador.dir/src/Montador.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rafael/trabalho1/src/Montador.cpp -o CMakeFiles/Montador.dir/src/Montador.cpp.s

CMakeFiles/Montador.dir/src/Montador.cpp.o.requires:

.PHONY : CMakeFiles/Montador.dir/src/Montador.cpp.o.requires

CMakeFiles/Montador.dir/src/Montador.cpp.o.provides: CMakeFiles/Montador.dir/src/Montador.cpp.o.requires
	$(MAKE) -f CMakeFiles/Montador.dir/build.make CMakeFiles/Montador.dir/src/Montador.cpp.o.provides.build
.PHONY : CMakeFiles/Montador.dir/src/Montador.cpp.o.provides

CMakeFiles/Montador.dir/src/Montador.cpp.o.provides.build: CMakeFiles/Montador.dir/src/Montador.cpp.o


# Object files for target Montador
Montador_OBJECTS = \
"CMakeFiles/Montador.dir/src/Montador.cpp.o"

# External object files for target Montador
Montador_EXTERNAL_OBJECTS =

libMontador.so: CMakeFiles/Montador.dir/src/Montador.cpp.o
libMontador.so: CMakeFiles/Montador.dir/build.make
libMontador.so: CMakeFiles/Montador.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rafael/trabalho1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libMontador.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Montador.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Montador.dir/build: libMontador.so

.PHONY : CMakeFiles/Montador.dir/build

CMakeFiles/Montador.dir/requires: CMakeFiles/Montador.dir/src/Montador.cpp.o.requires

.PHONY : CMakeFiles/Montador.dir/requires

CMakeFiles/Montador.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Montador.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Montador.dir/clean

CMakeFiles/Montador.dir/depend:
	cd /home/rafael/trabalho1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rafael/trabalho1 /home/rafael/trabalho1 /home/rafael/trabalho1/build /home/rafael/trabalho1/build /home/rafael/trabalho1/build/CMakeFiles/Montador.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Montador.dir/depend

