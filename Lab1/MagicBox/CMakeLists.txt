cmake_minimum_required(VERSION 3.16)

project(MagicBox LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(MagicBox
    src/hello.cpp
    src/MagicBox.cpp
)

target_include_directories(MagicBox PRIVATE include)

find_package(Threads REQUIRED)
target_link_libraries(MagicBox PRIVATE Threads::Threads)
