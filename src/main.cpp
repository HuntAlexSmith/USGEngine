#include <SDL2/SDL.h>      // SDL main
#include "Engine/Engine.h" // Engine
#include "Clock.h"         // Clock

int main(int argc, char* argv[]) {
    // First instance of engine
    std::shared_ptr<Engine> engine = Engine::GetInstance();

    // Initialize the engine
    if(!engine->Init())
        return -1; // Something failed, stop

    // Create clock for keeping track of delta time
    Clock engineClock;

    // Update the engine as it is running
    while(engine->IsRunning()) {
        engineClock.Tick();
        engine->Update(engineClock.GetDelta());
    }

    // Shut the engine down
    engine->Shutdown();

    // Return 0
    return 0;
}
