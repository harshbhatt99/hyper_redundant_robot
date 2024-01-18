#include <Wire.h>
#include  "define.h"
#define dc_servo11 0x19 //Left  
#define dc_servo12 0x2D //Right
#define dc_servo13 0x47 //Toph12
#define dc_servo14 0x0F //Down

#define dc_servo21 0x14  //Left 2
#define dc_servo22 0x4A //Right 2
#define dc_servo23 0x37 //Top 2
#define dc_servo24 0x1E //down 2
#define led 13

long CurPos;

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
  
char sread=Serial.read();
{
  switch( sread )
    {
      {
        // Individual Movement ................................................
        // Link 1.............................................................
   case 'a':
    MoveRel(dc_servo11, 50);
    //MoveRel(dc_servo4, 20);
    Serial.println("Link1 Forward Left");
   break;
   case 's':
    MoveRel(dc_servo12, 50);
    
   // MoveRel(dc_servo1, 20);
    Serial.println("Link1 Forward Right");
   break;
   case 'd':
    MoveRel(dc_servo13, 50);
    //MoveRel(dc_servo3, 20);
    Serial.println("Link1 Forward UP");
   break;
   case 'f':
    MoveRel(dc_servo14, 50);
   // MoveRel(dc_servo2, 20);
    Serial.println("Link1 Forward Down");
   break;
   case 'z':
    MoveRel(dc_servo11, -50);
    //MoveRel(dc_servo4, 20);
    Serial.println("Link1 Reverse Left");
   break;
   case 'x':
    MoveRel(dc_servo12, -50);
   // MoveRel(dc_servo1, 20);
    Serial.println("Link1 Reverse Right");
   break;
   case 'c':
    MoveRel(dc_servo13, -50);
    //MoveRel(dc_servo3, 20);
    Serial.println("Link1 Reverse Up");
   break;
   case 'v':
    MoveRel(dc_servo14, -50);
   // MoveRel(dc_servo2, 20);
    Serial.println("Link1 Reverse Down");
   break;
   
      // Link 2..................................................................
   case 'g':
    MoveRel(dc_servo21, 50);
    //MoveRel(dc_servo4, 20);
    Serial.println("Link2 Forward Left");
   break;
   case 'h':
    MoveRel(dc_servo22, 50);
   // MoveRel(dc_servo1, 20);
    Serial.println("Link2 Forward Right");
   break;
   case 'j':
    MoveRel(dc_servo23, 50);
    //MoveRel(dc_servo3, 20);
    Serial.println("Link2 Forward Up");
   break;
   case 'k':
    MoveRel(dc_servo24, 50);
   // MoveRel(dc_servo2, 20);
    Serial.println("Link2 Forward Down");
   break;
   case 'b':
   
    MoveRel(dc_servo21, -50);
    //MoveRel(dc_servo4, 20);
    Serial.println("Link2 Reverse Left");
   break;
   case 'n':
    MoveRel(dc_servo22, -50);
   // MoveRel(dc_servo1, 20);
    Serial.println("Link2 Reverse Right");
   break;
   case 'm':
    MoveRel(dc_servo23, -50);
    //MoveRel(dc_servo3, 20);
    Serial.println("Link2 Reverse Up");
   break;
   case 'l':
    
    MoveRel(dc_servo24, -50);
   // MoveRel(dc_servo2, 20);
    Serial.println("Link2 Reverse Down");
    break;

  // Combined Movement...........................................................................................
    
    case 'q':
    MoveRel(dc_servo11, 50);
    MoveRel(dc_servo12, -50);
    Serial.println("Motor RUN LR");
    break;
    case 'w':
    MoveRel(dc_servo12, 50);
    MoveRel(dc_servo11, -50);
    Serial.println("Motor RUN RL");
    break;
    case 'e':
    MoveRel(dc_servo13, 50);
    MoveRel(dc_servo14, -50);
    Serial.println("Motor RUN TB");
    break;
    case 'r':
    MoveRel(dc_servo14, 50);
    MoveRel(dc_servo13, -50);
    Serial.println("Motor RUN BT");
    break;
    
   case 't':
    MoveRel(dc_servo21, 50);
    MoveRel(dc_servo22, -50);
    Serial.println("Motor RUN LR");
   break;
   case 'y':
    MoveRel(dc_servo22, 50);
    MoveRel(dc_servo21, -50);
    Serial.println("Motor RUN RL");
   break;
   case 'u':
    MoveRel(dc_servo23, 50);
    MoveRel(dc_servo24, -50);
    Serial.println("Motor RUN TB");
   break;
   case 'i':
    MoveRel(dc_servo24, 50);
    MoveRel(dc_servo23, -50);
    Serial.println("Motor RUN BT");
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
  SpeedRun(dc_servo1,-255);
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
 }

