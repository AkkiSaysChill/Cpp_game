#include "physics.h"
#include <algorithm>

Physics::Physics() : velocity(0.0f) {}

void Physics::applyAcceleration(float acceleration) {
    velocity += acceleration;
}

void Physics::applyFriction(float friction) {
    velocity *= (1.0f - friction);
}

void Physics::updatePosition(int& position, int minPosition, int maxPosition) {
    position += static_cast<int>(velocity);
    position = std::max(position, minPosition);
    position = std::min(position, maxPosition);
}

// Implement the getter method for velocity
float Physics::getVelocity() const {
    return velocity;
}

