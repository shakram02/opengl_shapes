#include "display.hpp"
#include "shader.hpp"
#include "mesh.hpp"

#define SHADER_FOLDER_NAME "./script/"

using namespace std;

int main() {
    Display window(800, 600, "Test");

    Vertex vertices[] = {
            // Values are from -1 to 1
            // -1 left/bottom, 1 is right/top
            Vertex(glm::vec3(-0.5, -0.5, 0)),
            Vertex(glm::vec3(0, 0.5, 0)),
            Vertex(glm::vec3(0.5, -0.5, 0))
    };

    Shader shader(std::string(SHADER_FOLDER_NAME) + std::string("basic_shader"));
    Mesh mesh(vertices, (sizeof(vertices) / sizeof(Vertex)));

    bool isRunning = true;
    while (isRunning) {

        SDL_Event e;

        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                isRunning = false;
            }

            if (e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                isRunning = false;
            }
        }

        window.clear(0.15f, 0.2f, 0.15f, 1.0f);

        shader.bind();
        mesh.draw();

        window.swapBuffers();
    }
    return 0;
}
