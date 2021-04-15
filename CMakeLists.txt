cmake_minimum_required(VERSION 3.17)
project(PSS_HW4)

set(CMAKE_CXX_STANDARD 20)

add_executable(PSS_HW4 main.cpp PassengerGateway.cpp PassengerGateway.h Passenger.h MobileApp.cpp MobileApp.h Driver.h Car.cpp Car.h DriverGateway.cpp DriverGateway.h)