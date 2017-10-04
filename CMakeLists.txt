cmake_minimum_required(VERSION 3.9)

project("OpenGlDisplay")

include_directories("include")
file(GLOB SOURCES "src/*.cpp")

link_libraries("-lGL -lGLEW -lSDL2")

add_executable(open_gl_display ${SOURCES})