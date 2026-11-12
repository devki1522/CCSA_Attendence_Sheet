cmake_minimum_required(VERSION 3.20)

# Project name matching your repository
project(CCSA_Attendence_Sheet LANGUAGES CXX C)

# Enforce C++20 standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Crow is vendored in src/crow_include. These system packages are available in
# both the local vcpkg setup and the Linux container.
find_package(Threads REQUIRED)
find_package(SQLite3 REQUIRED)

# Executable target
add_executable(CCSA_Attendence_Sheet
    src/main.cpp
)

# Header search paths
target_include_directories(CCSA_Attendence_Sheet PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src/crow_include
)

# Link Crow and SQLite3 libraries
target_link_libraries(CCSA_Attendence_Sheet PRIVATE
    SQLite::SQLite3
    Threads::Threads
)

# Compiler warnings and standards compliance
if(MSVC)
    target_compile_options(CCSA_Attendence_Sheet PRIVATE /W4 /permissive-)
else()
    target_compile_options(CCSA_Attendence_Sheet PRIVATE -Wall -Wextra -Wpedantic)
endif()
