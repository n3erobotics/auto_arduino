/*
  Car.cpp - Library for a simple car usage.
  Created by Ruben Capitao, 2 March 2014.
*/

#include "Arduino.h"
#include "Car.h"

volatile unsigned long time_before;
volatile unsigned long time_now;

volatile boolean state=LOW;

static void sensorISR()
{
	if(digitalRead(A0)!=state){
		state=!state;
		
	}
  	
}

void Car::attachMotor(int8_t pin)
{
	_motor.attach(pin);
}
	
void Car::attachServo(int8_t pin){
	_servo.attach(pin);
}

void Car::setSpeed(int direction, int speed)
{
	_motor.setSpeed(direction, speed);
}

void Car::turn(int diretion, int degrees)
{
	if(degrees>65)
		degrees=65;
	if(diretion==RIGHT)
		_servo.write(90+degrees);
	else
		_servo.write(90-degrees);
}

void Car::attachSensor(int8_t pin)
{
	digitalWrite (2, HIGH);  // pull-up
	attachInterrupt(pin, reinterpret_cast<void (*)()>(&sensorISR), RISING);
}

void Car::attachRGB(int8_t pinR, int8_t pinG, int8_t pinB){
	_rgb.attach(pinR, pinG, pinB);
}

void Car::setRGB(int color){
	_rgb.setColor(color);
}


