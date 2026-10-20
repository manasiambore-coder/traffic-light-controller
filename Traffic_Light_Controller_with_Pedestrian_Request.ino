// Pin Definitions based on your Wokwi layout
const int carGreen = 2;
const int carYellow = 3;
const int carRed = 4;
const int pedGreen = 5;
const int pedRed = 6;
const int pedButton = 7;

// State Machine States
enum State { CARS_GO, CARS_WARN, PEDS_CROSS, PEDS_WARN };
State currentState = CARS_GO;

unsigned long previousMillis = 0;
bool pedRequest = false;

void setup() {
  // Initialize digital pins
  pinMode(carGreen, OUTPUT);
  pinMode(carYellow, OUTPUT);
  pinMode(carRed, OUTPUT);
  pinMode(pedGreen, OUTPUT);
  pinMode(pedRed, OUTPUT);
  pinMode(pedButton, INPUT_PULLUP); // Internal pull-up resistor enabled for the button

  Serial.begin(9600);
  Serial.println("--- Traffic Light System Initialized ---");
  
  // Initial State: Cars Go (Green), Pedestrians Wait (Red)
  setLights(HIGH, LOW, LOW, LOW, HIGH);
  Serial.println("State: CARS_GO (Green for vehicles)");
}

void loop() {
  // Read pedestrian button (LOW when pressed due to INPUT_PULLUP)
  if (digitalRead(pedButton) == LOW) {
    if (currentState == CARS_GO && !pedRequest) {
      pedRequest = true;
      Serial.println(">> Pedestrian request registered! Will switch after current cycle.");
    }
  }

  unsigned long currentMillis = millis();

  // State Machine Logic
  switch (currentState) {
    case CARS_GO:
      // If a button was pressed, transition to warning after 4 seconds
      if (pedRequest && (currentMillis - previousMillis >= 4000)) {
        previousMillis = currentMillis;
        currentState = CARS_WARN;
        setLights(LOW, HIGH, LOW, LOW, HIGH); // Car Yellow, Ped Red
        Serial.println("State: CARS_WARN (Yellow for vehicles)");
      } 
      // Normal automatic cycle if no button is pressed (changes every 7 seconds)
      else if (!pedRequest && (currentMillis - previousMillis >= 7000)) {
        previousMillis = currentMillis;
        currentState = CARS_WARN;
        setLights(LOW, HIGH, LOW, LOW, HIGH); // Car Yellow, Ped Red
        Serial.println("State: CARS_WARN (Yellow for vehicles)");
      }
      break;

    case CARS_WARN:
      // Keep yellow light on for 2 seconds
      if (currentMillis - previousMillis >= 2000) {
        previousMillis = currentMillis;
        currentState = PEDS_CROSS;
        setLights(LOW, LOW, HIGH, HIGH, LOW); // Car Red, Ped Green
        Serial.println("State: PEDS_CROSS (Safe for pedestrians to cross)");
      }
      break;

    case PEDS_CROSS:
      // Allow pedestrians to cross for 5 seconds
      if (currentMillis - previousMillis >= 5000) {
        previousMillis = currentMillis;
        currentState = PEDS_WARN;
        Serial.println("State: PEDS_WARN (Pedestrian warning - flashing)");
      }
      break;

    case PEDS_WARN:
      // Flash the pedestrian green light as a warning before switching back
      for (int i = 0; i < 3; i++) {
        digitalWrite(pedGreen, LOW);
        delay(300);
        digitalWrite(pedGreen, HIGH);
        delay(300);
      }
      // Reset back to cars go
      pedRequest = false;
      previousMillis = millis();
      currentState = CARS_GO;
      setLights(HIGH, LOW, LOW, LOW, HIGH); // Car Green, Ped Red
      Serial.println("State: CARS_GO (Green for vehicles)");
      break;
  }
}

// Helper function to update all LEDs easily
void setLights(int cg, int cy, int cr, int pg, int pr) 
{
  digitalWrite(carGreen, cg);
  digitalWrite(carYellow, cy);
  digitalWrite(carRed, cr);
  digitalWrite(pedGreen, pg);
  digitalWrite(pedRed, pr);
}