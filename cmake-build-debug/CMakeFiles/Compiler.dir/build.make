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


CMakeFiles/Compiler.dir/Node.cpp.o: CMakeFiles/Compiler.dir/flags.make
CMakeFiles/Compiler.dir/Node.cpp.o: ../Node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ivankalagin/Documents/GitHub/compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Compiler.dir/Node.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Compiler.dir/Node.cpp.o -c /Users/ivankalagin/Documents/GitHub/compiler/Node.cpp

CMakeFiles/Compiler.dir/Node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Compiler.dir/Node.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivankalagin/Documents/GitHub/compiler/Node.cpp > CMakeFiles/Compiler.dir/Node.cpp.i

CMakeFiles/Compiler.dir/Node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Compiler.dir/Node.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivankalagin/Documents/GitHub/compiler/Node.cpp -o CMakeFiles/Compiler.dir/Node.cpp.s

CMakeFiles/Compiler.dir/Node.cpp.o.requires:

.PHONY : CMakeFiles/Compiler.dir/Node.cpp.o.requires

CMakeFiles/Compiler.dir/Node.cpp.o.provides: CMakeFiles/Compiler.dir/Node.cpp.o.requires
	$(MAKE) -f CMakeFiles/Compiler.dir/build.make CMakeFiles/Compiler.dir/Node.cpp.o.provides.build
.PHONY : CMakeFiles/Compiler.dir/Node.cpp.o.provides

CMakeFiles/Compiler.dir/Node.cpp.o.provides.build: CMakeFiles/Compiler.dir/Node.cpp.o


CMakeFiles/Compiler.dir/Parser.cpp.o: CMakeFiles/Compiler.dir/flags.make
CMakeFiles/Compiler.dir/Parser.cpp.o: ../Parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ivankalagin/Documents/GitHub/compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Compiler.dir/Parser.cpp.o"
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
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ivankalagin/Documents/GitHub/compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Compiler.dir/Symbol.cpp.o"
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
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ivankalagin/Documents/GitHub/compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Compiler.dir/Token.cpp.o"
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
"CMakeFiles/Compiler.dir/Node.cpp.o" \
"CMakeFiles/Compiler.dir/Parser.cpp.o" \
"CMakeFiles/Compiler.dir/Symbol.cpp.o" \
"CMakeFiles/Compiler.dir/Token.cpp.o"

# External object files for target Compiler
Compiler_EXTERNAL_OBJECTS =

Compiler: CMakeFiles/Compiler.dir/main.cpp.o
Compiler: CMakeFiles/Compiler.dir/ConsoleCtrl.cpp.o
Compiler: CMakeFiles/Compiler.dir/Error.cpp.o
Compiler: CMakeFiles/Compiler.dir/Lexer.cpp.o
Compiler: CMakeFiles/Compiler.dir/Node.cpp.o
Compiler: CMakeFiles/Compiler.dir/Parser.cpp.o
Compiler: CMakeFiles/Compiler.dir/Symbol.cpp.o
Compiler: CMakeFiles/Compiler.dir/Token.cpp.o
Compiler: CMakeFiles/Compiler.dir/build.make
Compiler: AST/libAST.a
Compiler: codegen/libCodegen.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMLTO.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMPasses.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMObjCARCOpts.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMSymbolize.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMDebugInfoPDB.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMDebugInfoDWARF.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMMIRParser.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMFuzzMutate.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMCoverage.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMTableGen.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMDlltoolDriver.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMOrcJIT.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMXCoreDisassembler.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMXCoreCodeGen.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMXCoreDesc.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMXCoreInfo.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMXCoreAsmPrinter.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMSystemZDisassembler.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMSystemZCodeGen.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMSystemZAsmParser.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMSystemZDesc.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMSystemZInfo.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMSystemZAsmPrinter.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMSparcDisassembler.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMSparcCodeGen.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMSparcAsmParser.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMSparcDesc.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMSparcInfo.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMSparcAsmPrinter.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMPowerPCDisassembler.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMPowerPCCodeGen.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMPowerPCAsmParser.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMPowerPCDesc.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMPowerPCInfo.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMPowerPCAsmPrinter.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMNVPTXCodeGen.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMNVPTXDesc.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMNVPTXInfo.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMNVPTXAsmPrinter.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMMSP430CodeGen.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMMSP430Desc.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMMSP430Info.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMMSP430AsmPrinter.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMMipsDisassembler.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMMipsCodeGen.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMMipsAsmParser.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMMipsDesc.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMMipsInfo.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMMipsAsmPrinter.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMLanaiDisassembler.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMLanaiCodeGen.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMLanaiAsmParser.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMLanaiDesc.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMLanaiAsmPrinter.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMLanaiInfo.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMHexagonDisassembler.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMHexagonCodeGen.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMHexagonAsmParser.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMHexagonDesc.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMHexagonInfo.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMBPFDisassembler.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMBPFCodeGen.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMBPFAsmParser.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMBPFDesc.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMBPFInfo.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMBPFAsmPrinter.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMARMDisassembler.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMARMCodeGen.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMARMAsmParser.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMARMDesc.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMARMInfo.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMARMAsmPrinter.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMARMUtils.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMAMDGPUDisassembler.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMAMDGPUCodeGen.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMAMDGPUAsmParser.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMAMDGPUDesc.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMAMDGPUInfo.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMAMDGPUAsmPrinter.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMAMDGPUUtils.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMAArch64Disassembler.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMAArch64CodeGen.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMAArch64AsmParser.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMAArch64Desc.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMAArch64Info.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMAArch64AsmPrinter.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMAArch64Utils.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMObjectYAML.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMLibDriver.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMOption.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMWindowsManifest.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMX86Disassembler.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMX86AsmParser.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMX86CodeGen.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMGlobalISel.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMSelectionDAG.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMAsmPrinter.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMX86Desc.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMMCDisassembler.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMX86Info.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMX86AsmPrinter.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMX86Utils.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMMCJIT.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMLineEditor.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMInterpreter.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMExecutionEngine.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMRuntimeDyld.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMCodeGen.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMTarget.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMCoroutines.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMipo.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMInstrumentation.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMVectorize.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMScalarOpts.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMLinker.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMIRReader.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMAsmParser.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMInstCombine.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMBitWriter.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMAggressiveInstCombine.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMTransformUtils.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMAnalysis.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMProfileData.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMObject.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMMCParser.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMMC.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMDebugInfoCodeView.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMDebugInfoMSF.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMBitReader.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMCore.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMBinaryFormat.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMSupport.a
Compiler: /usr/local/Cellar/llvm/7.0.0_1/lib/libLLVMDemangle.a
Compiler: AST/libAST.a
Compiler: /usr/local/opt/libffi/lib/libffi.dylib
Compiler: CMakeFiles/Compiler.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ivankalagin/Documents/GitHub/compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable Compiler"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Compiler.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Compiler.dir/build: Compiler

.PHONY : CMakeFiles/Compiler.dir/build

CMakeFiles/Compiler.dir/requires: CMakeFiles/Compiler.dir/main.cpp.o.requires
CMakeFiles/Compiler.dir/requires: CMakeFiles/Compiler.dir/ConsoleCtrl.cpp.o.requires
CMakeFiles/Compiler.dir/requires: CMakeFiles/Compiler.dir/Error.cpp.o.requires
CMakeFiles/Compiler.dir/requires: CMakeFiles/Compiler.dir/Lexer.cpp.o.requires
CMakeFiles/Compiler.dir/requires: CMakeFiles/Compiler.dir/Node.cpp.o.requires
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

