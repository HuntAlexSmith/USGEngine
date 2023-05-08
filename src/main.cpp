#include <iostream>
#include <SDL2/SDL.h>
#include <glad/glad.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;

int main(int argc, char* argv[]) {
    // Test Window
    SDL_Window* window = nullptr;

    // Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Window did not initialize. SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Specify OpenGL version stuff
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    // Create the window
    window = SDL_CreateWindow("Getting Started", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if(window == nullptr) {
        std::cout << "Window failed to be created. SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create OpenGL Context for Window
    SDL_GLContext context;
    context = SDL_GL_CreateContext(window);

    // Load OpenGL using GLAD
    gladLoadGLLoader(SDL_GL_GetProcAddress);

    // Set up viewport with OpenGL
    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    SDL_Event e;
    bool quit = false;
    while(!quit) {
        while(SDL_PollEvent(&e)) {
            if(e.type == SDL_QUIT)
                quit = true;
        }
        glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
        SDL_GL_SwapWindow(window);
    }

    // Remember to destroy the Window
    SDL_DestroyWindow(window);

    // Quit the SDL subsystem
    SDL_Quit();

    std::cout << "Exited Successfully!" << std::endl;

    return 0;
}
