#ifndef VERTEX_H
#define VERTEX_H

#include <glm/glm.hpp>

using namespace glm;

class Vertex {
public:
  Vertex(const vec3 &pos) { this->pos = pos; }

protected:
private:
  vec3 pos;
};

#endif