//
// Created by ahmed on 10/6/17.
//

#include "value_limiter.hpp"

ValueLimiter::ValueLimiter(double initial, double min, double max, double delta) :
        m_position(initial),
        m_minVal(min),
        m_maxVal(max),
        m_delta(delta) {
    m_internalStep = m_delta / 10.0d;
}

void ValueLimiter::increment() {
    if ((m_final + m_delta) > m_maxVal)return;

    // Positive motion if we didn't hit the limit
    m_final += m_delta;
    m_direction = IncrementDirection::Increasing;
}

void ValueLimiter::update() {
    if (m_direction == IncrementDirection::Increasing && m_position < m_final) {
        m_position += m_internalStep;
    } else if (m_direction == IncrementDirection::Decreasing && m_position > m_final) {
        m_position -= m_internalStep;
    } else {
        m_position = m_final; // Set the value
        m_direction = IncrementDirection::None;
    }
}

double ValueLimiter::getValue() {

    if (m_direction != IncrementDirection::None) {
        this->update();
    }

    return m_position;
}

void ValueLimiter::decrement() {
    if ((m_final - m_delta) < m_minVal)return;

    // Negative motion if we didn't hit the limit
    m_final -= m_delta;
    m_direction = IncrementDirection::Decreasing;
}

