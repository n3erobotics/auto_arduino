#include <Servo.h>
#include "Motor.h"
#include "Car.h"
#include "Rgb.h"

#define MAX_CHAR 6 

Car car;

boolean led_status = false;
int rgb_color;
int value, rgb_value;

char dev;
char dir;

unsigned long time;

int myparseInt(){
  char buffer[MAX_CHAR], tmp;
  for(int i=0; i<MAX_CHAR; i++){
    tmp=Serial.read();
    buffer[i]=tmp;
  }
  return atoi(buffer);
}
void setup(){
  Serial.begin(115200);
  //Serial.println("Iniciar");
  car.attachMotor(6,5);
  car.attachServo(9);
  car.attachRGB(3,10,11);
}

void loop(){
  if (millis() > time){
    if (rgb_value == 0){
      car.setRGB(OFF);
      led_status = false; 
    }else{
      if (led_status == true){
        car.setRGB(OFF);
      }else{
        car.setRGB(rgb_color);
        rgb_value--;
      }
      time = millis()+1000;
      
      led_status = !led_status;
    }
    
  }
  
  if(Serial.available()){
    delay(10);
    dev=Serial.read();
    dir=Serial.read();
    value=Serial.parseInt();
    //Serial.print(dev);
    //Serial.print(" "); 
    //Serial.print(dir);
    //Serial.print(" ");
    //Serial.println(value);
    if(dev=='m'){
      if(dir=='b'){
        car.setSpeed(BACKWARD, value);
      }else{
        car.setSpeed(FORWARD, value);
      }
    }else if (dev == 's'){
      if(dir=='r'){
        car.turn(RIGHT, value);
      }else{
        car.turn(LEFT,value);
      }
    }else if(dev == 'l'){
      if(dir=='o'){
        rgb_color = OFF;
        //Serial.println("O");
      }else if(dir=='r'){
        rgb_color = RED;
        //Serial.println("R");
      }else if(dir == 'g'){
        rgb_color = GREEN;
        //Serial.println("G");
      }else if(dir == 'b'){
        rgb_color = BLUE;
        //Serial.println("B");
      }
      rgb_value = value;
      car.setRGB(rgb_color);
      time = millis()+1000;
      rgb_value--;
      led_status = true;
    }
  }
}
