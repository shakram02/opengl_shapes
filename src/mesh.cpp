#include "mesh.hpp"

Mesh::Mesh(Vertex *vertices, unsigned int count) {
    static const GLfloat g_vertex_buffer_data[] = {
            -0.1f, -0.3f, 0.0f,
            1.0f, -1.0f, 0.0f,
            0.0f, 1.0f, 0.0f,
    };

    this->m_vertexCount = sizeof(g_vertex_buffer_data) / sizeof(GLfloat);

    glGenVertexArrays(1, &(m_vertexArrayObject));
    glGenBuffers(1, &(m_vertexBufferObjects[POSITION_VB]));

    glBindVertexArray(m_vertexArrayObject);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObjects[POSITION_VB]);

    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *) 0);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

Mesh::~Mesh() {
    glDeleteVertexArrays(1, &(m_vertexArrayObject));
    glDeleteBuffers(1, &(m_vertexBufferObjects[POSITION_VB]));
}

void Mesh::draw() {
    glBindVertexArray(m_vertexArrayObject);
    glDrawArrays(GL_TRIANGLES, 0, m_vertexCount);
}