/*
   IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
   An IR LED must be connected to Arduino PWM pin 3.
   Version 0.1 July, 2009
   Copyright 2009 Ken Shirriff
   http://arcfn.com
*/

#include <IRremote.h>
int RECV_PIN = 11;
int BUTTON_PIN = 12;
int STATUS_PIN = 8;

IRrecv irrecv(RECV_PIN);
IRsend irsend;

decode_results results;


// Storage for the recorded code
int codeType = -1; // The type of code
unsigned long codeValue; // The code value if not raw
unsigned int rawCodes[RAWBUF]; // The durations if raw
int codeLen; // The length of the code
int toggle = 0; // The RC5/6 toggle state

//int output[34] = {-5900.,  2900., -2050.,   800., -2050.,   850., -2050.,   800.,
//        -2050.,   800., -2100.,  1800., -2050.,   850., -2050.,   800.,
//        -2050.,   850., -2000.,  1850., -2050.,   850., -2050.,   800.,
//        -2050.,   750., -2050.,   800., -2050.,   850., -2050.,   850.,
//        -2050.,   850.};

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(BUTTON_PIN, INPUT);
  pinMode(STATUS_PIN, OUTPUT);
  Serial.println(RAWBUF, DEC);

}


void storeCode(decode_results *results) {
  int codeNow;
  codeNow = results->rawlen;
  Serial.println(codeNow, DEC);
  if (codeNow > 0) {
    Serial.println("Saving Code");
    codeLen = results->rawlen;
    // To store raw codes:
    // Drop first value (gap)
    // Convert from ticks to microseconds
    // Tweak marks shorter, and spaces longer to cancel out IR receiver distortion
    for (int i = 1; i <= codeLen; i++) {
      if (i % 2) {
        // Mark
        rawCodes[i-1] = results->rawbuf[i] * USECPERTICK ;
        Serial.print(" m");
      }
      else {
        // Space
        rawCodes[i-1] = results->rawbuf[i] * USECPERTICK;
        Serial.print(" s");
      }
      Serial.print(rawCodes[i], DEC);
    }
    Serial.println("");
    Serial.println(codeNow, DEC);
  }
}

void sendCode(int repeat) {
  Serial.println("Get Ready");
  delay(1000);

  // Assume 30 KHz
  Serial.println("Sending raw 30");
  irsend.sendRaw(rawCodes, codeLen, 30);
  delay(1000);

  // Assume 33 KHz
  Serial.println("Sending raw 33");
  irsend.sendRaw(rawCodes, codeLen, 33);
  delay(1000);

  // Assume 33 KHz
  Serial.println("Sending raw 36");
  irsend.sendRaw(rawCodes, codeLen, 36);
  delay(1000);

  // Assume 33 KHz
  Serial.println("Sending raw 36.7");
  irsend.sendRaw(rawCodes, codeLen, 36.7);
  delay(1000);

  // Assume 38 KHz
  Serial.println("Sending raw 38");
  irsend.sendRaw(rawCodes, codeLen, 38);
  delay(1000);

  // Assume 40 KHz
  Serial.println("Sending raw 40");
  irsend.sendRaw(rawCodes, codeLen, 40);
  delay(1000);

  // Assume 56 KHz
  Serial.println("Sending raw 56");
  irsend.sendRaw(rawCodes, codeLen, 56);

  Serial.println("Sent raw");
  Serial.println(codeLen, DEC);
  for (int i = 0; i <= codeLen; i++) {
    Serial.print(rawCodes[i], DEC);
    Serial.print(" ");
  }
  Serial.println("");

}

int lastButtonState;

void loop() {
  // If button pressed, send the code.
  int current = digitalRead(BUTTON_PIN);
  int buttonState;

  if (current == LOW)
    buttonState = HIGH;
  else
    buttonState = LOW;
  if (lastButtonState == HIGH && buttonState == LOW) {
    Serial.println("Released");
    irrecv.enableIRIn(); // Re-enable receiver
  }

  if (buttonState) {
    Serial.println("Pressed, sending");
    digitalWrite(STATUS_PIN, HIGH);
    sendCode(lastButtonState == buttonState);
    digitalWrite(STATUS_PIN, LOW);
    delay(50); // Wait a bit between retransmissions
  }
  else if (irrecv.decode(&results)) {
    digitalWrite(STATUS_PIN, HIGH);
    storeCode(&results);
    irrecv.resume(); // resume receiver
    digitalWrite(STATUS_PIN, LOW);
  }
  lastButtonState = buttonState;
}
