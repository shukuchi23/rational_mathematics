cmake_minimum_required(VERSION 3.17)
project(hydra)

set(CMAKE_CXX_STANDARD 14)
set(PROJECT_HEADERS
        abstr_digit.h
        irracional.h
        )
set(PROJECT_SOURCES
        main.cpp
        irracional.cpp
        )
add_executable(hydra ${PROJECT_SOURCES} ${PROJECT_HEADERS})