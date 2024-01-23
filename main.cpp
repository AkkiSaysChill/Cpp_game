#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "physics.h"
#include <iostream>
#include <cmath>
#include <chrono>
#include <thread>


const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int CIRCLE_RADIUS = 20;
const float GRAVITY = 0.5f;
const float JUMP_VELOCITY = -10.0f;  // Negative velocity for jumping
const float MOVEMENT_SPEED = 5.0f;    // Adjust this value based on your preference

void renderFillCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius, SDL_Color color) {
    filledCircleColor(renderer, centerX, centerY, radius, SDL_MapRGB(SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888), color.r, color.g, color.b));
}

int WinMain() {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Event e;
    bool quit = false;
    bool isJumping = false;

    float circleX = SCREEN_WIDTH / 2.0f;
    float circleY = SCREEN_HEIGHT - CIRCLE_RADIUS;  // Set the initial position to the bottom

    Physics physics;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_LEFT:
                        // Set constant leftward velocity
                        physics.setVelocityX(-MOVEMENT_SPEED);
                      break;
                    case SDLK_RIGHT:
                         // Set constant rightward velocity
                        physics.setVelocityX(MOVEMENT_SPEED);
                        break;
                    case SDLK_SPACE:
                        std::cout << "Jumping! Y position: " << circleY << std::endl;
                        // Start jumping only when on the bottom
                        if (!isJumping && circleY == 560) {
                            physics.setVelocityY(JUMP_VELOCITY);
                            isJumping = true;
                            std::cout << "Jumping! Y position: " << circleY << std::endl; // Debugging print
                        }else {
                            isJumping = false;
                        }
                        break;
                }
            }
            // Reset velocity when the key is released
            else if (e.type == SDL_KEYUP) {
                switch (e.key.keysym.sym) {
                    case SDLK_LEFT:
                    case SDLK_RIGHT:
                    physics.setVelocityX(0.0f);
                    break;
                }
            }   
        }


        // Update physics and position
        physics.applyAcceleration(0.0f, GRAVITY);
        physics.updatePosition(circleX, circleY, CIRCLE_RADIUS, SCREEN_WIDTH - CIRCLE_RADIUS, CIRCLE_RADIUS, SCREEN_HEIGHT - CIRCLE_RADIUS, CIRCLE_RADIUS);

        // Check if the circle is on the ground
        if (circleY >= SCREEN_HEIGHT - CIRCLE_RADIUS) {
            isJumping = false;
            circleY = SCREEN_HEIGHT - CIRCLE_RADIUS;
            physics.resetVelocityY();
        }

        // Clear the renderer
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Render the filled circle using SDL_gfx
        renderFillCircle(renderer, static_cast<int>(circleX), static_cast<int>(circleY), CIRCLE_RADIUS, {255, 255, 255}); // White color

        // Present the renderer
        SDL_RenderPresent(renderer);

        // Frame rate control
        std::this_thread::sleep_for(std::chrono::milliseconds(16));  // Cap the frame rate to approximately 60 FPS
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
