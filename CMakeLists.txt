# cmake_minimum_required(VERSION <specify CMake version here>)
project(PSS_II_Homework_03)

set(CMAKE_CXX_STANDARD 17)

add_executable(PSS_II_Homework_03 accessLevel.h
        main.cpp
        room.cpp
        room.h
        users.cpp
        users.h
        )