#include "display.h"
#include <iostream>
Display::Display(int width, int height, const std::string &title) {
  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

  this->sdlWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,
                                     SDL_WINDOWPOS_CENTERED, width, height,
                                     SDL_WINDOW_OPENGL);
  this->sdlContext = SDL_GL_CreateContext(this->sdlWindow);
  this->closed = false;

  GLenum res = glewInit();

  if (res != GLEW_OK) {
    std::cerr << "Glew failed to initialize!" << std::endl;
  }

  glEnable(GL_DEPTH_TEST);

  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);
}

Display::~Display() {
  // Destroy objects in the reverse order they're created
  SDL_GL_DeleteContext(this->sdlContext);
  SDL_DestroyWindow(this->sdlWindow);
  SDL_Quit();
}

void Display::update() {
  SDL_GL_SwapWindow(this->sdlWindow);

  SDL_Event e;

  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      this->closed = true;
    }
  }
}

bool Display::isClosed() { return this->closed; }
