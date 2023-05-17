//*****************************************************************************
//  Filename: Clock.h
//  Author:   Hunter Smith
//  Date:     05/17/2023
//  Description:
//      Clock for doing very simple time tracking
//*****************************************************************************

#ifndef CLOCK_H
#define CLOCK_H

#include <SDL2/SDL.h>

class Clock {
public:
    // Ctor and dtor
    Clock();
    ~Clock();

    // Member functions
    void Tick();
    float GetDelta();

private:
    uint64_t curTickTime_ = 0;
    uint64_t lastTickTime_ = 0;
    uint64_t delta_ = 0;

};

#endif //USGENGINE_STUB_H
