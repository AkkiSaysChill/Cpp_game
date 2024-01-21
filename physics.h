#pragma once

class Physics {
public:
    Physics();

    void applyAcceleration(float acceleration);
    void applyFriction(float friction);
    void updatePosition(int& position, int minPosition, int maxPosition);

    // Add a public getter method for velocity
    float getVelocity() const;

private:
    float velocity;
};

