//
// Created by ahmed on 10/6/17.
//

#include "value_limiter.hpp"

ValueLimiter::ValueLimiter(float initial, float min, float max, float delta) :
        m_position(initial),
        m_minVal(min),
        m_maxVal(max),
        m_delta(delta) {}

void ValueLimiter::increment() {
    if ((m_position + m_delta) >= m_maxVal)return;

    // Positive motion if we didn't hit the limit
    m_position += m_delta;
}


float ValueLimiter::getValue() const {
    return m_position;
}

void ValueLimiter::decrement() {
    if ((m_position - m_delta) <= m_minVal)return;

    // Negative motion if we didn't hit the limit
    m_position -= m_delta;
}

