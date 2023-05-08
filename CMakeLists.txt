cmake_minimum_required(VERSION 3.25)
project(USGEngine)

# Require this standard
set(CMAKE_CXX_STANDARD 17)

# Set up the include directory
include_directories(include)

# Set up the lib directory
link_directories(libs)

# Executable gets added
add_executable(USGEngine src/main.cpp src/glad.c)

# Remember to link with SDL2
target_link_libraries(USGEngine SDL2main SDL2)
