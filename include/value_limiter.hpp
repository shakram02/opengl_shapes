//
// Created by ahmed on 10/6/17.
//

#ifndef OPEN_GL_DISPLAY_POSITION_CONTROLLER_HPP
#define OPEN_GL_DISPLAY_POSITION_CONTROLLER_HPP

class ValueLimiter {
public:
    ValueLimiter(double initial, double min, double max, double delta);

    void update();

    double getValue();

    void increment();

    void decrement();

private:

    double m_minVal;
    double m_maxVal;
    double m_position;
    double m_delta;

    // Provide smooth transition between values
    enum class IncrementDirection {
        Increasing,
        Decreasing,
        None
    };

    double m_final;
    double m_internalStep;
    IncrementDirection m_direction;
};

#endif //OPEN_GL_DISPLAY_POSITION_CONTROLLER_HPP
