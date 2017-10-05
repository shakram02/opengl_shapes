#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <fstream>
#include <iostream>
#include <string>

#define VERTEX_SHADER_EXTENSION ".vert"
#define FRAGMENT_SHADER_EXTENSION ".frag"

class Shader {
public:
    Shader(const std::string &fileName);
    void bind();
    virtual ~Shader();

protected:
private:
    static const unsigned int NUM_SHADERS = 2;

    Shader(const Shader &) {}

    void operator=(const Shader &) {}

    GLuint shaderProgram;        // Keep a handle of the program
    GLuint shaders[NUM_SHADERS]; // Vertex and fragment shaders
};

#endif
