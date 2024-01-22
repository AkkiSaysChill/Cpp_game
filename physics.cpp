
#include "physics.h"
#include <cmath>

Physics::Physics() : velocityX(0.0f), velocityY(0.0f), posX(0.0f), posY(0.0f) {}

float Physics::getVelocityX() const {
    return velocityX;
}

float Physics::getVelocityY() const {
    return velocityY;
}

void Physics::setVelocityX(float vx) {
    velocityX = vx;
}

void Physics::setVelocityY(float vy) {
    velocityY = vy;
}

void Physics::resetVelocityX() {
    velocityX = 0.0f;
}

void Physics::resetVelocityY() {
    velocityY = 0.0f;
}

void Physics::applyAcceleration(float accelX, float accelY) {
    velocityX += accelX;
    velocityY += accelY;
}

void Physics::updatePosition(float& posX, float& posY, float radius, float maxX, float minX, float maxY, float minY) {
    posX += velocityX;
    posY += velocityY;

    // Restrict the position within the boundaries
    if (posX + radius > maxX) {
        posX = maxX - radius;
        resetVelocityX();  // Stop horizontal movement when hitting the right boundary
    }

    if (posX - radius < minX) {
        posX = minX + radius;
        resetVelocityX();  // Stop horizontal movement when hitting the left boundary
    }

    if (posY + radius > maxY) {
        posY = maxY - radius;
        resetVelocityY();  // Stop vertical movement when hitting the bottom boundary
    }

    if (posY - radius < minY) {
        posY = minY + radius;
        resetVelocityY();  // Stop vertical movement when hitting the top boundary
    }
}

