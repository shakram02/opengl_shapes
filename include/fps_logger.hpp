//
// Created by ahmed on 10/6/17.
//

#ifndef TARGET_NAME_FPS_CALCULATOR_HPP
#define TARGET_NAME_FPS_CALCULATOR_HPP

#include <fstream>

class FpsLogger {
public:
    FpsLogger();

    double logAndGetFps(unsigned long frameCount);

    double getMinFps() const;

    ~FpsLogger();

private:
    unsigned long m_startTime;
    double m_minFps;
    double m_fps;
    std::ofstream m_fpsLogFile;
};

#endif //TARGET_NAME_FPS_CALCULATOR_HPP
