// Plane.h
#ifndef PLANE_H
#define PLANE_H

#include <string>

class Plane {
private:
    float pitch; // Quaternion based kalman filter , already implemented in MPU6050.h library.
    float roll; // same as phpitch angle.
    float yaw; // same as roll.
    float altitude; // Measured with 2D kalman filter, by fusing data from barometer BMP280 and Vz (ACCZ).
    float verticalSpeed; // same as a bove where state vector is x= [z z_dot].
    float speed; // Ground speed, vitesse au sol.
    std::string planeMode; // Stop,takeoff,Climbing, Cruise, Landing.

public:
    // Constructor of plane objet
    Plane(float initialpitch, float initialroll,float initialyaw,float initialAltitude, float initialVz, float initialSpeed, const std::string& initialMode);

    // Getter functions
    float getpitch() const;
    float getroll() const;
    float getyaw() const;
    float getAltitude() const;
    float getVerticalSpeed() const;
    float getSpeed() const;
    std::string getPlaneMode() const;

    // Setter functions (if needed)
    void setAttitude(float newAttitude);
    void setAltitude(float newAltitude);
    void setVerticalSpeed(float newVerticalSpeed);
    void setSpeed(float newSpeed);
    void setPlaneMode(const std::string& newMode);

    // Methods required to perform missions
/*1. Takeoff
  set d_th = 100% and d_e = x deg (max elevator deflection). 
  implement a PD controller of d_e to maintain a constant climbing rate of 40 m/10s.
  Note : Pay attention as max deflexion of elevator or low throttle can cause the plane to enter an aerodynamic stall.
  */
    void takeoff();
// how much thottle THR is needed ?
    void climbToAltitude(float newAttitude);
// control elevator servo to pitch down . reduce THR
    void descendToAltitude(float newAltitude);
// Refer to Plane\Test for a block diagram of this. u =(d_th d_e) et y = (z Vz q theta) q measured by gyro. all good
    void HoldAltitude(float newAltitude);
/*1. reduce d_th and bring the nose down to prevent stall.
2. deploy Flaps (servoFlaps.write(30 deg) ) 
3. Lateral control .
*/
    void land();
/* flare . when plane reachs to z_min= 10m, do the following:
1. For precision purposes, use RadioAltimeter ( precision qlqs mm) to measure height and no longer Vz x z estimated by KF .
2. when z=2m : 
    hold a 10 deg pitch .
    bring throttle to idle position (0%).
*/
    void flare(Plane plane, float minH)
};

#endif // PLANE_H
