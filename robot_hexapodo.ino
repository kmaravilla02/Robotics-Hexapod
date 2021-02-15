#include <Servo.h> 

int duration1, distance1;
int duration2, distance2;
int duration3, distance3;


 float d1 = 0;
 float d2 = 0;
 float d3 = 0;


int ledPin1 = 3;
int ledPin2 = 4;
int ledPin3 = 5;

int trigPin1 = 8;
int echoPin1 = 9;

int trigPin2 = 10;
int echoPin2 = 11;

int trigPin3 = 12;
int echoPin3 = 13;
 
Servo legsCenter;
Servo legsRight;
Servo legsLeft;
int delayLong = 250;
int delayShort = 350;
boolean debug = false;
 
void setup() 
{
  legsCenter.attach(12);
  legsRight.attach(11);
  legsLeft.attach(10);  


  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  
} 
 
void loop() {
  Serial.println("\n");
leftsensor(trigPin1,echoPin1,d1);
frontsensor(trigPin2,echoPin2,d2);
rightsensor(trigPin3,echoPin3,d3);
if ((d1 <= 30 && d1 >= 16) && (d2 <= 30 && d2 >= 16) && (d3 <= 30 && d3 >= 16)) { //FAR FAR FAR
      digitalWrite (ledPin1, LOW);
      digitalWrite (ledPin2, HIGH);
      digitalWrite (ledPin3, LOW);
}
else if ((d1 <= 30 && d1 >= 16) && (d2 <= 30 && d2 >= 16) && (d3 < 16)) { //FAR FAR NEAR
      digitalWrite (ledPin1, LOW);
      digitalWrite (ledPin2, HIGH);
      digitalWrite (ledPin3, LOW);
}
else if ((d1 <= 30 && d1 >= 16) && (d2 <= 30 && d2 >= 16) && (d3 > 30)) { //FAR FAR VFAR
      digitalWrite (ledPin1, LOW);
      digitalWrite (ledPin2, HIGH);
      digitalWrite (ledPin3, LOW);
}
else if ((d1 <= 30 && d1 >= 16) && (d2 > 16) && (d3 <= 30 && d3 >= 16)) { //FAR NEAR FAR
      digitalWrite (ledPin1, LOW);
      digitalWrite (ledPin2, LOW);
      digitalWrite (ledPin3, HIGH);
}

else if ((d1 <= 30 && d1 >= 16) && (d2 < 16) && (d3 < 16)) { //FAR NEAR NEAR
      digitalWrite (ledPin1, HIGH);
      digitalWrite (ledPin2, LOW);
      digitalWrite (ledPin3, LOW);
}

else if ((d1 <= 30 && d1 >= 16) && (d2 < 16) && (d3 > 30)) { //FAR NEAR VFAR
      digitalWrite (ledPin1, LOW);
      digitalWrite (ledPin2, LOW);
      digitalWrite (ledPin3, HIGH);
}
else if ((d1 <= 30 && d1 >= 16) && (d2 > 30) && (d3 <= 30 && d3 >= 16)) { //FAR VFAR FAR
      digitalWrite (ledPin1, LOW);
      digitalWrite (ledPin2, HIGH);
      digitalWrite (ledPin3, LOW);
}

else if ((d1 <= 30 && d1 >= 16) && (d2 > 30) && (d3 < 16)) { //FAR VFAR NEAR
      digitalWrite (ledPin1, LOW);
      digitalWrite (ledPin2, HIGH);
      digitalWrite (ledPin3, LOW);
}

else if ((d1 <= 30 && d1 >= 16) && (d2 > 30) && (d3 > 30)) { //FAR VFAR VFAR
      digitalWrite (ledPin1, LOW);
      digitalWrite (ledPin2, LOW);
      digitalWrite (ledPin3, HIGH);
}

else if ((d1 < 16) && (d2 <= 30 && d2 >= 16) && (d3 <= 30 && d3 >= 16)) { //NEAR FAR FAR
      digitalWrite (ledPin1, LOW);
      digitalWrite (ledPin2, LOW);
      digitalWrite (ledPin3, HIGH);
}

else if ((d1 < 16) && (d2 <= 30 && d2 >= 16) && (d3 < 16)) { //NEAR FAR NEAR
      digitalWrite (ledPin1, LOW);
      digitalWrite (ledPin2, HIGH);
      digitalWrite (ledPin3, LOW);
}

else if ((d1 < 16) && (d2 <= 30 && d2 >= 16) && (d3 > 30)) { //NEAR FAR VFAR
      digitalWrite (ledPin1, LOW);
      digitalWrite (ledPin2, LOW);
      digitalWrite (ledPin3, HIGH);
}

else if ((d1 < 16) && (d2 < 16) && (d3 <= 30 && d3 >= 16)) { //NEAR NEAR FAR
      digitalWrite (ledPin1, LOW);
      digitalWrite (ledPin2, LOW);
      digitalWrite (ledPin3, HIGH);
}

else if (d1 < 16 && d2 < 16 && d3 <16) {  //NEAR NEAR NEAR
      digitalWrite (ledPin1, LOW);
      digitalWrite (ledPin2, LOW);
      digitalWrite (ledPin3, HIGH);
}

else if ((d1 < 16) && (d2 < 16) && (d3 > 30 )) { //NEAR NEAR VFAR
      digitalWrite (ledPin1, LOW);
      digitalWrite (ledPin2, LOW);
      digitalWrite (ledPin3, HIGH);
}

else if ((d1 < 16) && (d2 > 30 ) && (d3 <= 30 && d3 >= 16)) { //NEAR VFAR FAR
      digitalWrite (ledPin1, LOW);
      digitalWrite (ledPin2, HIGH);
      digitalWrite (ledPin3, LOW);
}

else if ((d1 < 16) && (d2 > 30) && (d3 < 16)) { //NEAR VFAR NEAR
      digitalWrite (ledPin1, LOW);
      digitalWrite (ledPin2, HIGH);
      digitalWrite (ledPin3, LOW);
}

else if ((d1 < 16) && (d2 > 30 ) && (d3 > 30)) { //NEAR VFAR VFAR
      digitalWrite (ledPin1, LOW);
      digitalWrite (ledPin2, HIGH);
      digitalWrite (ledPin3, LOW);
}

else if ((d1 > 30) && (d2 <= 30 && d2 >= 16) && (d3 <= 30 && d3 >= 16)) { //VFAR FAR FAR
      digitalWrite (ledPin1, LOW);
      digitalWrite (ledPin2, HIGH);
      digitalWrite (ledPin3, LOW);
}

else if ((d1 > 30) && (d2 <= 30 && d2 >= 16) && (d3 < 16)) { //VFAR FAR NEAR
      digitalWrite (ledPin1, LOW);
      digitalWrite (ledPin2, HIGH);
      digitalWrite (ledPin3, LOW);
}

else if ((d1 > 30) && (d2 <= 30 && d2 >= 16) && (d3 > 30)) { //VFAR FAR VFAR
      digitalWrite (ledPin1, LOW);
      digitalWrite (ledPin2, HIGH);
      digitalWrite (ledPin3, LOW);
}

else if ((d1 > 30) && (d2 < 16 ) && (d3 <= 30 && d3 >= 16)) { //VFAR NEAR FAR
      digitalWrite (ledPin1, HIGH);
      digitalWrite (ledPin2, LOW);
      digitalWrite (ledPin3, LOW);
}

else if ((d1 > 30) && (d2 < 16) && (d3 < 16)) { //VFAR NEAR NEAR
      digitalWrite (ledPin1, HIGH);
      digitalWrite (ledPin2, LOW);
      digitalWrite (ledPin3, LOW);
}

else if ((d1 > 30) && (d2 < 16) && (d3 > 30 )) { //VFAR NEAR VFAR
      digitalWrite (ledPin1, LOW);
      digitalWrite (ledPin2, LOW);
      digitalWrite (ledPin3, HIGH);
}

else if ((d1 > 30) && (d2 > 30) && (d3 <= 30 && d3 >= 16)) { //VFAR VFAR FAR
      digitalWrite (ledPin1, LOW);
      digitalWrite (ledPin2, HIGH);
      digitalWrite (ledPin3, LOW);
}

else if ((d1 > 30) && (d2 > 30) && (d3 < 16)) { //VFAR VFAR NEAR
      digitalWrite (ledPin1, HIGH);
      digitalWrite (ledPin2, LOW);
      digitalWrite (ledPin3, LOW);
}

else if ((d1 > 30) && (d2 > 301) && (d3 > 30)) { //VFAR VFAR VFAR
      digitalWrite (ledPin1, LOW);
      digitalWrite (ledPin2, HIGH);
      digitalWrite (ledPin3, LOW);
}
/*
else { //Neutral
      digitalWrite (ledPin1, LOW);
      digitalWrite (ledPin2, LOW);
      digitalWrite (ledPin3, LOW);
}

*/
delay(800);
}
/*{ 
  if(debug) {
    legs_neutral();
  } else {
  
    upL();
    delay(delayShort);
  
    legL_rev();
    legR_fwd();
    delay(delayLong);
    
    upR();
    delay(delayShort);  
    
    legL_fwd();
    legR_rev();
    delay(delayLong);
    
  }
} 
*/
/*
void upR() {          // Right side raised
  legsCenter.write(160);
}
void upL() {          // Left side raised
  legsCenter.write(20);
}

void legR_fwd() {
  legsRight.write(110);
}
void legR_rev() {
  legsRight.write(75);
}

void legL_fwd() {
  legsLeft.write(75);
}
void legL_rev() {
  legsLeft.write(110);
}

void legs_neutral() {
  legsCenter.write(90); 
  legsRight.write(90);
  legsLeft.write(90);  
}
*/
void leftsensor(int trigPin1, int echoPin1, float &d1){ // This function is for first sensor.

  digitalWrite (trigPin1, HIGH);
  delayMicroseconds (10);
  digitalWrite (trigPin1, LOW);
  duration1 = pulseIn (echoPin1, HIGH);
  distance1 = duration1/29 /2;
  d1 = distance1;

      Serial.print("Left Sensor: ");
      Serial.print(d1);  
      Serial.print("cm    ");

  /*
   if (distance1 < 16) {  // Change the number for long or short distances.
    digitalWrite (ledPin1, LOW);
  } else {
    digitalWrite (ledPin1, HIGH);
  }    
  */
}
void frontsensor(int trigPin2, int echoPin2, float &d2){ // This function is for second sensor.

    digitalWrite (trigPin2, HIGH);
    delayMicroseconds (10);
    digitalWrite (trigPin2, LOW);
    duration2 = pulseIn (echoPin2, HIGH);
    distance2 = duration2/29 /2;
    d2 = distance2;
    
      Serial.print("Front Sensor: "); 
      Serial.print(d2);  
      Serial.print("cm    ");
   /*
    if (distance2 < 16) {  // Change the number for long or short distances.
      digitalWrite (ledPin2, LOW);
    }
 else {
      digitalWrite (ledPin2, HIGH);
    }   
    */ 
}
void rightsensor(int trigPin3, int echoPin3, float &d3){ // This function is for third sensor.
    
    digitalWrite (trigPin3, HIGH);
    delayMicroseconds (10);
    digitalWrite (trigPin3, LOW);
    duration3 = pulseIn (echoPin3, HIGH);
    distance3 = duration3/29 /2;
    d3 = distance3;

      Serial.print("Right Sensor: ");   
      Serial.print(d3);  
      Serial.print("cm");
  /* 
    if (distance3 < 16) {  // Change the number for long or short distances.
      digitalWrite (ledPin3, LOW);
    }
 else {
      digitalWrite (ledPin3, HIGH);
    }  
    */ 
}

