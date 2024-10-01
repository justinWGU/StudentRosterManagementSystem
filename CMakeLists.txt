cmake_minimum_required(VERSION 3.27)
project(C867Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(C867Project main.cpp
        Roster.cpp
        student.cpp
        RosterCLI.cpp
        RosterCLI.h)
