#ifndef ENEMY_H
#define ENEMY_H

#include <SDL2/SDL.h>

class Enemy {
public:
    Enemy(float x, float y);

    void update();
    void render(SDL_Renderer* renderer);

private:
    float x, y;
};

#endif // ENEMY_H

