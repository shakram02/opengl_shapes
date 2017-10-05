#ifndef DISPLAY_H
#define DISPLAY_H

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <iostream>
#include <string>

class Display {
public:
  Display(int width, int height, const std::string &title);
  virtual ~Display();
  void update();
  bool isClosed();

protected:
private:
  SDL_Window *sdlWindow;
  SDL_GLContext sdlContext;
  bool closed;
};

#endif // DISPLAY_H
