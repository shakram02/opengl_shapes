cmake_minimum_required(VERSION 3.8)

set(TARGET_NAME "open_gl_display")
# Name the project
project(TARGET_NAME)

# Add the include and src directories to the build
include_directories("include")
file(GLOB SOURCES "src/*.cpp")

# Add libraries to the linker
link_libraries("-lGL -lGLEW -lSDL2")

add_executable(${TARGET_NAME} ${SOURCES})

file(GLOB SHADER_SCRIPTS "script/*")
file(COPY ${SHADER_SCRIPTS} DESTINATION "${CMAKE_BINARY_DIR}/script")
