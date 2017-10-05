#include "mesh.hpp"

Mesh::Mesh(Vertex *vertices, unsigned int count) {

    this->m_drawCount = count;
    glGenVertexArrays(1, &(this->m_vertexArrayObject));
    glBindVertexArray(this->m_vertexArrayObject);

    glGenBuffers(this->NUM_BUFFERS, this->m_vertexArrayBuffers);
    glBindBuffer(GL_ARRAY_BUFFER, this->m_vertexArrayBuffers[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, count * sizeof(Vertex), vertices, GL_STATIC_DRAW);

    // Vertex attributes; pos, color, ...etc
    // The GPU sees the Vertex as a sequential array of data
    glEnableVertexAttribArray(0);
    // 3 pieces of data, (Vec3)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindVertexArray(0); // No operations will further affect the array after this statement
}

Mesh::~Mesh() { glDeleteVertexArrays(1, &(this->m_vertexArrayObject)); }

void Mesh::draw() {
    glBindVertexArray(this->m_vertexArrayObject);

    glDrawArrays(GL_TRIANGLES, 0, this->m_drawCount);
    glDisableVertexAttribArray(0);
//  glBindVertexArray(0); // No operations will further affect the array after this statement
}