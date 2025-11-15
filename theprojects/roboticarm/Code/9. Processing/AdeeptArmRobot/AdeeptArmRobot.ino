/***********************************************************
File name: AdeeptArmRobot.ino
Description:Control the robotic arm to grab objects through the upper
            computer interface written by Processing.
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2020/12/12
Released: 2025/11/14
Author: Rafa
***********************************************************/
#include <Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET     4
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET);
int servopin1 = 9;    //Define servo interface digital interface 9
int servopin2 = 6;    //Define servo interface digital interface 6
int servopin3 = 5;    //Define servo interface digital interface 5
int servopin4 = 3;    //Define servo interface digital interface 3
int servopin5 = 11;   //Define servo interface digital interface 11

int moveServoData;
int servo1Angle=90;
int servo2Angle=90;
int servo3Angle=90;
int servo4Angle=90;
int servo5Angle=90;
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
int angle = 90;        //Angle of rotation of the servo

boolean autoLock = false;
//boolean key_mouse_lock = false;
boolean closeLock = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(servopin1,OUTPUT);//Set the servo interface as the output interface
  pinMode(servopin2,OUTPUT);//Set the servo interface as the output interface
  pinMode(servopin3,OUTPUT);//Set the servo interface as the output interface
  pinMode(servopin4,OUTPUT);//Set the servo interface as the output interface
  pinMode(servopin5,OUTPUT);//Set the servo interface as the output interface
  Serial.begin(9600);
  servo1.attach(servopin1);
  servo2.attach(servopin2);
  servo3.attach(servopin3);
  servo4.attach(servopin4);
  servo5.attach(servopin5);
  servo1.write(90);
  servo2.write(90);
  servo3.write(90);
  servo4.write(90);
  servo5.write(105); 
  delay(20);
  //servo1Pulse(90);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextColor(WHITE);//Sets the font display color
  display.clearDisplay();//cls
  display.clearDisplay();
  //Set the font size
  display.setTextSize(2);
  //Set the display location
  display.setCursor(3,1);
  //String displayed
  display.print("IES Axati");
  display.setCursor(3,20);
  //String displayed
  display.print("Waiting...");
  //Began to show
  display.display();
}
void loop() {
  delay(20);
  do{
    moveServoData = Serial.read();
    if (moveServoData == 111 || moveServoData == 79) {//o O
      autoLock = false;
      closeLock=false;
      servo1Angle++;
      if(servo1Angle>=180){servo1Angle=180;}
      servo1.write(servo1Angle);
    }
    if (moveServoData == 112 || moveServoData == 80){//p
      autoLock = false;
      closeLock=false;
      servo1Angle--;
      if(servo1Angle<=0){servo1Angle=0;}
      servo1.write(servo1Angle);
    }
    if (moveServoData == 117 || moveServoData == 85) {//u
      autoLock = false;
      closeLock=false;
      servo2Angle++;
      if(servo2Angle>=180){servo2Angle=180;}
      servo2.write(servo2Angle);
    }
    if (moveServoData == 105 || moveServoData == 73) {//i
      autoLock = false;
      closeLock=false;
      servo2Angle--;
      if(servo2Angle<=0){servo2Angle=0;}
      servo2.write(servo2Angle);
    }
    if (moveServoData == 116 || moveServoData == 84) {//t
      autoLock = false;
      closeLock=false;
      servo3Angle++;
      if(servo3Angle>=180){servo3Angle=180;}
      servo3.write(servo3Angle);
    }
    if (moveServoData == 121 || moveServoData == 89) {//y
      autoLock = false;
      closeLock=false;
      servo3Angle--;
      if(servo3Angle<=0){servo3Angle=0;}
      servo3.write(servo3Angle);
    }
    
    if (moveServoData == 101 || moveServoData == 69) {//e
      autoLock = false;
      closeLock=false;
      servo4Angle++;
      if(servo4Angle>=180){servo4Angle=180;}
      servo4.write(servo4Angle);
    }
    if (moveServoData == 114 || moveServoData == 82) {//r
      autoLock = false;
      closeLock=false;
      servo4Angle--;
      if(servo4Angle<=0){servo4Angle=0;}
      servo4.write(servo4Angle);
    }
    if(moveServoData == 113 || moveServoData == 81) {//q 
      autoLock = false;
      closeLock=false;
      servo5Angle+=10;
      if(servo5Angle>=105){servo5Angle=105;}
      servo5.write(servo5Angle);
    }
    if(moveServoData == 119 || moveServoData == 87) {//w
      autoLock = false;
      closeLock=false;
      servo5Angle-=10;
      if(servo5Angle<=35){servo5Angle=35;}
      servo5.write(servo5Angle);
    } 
    if(moveServoData == 110 || moveServoData ==78){//n
      autoLock = true;
//      key_mouse_lock = false;
      closeLock=false;
    }
  }
  while(Serial.available()>0);
  if(moveServoData>0)
    displayInfo(moveServoData);
}

void displayInfo(int moveServoData){
  String text1,text2;

  display.clearDisplay();
  //Set the font size
  display.setTextSize(2);
  //Set the display location
  display.setCursor(3,1);
  //String displayed
  display.print("IES Axati");
  display.display();

  if (moveServoData == 111 || moveServoData == 79) {
    text1="Base";
    text2="left!";
  }else if(moveServoData == 112 || moveServoData == 80){
    text1="Base";
    text2="right!";
  }else if (moveServoData == 117 || moveServoData == 85) {
    text1="Shoulder";
    text2="opening!";
  }else if (moveServoData == 105 || moveServoData == 73) {
    text1="Shoulder";
    text2="closing!";
  }else if (moveServoData == 116 || moveServoData == 84) {
    text1="Elbow";
    text2="closing!";
  }else if (moveServoData == 121 || moveServoData == 89) {
    text1="Elbow";
    text2="opening!";
  }else if (moveServoData == 101 || moveServoData == 69) {
    text1="Rotate";
    text2="left!";
  }else if (moveServoData == 114 || moveServoData == 82) {
    text1="Rotate";
    text2="right!";
  }else if(moveServoData == 113 || moveServoData == 81) {
    text1="Gripper";
    text2="closing!";
  }else if(moveServoData == 119 || moveServoData == 87) {
    text1="Gripper";
    text2="opening!";
  }else if(moveServoData == 110 || moveServoData ==78){
  }

  display.setCursor(3,20);
  display.print(text1);
  display.setCursor(3,40);
  display.print(text2);

  display.display();
  //delay(1000);
  display.clearDisplay();
  //Set the font size
  display.setTextSize(2);
  //Set the display location
  display.setCursor(3,1);
  //String displayed
  display.print("IES Axati");
  display.setCursor(3,20);
  //String displayed
  display.print("Waiting...");
  //Began to show
  display.display();
}