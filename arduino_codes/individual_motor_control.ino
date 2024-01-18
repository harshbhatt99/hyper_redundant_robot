#include <Wire.h>
#include  "define.h"
//#include <SoftwareSerial.h>
#define dc_servo11 0x7D //Top 1 done '1''q'
#define dc_servo12 0x07 //Right 1 done  '2''w'.... changed
#define dc_servo13 0x075
//Bottom 1 done '3''e'
#define dc_servo14 0x08 //Left 1 done '4''r'

#define dc_servo21 0x1C // Top 2 done '5''t'
#define dc_servo22 0x1F // initially 1F //Right 2 done'6''y'
#define dc_servo23 0x07 //Bottom 2 done '7''u'....... changed
#define dc_servo24 0x2D //Left 2 done '8''i'

#define dc_servo31 0x0D //Top 3 'a''z'done but not running
#define dc_servo32 0x08 //Right 3 's''x'done ... changed
#define dc_servo33 0x2D //Bottom 3 done 'd''c'
#define dc_servo34 0x1B //Left 3 done 'f''v'

#define dc_servo41 0x1E //Top 4 done 'g''b'
#define dc_servo42 0x20 //Right 4 done'h''n'
#define dc_servo43 0x0F // iniitally 0F //Bottom 4 done'j''m'
#define dc_servo44 0x47 //Left 4 done'k''l'
#define led 13

long CurPos;
String sread;

void setup()
{

  Wire.begin(); // join i2c bus (address optional for master)
  Serial.begin(9600);    //Initiate serial port
  Serial.println("Motor Stopped");
  
//  intmotor();
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
int cnt = 200; //Individual movement count
char sread = Serial.read();
{
  

  switch(sread)
    {
       
      {
        // Individual Movement ................................................
        // Section 1.............................................................
   case '1':
    MoveRel(dc_servo11, cnt);
    Serial.println("Link1 Forward Top");
   break;
   
   case '2':
    MoveRel(dc_servo12, cnt);
    Serial.println("Link1 Forward Right");
   break;
   
   case '3':
    MoveRel(dc_servo13, cnt);
    Serial.println("Link1 Forward Bottom");
   break;
   
   case '4':
    MoveRel(dc_servo14, cnt);
    Serial.println("Link1 Forward Left");
   break;
   
   case 'q':
    MoveRel(dc_servo11, -cnt);
    Serial.println("Link1 Reverse Top");
   break;
   
   case 'w':
    MoveRel(dc_servo12, -cnt);
    Serial.println("Link1 Reverse Right");
   break;
   
   case 'e':
    MoveRel(dc_servo13, -cnt);
    Serial.println("Link1 Reverse Bottom");
   break;
   
   case 'r':
    MoveRel(dc_servo14, -cnt);
    Serial.println("Link1 Reverse Left");
   break;
   
      // Section 2..................................................................
   case '5':
    MoveRel(dc_servo21, cnt);
    Serial.println("Link2 Forward Top");
   break;
   
   case '6':
    MoveRel(dc_servo22, cnt);
    Serial.println("Link2 Forward Right");
   break;
   
   case '7':
    MoveRel(dc_servo23, cnt);
    Serial.println("Link2 Forward Bottom");
   break;
   
   case '8':
    MoveRel(dc_servo24, cnt);
    Serial.println("Link2 Forward Left");
   break;
   
   case 't':
    MoveRel(dc_servo21, -cnt);
    Serial.println("Link2 Reverse Left");
   break;
   
   case 'y':
    MoveRel(dc_servo22, -cnt);
    Serial.println("Link2 Reverse Right");
   break;
   
   case 'u':
    MoveRel(dc_servo23, -cnt);
    Serial.println("Link2 Reverse Bottom");
   break;
   
   case 'i': 
    MoveRel(dc_servo24, -cnt);
    Serial.println("Link2 Reverse Left");
    break;


      // Section 3..................................................................
   case 'a':
    MoveRel(dc_servo31, cnt);
    Serial.println("Link3 Forward Top");
   break;
   
   case 's':
    MoveRel(dc_servo32, cnt);
    Serial.println("Link3 Forward Right");
   break;
   
   case 'd':
    MoveRel(dc_servo33, cnt);
    Serial.println("Link3 Forward Bottom");
   break;
   
   case 'f':
    MoveRel(dc_servo34, cnt);
    Serial.println("Link3 Forward Left");
   break;
   
   case 'z':
   
    MoveRel(dc_servo31, -cnt);
    Serial.println("Link3 Reverse Top");
   break;
   
   case 'x':
    MoveRel(dc_servo32, -cnt);
    Serial.println("Link3 Reverse Right");
   break;
   
   case 'c':
    MoveRel(dc_servo33, -cnt);
    Serial.println("Link3 Reverse Bottom");
   break;
   
   case 'v':   
    MoveRel(dc_servo34, -cnt);
    Serial.println("Link3 Reverse Left");
    break;


      // Section 4..................................................................
   case 'g':
    MoveRel(dc_servo41, cnt);
    Serial.println("Link4 Forward Top");
   break;
   
   case 'h':
    MoveRel(dc_servo42, cnt);
    Serial.println("Link4 Forward Right");
   break;
   
   case 'j':
    MoveRel(dc_servo43, cnt);
    Serial.println("Link4 Forward Bottom");
   break;
   
   case 'k':
    MoveRel(dc_servo44, cnt);
    Serial.println("Link4 Forward Left");
   break;
   
   case 'b':
    MoveRel(dc_servo41, -cnt);
    Serial.println("Link4 Reverse Top");
   break;
   
   case 'n':
    MoveRel(dc_servo42, -cnt);
    Serial.println("Link4 Reverse Right");
   break;
   
   case 'm':
    MoveRel(dc_servo43, -cnt);
    Serial.println("Link4 Reverse Bottom");
   break;
   
   case 'l':
    MoveRel(dc_servo44, -cnt);
    Serial.println("Link4 Reverse Left");
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
//void intmotor()
//{
//  SetMaxSpeed(dc_servo11,250);
//  SetMaxSpeed(dc_servo12,250);
//  SetMaxSpeed(dc_servo13,250);
//  SetMaxSpeed(dc_servo14,250);
//  
//  SetMaxSpeed(dc_servo21,250);
//  SetMaxSpeed(dc_servo22,250);
//  SetMaxSpeed(dc_servo23,250);
//  SetMaxSpeed(dc_servo24,250);
//
//  SetMaxSpeed(dc_servo31,250);
//  SetMaxSpeed(dc_servo32,250);
//  SetMaxSpeed(dc_servo33,250);
//  SetMaxSpeed(dc_servo34,250);
//  
//  SetMaxSpeed(dc_servo41,250);
//  SetMaxSpeed(dc_servo42,250);
//  SetMaxSpeed(dc_servo43,250);
//  SetMaxSpeed(dc_servo44,250);
// }

