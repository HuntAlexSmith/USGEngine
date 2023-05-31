//*****************************************************************************
//  Filename: InputManager.h
//  Author:   Hunter Smith
//  Date:     05/31/2023
//  Description:
//      Class handles input incoming from SDL and provides polling for event
//      results.
//*****************************************************************************

#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <unordered_map>
#include <SDL2/SDL.h>
#include "../../Graphics/GfxEngine.h"
#include "InputMap.h"

enum KeyState {
    None,
    Triggered,
    Down,
    Released
};

typedef std::unordered_map<USGKey, KeyState> InputMap;
typedef std::unordered_map<SDL_Keycode, USGKey> SDLToUSGMap;

class InputManager {
public:
    // Ctor and Dtor
    InputManager();
    ~InputManager();

    // Member functions
    void Update(const GfxEngine& gfxEngine);
    bool KeyIs(USGKey key, KeyState state);

    // Inline getter
    inline bool QuitTriggered() const { return quit_; }

private:

    // Helper function for updating keys
    void UpdateKeys();
    void ProcessKeyDown(SDL_Keycode sdlKey);
    void ProcessKeyUp(SDL_Keycode sdlKey);

    InputMap inputMap_;
    SDLToUSGMap sdlToUsgMap_;
    bool quit_;

};

#endif
