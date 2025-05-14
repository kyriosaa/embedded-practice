// Example for APCSA/APCSP extra credit

#define buttonPin = 2;   // button connected to digital pin 2
#define ledPin = 13;     // LED connected to digital pin 13

void setup() {
  pinMode(buttonPin, INPUT);    // button is an INPUT
  pinMode(ledPin, OUTPUT);      // LED is an OUTPUT
}

void loop() {
  int buttonState = digitalRead(buttonPin); // read the state of the button (released, pressed) ( LOW(0), HIGH(1) )

  if (buttonState == HIGH) {    // if the button is pressed
    digitalWrite(ledPin, HIGH); // turn on LED
  } else {                      // if the button isnt pressed
    digitalWrite(ledPin, LOW);  // turn off LED
  }
}
