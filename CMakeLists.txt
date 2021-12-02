cmake_minimum_required(VERSION 3.10)
project(AdventOfCode2021)

include_directories(
	include
        Utils/include
)

#---------------------------------------
# Create the Executable
#---------------------------------------
add_executable(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/main.cpp ${CMAKE_SOURCE_DIR}/Dec1/Solution1.cpp ${CMAKE_SOURCE_DIR}/Dec1/Solution2.cpp 
	${CMAKE_SOURCE_DIR}/include/Declarations.h ${CMAKE_SOURCE_DIR}/Utils/include/Slider.h)

# Post Build for Day 1 Inputs.
add_custom_command(TARGET AdventOfCode2021 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/Dec1/puzzle.input Inputs/Dec1/puzzle.input
)

message(STATUS "Done Configuring ${PROJECT_NAME}...")

