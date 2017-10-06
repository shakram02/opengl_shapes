#include "mesh.hpp"

Mesh::Mesh(Vertex *vertices, unsigned int count) {
    this->m_vertexCount = count;

    glGenVertexArrays(1, &(m_vertexArrayObject));
    glGenBuffers(1, &(m_vertexBufferObjects[POSITION_VB]));

    glBindVertexArray(m_vertexArrayObject);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObjects[POSITION_VB]);

    glBufferData(GL_ARRAY_BUFFER, count * sizeof(Vertex), vertices, GL_STATIC_DRAW);
    // 3 is the vector dimension
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *) 0);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

Mesh::~Mesh() {
    glDeleteVertexArrays(1, &(m_vertexArrayObject));
    glDeleteBuffers(1, &(m_vertexBufferObjects[POSITION_VB]));
}

void Mesh::draw(GLenum mode) {
    glBindVertexArray(m_vertexArrayObject);
    glDrawArrays(mode, 0, m_vertexCount);
}