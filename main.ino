#include <Arduino.h>

#include "definitions.h"


// Battery monitoring settings
const uint8_t ANALOG_PIN = 34;  // Pin used for reading battery voltage
const float R1 = 10000.0;
const float R2 = 10000.0;
const float MAX_VOLTAGE = 4.2;            // Maximum battery voltage (adjusted for LiPo)
const uint32_t lowBatteryThreshold = 20;  // Threshold for sad expression

// IR sensor pins
#define IR_SENSOR_LEFT_PIN 32
#define IR_SENSOR_RIGHT_PIN 33
#define IR_SENSOR_FRONT_LEFT_PIN 25
#define IR_SENSOR_FRONT_RIGHT_PIN 26
#define IR_SENSOR_BACK_LEFT_PIN 27
#define IR_SENSOR_BACK_RIGHT_PIN 35

// Other pins
#define CHARGING_DETECTION_PIN 12  // Pin to detect if charging
#define SWITCH_PIN 15              // Pin for a switch (not used in this code)
#define BUZZER_PIN 14              // Pin for the buzzer

bool eyesOpen = true;               // Flag to indicate if eyes are currently open
bool batteryWarningPlayed = false;  // Flag to prevent repeated battery warnings




void setup() {
  Serial.begin(115200);


  // all the setup code here
  defState();

  pinMode(ledPin, OUTPUT);


  u8g2.begin();
  u8g2.clearBuffer();  // Clear the display buffer


  // Set pin modes
  pinMode(IR_SENSOR_LEFT_PIN, INPUT);
  pinMode(IR_SENSOR_RIGHT_PIN, INPUT);
  pinMode(IR_SENSOR_FRONT_LEFT_PIN, INPUT);
  pinMode(IR_SENSOR_FRONT_RIGHT_PIN, INPUT);
  pinMode(IR_SENSOR_BACK_LEFT_PIN, INPUT);
  pinMode(IR_SENSOR_BACK_RIGHT_PIN, INPUT);
  pinMode(SWITCH_PIN, INPUT_PULLUP);
  pinMode(CHARGING_DETECTION_PIN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);  // Ensure buzzer is off initially
  normal();
}



void loop() {
  blinking();
  Serial.println("Blinking");
  delay(1000);
  
 


  u8g2.sendBuffer();  // Transfer internal memory to the display
  delay(10);          // Short delay to control refresh rate

  normal();
  Serial.println("normal");
  delay(1000);


  sad();
  Serial.println("sad");
  delay(1000);


  close();
  Serial.println("close");
  delay(1000);

  blink();
  Serial.println("blink");
  delay(1000);

  upset();
  Serial.println("upset");
  delay(1000);

  wonder();
  Serial.println("wonder");
  delay(1000);

  happy();
  Serial.println("happy");
  delay(1000);

  cute();
  Serial.println("cute");
  delay(1000);

  angry();
  Serial.println("angry");
  delay(1000);

  suspicious();
  Serial.println("suspicious");
  delay(1000);

  downeye();
  Serial.println("downeye");
  delay(1000);

  upeye();
  Serial.println("upeye");
  delay(1000);

  lefteye();
  Serial.println("lefteye");
  delay(1000);
}



uint32_t getBatteryPercentage() {
  int sensorValue = analogRead(ANALOG_PIN);                 // Read the analog pin
  float voltage = sensorValue * (MAX_VOLTAGE / 4095.0);     // Convert to voltage
  float batteryPercentage = (voltage / MAX_VOLTAGE) * 100;  // Convert to percentage
  return (uint32_t)batteryPercentage;
}

void drawBatterySymbol(uint32_t percentage) {
  // Battery dimensions
  const int batteryWidth = 20;
  const int batteryHeight = 10;
  const int batteryX = 108;
  const int batteryY = 0;

  u8g2.drawFrame(batteryX, batteryY, batteryWidth, batteryHeight);
  u8g2.drawBox(batteryX + batteryWidth, batteryY + 2, 2, batteryHeight - 4);

  // Calculate battery level width based on percentage
  int levelWidth = map(percentage, 0, 100, 0, batteryWidth - 2);
  u8g2.drawBox(batteryX + 1, batteryY + 1, levelWidth, batteryHeight - 2);
}



void activateBuzzer() {
  digitalWrite(BUZZER_PIN, HIGH);
}

void deactivateBuzzer() {
  digitalWrite(BUZZER_PIN, LOW);
}
