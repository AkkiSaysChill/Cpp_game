#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>


int WinMain(){
        // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow(
        "Moving Red Circle",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640,
        480,
        SDL_WINDOW_SHOWN
    );

    if (window == nullptr) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == nullptr) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Circle properties
    int circleX = 320; // Initial X position
    int circleY = 240; // Initial Y position
    int circleRadius = 20; // Circle radius
    Uint8 circleRed = 255; // Red color value

    // Main loop flag
    bool quit = false;

    // Event handler
    SDL_Event e;

    // Main loop
    while (!quit) {
        // Handle events on the queue
        while (SDL_PollEvent(&e) != 0) {
            // User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }

            // Handle key presses
            if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_LEFT:
                        // Move left and keep within window bounds
                        circleX = std::max(circleX - 10, circleRadius);
                        break;
                    case SDLK_RIGHT:
                        // Move right and keep within window bounds
                        circleX = std::min(circleX + 10, 640 - circleRadius);
                        break;
                }
            }
        }

        // Clear the screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw a filled red circle
        filledCircleRGBA(renderer, circleX, circleY, circleRadius, circleRed, 0, 0, 255);

        // Update the screen
        SDL_RenderPresent(renderer);

        // Introduce a delay to control the speed of movement
        SDL_Delay(10);
    }

    // Destroy window and renderer
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    // Quit SDL subsystems
    SDL_Quit();

    return 0;
}

