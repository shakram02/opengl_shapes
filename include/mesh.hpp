#ifndef MESH_H
#define MESH_H

#include "vertex.hpp"
#include <GL/glew.h>

class Mesh {
public:
  Mesh(Vertex *vertices, unsigned int count);
  void draw();
  virtual ~Mesh();

protected:
private:
  void operator=(const Mesh &other) {}
  Mesh(const Mesh &other);

  enum {
    POSITION_VB=0,
    NUM_BUFFERS=1
  };

  GLuint m_vertexArrayObject;
  GLuint m_vertexArrayBuffers[NUM_BUFFERS];
  unsigned int m_drawCount;
};

#endif // MESH_H
