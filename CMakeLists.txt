cmake_minimum_required(VERSION 3.6)
project(Compiler)

set(CMAKE_CXX_STANDARD 11)

#add_subdirectory(AST)

set(SOURCE_FILES main.cpp ConsoleCtrl.h ConsoleCtrl.cpp Error.h Error.cpp
        Lexer.h Lexer.cpp Node.h Node.cpp Parser.h Parser.cpp Symbol.h Symbol.cpp
        Token.h Token.cpp AST/AST.h AST/AST.cpp AST/ExpressionType.h AST/ExpressionType.cpp AST/Visitor.h)

include_directories(${Boost_INCLUDE_DIR})

add_executable(Compiler ${SOURCE_FILES})
