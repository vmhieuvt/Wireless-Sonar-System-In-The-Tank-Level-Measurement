 /*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
* by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*/



const int trigPin = 11;
const int echoPin = 12;
int state = 0;
#define ledPin 7
// defines variables
long duration;
int distance;
void setup() {
pinMode(ledPin, OUTPUT);
digitalWrite(ledPin, LOW);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(38400); // Starts the serial communication

}
void loop() {
  if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
  }
 // Controlling the LED
 if (state == 'a') {
  digitalWrite(ledPin, HIGH); // LED ON
  // Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(10);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
delay(200);
// Calculating the distance
distance= duration*0.034/(2*0.965);
// Prints the distance on the Serial Monitor
Serial.println(distance);
Serial.write(distance);
state = 0;
delay(500);

 }
 else {
  digitalWrite(ledPin, LOW); // LED ON
  state = 0;
 }
 

}
