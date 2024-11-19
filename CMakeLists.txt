cmake_minimum_required(VERSION 3.29)
project(DSA_Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(DSA_Project main.cpp
        Helpers/ReadWrite.h
        Models/Section.h
        Models/Book.h
        Models/Employee.h
        Models/Owner.h
        Models/LinkedList.h
)
