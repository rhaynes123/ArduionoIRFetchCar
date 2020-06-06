#include <Servo.h>
// ------------------------------Variables-----------------------------------
Servo LeftServo;
Servo RightServo;
const int FRONTIRSENSOR = 9;
const int LEFTIRSENSOR = 10;
const int RIGHTIRSENSOR = 11;
int FrontObstacle;


void setup() 
{
  // put your setup code here, to run once:
   pinMode(FRONTIRSENSOR, INPUT);
   pinMode(LEFTIRSENSOR, INPUT);
   pinMode(RIGHTIRSENSOR, INPUT);
   
   Serial.begin(9600);
   
   LeftServo.attach(8);
   RightServo.attach(7);

}

void loop() 
{
  // put your main code here, to run repeatedly:
  
  FrontObstacle = digitalRead(FRONTIRSENSOR);
  
  if(FrontObstacle == LOW)
  {
    adjustdirection();
  }
  else if(FrontObstacle == HIGH)
  {
   forward();
  }
  
  delay(100);

}
void adjustdirection()
{
  /*
   * Any value above 90 will cause a wheel to go in reverse
   * Any value below 90 will cause a wheel to go forward
   * 90 will stop a wheel
   */
    LeftServo.write(90);
    RightServo.write(90);
    Serial.println("STOP!");
    
    LeftServo.write(150);
    RightServo.write(150);
    Serial.println("Back Up!");
    
    LeftServo.write(80);
    RightServo.write(100);
    Serial.println("Turn Right!");
  
}
void forward()
{
    LeftServo.write(80); 
    RightServo.write(80);
    Serial.println("GO!");
}
