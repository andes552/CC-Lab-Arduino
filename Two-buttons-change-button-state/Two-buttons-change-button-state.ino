// Variables for blue button + led
const int blue = 9;
const int buttonBlue = 2;
boolean lastButtonBlue = LOW;     // Boolean variables can only be on/off (true/false) 
boolean currentButtonBlue = LOW;  // The boolean variables check the current status of the button
boolean ledOnBlue = false;        

// Variables for yellow button + led
const int yellow = 11;
const int buttonYellow = 4;
boolean lastButtonYellow = LOW;
boolean currentButtonYellow = LOW;
boolean ledOnYellow = false;

// Setup buttons and leds to pins
void setup() {
  pinMode(blue, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(buttonBlue, INPUT);
  pinMode(buttonYellow, INPUT); 
}

// Debounce function for the blue button
boolean debounceBlue(boolean lastBlue){
  boolean current = digitalRead(buttonBlue);
  if(lastBlue != current){
    delay(5);
    current = digitalRead(buttonBlue);
    }
    return current;
}

// Debounce function for the yellow button
boolean debounceYellow(boolean lastYellow){
  boolean current = digitalRead(buttonYellow);
  if(lastYellow != current){
    delay(5);
    current = digitalRead(buttonYellow);
    }
    return current;
}

void loop() {
  // Calling the debounce functions
  currentButtonBlue = debounceBlue(lastButtonBlue);
  currentButtonYellow = debounceYellow(lastButtonYellow);

  // Statement that test the current state and change according to current button (blue)
  if(lastButtonBlue == LOW && currentButtonBlue == HIGH){
    ledOnBlue = !ledOnBlue;
    }
    lastButtonBlue = currentButtonBlue;
    digitalWrite(blue, ledOnBlue);

  // Statement that test the current state and change according to current button (yellow)
  if(lastButtonYellow == LOW && currentButtonYellow == HIGH){
    ledOnYellow = !ledOnYellow;
    }
    lastButtonYellow = currentButtonYellow;
    digitalWrite(yellow, ledOnYellow);
}
