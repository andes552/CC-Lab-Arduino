// The flex sensor is connected to analog pin no. 0
int flexPin = 0;

// Setting up the LEDs in pin 4 to 13
void setup() {
  for (int i=4; i<14; i++){
    pinMode(i, OUTPUT);
  }
}

void loop(){
  Serial.begin(9600);
  
  // Turn off all LED lights
  for (int i=4; i<14; i++){
    digitalWrite(i, LOW);
  }

  // Read the flexsensor and map values to LED pins
  int flexReading = map(analogRead(flexPin), 750, 900, 4, 13);

  // Contrain the value of the flex/LEDs
  int LEDnum = constrain(flexReading, 4, 13);
  
  // Print the mapped value of the flex sensor
  Serial.print("Flex: ");
  Serial.println(flexReading);

  // Call the blink function
  blink(LEDnum, 10,1);
}

// The blink function: Control on/off of the LEDs
void blink(int LEDPin, int onTime, int offTime){
  // Turn the LED on
  digitalWrite(LEDPin, HIGH);

  // Delay
  delay(onTime);

  // Turn the LED off
  digitalWrite(LEDPin, LOW);

  // Delay
  delay(offTime);
}

