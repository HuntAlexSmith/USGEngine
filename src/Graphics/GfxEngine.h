//*****************************************************************************
//  Filename: GfxEngine.h
//  Author:   Hunter Smith
//  Date:     05/30/2023
//  Description:
//      This Engine will manage everything graphics, making sure everything
//      is initialized, updated, and deleted properly.
//*****************************************************************************

#ifndef USGENGINE_STUB_H
#define USGENGINE_STUB_H

#include "SDL2/SDL.h"

class GfxEngine {
public:
    // Ctor and Dtor
    GfxEngine();
    ~GfxEngine();

    // Member functions
    void Init();
    void Shutdown();

    // Getters
    inline bool IsRunning() { return running_; }

private:

    bool sdlInit_;

    SDL_Window* window_;
    int windowWidth_;
    int windowHeight_;

    SDL_GLContext glContext_;
    bool running_;

};

#endif //USGENGINE_STUB_H
