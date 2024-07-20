cmake_minimum_required(VERSION 3.29)
project(Compiler C)

# Set the C standard to C11
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Define the include directories
include_directories(include)

# Define source files
set(SOURCE_FILES
        main.c
        lLexer.c
        include/lUtils.h
        lUtils.c
)

set(SCRATCH_FILES
        scratch/scratch.c
        scratch/scratch.c
)

# Define header files
set(HEADER_FILES
        include/lToken.h
        include/lLexer.h
)

# Create the executable
add_executable(Compiler ${SOURCE_FILES} ${HEADER_FILES})
add_executable(Scratch ${SCRATCH_FILES} ${HEADER_FILES})

# Specify include directories for the target
target_include_directories(Compiler PRIVATE include)

# Add build types and options (optional)
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# Set compile options (optional)
target_compile_options(Compiler PRIVATE
        $<$<C_COMPILER_ID:GNU>:-Wall -Wextra -Wpedantic>
        $<$<C_COMPILER_ID:Clang>:-Wall -Wextra -Wpedantic>
        $<$<C_COMPILER_ID:MSVC>:/W4 /permissive->
)