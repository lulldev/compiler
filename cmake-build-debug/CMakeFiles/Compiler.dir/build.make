# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /Applications/CLion2017.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion2017.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ivankalagin/Documents/GitHub/compiler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ivankalagin/Documents/GitHub/compiler/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Compiler.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Compiler.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Compiler.dir/flags.make

CMakeFiles/Compiler.dir/main.cpp.o: CMakeFiles/Compiler.dir/flags.make
CMakeFiles/Compiler.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ivankalagin/Documents/GitHub/compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Compiler.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Compiler.dir/main.cpp.o -c /Users/ivankalagin/Documents/GitHub/compiler/main.cpp

CMakeFiles/Compiler.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Compiler.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivankalagin/Documents/GitHub/compiler/main.cpp > CMakeFiles/Compiler.dir/main.cpp.i

CMakeFiles/Compiler.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Compiler.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivankalagin/Documents/GitHub/compiler/main.cpp -o CMakeFiles/Compiler.dir/main.cpp.s

CMakeFiles/Compiler.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Compiler.dir/main.cpp.o.requires

CMakeFiles/Compiler.dir/main.cpp.o.provides: CMakeFiles/Compiler.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Compiler.dir/build.make CMakeFiles/Compiler.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Compiler.dir/main.cpp.o.provides

CMakeFiles/Compiler.dir/main.cpp.o.provides.build: CMakeFiles/Compiler.dir/main.cpp.o


CMakeFiles/Compiler.dir/ConsoleCtrl.cpp.o: CMakeFiles/Compiler.dir/flags.make
CMakeFiles/Compiler.dir/ConsoleCtrl.cpp.o: ../ConsoleCtrl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ivankalagin/Documents/GitHub/compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Compiler.dir/ConsoleCtrl.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Compiler.dir/ConsoleCtrl.cpp.o -c /Users/ivankalagin/Documents/GitHub/compiler/ConsoleCtrl.cpp

CMakeFiles/Compiler.dir/ConsoleCtrl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Compiler.dir/ConsoleCtrl.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivankalagin/Documents/GitHub/compiler/ConsoleCtrl.cpp > CMakeFiles/Compiler.dir/ConsoleCtrl.cpp.i

CMakeFiles/Compiler.dir/ConsoleCtrl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Compiler.dir/ConsoleCtrl.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivankalagin/Documents/GitHub/compiler/ConsoleCtrl.cpp -o CMakeFiles/Compiler.dir/ConsoleCtrl.cpp.s

CMakeFiles/Compiler.dir/ConsoleCtrl.cpp.o.requires:

.PHONY : CMakeFiles/Compiler.dir/ConsoleCtrl.cpp.o.requires

CMakeFiles/Compiler.dir/ConsoleCtrl.cpp.o.provides: CMakeFiles/Compiler.dir/ConsoleCtrl.cpp.o.requires
	$(MAKE) -f CMakeFiles/Compiler.dir/build.make CMakeFiles/Compiler.dir/ConsoleCtrl.cpp.o.provides.build
.PHONY : CMakeFiles/Compiler.dir/ConsoleCtrl.cpp.o.provides

CMakeFiles/Compiler.dir/ConsoleCtrl.cpp.o.provides.build: CMakeFiles/Compiler.dir/ConsoleCtrl.cpp.o


CMakeFiles/Compiler.dir/Error.cpp.o: CMakeFiles/Compiler.dir/flags.make
CMakeFiles/Compiler.dir/Error.cpp.o: ../Error.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ivankalagin/Documents/GitHub/compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Compiler.dir/Error.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Compiler.dir/Error.cpp.o -c /Users/ivankalagin/Documents/GitHub/compiler/Error.cpp

CMakeFiles/Compiler.dir/Error.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Compiler.dir/Error.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivankalagin/Documents/GitHub/compiler/Error.cpp > CMakeFiles/Compiler.dir/Error.cpp.i

CMakeFiles/Compiler.dir/Error.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Compiler.dir/Error.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivankalagin/Documents/GitHub/compiler/Error.cpp -o CMakeFiles/Compiler.dir/Error.cpp.s

CMakeFiles/Compiler.dir/Error.cpp.o.requires:

.PHONY : CMakeFiles/Compiler.dir/Error.cpp.o.requires

CMakeFiles/Compiler.dir/Error.cpp.o.provides: CMakeFiles/Compiler.dir/Error.cpp.o.requires
	$(MAKE) -f CMakeFiles/Compiler.dir/build.make CMakeFiles/Compiler.dir/Error.cpp.o.provides.build
.PHONY : CMakeFiles/Compiler.dir/Error.cpp.o.provides

CMakeFiles/Compiler.dir/Error.cpp.o.provides.build: CMakeFiles/Compiler.dir/Error.cpp.o


CMakeFiles/Compiler.dir/Lexer.cpp.o: CMakeFiles/Compiler.dir/flags.make
CMakeFiles/Compiler.dir/Lexer.cpp.o: ../Lexer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ivankalagin/Documents/GitHub/compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Compiler.dir/Lexer.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Compiler.dir/Lexer.cpp.o -c /Users/ivankalagin/Documents/GitHub/compiler/Lexer.cpp

CMakeFiles/Compiler.dir/Lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Compiler.dir/Lexer.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivankalagin/Documents/GitHub/compiler/Lexer.cpp > CMakeFiles/Compiler.dir/Lexer.cpp.i

CMakeFiles/Compiler.dir/Lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Compiler.dir/Lexer.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivankalagin/Documents/GitHub/compiler/Lexer.cpp -o CMakeFiles/Compiler.dir/Lexer.cpp.s

CMakeFiles/Compiler.dir/Lexer.cpp.o.requires:

.PHONY : CMakeFiles/Compiler.dir/Lexer.cpp.o.requires

CMakeFiles/Compiler.dir/Lexer.cpp.o.provides: CMakeFiles/Compiler.dir/Lexer.cpp.o.requires
	$(MAKE) -f CMakeFiles/Compiler.dir/build.make CMakeFiles/Compiler.dir/Lexer.cpp.o.provides.build
.PHONY : CMakeFiles/Compiler.dir/Lexer.cpp.o.provides

CMakeFiles/Compiler.dir/Lexer.cpp.o.provides.build: CMakeFiles/Compiler.dir/Lexer.cpp.o


CMakeFiles/Compiler.dir/Parser.cpp.o: CMakeFiles/Compiler.dir/flags.make
CMakeFiles/Compiler.dir/Parser.cpp.o: ../Parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ivankalagin/Documents/GitHub/compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Compiler.dir/Parser.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Compiler.dir/Parser.cpp.o -c /Users/ivankalagin/Documents/GitHub/compiler/Parser.cpp

CMakeFiles/Compiler.dir/Parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Compiler.dir/Parser.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivankalagin/Documents/GitHub/compiler/Parser.cpp > CMakeFiles/Compiler.dir/Parser.cpp.i

CMakeFiles/Compiler.dir/Parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Compiler.dir/Parser.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivankalagin/Documents/GitHub/compiler/Parser.cpp -o CMakeFiles/Compiler.dir/Parser.cpp.s

CMakeFiles/Compiler.dir/Parser.cpp.o.requires:

.PHONY : CMakeFiles/Compiler.dir/Parser.cpp.o.requires

CMakeFiles/Compiler.dir/Parser.cpp.o.provides: CMakeFiles/Compiler.dir/Parser.cpp.o.requires
	$(MAKE) -f CMakeFiles/Compiler.dir/build.make CMakeFiles/Compiler.dir/Parser.cpp.o.provides.build
.PHONY : CMakeFiles/Compiler.dir/Parser.cpp.o.provides

CMakeFiles/Compiler.dir/Parser.cpp.o.provides.build: CMakeFiles/Compiler.dir/Parser.cpp.o


CMakeFiles/Compiler.dir/Symbol.cpp.o: CMakeFiles/Compiler.dir/flags.make
CMakeFiles/Compiler.dir/Symbol.cpp.o: ../Symbol.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ivankalagin/Documents/GitHub/compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Compiler.dir/Symbol.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Compiler.dir/Symbol.cpp.o -c /Users/ivankalagin/Documents/GitHub/compiler/Symbol.cpp

CMakeFiles/Compiler.dir/Symbol.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Compiler.dir/Symbol.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivankalagin/Documents/GitHub/compiler/Symbol.cpp > CMakeFiles/Compiler.dir/Symbol.cpp.i

CMakeFiles/Compiler.dir/Symbol.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Compiler.dir/Symbol.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivankalagin/Documents/GitHub/compiler/Symbol.cpp -o CMakeFiles/Compiler.dir/Symbol.cpp.s

CMakeFiles/Compiler.dir/Symbol.cpp.o.requires:

.PHONY : CMakeFiles/Compiler.dir/Symbol.cpp.o.requires

CMakeFiles/Compiler.dir/Symbol.cpp.o.provides: CMakeFiles/Compiler.dir/Symbol.cpp.o.requires
	$(MAKE) -f CMakeFiles/Compiler.dir/build.make CMakeFiles/Compiler.dir/Symbol.cpp.o.provides.build
.PHONY : CMakeFiles/Compiler.dir/Symbol.cpp.o.provides

CMakeFiles/Compiler.dir/Symbol.cpp.o.provides.build: CMakeFiles/Compiler.dir/Symbol.cpp.o


CMakeFiles/Compiler.dir/Token.cpp.o: CMakeFiles/Compiler.dir/flags.make
CMakeFiles/Compiler.dir/Token.cpp.o: ../Token.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ivankalagin/Documents/GitHub/compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Compiler.dir/Token.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Compiler.dir/Token.cpp.o -c /Users/ivankalagin/Documents/GitHub/compiler/Token.cpp

CMakeFiles/Compiler.dir/Token.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Compiler.dir/Token.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivankalagin/Documents/GitHub/compiler/Token.cpp > CMakeFiles/Compiler.dir/Token.cpp.i

CMakeFiles/Compiler.dir/Token.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Compiler.dir/Token.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivankalagin/Documents/GitHub/compiler/Token.cpp -o CMakeFiles/Compiler.dir/Token.cpp.s

CMakeFiles/Compiler.dir/Token.cpp.o.requires:

.PHONY : CMakeFiles/Compiler.dir/Token.cpp.o.requires

CMakeFiles/Compiler.dir/Token.cpp.o.provides: CMakeFiles/Compiler.dir/Token.cpp.o.requires
	$(MAKE) -f CMakeFiles/Compiler.dir/build.make CMakeFiles/Compiler.dir/Token.cpp.o.provides.build
.PHONY : CMakeFiles/Compiler.dir/Token.cpp.o.provides

CMakeFiles/Compiler.dir/Token.cpp.o.provides.build: CMakeFiles/Compiler.dir/Token.cpp.o


# Object files for target Compiler
Compiler_OBJECTS = \
"CMakeFiles/Compiler.dir/main.cpp.o" \
"CMakeFiles/Compiler.dir/ConsoleCtrl.cpp.o" \
"CMakeFiles/Compiler.dir/Error.cpp.o" \
"CMakeFiles/Compiler.dir/Lexer.cpp.o" \
"CMakeFiles/Compiler.dir/Parser.cpp.o" \
"CMakeFiles/Compiler.dir/Symbol.cpp.o" \
"CMakeFiles/Compiler.dir/Token.cpp.o"

# External object files for target Compiler
Compiler_EXTERNAL_OBJECTS =

Compiler: CMakeFiles/Compiler.dir/main.cpp.o
Compiler: CMakeFiles/Compiler.dir/ConsoleCtrl.cpp.o
Compiler: CMakeFiles/Compiler.dir/Error.cpp.o
Compiler: CMakeFiles/Compiler.dir/Lexer.cpp.o
Compiler: CMakeFiles/Compiler.dir/Parser.cpp.o
Compiler: CMakeFiles/Compiler.dir/Symbol.cpp.o
Compiler: CMakeFiles/Compiler.dir/Token.cpp.o
Compiler: CMakeFiles/Compiler.dir/build.make
Compiler: AST/libAST.a
Compiler: codegen/libCodegen.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMCore.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMIRReader.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMSupport.a
Compiler: AST/libAST.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMAsmParser.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMBitReader.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMCore.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMBinaryFormat.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMSupport.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMDemangle.a
Compiler: CMakeFiles/Compiler.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ivankalagin/Documents/GitHub/compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable Compiler"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Compiler.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Compiler.dir/build: Compiler

.PHONY : CMakeFiles/Compiler.dir/build

CMakeFiles/Compiler.dir/requires: CMakeFiles/Compiler.dir/main.cpp.o.requires
CMakeFiles/Compiler.dir/requires: CMakeFiles/Compiler.dir/ConsoleCtrl.cpp.o.requires
CMakeFiles/Compiler.dir/requires: CMakeFiles/Compiler.dir/Error.cpp.o.requires
CMakeFiles/Compiler.dir/requires: CMakeFiles/Compiler.dir/Lexer.cpp.o.requires
CMakeFiles/Compiler.dir/requires: CMakeFiles/Compiler.dir/Parser.cpp.o.requires
CMakeFiles/Compiler.dir/requires: CMakeFiles/Compiler.dir/Symbol.cpp.o.requires
CMakeFiles/Compiler.dir/requires: CMakeFiles/Compiler.dir/Token.cpp.o.requires

.PHONY : CMakeFiles/Compiler.dir/requires

CMakeFiles/Compiler.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Compiler.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Compiler.dir/clean

CMakeFiles/Compiler.dir/depend:
	cd /Users/ivankalagin/Documents/GitHub/compiler/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ivankalagin/Documents/GitHub/compiler /Users/ivankalagin/Documents/GitHub/compiler /Users/ivankalagin/Documents/GitHub/compiler/cmake-build-debug /Users/ivankalagin/Documents/GitHub/compiler/cmake-build-debug /Users/ivankalagin/Documents/GitHub/compiler/cmake-build-debug/CMakeFiles/Compiler.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Compiler.dir/depend

