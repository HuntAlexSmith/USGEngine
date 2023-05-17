//*****************************************************************************
//  Filename: Engine.cpp
//  Author:   Hunter Smith
//  Date:     05/17/2023
//  Description:
//      This class will define the base engine that will handle everything
//*****************************************************************************

#include "Engine.h"
#include <iostream> // cout, cin
#include <SDL2/SDL.h>

// Declare static instance of the engine
std::shared_ptr<Engine> Engine::instance_;

// Constructor
Engine::Engine() :
    deltaTime_(0.0f)
    , isRunning_(false)
    , lifeTimer_(0.0f)
{
}

Engine::~Engine() {

}

bool Engine::Init() {
    // Only initialize if engine is not running
    if(!isRunning_) {

        // Initialize SDL
        if(SDL_Init(SDL_INIT_VIDEO) != 0) {
            std::cout << "Failed to initialize SDL \n";
            return false;
        }

        // Remember to set is running to true
        isRunning_ = true;
    }
    // Initialized successfully
    return true;
}

void Engine::Update(float dt) {
    // Remember to clamp dt
    deltaTime_ = dt;

    if(static_cast<int>(lifeTimer_) < static_cast<int>(lifeTimer_ + deltaTime_)) {
        std::cout << "Engine has been alive for " << static_cast<int>(lifeTimer_ + deltaTime_) << " seconds.\n";
    }

    lifeTimer_ += deltaTime_;

    // Test, remember to remove this
    if(lifeTimer_ > 2.0f){
        isRunning_ = false;
        std::cout << "Engine has been running for " << static_cast<int>(lifeTimer_) << " seconds, shutting down.\n";
    }

}

void Engine::Shutdown() {
    SDL_Quit();
}

std::shared_ptr<Engine> Engine::GetInstance() {
    // There is no instance yet, create one
    if(!instance_)
        instance_ = std::make_shared<Engine>();

    // Return the instance of the engine
    return instance_;
}
