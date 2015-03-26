/*
  Car.h - Library for a simple car usage.
  Created by Ruben Capitao, 2 March 2014.
*/
#ifndef Car_h
#define Car_h

#define RIGHT 0
#define LEFT 1

#include "Arduino.h"
#include "Motor.h"
#include "Servo.h"
#include "Rgb.h"

class Car
{
	public:
		void attachMotor(int8_t pin1, int8_t pin2);	
		void attachServo(int8_t pin);
		void attachSensor(int8_t pin);
		void setSpeed(int direction, int speed);
		void turn(int diretion, int degrees);
        void attachRGB(int8_t pinR, int8_t pinG, int8_t pinB);
		void setRGB(int color);
	private:
		Motor _motor;
		Servo _servo;
        RGB _rgb;
};

#endif
