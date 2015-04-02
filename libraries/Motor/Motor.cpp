/*
  Motor.cpp - Library for simple DC Motor usage.
  Created by Ruben Capitao, 2 March 2014.
*/

#include "Arduino.h"
#include "Motor.h"

void Motor::attach(int pin)
{
  _motor.attach(pin);
}

void Motor::setSpeed(int dir, int speed)
{
  if(dir){
    myservo.writeMicroseconds(MICROS_TO_FORWARD+speed);
  }else{
    myservo.writeMicroseconds(MICROS_TO_BACKWARD+speed);
  }
}
