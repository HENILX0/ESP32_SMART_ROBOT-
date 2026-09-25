#include<ESP32Servo.h>
#include<ultrasonic.h>

Ultrasonic ultrasonic(33 , 32);
int distance ;

Servo servo1;
Servo1 servo2;

const int in1 = 15;
const int in2 = 2;
const int in3 = 4;
const int in4 = 5;

const int ena = 27;
const int enb = 26;

const int led = 18;


void forward()

{
  digitalWrite(in1 , 1);
  digitalWrite(in2 , 0);
  digitalWrite(in3 , 0);
  digitalWrite(in4 , 1);

  analogWrite(ena , 128);
  analogWrite(enb , 128);

  Serial.println("FORWARD");
  delay(500);
}

void right()

{
  digitalWrite(in1 , 1);
  digitalWrite(in2 , 0);
  digitalWrite(in3 , 1);
  digitalWrite(in4 , 0);

  analogWrite(ena , 128);
  analogWrite(enb , 128);

  Serial.println("RIGHT");
  delay(500);
}

void left()

{
  digitalWrite(in1 , 0);
  digitalWrite(in2 , 1);
  digitalWrite(in3 , 0);
  digitalWrite(in4 , 1);

  analogWrite(ena , 128);
  analogWrite(enb , 128);

  Serial.println("LEFT");
  delay(500);
}

void stop()

{
  digitalWrite(in1 , 0);
  digitalWrite(in2 , 0);
  digitalWrite(in3 , 0);
  digitalWrite(in4 , 0);

  analogWrite(ena , 128);
  analogWrite(enb , 128);

  Serial.println("STOP");
  delay(500);
}

void scanning()
{
  for(int servo = 0 ; servo 90 ; servo+= 2)
  {
    distance = ultrasonic.read();
    servo1.write(servo)
  }
}

void setup(){

  Serial.begin(115200);

  pinMode(in1  , OUTPUT);
  pinMode(in2 , OUTPUT);
  pinMode(in3  , OUTPUT);
  pinMode(in4  , OUTPUT);
  pinMode(ena  , OUTPUT);
  pinMode(enb  , OUTPUT);

  pinMode(led  , OUTPUT);

  servo1.attach(12);
  servo2.attach(14);

}

void loop()
{
  
  scanning();
  
  if(distance <8 )
  {
    scanning();
    break;

    right();
    delay(1000);
    stop();
    delay(1000);
    forward();
    if(distance <=2)
    {
      servo2.write(180);
    }

  }


   if(distance <8 )
  {
    scanning();
    break;

    left();
    delay(1000);
    stop();
    delay(1000);
    forward();
    if(distance <=2)
    {
      servo2.write(180);
    }

  }
}