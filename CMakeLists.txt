cmake_minimum_required(VERSION 3.9)
project(Symulacja_Ruchu_Pieszych)

set(CMAKE_CXX_STANDARD 11)

add_executable(Symulacja_Ruchu_Pieszych main.cpp Reader.cpp Reader.h Field.cpp Field.h StaticField.cpp StaticField.h Symulation.cpp Symulation.h)