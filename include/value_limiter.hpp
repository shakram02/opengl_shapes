//
// Created by ahmed on 10/6/17.
//

#ifndef OPEN_GL_DISPLAY_POSITION_CONTROLLER_HPP
#define OPEN_GL_DISPLAY_POSITION_CONTROLLER_HPP

class ValueLimiter {
public:
    ValueLimiter(float initial, float min, float max, float delta);

    float getValue() const;

    void increment();

    void decrement();

private:

    float m_minVal;
    float m_maxVal;
    float m_position;
    float m_delta;

};

#endif //OPEN_GL_DISPLAY_POSITION_CONTROLLER_HPP
