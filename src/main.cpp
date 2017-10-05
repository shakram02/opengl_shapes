#include "display.h"
#include "shader.h"
#include <GL/glew.h>
#include <iostream>

#define SHADER_FOLDER_NAME "./script/"

using namespace std;

int main() {
  Display d(800, 600, "Cool");

  Shader s(std::string(SHADER_FOLDER_NAME) + std::string("basic_shader"));

  s.bind();

  while (!d.isClosed()) {
    glClearColor(0.15f, 0.15f, 0.15f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    d.update();
  }

  return 0;
}
