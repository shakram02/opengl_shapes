//
// Created by ahmed on 10/6/17.
//

#include <fps_logger.hpp>
#include <SDL2/SDL_timer.h>
#include <climits>
#include <iostream>

FpsLogger::FpsLogger() {
    m_startTime = SDL_GetTicks();
    m_minFps = INT_MAX;

    m_fpsLogFile.open("./fps_log.csv");
    m_fpsLogFile << std::endl;
}

double FpsLogger::logAndGetFps(unsigned long frameCount) {
    unsigned long currentTime = SDL_GetTicks();
    double delta = ((double) (currentTime - m_startTime) / 1000);

    if (delta == 0) {
        return m_minFps;
    }

    m_fps = (double) (frameCount) / delta;
    m_minFps = std::fmin(m_fps, m_minFps);

    m_fpsLogFile << currentTime << "," << m_fps << std::endl;

    return m_fps;
}

double FpsLogger::getMinFps() const {
    return m_minFps;
}

FpsLogger::~FpsLogger() {
    m_fpsLogFile.close();
}
