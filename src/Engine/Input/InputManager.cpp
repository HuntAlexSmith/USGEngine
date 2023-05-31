//*****************************************************************************
//  Filename: InputManager.cpp
//  Author:   Hunter Smith
//  Date:     05/31/2023
//  Description:
//      Implementation of the InputManager
//*****************************************************************************

#include "InputManager.h"

InputManager::InputManager() :
    inputMap_()
    , sdlToUsgMap_()
    , quit_(false)
{
    // Escape key
    sdlToUsgMap_[SDLK_ESCAPE] = USGKey::ESC;

    // Number Keys
    for(int i = 0; i < 10; ++i) {
        sdlToUsgMap_[SDLK_0+i] = static_cast<USGKey>(USGKey::Key0 + i);
    }

    // Letter Keys
    for(int i = 0; i < 26; ++i) {
        sdlToUsgMap_[SDLK_a+i] = static_cast<USGKey>(USGKey::A + i);
    }

    // Function Keys
    for(int i = 0; i < 12; ++i) {
        sdlToUsgMap_[SDLK_F1+i] = static_cast<USGKey>(USGKey::F1 + i);
    }

    // Arrow Keys
    for(int i = 0; i < 4; ++i) {
        sdlToUsgMap_[SDLK_RIGHT + i] = static_cast<USGKey>(USGKey::RightArrow + i);
    }

    // Add all USG keys to the status map
    for(int i = 0; i < USGKey::KeyCount; ++i) {
        inputMap_[static_cast<USGKey>(USGKey::ESC + i)] = KeyState::None;
    }
}

InputManager::~InputManager() {
    // May not be needed, but will leave here just in case
}

void InputManager::Update(const GfxEngine& gfxEngine) {
    if(!gfxEngine.IsRunning()) {
        // Engine is not running, no input to gather
        return;
    }

    // Otherwise, time to do SDL stuff
    // Remember to update all the current keys for down and none
    UpdateKeys();

    SDL_Event curEvent;
    while(SDL_PollEvent(&curEvent)) {
        switch(curEvent.type) {
            case SDL_KEYDOWN:
                ProcessKeyDown(curEvent.key.keysym.sym);
                break;
            case SDL_KEYUP:
                ProcessKeyUp(curEvent.key.keysym.sym);
                break;
            case SDL_QUIT:
                quit_ = true;
                break;
        }
    }
}

bool InputManager::KeyIs(USGKey key, KeyState state) {
    // Make sure key is valid
    auto result = inputMap_.find(key);
    if(result == inputMap_.end())
        return false;

    // Key is valid, check state
    return (result->second == state);
}

void InputManager::UpdateKeys() {
    // Iterate over all keys in map and check for triggered or release to update
    for(auto& itr : inputMap_) {
        // Triggered last frame, update to being held down
        if(itr.second == KeyState::Triggered)
            itr.second = KeyState::Down;

        // Released last frame, update to being none
        else if(itr.second == KeyState::Released)
            itr.second = KeyState::None;
    }

    // Update quit to be false
    quit_ = false;
}

void InputManager::ProcessKeyDown(SDL_Keycode sdlKey) {
    // Check that key is valid
    auto result = sdlToUsgMap_.find(sdlKey);
    if(result == sdlToUsgMap_.end())
        return;

    // Key is valid, update as necessary
    inputMap_[result->second] = KeyState::Triggered;
}

void InputManager::ProcessKeyUp(SDL_Keycode sdlKey) {
    // Check that key is valid
    auto result = sdlToUsgMap_.find(sdlKey);
    if(result == sdlToUsgMap_.end())
        return;

    // Key is valid, update as necessary
    inputMap_[result->second] = KeyState::Released;
}
