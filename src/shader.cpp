#include "shader.hpp"
static GLuint createShader(const std::string &text, GLenum shaderType);
static void checkShaderError(GLuint shader, GLuint flag, bool isProgram,const std::string &errorMessage);
static std::string loadShader(const std::string &fileName);

Shader::Shader(const std::string &fileName) {

  this->shaderProgram = glCreateProgram();

  this->shaders[0] = createShader(loadShader(fileName + VERTEX_SHADER_EXTENSION), GL_VERTEX_SHADER);
  this->shaders[1] = createShader(loadShader(fileName + FRAGMENT_SHADER_EXTENSION),GL_FRAGMENT_SHADER);

  // Add the shaders
  for (unsigned int i = 0; i < this->NUM_SHADERS; i++) {
    glAttachShader(this->shaderProgram, this->shaders[i]);
  }

  glBindAttribLocation(this->shaderProgram, 0, "position");

  glLinkProgram(this->shaderProgram);
  checkShaderError(this->shaderProgram, GL_LINK_STATUS, true,
                         "Error: Linking failed");

  glValidateProgram(this->shaderProgram);
  checkShaderError(this->shaderProgram, GL_VALIDATE_STATUS, true,
                         "Error: Program is invalid");
}

void Shader::bind() { glUseProgram(this->shaderProgram); }

Shader::~Shader() {
  for (unsigned int i = 0; i < this->NUM_SHADERS; i++) {
    glDetachShader(this->shaderProgram, this->shaders[i]);
    glDeleteShader(this->shaders[i]);
  }
  glDeleteProgram(this->shaderProgram);
}

std::string loadShader(const std::string &fileName) {
  std::ifstream file;
  file.open((fileName).c_str());

  std::string output;
  std::string line;

  if (file.is_open()) {
      getline(file, output,'\0');
  } else {
      std::cerr << "Unable to load shader: " << fileName << std::endl;
  }

  return output;
}

void checkShaderError(GLuint shader, GLuint flag, bool isProgram,
                              const std::string &errorMessage) {
  GLint success = 0;
  GLchar error[1024] = {0};

  if (isProgram) {
    glGetProgramiv(shader, flag, &success);
  } else {
    glGetShaderiv(shader, flag, &success);
  }

  if (success == GL_FALSE) {
    if (isProgram) {
      glGetProgramInfoLog(shader, sizeof(error), NULL, error);
    } else {
      glGetShaderInfoLog(shader, sizeof(error), NULL, error);
    }

    std::cerr << errorMessage << ": '" << error << "'" << std::endl;
  }
}

GLuint createShader(const std::string &text, GLenum shaderType) {

  GLuint shader = glCreateShader(shaderType);

  if (shader == 0) {
    std::cerr << "Error: Shader creation failed" << std::endl;
  }

  const GLchar *shaderSourceStrings[1];
  GLint shaderSourceLengths[1];

  shaderSourceStrings[0] = text.c_str();
  shaderSourceLengths[0] =text.length();

  glShaderSource(shader, 1, shaderSourceStrings, shaderSourceLengths);

  glCompileShader(shader);
  checkShaderError(shader, GL_COMPILE_STATUS, false,
                         "Error: Shader compilation failed");
  return shader;
}
