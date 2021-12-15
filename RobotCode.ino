#include <string.h>

//front ultrasonic sensor
#define echoPinFront 2 
#define trigPinFront 3 

//right ultrasonic sensor

#define echoPinRight 4
#define trigPinRight 5

//left ultrasonic sensor

#define echoPinLeft 6
#define trigPinLeft 7

//Functions Prototypes
bool ObjectInFront();
bool ObjectInRight();
bool ObjectInLeft();
bool TestStart();
void Move();
void Rotate(String Direction);



long durationF;//F for Front
long durationR;//R for Right
long durationL;//L for Left
int distanceF;//F for Front
int distanceR;//R for Right
int distanceL;//L for Left

bool ObjectInFront()
{
  digitalWrite(trigPinFront, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinFront, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinFront, LOW);
  durationF = pulseIn(echoPinFront, HIGH);
  distanceF = durationF * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  if(distanceF<11)
  {
    return true;
  }
  return false;  
}
bool ObjectInRight()
{
  digitalWrite(trigPinRight, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinRight, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinRight, LOW);
  durationR = pulseIn(echoPinRight, HIGH);
  distanceR = durationR * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  if(distanceR<11)
  {
    return true;
  }  
  return false;
}
bool ObjectInLeft()
{
  digitalWrite(trigPinLeft, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinLeft, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinLeft, LOW);
  durationL = pulseIn(echoPinLeft, HIGH);
  distanceL = durationL * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  if(distanceL<11)
  {
    return true;
  }  
  return false;
}



void setup() 
{
  pinMode(13,OUTPUT);   //left motors forward
  pinMode(12,OUTPUT);   //left motors reverse
  pinMode(11,OUTPUT);   //right motors forward
  pinMode(10,OUTPUT);   //right motors reverse
  pinMode(trigPinFront, OUTPUT); 
  pinMode(echoPinFront, INPUT);
  pinMode(trigPinRight, OUTPUT); 
  pinMode(echoPinRight, INPUT);
  pinMode(trigPinLeft, OUTPUT); 
  pinMode(echoPinLeft, INPUT);
  Serial.begin(9600);  
}
bool TestStart()
{
  if(!ObjectInFront())
  {
    Move();
  }
}
void Move()
{
  digitalWrite(13,HIGH);
  digitalWrite(11,HIGH);
  delay(1.5);
  digitalWrite(13,LOW);
  digitalWrite(11,LOW);
}
void Rotate(String Direction)
{
  if(Direction=="Right")
  {
    digitalWrite(13,HIGH);
    delay(2); 
    digitalWrite(13,LOW);
}
  if(Direction=="Left")
  {
    digitalWrite(11,HIGH);
    delay(2);
    digitalWrite(11,LOW);
  }  
}



void loop() 
{
  if(ObjectInFront())
  {  
    if(ObjectInRight())
    {
      if(ObjectInLeft())
      {
        //rotate robot 180
      }
      else
      {
        //rotate robot -90 degres
      }
    }
    else
    {
      Rotate("Right");
    }

  }
  else
  {
    Move();    
  }  
}
