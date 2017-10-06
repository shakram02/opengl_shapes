#include <fps_logger.hpp>
#include "display.hpp"
#include "shader.hpp"
#include "mesh.hpp"


#define SHADER_FOLDER_NAME "./script/"

using namespace std;

int main() {
    Display window(800, 600, "Test");

    Vertex vertices[] = {
            Vertex(vec3(-0.03f, -0.03f, 0.0f)),
            Vertex(vec3(0.03f, -0.03f, 0.0f)),
            Vertex(vec3(0.0f, 0.03f, 0.0f))
    };

    Shader shader(std::string(SHADER_FOLDER_NAME) + std::string("basic_shader"));
    shader.bind();
    Mesh mesh(vertices, (sizeof(vertices) / sizeof(Vertex)));
    Transform transform;

    float angleRad = 0.0f;
    bool isRunning = true;
    FpsLogger fpsLogger;
    unsigned long frameCount = 0;
    double fps = 0;

    while (isRunning) {
        window.clear(0.15f, 0.15f, 0.15f, 1.0f);
        SDL_Event e;

        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                isRunning = false;
            }

            if (e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                isRunning = false;
            }
        }

        glm::vec3 pos = transform.getPosition();
        float sin_delta = sinf(angleRad);
        float cos_delta = cosf(angleRad);
        pos.x = sin_delta;
        pos.y = cos_delta;
        transform.setPosition(pos);

        shader.update(transform);
        mesh.draw();

        angleRad += 0.03f;
        frameCount++;

        cout << "Min FPS: " << fpsLogger.getMinFps() << endl;

        fps = fpsLogger.logAndGetFps(frameCount);
        window.setTitlePostfix(to_string(fps));

        window.swapBuffers();
        SDL_Delay(32);
    }

    return 0;
}
