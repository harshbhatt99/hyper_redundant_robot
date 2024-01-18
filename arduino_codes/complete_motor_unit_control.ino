#include <Wire.h>
#include  "define.h"
#include <SoftwareSerial.h>
#define dc_servo11 0x7D //Top 1 q
#define dc_servo12 0x07 //Right 1 s
#define dc_servo13 0x01 //Bottom 1 a
#define dc_servo14 0x0F //Left 1 w

#define dc_servo21 0x1C // Top 2  e 
#define dc_servo22 0x1F //Right 2 f
#define dc_servo23 0x07 //Bottom 2 d
#define dc_servo24 0x2D //Left 2 r

#define dc_servo31 0x25 //Top 3
#define dc_servo32 0x67 //Right 3
#define dc_servo33 0x33 //Bottom 3
#define dc_servo34 0x4A //Left 3

#define dc_servo41 0x25 //Top 4
#define dc_servo42 0x67 //Right 4
#define dc_servo43 0x33 //Bottom 4
#define dc_servo44 0x4A //Left 4
#define led 13

long CurPos;
String sread;

void setup()
{

  Wire.begin(); // join i2c bus (address optional for master)
  Serial.begin(9600);    //Initiate serial port
  Serial.println("Motor Stopped");
  
  intmotor();
  pinMode(led, OUTPUT);    //Setup LED pin as output
  digitalWrite(led, 1);    //LED On
}
void loop()
{
Demo();
}
void Demo(void)
{
int count = 200; //Combined movement count
int cnt = 50; //Individual movement count
char sread = Serial.read();
{
  
  switch(sread)
    {
       
      {
        
//  // Combined Movement...........................................................................................
    
    case 'q':
    MoveRel(dc_servo11, count);
    MoveRel(dc_servo13, -count);
    Serial.println("Section-1 UP");
    break;
    case 'w':
    MoveRel(dc_servo14, count);
    MoveRel(dc_servo12, -count);
    Serial.println("Section-1 LEFT");
    break;
    case 'a':
    MoveRel(dc_servo13, count);
    MoveRel(dc_servo11, -count);
    Serial.println("Section-1 DOWN");
    break;
    case 's':
    MoveRel(dc_servo12, count);
    MoveRel(dc_servo14, -count);
    Serial.println("Section-1 RIGHT");
    break;

    case 'e':
    MoveRel(dc_servo21, count);
    MoveRel(dc_servo23, -count);
    Serial.println("Section-2 UP");
    break;
    case 'r':
    MoveRel(dc_servo24, count);
    MoveRel(dc_servo22, -count);
    Serial.println("Section-2 LEFT");
    break;
    case 'd':
    MoveRel(dc_servo23, count);
    MoveRel(dc_servo21, -count);
    Serial.println("Section-2 DOWN");
    break;
    case 'f':
    MoveRel(dc_servo22, count);
    MoveRel(dc_servo24, -count);
    Serial.println("Section-2 RIGHT");
    break;  
    case 't':
    MoveRel(dc_servo31, count);
    MoveRel(dc_servo33, -count);
    Serial.println("Section-3 UP");
    break;
    case 'y':
    MoveRel(dc_servo34, count);
    MoveRel(dc_servo32, -count);
    Serial.println("Section-3 LEFT");
    break;
    case 'g':
    MoveRel(dc_servo33, count);
    MoveRel(dc_servo31, -count);
    Serial.println("Section-3 DOWN");
    break;
    case 'h':
    MoveRel(dc_servo32, count);
    MoveRel(dc_servo34, -count);
    Serial.println("Section-3 RIGHT");
    break;
    
    case 'u':
    MoveRel(dc_servo41, count);
    MoveRel(dc_servo43, -count);
    Serial.println("Section-1 UP");
    break;
    case 'i':
    MoveRel(dc_servo44, count);
    MoveRel(dc_servo42, -count);
    Serial.println("Section-1 LEFT");
    break;
    case 'j':
    MoveRel(dc_servo43, count);
    MoveRel(dc_servo41, -count);
    Serial.println("Section-1 DOWN");
    break;
    case 'k':
    MoveRel(dc_servo42, count);
    MoveRel(dc_servo44, -count);
    Serial.println("Section-1 RIGHT");
    break;

    case 'z':
    MoveRel(dc_servo11, count);
    MoveRel(dc_servo12, count);
    MoveRel(dc_servo13, count);
    MoveRel(dc_servo14, count);
    Serial.println("Section-1 ALL pull");
    break;

    case 'x':
    MoveRel(dc_servo11, -count);
    MoveRel(dc_servo12, -count);
    MoveRel(dc_servo13, -count);
    MoveRel(dc_servo14, -count);
    Serial.println("Section-1 ALL release");
    break;
   
  default:
    break;
  }
  
}
}
}
/*//---------Speed Mode tesing
  Serial.println("Speed Control Mode");
  int i;
  SetDamping(dc_servo1,100);  
  Serial.println("Motor Running at Speed -255 Damping 100");
  SpeedRun(dc_servo1,-255);t
  t
  t
  
  delay(3000);
  digitalWrite(led, 0);
  Serial.println("Motor Running at Speed -255 Damping 100");
  SetDamping(dc_servo1,0);  
  for(i=-255;i<=255;i++)
  {
    SpeedRun(dc_servo1,i);
    Serial.println(i);
    delay(30);
  }
  digitalWrite(led, 1);
  SetDamping(dc_servo1,200);  
  SpeedRun(dc_servo1,0);
  Serial.println("Motor Running at Speed 0 Damping 200");
  delay(3000);
  digitalWrite(led, 0);
  SetDamping(dc_servo1,0);  
//----------Position Mode testing

  Serial.println("Position Mode, Set current position to 0");
  SetPos(dc_servo1,0);
  delay(3000);
  digitalWrite(led, 1);    //LED On
  Serial.println("Position Mode, Move half rotaiton : 900 steps");
  MoveAbs(dc_servo1, 900);
  delay(3000);
  Serial.println("Position Mode, Go to 0 Position");
  MoveAbs(dc_servo1, 0);
  delay(3000);
  Serial.println("Position Mode Relative Move, Go to +2000 Counts");
  MoveRel(dc_servo1, 2000);
  delay(500);
  Serial.println("Position Mode Relative Move, Go to +1000 Counts");
  MoveRel(dc_servo1, 1000);
  delay(500);
  Serial.println("Position Mode Relative Move, Go to +500 Counts");
  MoveRel(dc_servo1, 500);
  delay(500);
  Serial.println("Position Mode Relative Move, Go to -200 Counts");
  MoveRel(dc_servo1, -200);
  delay(500);
  Serial.println("Position Mode Absolute Move, Go to 0 Position");
  MoveAbs(dc_servo1, 0);
  Serial.println("End Program, Strating over...");
  delay(3000);
  digitalWrite(led, 0);
}*/
void intmotor()
{
  SetMaxSpeed(dc_servo11,250);
  SetMaxSpeed(dc_servo12,250);
  SetMaxSpeed(dc_servo13,250);
  SetMaxSpeed(dc_servo14,250);
  
  SetMaxSpeed(dc_servo21,250);
  SetMaxSpeed(dc_servo22,250);
  SetMaxSpeed(dc_servo23,250);
  SetMaxSpeed(dc_servo24,250);

  SetMaxSpeed(dc_servo31,250);
  SetMaxSpeed(dc_servo32,250);
  SetMaxSpeed(dc_servo33,250);
  SetMaxSpeed(dc_servo34,250);
  
  SetMaxSpeed(dc_servo41,250);
  SetMaxSpeed(dc_servo42,250);
  SetMaxSpeed(dc_servo43,250);
  SetMaxSpeed(dc_servo44,250);
 }

