int trigPin = 12;    // Trigger
int echoPin = 13;    // Echo
long duration, cm;
long cm_constrained;

void setup() {
  // put your setup code here, to run once:
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  


}

void loop() {
  // put your main code here, to run repeatedly:
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(echoPin,LOW);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
 
  
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  cm = (duration /2) /58.0 ;     // Divide by 29.1 or multiply by 0.0343
  cm_constrained = constrain(cm, 2, 400);


  Serial.print("duration: ");
  Serial.print(duration);
  Serial.print(" distance: "); 
  Serial.print(cm);
  Serial.println();
  
  delay(100);


}
