#ifndef ENEMY_H
#define ENEMY_H

#include <SDL2/SDL.h>

class Enemy {
public:
    Enemy(float x, float y);

    void update();
    void render(SDL_Renderer* renderer);
    float getX() const;
    float getY() const;
    float getRadius() const;
    float getHealth() const;
    void hit(); // Function to handle when enemy is hit by a bullet
    void destory();

private:
    float x, y;
    const float radius = 20.0f; // Radius of the enemy
    float health;
};

#endif // ENEMY_H
