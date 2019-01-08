cmake_minimum_required(VERSION 3.6)
project(Compiler)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp ConsoleCtrl.h ConsoleCtrl.cpp Error.h Error.cpp
        Lexer.h Lexer.cpp Parser.h Parser.cpp Symbol.h Symbol.cpp Token.h Token.cpp)

add_subdirectory(AST)
add_subdirectory(codegen)

set(LLVM_DIR /usr/local/Cellar/llvm/7.0.0_1/lib/cmake/llvm)
find_package(LLVM REQUIRED CONFIG)
if (LLVM_FOUND)
    include_directories(${LLVM_INCLUDE_DIRS})
    add_definitions(${LLVM_DEFINITIONS})
endif()

add_executable(Compiler ${SOURCE_FILES})
target_compile_options(Compiler PRIVATE -Wall -Wextra -pedantic)

llvm_map_components_to_libnames(llvm_libs core irreader support)
target_link_libraries(Compiler AST Codegen ${Boost_LIBRARIES} ${llvm_libs})
