cmake_minimum_required(VERSION 3.6)
project(Compiler)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp ConsoleCtrl.h ConsoleCtrl.cpp Error.h Error.cpp
        Lexer.h Lexer.cpp Node.h Node.cpp Parser.h Parser.cpp Symbol.h Symbol.cpp
        Token.h Token.cpp)

include_directories(${Boost_INCLUDE_DIR})

add_executable(Compiler ${SOURCE_FILES})
