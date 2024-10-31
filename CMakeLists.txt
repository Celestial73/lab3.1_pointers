cmake_minimum_required(VERSION 3.26)
project(lab1_pointers)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab1_pointers main.cpp
        tests/ArraySequenceSharedPtrTests.cpp
        tests/ListSequenceUniquePtrTests.cpp
        tests/SmartArraySmartPtrTests.cpp
        tests/UniquePtrTests.cpp
        tests/SmartPtrTests.cpp
        tests/SharedPtrTests.cpp
)
