//*****************************************************************************
//  Filename: Engine.h
//  Author:   Hunter Smith
//  Date:     05/17/2023
//  Description:
//      This class will define the base engine that will handle everything
//*****************************************************************************

#ifndef ENGINE_H
#define ENGINE_H

#include <memory> // shared_ptr for singleton pattern
#include "../Graphics/GfxEngine.h"
#include "Input/InputManager.h"

// There should only ever be one engine running, so we will use singleton pattern. This will allow for anything to
// access information of the engine
class Engine {
public:
    // Ctor and dtor
    Engine();
    ~Engine();

    // Do not need copy constructor or assignment operator
    Engine(Engine& other) = delete;
    void operator=(Engine& other) = delete;

    // Static function for getting the current instance of the engine
    static std::shared_ptr<Engine> GetInstance();

    // Member functions
    bool Init();
    void Update(float dt);
    void Shutdown();

    // Getters and Setters
    [[nodiscard]] inline float GetDT() const { return deltaTime_; }
    [[nodiscard]] inline bool IsRunning() const { return isRunning_; }

private:
    // Static instance of the engine
    static std::shared_ptr<Engine> instance_;

    float deltaTime_; // The current delta time
    bool isRunning_;  // Flag for if the engine is running or not
    float lifeTimer_; // How long the engine has been alive for in seconds

    // Graphics Engine instance
    std::shared_ptr<GfxEngine> gfxEngine_;

    // Input management
    InputManager inputManager_;

};

#endif
