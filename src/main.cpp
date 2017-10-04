#include <iostream>
#include <GL/glew.h>
#include "display.h"

using namespace std;

int main()
{
    Display d(800,600,"Cool");

    while(!d.isClosed()){
        glClearColor(0.15f,0.15f,0.15f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        d.update();
    }

    return 0;
}
