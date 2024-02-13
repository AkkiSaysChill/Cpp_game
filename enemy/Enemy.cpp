#include "Enemy.h"
#include <SDL2/SDL2_gfxPrimitives.h>

Enemy::Enemy(float x, float y) : x(x), y(y) {}

void Enemy::update() {
    // Update enemy logic here
}

void Enemy::render(SDL_Renderer* renderer) {
    // Render enemy graphics here
    // Example:
    filledCircleColor(renderer, static_cast<int>(x), static_cast<int>(y), 20, SDL_MapRGB(SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888), 255, 0, 0)); // Red circle
}

