#ifndef ENEMY_H
#define ENEMY_H

#include <SDL2/SDL.h>

class Enemy {
public:
    Enemy(float x, float y);

    // Copy constructor
    Enemy(const Enemy& other) = default;

    // Move constructor
    Enemy(Enemy&& other) noexcept = default;

    // Move assignment operator
    Enemy& operator=(Enemy&& other) noexcept;
    Enemy& operator=(const Enemy& other);

    void update();
    void render(SDL_Renderer* renderer);
    float getX() const;
    float getY() const;
    float getRadius() const;
    float getHealth() const;
    void hit(); // Function to handle when enemy is hit by a bullet
    void destory();
    bool renderEnabled = true; // Flag to determine if rendering is enabled

private:
    float x, y;
    const float radius = 20.0f; // Radius of the enemy
    float health;
    bool play;
};

#endif // ENEMY_H

