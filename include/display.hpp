#ifndef DISPLAY_H
#define DISPLAY_H

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include <sstream>

class Display {
public:
    Display(int width, int height, const std::string &title);

    virtual ~Display();

    void swapBuffers();

    void clear(float r, float g, float b, float a);

    void setTitlePostfix(const std::string &postfix);

protected:
private:
    SDL_Window *sdlWindow;
    SDL_GLContext sdlContext;
    std::string m_baseWindowTitle;

    void operator=(const Display &other) {}

    Display(const Display &other);
};

#endif // DISPLAY_H
