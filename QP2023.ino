#include <Servo.h>
#include <SoftwareSerial.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
int randTarget[] = {1,2,3,4,5,6}; // used to generate random targets
int target[7]; // used to read sensor data
int hit[7]; // used to check if target is hit, hit =1, not hit =0
int numTargets = 0; // tracks numner of targets user is using
String input;
unsigned long startMillis[7]; // start time when you hit target
unsigned long checkMillis[7]; // checks if target is swinging

const unsigned long reset = 4000;
void setup() {
  // initialize servos
  Serial.begin(9600);
  servo1.attach(13);
  servo1.write(90);
  servo2.attach(12);
  servo2.write(0);
  servo3.attach(11);
  servo3.write(90);
  servo4.attach(10);
  servo4.write(0);
  servo5.attach(9);
  servo5.write(90);
  servo6.attach(8);
  servo6.write(0);
  delay(2000); //give time for arduino to get ready
  for (int i = 0; i<8; i++) { // initialize starting values
    checkMillis[i] = 0;
    hit[i] = 0;
    startMillis[i] = 0;  
  }
  while(numTargets == 0) // if numTargets = 0 game is either paused or not up yet so keep looping to check when game starts
  {    
    event();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  game();
  restart();
}
void event() {
//reads data from Serial moniter, updates numTargets value if it changes
  if(Serial.available()!=0) {    
    input = Serial.readStringUntil('\n'); //read numtargets from txt file
    if (numTargets != input.toInt()) {
      numTargets = input.toInt(); //update if numTargets is changed
      if(numTargets == 1)
      {
        servo1.write(0);
        Serial.println(7);   
      }
      else if(numTargets == 2)
      {
        servo1.write(0);
        servo2.write(90);
        Serial.println(7);
        delay(100);
        Serial.println(8);
        delay(100);
      }
      else if(numTargets == 3)
      {
        servo1.write(0);
        servo2.write(90);
        servo3.write(0);
        Serial.println(7);
        delay(100);
        Serial.println(8);
        delay(100);
        Serial.println(9);
        delay(100);        
      }
      else if(numTargets == 4)
      {
        servo1.write(0);
        servo2.write(90);
        servo3.write(0);
        servo4.write(90);
        Serial.println(7);
        delay(100);
        Serial.println(8);
        delay(100);
        Serial.println(9);
        delay(100);
        Serial.println(10);
        delay(100);        
      }
      else if(numTargets == 5)
      {
        servo1.write(0);
        servo2.write(90);
        servo3.write(0);
        servo4.write(90);
        servo5.write(0);
        Serial.println(7);
        delay(100);
        Serial.println(8);
        delay(100);
        Serial.println(9);
        delay(100);
        Serial.println(10);
        delay(100);
        Serial.println(11);
        delay(100);
      }
      else if(numTargets == 6)
      {
        servo1.write(0);
        servo2.write(90);
        servo3.write(0);
        servo4.write(90);
        servo5.write(0);
        servo6.write(90);
        Serial.println(7);
        delay(100);
        Serial.println(8);
        delay(100);
        Serial.println(9);
        delay(100);
        Serial.println(10);
        delay(100);
        Serial.println(11);
        delay(100);
        Serial.println(12);
        delay(100);
      }
      delay(2000);      
    }
  }
}
void restart()
{
  if(Serial.available()!=0) {    
    input = Serial.readStringUntil('\n'); //read numtargets from txt file
    if (input.toInt() == 0) {
      servo1.write(90);
      servo2.write(0);
      servo3.write(90);
      servo4.write(0);
      servo5.write(90);
      servo6.write(0);
      numTargets = 0;
      while(numTargets == 0) // if numTargets = 0 game is either paused or not up yet so keep looping to check when game starts
      {    
        event();
      }
    }
  }
}
void start(){
  while(numTargets == 0) // if numTargets = 0 game is either paused or not up yet so keep looping to check when game starts
  {    
    event();
  }
  game();
}
void game(){
  if(numTargets == 1)
  {
    target1();   
  }
  if(numTargets == 2)
  {
    target1();
    target2();    
  }
  if(numTargets == 3)
  {
    target1();
    target2();
    target3();
  }
  if(numTargets == 4)
  {
    target1();
    target2();
    target3();
    target4();
  }
  if(numTargets == 5)
  {
    target1();
    target2();
    target3();
    target4();
    target5();
  }
  if(numTargets == 6)
  {
    target1();
    target2();
    target3();
    target4();
    target5();
    target6();
  }
}
void swap(int a, int b)
{
  int t = randTarget[a];
  randTarget[a] = randTarget[b];
  randTarget[b] = t;
}
void target1()
{
  target[1] = analogRead(1);
  if(hit[1] == 0){
    if ((millis() - checkMillis[1]) > reset)
   {
      if (target[1] > 50) 
      {
       servo1.write(90);
        startMillis[1] = millis();
        hit[1] = 1;
        Serial.println(1);
      }
    }
  }
  if(hit[1] == 1)
  {
    if ((millis() - startMillis[1]) > reset)
    {
      servo1.write(0);
      checkMillis[1] = millis();
      hit[1] = 0;
      Serial.println(7);      
    } 
  } 
}

void target2()
{
  target[2] = analogRead(2);
  if(hit[2] == 0){
    if ((millis() - checkMillis[2]) > reset)
    {
      if (target[2] > 50) 
      {
        servo2.write(0);
        startMillis[2] = millis();
        hit[2] = 1;
        Serial.println(2);
      }
    }
  }
  if(hit[2] == 1)
  {
    if ((millis() - startMillis[2]) > reset)
    {
      servo2.write(90);
      checkMillis[2] = millis();
      hit[2] = 0;
      Serial.println(8);      
    } 
  } 
}
void target3()
{
  target[3] = analogRead(3);
  if(hit[3] == 0)
  {
    if ((millis() - checkMillis[3]) > reset)
    {
      if (target[3] > 50) 
      {
        servo3.write(90);
        startMillis[3] = millis();
        hit[3] = 1;
        Serial.println(3);
      }
    }
  }
  if(hit[3] == 1)
  {
    if ((millis() - startMillis[3]) > reset)
    {
      servo3.write(0);
      checkMillis[3] = millis();
      hit[3] = 0;
      Serial.println(9);
    } 
  } 
}
void target4()
{
  if (hit[4] == 0) 
  {
    target[4] = analogRead(4);
    if ((millis() - checkMillis[4]) > reset)
    {
      if (target[4] > 50) 
      {
        servo4.write(0);
        startMillis[4] = millis();
        hit[4] = 1;
        Serial.println(4);
      }
    }
  }
  if(hit[4] == 1)
  {
    if ((millis() - startMillis[4]) > reset)
    {
      servo4.write(90);
      checkMillis[4] = millis();
      hit[4] = 0;
      Serial.println(10);
    } 
  } 
}
void target5()
{
  if (hit[5] == 0)
  {
    target[5] = analogRead(5);
    if ((millis() - checkMillis[5]) > reset)
    {
      if (target[5] > 50) 
      {
        servo5.write(90);
        startMillis[5] = millis();
        hit[5] = 1;
        Serial.println(5);
      }
    }
  }
  if(hit[5] == 1)
  {
    if ((millis() - startMillis[5]) > reset)
    {
      servo5.write(0);
      checkMillis[5] = millis();
      hit[5] = 0;
      Serial.println(11);
    } 
  } 
}
void target6()
{
  if(hit[6] == 0)
  {
    target[6] = analogRead(6);
    if ((millis() - checkMillis[6]) > reset)
    {
      if (target[6] > 50) 
      {
        servo6.write(0);
        startMillis[6] = millis();
        hit[6] = 1;
        Serial.println(6);
      }
    }
  }
  if(hit[6] == 1)
  {
    if ((millis() - startMillis[6]) > reset)
    {
      servo6.write(90);
      checkMillis[6] = millis();
      hit[6] = 0;
    } 
  } 
}