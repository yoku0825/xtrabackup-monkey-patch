# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup

# Include any dependencies generated for this target.
include extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/depend.make

# Include the progress variables for this target.
include extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/progress.make

# Include the compile flags for this target's objects.
include extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/flags.make

extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/kmip_bio.c.o: extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/flags.make
extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/kmip_bio.c.o: extra/libkmip/libkmip/src/kmip_bio.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/kmip_bio.c.o"
	cd /mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/extra/libkmip/libkmip/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/kmip.dir/kmip_bio.c.o   -c /mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/extra/libkmip/libkmip/src/kmip_bio.c

extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/kmip_bio.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kmip.dir/kmip_bio.c.i"
	cd /mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/extra/libkmip/libkmip/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/extra/libkmip/libkmip/src/kmip_bio.c > CMakeFiles/kmip.dir/kmip_bio.c.i

extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/kmip_bio.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kmip.dir/kmip_bio.c.s"
	cd /mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/extra/libkmip/libkmip/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/extra/libkmip/libkmip/src/kmip_bio.c -o CMakeFiles/kmip.dir/kmip_bio.c.s

extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/kmip.c.o: extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/flags.make
extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/kmip.c.o: extra/libkmip/libkmip/src/kmip.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/kmip.c.o"
	cd /mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/extra/libkmip/libkmip/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/kmip.dir/kmip.c.o   -c /mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/extra/libkmip/libkmip/src/kmip.c

extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/kmip.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kmip.dir/kmip.c.i"
	cd /mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/extra/libkmip/libkmip/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/extra/libkmip/libkmip/src/kmip.c > CMakeFiles/kmip.dir/kmip.c.i

extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/kmip.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kmip.dir/kmip.c.s"
	cd /mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/extra/libkmip/libkmip/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/extra/libkmip/libkmip/src/kmip.c -o CMakeFiles/kmip.dir/kmip.c.s

extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/kmip_locate.c.o: extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/flags.make
extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/kmip_locate.c.o: extra/libkmip/libkmip/src/kmip_locate.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/kmip_locate.c.o"
	cd /mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/extra/libkmip/libkmip/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/kmip.dir/kmip_locate.c.o   -c /mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/extra/libkmip/libkmip/src/kmip_locate.c

extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/kmip_locate.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kmip.dir/kmip_locate.c.i"
	cd /mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/extra/libkmip/libkmip/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/extra/libkmip/libkmip/src/kmip_locate.c > CMakeFiles/kmip.dir/kmip_locate.c.i

extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/kmip_locate.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kmip.dir/kmip_locate.c.s"
	cd /mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/extra/libkmip/libkmip/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/extra/libkmip/libkmip/src/kmip_locate.c -o CMakeFiles/kmip.dir/kmip_locate.c.s

extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/kmip_memset.c.o: extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/flags.make
extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/kmip_memset.c.o: extra/libkmip/libkmip/src/kmip_memset.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/kmip_memset.c.o"
	cd /mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/extra/libkmip/libkmip/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/kmip.dir/kmip_memset.c.o   -c /mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/extra/libkmip/libkmip/src/kmip_memset.c

extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/kmip_memset.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kmip.dir/kmip_memset.c.i"
	cd /mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/extra/libkmip/libkmip/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/extra/libkmip/libkmip/src/kmip_memset.c > CMakeFiles/kmip.dir/kmip_memset.c.i

extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/kmip_memset.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kmip.dir/kmip_memset.c.s"
	cd /mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/extra/libkmip/libkmip/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/extra/libkmip/libkmip/src/kmip_memset.c -o CMakeFiles/kmip.dir/kmip_memset.c.s

# Object files for target kmip
kmip_OBJECTS = \
"CMakeFiles/kmip.dir/kmip_bio.c.o" \
"CMakeFiles/kmip.dir/kmip.c.o" \
"CMakeFiles/kmip.dir/kmip_locate.c.o" \
"CMakeFiles/kmip.dir/kmip_memset.c.o"

# External object files for target kmip
kmip_EXTERNAL_OBJECTS =

extra/libkmip/libkmip/src/libkmip.a: extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/kmip_bio.c.o
extra/libkmip/libkmip/src/libkmip.a: extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/kmip.c.o
extra/libkmip/libkmip/src/libkmip.a: extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/kmip_locate.c.o
extra/libkmip/libkmip/src/libkmip.a: extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/kmip_memset.c.o
extra/libkmip/libkmip/src/libkmip.a: extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/build.make
extra/libkmip/libkmip/src/libkmip.a: extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C static library libkmip.a"
	cd /mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/extra/libkmip/libkmip/src && $(CMAKE_COMMAND) -P CMakeFiles/kmip.dir/cmake_clean_target.cmake
	cd /mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/extra/libkmip/libkmip/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/kmip.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/build: extra/libkmip/libkmip/src/libkmip.a

.PHONY : extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/build

extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/clean:
	cd /mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/extra/libkmip/libkmip/src && $(CMAKE_COMMAND) -P CMakeFiles/kmip.dir/cmake_clean.cmake
.PHONY : extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/clean

extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/depend:
	cd /mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup /mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/extra/libkmip/libkmip/src /mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup /mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/extra/libkmip/libkmip/src /mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : extra/libkmip/libkmip/src/CMakeFiles/kmip.dir/depend

