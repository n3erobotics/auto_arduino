/*
  Motor.h - Library for simple DC Motor usage.
  Created by Ruben Capitao, 2 March 2014.
*/
#ifndef Motor_h
#define Motor_h

#define FORWARD 0
#define BACKWARD 1
#define MICROS_TO_FOWARD 1580
#define MICROS_TO_BACKWARD 1580

#include "Arduino.h"
#include "Servo.h

class Motor
{
  public:
    void attach(int pin1);
    void setSpeed(int dir, int speed);
  private:
    Servo _motor;
};

#endif
