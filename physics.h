#ifndef PHYSICS_H
#define PHYSICS_H

class Physics {
private:
    float velocityX;
    float velocityY;
    float posX;
    float posY;

public:
    Physics();

    float getVelocityX() const;
    float getVelocityY() const;

    void setVelocityX(float vx);
    void setVelocityY(float vy);

    void resetVelocityX();
    void resetVelocityY();

    void applyAcceleration(float accelX, float accelY);
    void updatePosition(float& posX, float& posY, float radius, float maxX, float minX, float maxY, float minY);
};

#endif // PHYSICS_H

