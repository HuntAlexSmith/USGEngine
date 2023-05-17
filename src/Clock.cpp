//*****************************************************************************
//  Filename: Clock.cpp
//  Author:   Hunter Smith
//  Date:     05/17/2023
//  Description:
//      Clock for doing very simple time tracking
//*****************************************************************************

#include "Clock.h"

Clock::Clock() :
    curTickTime_(0)
    , lastTickTime_(0)
    , delta_(0)
{}

Clock::~Clock() {

}

void Clock::Tick() {
    curTickTime_ = SDL_GetTicks64();
    delta_ = curTickTime_ - lastTickTime_;
    lastTickTime_ = curTickTime_;
}

float Clock::GetDelta() {
    return static_cast<float>(delta_) / 1000.0f;
}
