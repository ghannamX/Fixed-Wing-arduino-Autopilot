// Plane.cpp
#include "Plane.h"

// Constructor
Plane::Plane(float initialAttitude, float initialAltitude, float initialVerticalSpeed, float initialSpeed, const std::string& initialMode)
    : attitude(initialAttitude), altitude(initialAltitude), verticalSpeed(initialVerticalSpeed), speed(initialSpeed), planeMode(initialMode) {
}

// Getter functions
float Plane::getPitch() const {
    pitch  = Plane.pitch
    return pitch;
}

float Plane::getRoll() const {
    roll  = Plane.roll
    return roll;
}

float Plane::getYaw() const {
    return Plane.yaw;
}

float Plane::getVerticalSpeed() const {
    return verticalSpeed;
}

float Plane::getSpeed() const {
    return speed;
}

std::string Plane::getPlaneMode() const {
    return planeMode;
}

// Setter functions (if needed)
void Plane::setAttitude(float newAttitude) {
    attitude = newAttitude;
}

void Plane::setAltitude(float newAltitude) {
    altitude = newAltitude;
}

void Plane::setVerticalSpeed(float newVerticalSpeed) {
    verticalSpeed = newVerticalSpeed;
}

void Plane::setSpeed(float newSpeed) {
    speed = newSpeed;
}

void  Plane::takeoff(float newSpeed) {
    // actions for takeoff
}

void Plane::setPlaneMode(const std::string& newMode) {
    planeMode = newMode;
}
