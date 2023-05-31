//*****************************************************************************
//  Filename: GfxEngine.h
//  Author:   Hunter Smith
//  Date:     05/30/2023
//  Description:
//      This Engine will manage everything graphics, making sure everything
//      is initialized, updated, and deleted properly.
//*****************************************************************************

#ifndef GFXENGINE_H
#define GFXENGINE_H

#include "SDL2/SDL.h"
#include <memory>

// Will only ever want one running at one time, so follow singleton pattern
class GfxEngine {
public:
    // Ctor and Dtor
    GfxEngine();
    ~GfxEngine();

    // Member functions
    void Init();
    void Shutdown();

    // Getters
    inline bool IsRunning() const { return running_; }

    // Get Instance
    static std::shared_ptr<GfxEngine> GetInstance();

private:

    static std::shared_ptr<GfxEngine> instance_;

    bool sdlInit_;

    SDL_Window* window_;
    int windowWidth_;
    int windowHeight_;

    SDL_GLContext glContext_;
    bool running_;

};

#endif
