

#define LEDPIN 13
#define LEDPIN2 8
#define POTENT  5
#define BUTTON 4

unsigned long time;
int side;
int on, last;

void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(LEDPIN2, OUTPUT);
  pinMode(BUTTON, INPUT);
  time = millis();
  side = 1;
  on = 0;
}

void loop(){
  int current = digitalRead(BUTTON);
  if(current != last && last) {
    on = !on;
  }
  if(on) {
    int val = analogRead(POTENT);
    int interval = map(val, 0, 1023, 10, 1000);
    if(millis() - time > interval) {
      // Inverte os leds
      digitalWrite(LEDPIN, side);
      digitalWrite(LEDPIN2, !side);
      side = !side;
      time = millis(); 
    }
  } else {
     digitalWrite(LEDPIN, LOW);
     digitalWrite(LEDPIN2, LOW);
  }
  last = current;
}
