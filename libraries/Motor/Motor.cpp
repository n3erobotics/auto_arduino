/*
  Motor.cpp - Library for simple DC Motor usage.
  Created by Ruben Capitao, 2 March 2014.
*/

#include "Motor.h"

void Motor::attach(int pin1)
{
  _motor.attach(pin1);
}

void Motor::setSpeed(int dir, int speed)
{
  if(dir){
    myservo.writeMicroseconds(MICROS_TO_FORWARD+speed);
  }else{
    myservo.writeMicroseconds(MICROS_TO_BACKWARD+speed);
  }
}
