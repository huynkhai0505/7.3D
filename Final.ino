
int ledPin = 12;       
int inputPin1 = 2;      
int inputPin2 = 3;
int inputPin3 = 4;         
int pirState = LOW;             
int val = 0;                   
int pinSpeaker = 9;           

void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin1, INPUT);  // declare sensor as input
  pinMode(inputPin2, INPUT);
  pinMode(inputPin3, INPUT);
  pinMode(pinSpeaker, OUTPUT);
  Serial.begin(57400);
}

void loop(){
  //PIR sensor 1
  val = digitalRead(inputPin1);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH);  // turn LED ON
    playTone(300, 160);
    delay(200);

    
    if (pirState == LOW) {
      Serial.println("Motion detected!");
      pirState = HIGH;
    }
  } else {
      digitalWrite(ledPin, LOW); 
      playTone(0, 0);
      delay(200);    
      if (pirState == HIGH){
      Serial.println("Motion ended!");
      pirState = LOW;
    }
  }

  //PIR sensor 2
  val = digitalRead(inputPin2);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH);  // turn LED ON
    playTone(300, 160);
    delay(200);

    
    if (pirState == LOW) {
      Serial.println("Motion detected!");
      pirState = HIGH;
    }
  } else {
      digitalWrite(ledPin, LOW); 
      playTone(0, 0);
      delay(200);    
      if (pirState == HIGH){
      Serial.println("Motion ended!");
      pirState = LOW;
    }
  }

  // PIR sensor 3  
  val = digitalRead(inputPin3);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH);  // turn LED ON
    playTone(300, 160);
    delay(200);

    
    if (pirState == LOW) {
      Serial.println("Motion detected!");
      pirState = HIGH;
    }
  } else {
      digitalWrite(ledPin, LOW); 
      playTone(0, 0);
      delay(200);    
      if (pirState == HIGH){
      Serial.println("Motion ended!");
      pirState = LOW;
    }
  }
}
void playTone(long duration, int freq) {
    duration *= 1000;
    int period = (1.0 / freq) * 100000;
    long elapsed_time = 0;
    while (elapsed_time < duration) {
        digitalWrite(pinSpeaker,HIGH);
        delayMicroseconds(period / 2);
        digitalWrite(pinSpeaker, LOW);
        delayMicroseconds(period / 2);
        elapsed_time += (period);
    }
}
