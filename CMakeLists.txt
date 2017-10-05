cmake_minimum_required(VERSION 3.9)

set(TARGET_NAME "open_gl_display")
# Name the project
project(TARGET_NAME)

# Add the include and src directories to the build
include_directories("include")
file(GLOB SOURCES "src/*.cpp")

# Add libraries to the linker
link_libraries("-lGL -lGLEW -lSDL2")

add_executable(${TARGET_NAME} ${SOURCES})

# Copy the res folder containing shaders to the output directory
add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       "${CMAKE_SOURCE_DIR}/script" "${CMAKE_BINARY_DIR}/script")
