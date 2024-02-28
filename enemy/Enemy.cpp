#include <iostream>
#include "Enemy.h"
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_mixer.h>
#include <utility>

Enemy::Enemy(float x, float y) : x(x), y(y), health(100.0f), play(false) {}

void Enemy::update() {
    if(health <= 0) {
        if (!play) {
            play = true;
            destory();
            renderEnabled = false; // Disable rendering
        } 
    }
}

void Enemy::render(SDL_Renderer* renderer) {
    // Render enemy graphics here
    if (renderEnabled) {
        filledCircleColor(renderer, static_cast<int>(x), static_cast<int>(y), static_cast<int>(radius), SDL_MapRGB(SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888), 255, 0, 0)); // Red circle
    }
}

float Enemy::getX() const {
    return x;
}

float Enemy::getY() const {
    return y;
}

float Enemy::getRadius() const {
    return radius;
}

float Enemy::getHealth() const {
    return health;
}

void Enemy::hit() {
    if (renderEnabled) {
        health -= 20;
        std::cout << "Enemy health: " << health << std::endl;
        // You can add more logic here to handle the enemy being hit
    }
}

Enemy& Enemy::operator=(const Enemy& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
        health = other.health;
        play = other.play;
    }
    return *this;
}

Enemy& Enemy::operator=(Enemy&& other) noexcept {
    if (this != &other) {
        x = std::exchange(other.x, 0.0f);
        y = std::exchange(other.y, 0.0f);
        health = std::exchange(other.health, 0.0f);
        play = std::exchange(other.play, false);
    }
    return *this;
}

void Enemy::destory() {
    Mix_Chunk* explode = Mix_LoadWAV("src/explode.wav");
    if (explode == nullptr) {
        std::cerr << "Failed to load explosion sound effect: " << Mix_GetError() << std::endl;
        return; // Exit early if sound effect loading fails
    }

    Mix_PlayChannel(-1, explode, 0);
    std::cout << "die" << std::endl;

    Mix_FreeChunk(explode); // Free memory allocated for the sound effect
}
