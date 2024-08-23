#ifndef blink_h
#define blink_h

const int ledPin = 2;

void blinking() {
  // Turn the LED on
  digitalWrite(ledPin, HIGH);
  delay(1000);  // Wait for 1 second

  // Turn the LED off
  digitalWrite(ledPin, LOW);
  delay(1000);  // Wait for 1 second
}

#endif