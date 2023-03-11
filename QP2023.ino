#include <Servo.h>
#include <SoftwareSerial.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
int target[7]; //
int hit[7]; // used to check if target is hit, hit =1, not hit =0
int numTargets = 0; // tracks numner of targets user is using
String input;
unsigned long startMillis[7]; // start time when you hit target
unsigned long checkMillis[7]; // checks if target is swinging

const unsigned long twosec = 2000;
const unsigned long onesec =  1000;
void setup() {
  // you can do a srvo array, but I forgot how to do that so here is a long list of code
  Serial.begin(9600);
  servo1.attach(13);
  servo1.write(0);
  servo2.attach(12);
  servo2.write(90);
  servo3.attach(11);
  servo3.write(0);
  servo4.attach(10);
  servo4.write(90);
  servo5.attach(9);
  servo5.write(0);
  servo6.attach(8);
  servo6.write(90);
  delay(twosec);
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
}
void event() {
//reads data from serial moniter, updates numTargets value if it changes
  if(Serial.available()!=0) {
    input = Serial.readStringUntil('x'); //read numtargets from txt file
    if (numTargets != input.toInt()) {
      numTargets = input.toInt(); //update if numTargets is changed
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
  target1();
  target2();
  target3();
  target4();
  target5();
  target6();
}

void target1()
{
  target[1] = analogRead(1);
  if ((millis() - checkMillis[1]) > twosec)
  {
    if (target[1] > 25) 
    {
      servo1.write(90);
      startMillis[1] = millis();
      hit[1] = 1;
      Serial.println(1);
    }
  }
  if(hit[1] == 1)
  {
    if ((millis() - startMillis[1]) > twosec)
    {
      servo1.write(0);
      checkMillis[1] = millis();
      hit[1] = 0;
    } 
  } 
}

void target2()
{
  target[2] = analogRead(2);
  if ((millis() - checkMillis[2]) > twosec)
  {
    if (target[2] > 25) 
    {
      servo2.write(0);
      startMillis[2] = millis();
      hit[2] = 1;
      Serial.println(2);
    }
  }
  if(hit[2] == 1)
  {
    if ((millis() - startMillis[2]) > twosec)
    {
      servo2.write(90);
      checkMillis[2] = millis();
      hit[2] = 0;
    } 
  } 
}
void target3()
{
  target[3] = analogRead(3);
  if ((millis() - checkMillis[3]) > twosec)
  {
    if (target[3] > 25) 
    {
      servo3.write(90);
      startMillis[3] = millis();
      hit[3] = 1;
      Serial.println(3);
    }
  }
  if(hit[3] == 1)
  {
    if ((millis() - startMillis[3]) > twosec)
    {
      servo3.write(0);
      checkMillis[3] = millis();
      hit[3] = 0;
    } 
  } 
}
void target4()
{
  target[4] = analogRead(4);
  if ((millis() - checkMillis[4]) > twosec)
  {
    if (target[4] > 25) 
    {
      servo4.write(0);
      startMillis[4] = millis();
      hit[4] = 1;
      Serial.println(4);
    }
  }
  if(hit[4] == 1)
  {
    if ((millis() - startMillis[4]) > twosec)
    {
      servo4.write(90);
      checkMillis[4] = millis();
      hit[4] = 0;
    } 
  } 
}
void target5()
{
  target[5] = analogRead(5);
  if ((millis() - checkMillis[5]) > twosec)
  {
    if (target[5] > 25) 
    {
      servo5.write(90);
      startMillis[5] = millis();
      hit[5] = 1;
      Serial.println(5);
    }
  }
  if(hit[5] == 1)
  {
    if ((millis() - startMillis[5]) > twosec)
    {
      servo5.write(0);
      checkMillis[5] = millis();
      hit[5] = 0;
    } 
  } 
}
void target6()
{
  target[6] = analogRead(6);
  if ((millis() - checkMillis[6]) > twosec)
  {
    if (target[6] > 25) 
    {
      servo6.write(0);
      startMillis[6] = millis();
      hit[6] = 1;
      Serial.println(6);
    }
  }
  if(hit[6] == 1)
  {
    if ((millis() - startMillis[6]) > twosec)
    {
      servo6.write(90);
      checkMillis[6] = millis();
      hit[6] = 0;
    } 
  } 
}