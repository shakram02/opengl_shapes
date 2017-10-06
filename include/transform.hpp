//
// Matrix transform interface
//

#ifndef TARGET_NAME_TRANSFORM_H
#define TARGET_NAME_TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Transform {
public:
    Transform(const glm::vec3 &pos = glm::vec3(), const glm::vec3 &rot = glm::vec3(),
              const glm::vec3 &scale = glm::vec3(1.0f, 1.0f, 1.0f));

    const glm::vec3 &getPosition() const;

    const glm::vec3 &getRotation() const;

    const glm::vec3 &getScale() const;

    void setPosition(const glm::vec3 &position);

    void setRotation(const glm::vec3 &rotation);

    void setScale(const glm::vec3 &scale);

    glm::mat4 getModel();

private:
    glm::vec3 m_pos;
    glm::vec3 m_rot;
    glm::vec3 m_scale;
};


#endif //TARGET_NAME_TRANSFORM_H
