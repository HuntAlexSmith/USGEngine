cmake_minimum_required(VERSION 3.25)
project(USGEngine)

# Require this standard
set(CMAKE_CXX_STANDARD 17)

# Set up the include directory
include_directories(include)

# Set up the lib directory
link_directories(libs)

# Executable gets added
add_executable(USGEngine src/main.cpp src/glad.c src/Engine/Engine.cpp src/Clock.cpp src/ID/IDGen.cpp src/Engine/Entity/Entity.cpp)

# Custom command for copying important SDL2 dll
add_custom_command(TARGET USGEngine POST_BUILD        # Adds post-build event
        COMMAND ${CMAKE_COMMAND} -E copy_if_different # Executes cmake -E copy_if_different
        "${PROJECT_SOURCE_DIR}/libs/SDL2.dll"         # Input path (SDL2 dll)
        $<TARGET_FILE_DIR:USGEngine>)                 # Output path (build)

# Remember to link with SDL2
target_link_libraries(USGEngine SDL2main SDL2)
