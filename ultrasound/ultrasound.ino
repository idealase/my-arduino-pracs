/*
 * Ultrasonic sensor demo
 * Industrial Automation and Robotics, ICTE5005
 * Department of Computing, Curtin University
 */

 int triggerPin = 11;
 int echoPin = 12;
 long delayUS;
 long distanceCM;

void setup() {
  // Start the serial port so we can communicate using
  // the serial monitor. 9600 refers to the baud rate
  // (the speed of data transmission), 9600 is pretty
  // common and reliable if you're just doing text.
  Serial.begin(9600)

  // the trigger pin is an output to send the pulse
  pinMode(triggerPin, OUTPUT);

  // the echon pis is an input to receive the pulse
  pinMode(echoPin, INPUT);

  // it's a good idea to initialise outputs to
  // something we know is sensible
  digitalWrite(triggerPin, LOW);
}

void loop() {
  // Write a 10us high pulse to the trigger pin
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  // Wait for the echo pin to go high. The pulseIn
  // function waits until the pin goes high and returns
  // the number of microseconds it took to do so.
  // Waits at most 12,000 microseconds before giving up
  // (corresponds to a little over 2m distance).
  delayUS = pulseIn(echoPin, HIGH, 12000);

  // Convert the delay into a distance. Note that we halve
  // the delay to get the one-way distance
  distanceCM = (delayUS/2) / 29.1;

  // Print to the serial monitor
  Serial.print(distanceCM);
  serial.println(" cm");

  // Wait before running again.
  delay(500);
}
