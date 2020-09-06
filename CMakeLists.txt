cmake_minimum_required(VERSION 3.17)
project(hydra)

set(CMAKE_CXX_STANDARD 14)
set(PROJECT_HEADERS
        abstr_digit.h
        irracional.h
        Double.h
        fraction.h
        )
set(PROJECT_SOURCES
        main.cpp
        irracional.cpp
        Double.cpp
        fraction.cpp
        )
add_executable(hydra ${PROJECT_SOURCES} ${PROJECT_HEADERS})