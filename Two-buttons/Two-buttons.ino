const int blue = 9;
const int yellow = 11;
const int buttonBlue = 2;
const int buttonYellow = 4;


void setup() {
  pinMode(blue, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(buttonBlue, INPUT);
  pinMode(buttonYellow, INPUT); 
}

void loop() {
  if(digitalRead(buttonBlue) == HIGH){
    digitalWrite(blue, HIGH);
    }
    else{
      digitalWrite(blue, LOW);
      }

  if(digitalRead(buttonYellow) == HIGH){
    digitalWrite(yellow, HIGH);
    }
    else{
      digitalWrite(yellow, LOW);
      }
}
