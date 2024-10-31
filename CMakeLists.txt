cmake_minimum_required(VERSION 3.15)
project(Business-Tracker)

set(CMAKE_CXX_STANDARD 17)

add_executable(M2OEP_Main
                     main.cpp
                     Clients.cpp
                     Business.cpp
                     Finances.cpp
                     Schedule.cpp
                     TimePoint.cpp
        Event.cpp
        Event.h
        Meeting.cpp
        Meeting.h
        Project.cpp
        Project.h)

add_executable(M2OEP_Testing
                     testing.cpp
                     Clients.cpp
                     Business.cpp
                     Finances.cpp
                     Schedule.cpp
                     TimePoint.cpp
        Event.cpp
        Event.h
        Meeting.cpp
        Meeting.h
        Project.cpp
        Project.h)