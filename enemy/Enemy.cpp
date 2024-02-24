#include <iostream>
#include "Enemy.h"
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_mixer.h>

Enemy::Enemy(float x, float y) : x(x), y(y) {}

void Enemy::update() {
    if(health <= -100) {
        
        destory();
    }
}

void Enemy::render(SDL_Renderer* renderer) {
    // Render enemy graphics here
    filledCircleColor(renderer, static_cast<int>(x), static_cast<int>(y), static_cast<int>(radius), SDL_MapRGB(SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888), 255, 0, 0)); // Red circle
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
    health -= 20;
    std::cout << "Enemy health: " << health << std::endl;
    // You can add more logic here to handle the enemy being hit
}

void Enemy::destory() {
    

    Mix_Chunk* explode = Mix_LoadWAV("src/explode.wav");
    Mix_PlayChannel(-1, explode, 0);
    std::cout << "die" << std::endl;
}

