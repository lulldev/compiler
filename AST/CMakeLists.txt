cmake_minimum_required(VERSION 3.6)
project(AST)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES AST.cpp AST.h ExpressionType.cpp ExpressionType.h Visitor.h)

include_directories(${Boost_INCLUDE_DIR})

add_library(AST ${SOURCE_FILES})
