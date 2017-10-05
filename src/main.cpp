#include "display.hpp"
#include "shader.hpp"
#include "mesh.hpp"
#include "transform.hpp"

#define SHADER_FOLDER_NAME "./script/"

using namespace std;

int main() {
    Display window(800, 600, "Test");

    Vertex vertices[] = {
            Vertex(vec3(-0.01f, -0.03f, 0.0f)),
            Vertex(vec3(0.10f, -0.10f, 0.0f)),
            Vertex(vec3(0.0f, 0.10f, 0.0f))
    };

    Shader shader(std::string(SHADER_FOLDER_NAME) + std::string("basic_shader"));
    Mesh mesh(vertices, (sizeof(vertices) / sizeof(Vertex)));

    Transform transform;
    float angle = 0.0f;

    bool isRunning = true;
    while (isRunning) {
        window.clear(0.15f, 0.15f, 0.15f, 1.0f);
        SDL_Event e;

        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                isRunning = false;
            }

            if (e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                isRunning = false;
            }
        }

        glm::vec3 pos = transform.getPosition();
        pos.x = sinf(angle);
        transform.setPosition(pos);

        shader.bind();
        shader.update(transform);

        mesh.draw();

        window.swapBuffers();

        angle += 0.01f;
    }
    return 0;
}
