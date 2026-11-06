
cmake_minimum_required(VERSION 3.16)

project(Menu LANGUAGES CXX)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Create executable
add_executable(Menu
    src/Main.cpp
    src/Menu.cpp
    src/Color.cpp
)

# Include header files
target_include_directories(Menu PRIVATE include)
