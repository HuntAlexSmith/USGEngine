//*****************************************************************************
//  Filename: GfxEngine.cpp
//  Author:   Hunter Smith
//  Date:     05/30/2023
//  Description:
//      Implementation of the graphics engine
//*****************************************************************************

#include "GfxEngine.h"
#include <glad/glad.h>
#include <iostream>

GfxEngine::GfxEngine() :
    sdlInit_(true)
    , window_(nullptr)
    , windowWidth_(0)
    , windowHeight_(0)
    , glContext_(nullptr)
    , running_(false)
{
}

GfxEngine::~GfxEngine() {

}

// Member functions
void GfxEngine::Init() {
    // Initialize SDL video
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        // Initialization failed, print message
        std::cout << "SDL Video failed to Initialize: " << SDL_GetError() << "\n";
        return;
    }
    sdlInit_ = true;

    // Otherwise, start getting OpenGL ready
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4); // Major Version
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6); // Minor Version

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);          // Double buffer rendering
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);           // 24-bit depth buffer

    // Create and SDL window
    window_ = SDL_CreateWindow("USGEngine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 800, SDL_WINDOW_OPENGL);

    // Window failed to be created, error
    if(window_ == nullptr) {
        std::cout << "SDL Window failed to be created: " << SDL_GetError() << "\n";
        return;
    }

    // Now Create a context for OpenGL
    glContext_ = SDL_GL_CreateContext(window_);
    if(glContext_ == nullptr) {
        // Context failed to be created
        std::cout << "GL Context failed to be created: " << SDL_GetError() << "\n";
        return;
    }

    // Get load address for GLAD
    if(!gladLoadGLLoader(SDL_GL_GetProcAddress)) {
        // Failed to load OpenGL
        std::cout << "Failed to load OpenGL with GLAD\n";
        return;
    }

    // Print out basic information of OpenGL
    std::cout << "Vendor: " << glGetString(GL_VENDOR) << "\n";
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << "\n";
    std::cout << "Version: " << glGetString(GL_VERSION) << "\n";

    // May want to enable the V-Sync, not sure
    //    SDL_GL_SetSwapInterval(1);

    // Enable depth test
    glEnable(GL_DEPTH_TEST);

    // Set the viewport
    SDL_GetWindowSize(window_, &windowWidth_, &windowHeight_);
    glViewport(0, 0, windowWidth_, windowHeight_);

    // Set a basic clear color
    glClearColor(0.0f, 1.0f, 0.0f, 0.0f);

    // Remember to say the engine is running now
    running_ = true;
}

void GfxEngine::Shutdown() {
    // Destroy gl context, destroy window, and shutdown SDL
    if(glContext_) {
        SDL_GL_DeleteContext(glContext_);
        glContext_ = nullptr;
    }

    if(window_) {
        SDL_DestroyWindow(window_);
        window_ = nullptr;
    }

    if(sdlInit_)
        SDL_Quit();
}
