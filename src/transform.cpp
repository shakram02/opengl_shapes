//
// Created by ahmed on 10/5/17.
//

#include "transform.hpp"

using namespace glm;

Transform::Transform(const vec3 &pos, const vec3 &rot, const vec3 &scale) :
        m_pos(pos), m_rot(rot), m_scale(scale) {}

const glm::vec3 &Transform::getPosition() const {
    return m_pos;
}

const vec3 &Transform::getRotation() const {
    return m_rot;
}

const vec3 &Transform::getScale() const {
    return m_scale;
}

void Transform::setPosition(const vec3 &position) {
    Transform::m_pos = position;
}

void Transform::setRotation(const vec3 &rotation) {
    Transform::m_rot = rotation;
}

void Transform::setScale(const vec3 &scale) {
    Transform::m_scale = scale;
}

mat4 Transform::getModel() {
    mat4 scaleMatrix = scale(m_scale);
    mat4 posMatrix = translate(m_pos);

    mat4 rotXMatrix = rotate(m_rot.x, vec3(1, 0, 0));
    mat4 rotYMatrix = rotate(m_rot.y, vec3(0, 1, 0));
    mat4 rotZMatrix = rotate(m_rot.z, vec3(0, 0, 1));

    mat4 rotMatrix = rotZMatrix * rotYMatrix * rotXMatrix;
    return posMatrix * rotMatrix * scaleMatrix;
}

