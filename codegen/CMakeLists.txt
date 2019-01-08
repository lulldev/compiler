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
llvm_map_components_to_libnames(llvm_libs core irreader support)
target_link_libraries(Codegen AST ${Boost_LIBRARIES} ${llvm_libs})
