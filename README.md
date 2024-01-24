# Fixed-Wing-arduino-Autopilot
Implementation of an Arduino-based autopilot for aircraft control, featuring functionalities such as Auto-takeoff, Auto-landing, and Altitude-hold.
# Problem(s) and motivation
When flying an aircraft in the manual mode, the flight is less safe and hence subject to many undesirable behaviors suchs aerodynamic stall, a high bank angle or even changing route due to external pertubation such as change in wind speed and direction as demonstrated in video below. Another problem emerges when the pilot himself is not well-trained on the newly built model which was my case in the video.



https://github.com/ghannamX/Fixed-Wing-arduino-Autopilot/assets/154473723/bc8be17e-3ad6-4caa-be80-c3580b49cbb8

Here, I have mistakenly cut off the powers at that very moment when the plane needed its maximum thrust to take-off from the ground. Because I thought it will divert from the runway and hit the grass causing consequently damage to the propeller.




https://github.com/ghannamX/Fixed-Wing-arduino-Autopilot/assets/154473723/dec3edc7-b775-4b67-9c57-942879c4400d

On this windy day, the weather conditions affected significantly the route of the plane and diverted it to the opposite direction. I could have been quicker to respond by applying elevator up before crashing into the field.

Now that we have identified the issues with manual control, let us explore what Fly-By-Wire technology can bring to the table !

# Sensors
We need to determine the attitude of the aircraft (pitch, roll, yaw) as well as its altitude. For this purpose we will need an ultrasonic sensor, a barometer and an IMU (Inertial measurement unit). The latter allows us to determin orientation and when fused with barometeric readings, then we make a better estimation of altitude based on EKF (Extended Kalman Filter). Inspired by radar altimiter in real jets, the plane incroporates an ultrasonic sensor to measure precisely altitude near the ground to perform a smooth landing.
The picture below dipects the sensors :
![sensors](https://github.com/ghannamX/Fixed-Wing-arduino-Autopilot/assets/154473723/96c0836f-d268-40ad-bd49-258473981108)
