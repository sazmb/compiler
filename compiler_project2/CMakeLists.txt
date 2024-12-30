cmake_minimum_required(VERSION 3.28)
project(compiler_project2 C)

set(CMAKE_C_STANDARD 11)

add_executable(compiler_project2 main.c
        header_files/def.h
        lexer.c
        parser.c
        header_files/parser.h
        symbolTable.c
        header_files/symbolTable.h
        tree.c
        genCode.c
        header_files/genCode.h)
