cmake_minimum_required(VERSION 3.9)
project(Codegen)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES
        CodegenVisitor.cpp
        CodegenVisitor.h
        CodegenContext.cpp
        CodegenContext.h
        ScopeChain.h)

include_directories(../AST)
include_directories(${Boost_INCLUDE_DIR})

set(LLVM_DIR /usr/local/Cellar/llvm/7.0.0_1/lib/cmake/llvm)
find_package(LLVM REQUIRED CONFIG)
if (LLVM_FOUND)
    include_directories(${LLVM_INCLUDE_DIRS})
    add_definitions(${LLVM_DEFINITIONS})
endif()

add_library(Codegen ${SOURCE_FILES})
llvm_map_components_to_libnames(llvm_libs LTO Passes ObjCARCOpts Symbolize DebugInfoPDB DebugInfoDWARF MIRParser FuzzMutate Coverage TableGen DlltoolDriver OrcJIT XCoreDisassembler XCoreCodeGen XCoreDesc XCoreInfo XCoreAsmPrinter SystemZDisassembler SystemZCodeGen SystemZAsmParser SystemZDesc SystemZInfo SystemZAsmPrinter SparcDisassembler SparcCodeGen SparcAsmParser SparcDesc SparcInfo SparcAsmPrinter PowerPCDisassembler PowerPCCodeGen PowerPCAsmParser PowerPCDesc PowerPCInfo PowerPCAsmPrinter NVPTXCodeGen NVPTXDesc NVPTXInfo NVPTXAsmPrinter MSP430CodeGen MSP430Desc MSP430Info MSP430AsmPrinter MipsDisassembler MipsCodeGen MipsAsmParser MipsDesc MipsInfo MipsAsmPrinter LanaiDisassembler LanaiCodeGen LanaiAsmParser LanaiDesc LanaiAsmPrinter LanaiInfo HexagonDisassembler HexagonCodeGen HexagonAsmParser HexagonDesc HexagonInfo BPFDisassembler BPFCodeGen BPFAsmParser BPFDesc BPFInfo BPFAsmPrinter ARMDisassembler ARMCodeGen ARMAsmParser ARMDesc ARMInfo ARMAsmPrinter ARMUtils AMDGPUDisassembler AMDGPUCodeGen AMDGPUAsmParser AMDGPUDesc AMDGPUInfo AMDGPUAsmPrinter AMDGPUUtils AArch64Disassembler AArch64CodeGen AArch64AsmParser AArch64Desc AArch64Info AArch64AsmPrinter AArch64Utils ObjectYAML LibDriver Option WindowsManifest X86Disassembler X86AsmParser X86CodeGen GlobalISel SelectionDAG AsmPrinter X86Desc MCDisassembler X86Info X86AsmPrinter X86Utils MCJIT LineEditor Interpreter ExecutionEngine RuntimeDyld CodeGen Target Coroutines ipo Instrumentation Vectorize ScalarOpts Linker IRReader AsmParser InstCombine BitWriter AggressiveInstCombine TransformUtils Analysis ProfileData Object MCParser MC DebugInfoCodeView DebugInfoMSF BitReader Core BinaryFormat Support Demangle)
target_link_libraries(Codegen AST ${Boost_LIBRARIES} ${llvm_libs})
