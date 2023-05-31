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
#include <stdexcept>
#include "../Common/Common.h"
#include "../ID/IDGen.h"

// Declare static instance of the engine
std::shared_ptr<Engine> Engine::instance_ = nullptr;

// Constructor
Engine::Engine() :
    deltaTime_(0.0f)
    , isRunning_(false)
    , lifeTimer_(0.0f)
    , gfxEngine_(GfxEngine::GetInstance())
    , inputManager_()
{
    Engine* curEngine = instance_.get();
    if(curEngine != nullptr && this != curEngine) {
        std::cout << "Invalid Engine Instance! Throwing Exception..." << std::endl;
        throw std::runtime_error("Invalid Engine Instance!");
    }
}

// Destructor
Engine::~Engine() {

}

bool Engine::Init() {
    // Check if this isn't equal to the instance
    if(this != instance_.get())
        return false;

    // Only initialize if engine is not running
    if(!isRunning_) {

        // Initialize Graphics
        gfxEngine_->Init();

        // Remember to set is running to true
        isRunning_ = true;
    }
    // Initialized successfully
    return true;
}

void Engine::Update(float dt) {
    // Check for instance that is not of the singleton
    if(this != instance_.get())
        return;

    // Remember to clamp dt
    deltaTime_ = dt;

    // Update the input manager
    inputManager_.Update(*gfxEngine_);

    // Print how long engine has been alive for and update life timer
    if(static_cast<int>(lifeTimer_) < static_cast<int>(lifeTimer_ + deltaTime_)) {
        std::cout << "Engine has been alive for " << static_cast<int>(lifeTimer_ + deltaTime_) << " seconds.\n";
    }

    lifeTimer_ += deltaTime_;

    // Check for quit or escape
    if(inputManager_.QuitTriggered() || inputManager_.KeyIs(USGKey::ESC, KeyState::Triggered))
        isRunning_ = false;
}

void Engine::Shutdown() {
    // Check if this isn't equal to the instance
    if(this != instance_.get())
        return;

    gfxEngine_->Shutdown();
}

std::shared_ptr<Engine> Engine::GetInstance() {
    // There is no instance yet, create one
    if(!instance_)
        instance_ = std::make_shared<Engine>();

    // Return the instance of the engine
    return instance_;
}
