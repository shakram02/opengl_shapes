#include <fps_logger.hpp>
#include "display.hpp"
#include "shader.hpp"
#include <mesh.hpp>
#include "value_limiter.hpp"

#define SHADER_FOLDER_NAME "./script/"

using namespace std;

int main() {
    Display window(800, 600, "Test");

    Vertex vertices[] = {
            Vertex(vec3(-0.03f, -0.03f, 0.0f)),
            Vertex(vec3(0.03f, -0.03f, 0.0f)),
            Vertex(vec3(0.0f, 0.03f, 0.0f)),
            Vertex(vec3(-0.13f, -0.03f, 0.0f)),
            Vertex(vec3(0.03f, -0.23f, 0.0f)),
            Vertex(vec3(0.0f, 0.03f, 0.1f))
    };

    Shader shader(std::string(SHADER_FOLDER_NAME) + std::string("basic_shader"));
    shader.bind();
    Mesh mesh(vertices, (sizeof(vertices) / sizeof(Vertex)));
    Transform transform;

    float virtualTimePassed = 0.0f;
    bool isRunning = true;
    FpsLogger fpsLogger;


    ValueLimiter horizontalLimiter(0, -1, 1, 0.05f);
    ValueLimiter verticalLimiter(0, -1, 1, 0.05f);
    ValueLimiter timeSpeedLimiter(0, 0, 5.0f, 0.02f);

    unsigned long frameCount = 0;

    double minFps = INT_MAX, tempFps;
    double fps = 0;

    float sinScale = 0, cosScale = 0;

    SDL_Delay(32);

    while (isRunning) {
        SDL_Delay(32);
        window.clear(0.15f, 0.15f, 0.15f, 1.0f);
        SDL_Event e;

        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                isRunning = false;
            }

            if (e.type == SDL_KEYDOWN) {
                SDL_Scancode scanCode = e.key.keysym.scancode;
                if (scanCode == SDL_SCANCODE_ESCAPE)isRunning = false;
                else if (scanCode == SDL_SCANCODE_RIGHT) horizontalLimiter.increment();
                else if (scanCode == SDL_SCANCODE_LEFT) horizontalLimiter.decrement();

                else if (scanCode == SDL_SCANCODE_UP) verticalLimiter.increment();
                else if (scanCode == SDL_SCANCODE_DOWN) verticalLimiter.decrement();

                else if (scanCode == SDL_SCANCODE_W) timeSpeedLimiter.increment();
                else if (scanCode == SDL_SCANCODE_S) timeSpeedLimiter.decrement();
                cout << "KEY PRESS: " << scanCode << " @ " << frameCount << endl;
            }
        }

        glm::vec3 pos = transform.getPosition();

//        float sin_delta = sinScale * sinf(virtualTimePassed);
//        float cos_delta = cosScale * cosf(virtualTimePassed);

        pos.x = sinf(virtualTimePassed) * horizontalLimiter.getValue();
        pos.y = cosf(virtualTimePassed) * verticalLimiter.getValue();

        transform.setPosition(pos);

        shader.update(transform);
        mesh.draw();

        virtualTimePassed += timeSpeedLimiter.getValue();
        frameCount++;

        tempFps = fpsLogger.getMinFps();
        if (minFps < tempFps) {
            minFps = tempFps;
            cout << "Min FPS: " << minFps << endl;
        }

        fps = fpsLogger.logAndGetFps(frameCount);
        window.setTitlePostfix(to_string(fps));

        window.swapBuffers();
    }

    return 0;
}
