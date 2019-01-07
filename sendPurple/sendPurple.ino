int IRledPin =  13;
int RECV_PIN = 11;
int BUTTON_PIN = 12;
int STATUS_PIN = 8;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Ready to decode IR!");
  pinMode(BUTTON_PIN, INPUT);
  pinMode(STATUS_PIN, OUTPUT);
}

void sendPurple() {
  pulseIR(2840);
  delayMicroseconds(6040);
  pulseIR(2920);
  delayMicroseconds(2080);
  pulseIR(800);
  delayMicroseconds(2120);
  pulseIR(840);
  delayMicroseconds(2080);
  pulseIR(880);
  delayMicroseconds(2080);
  pulseIR(840);
  delayMicroseconds(2080);
  pulseIR(1920);
  delayMicroseconds(2040);
  pulseIR(840);
  delayMicroseconds(2200);
  pulseIR(720);
  delayMicroseconds(2120);
  pulseIR(800);
  delayMicroseconds(2120);
  pulseIR(1880);
  delayMicroseconds(2080);
  pulseIR(840);
  delayMicroseconds(2120);
  pulseIR(800);
  delayMicroseconds(2120);
  pulseIR(840);
  delayMicroseconds(2080);
  pulseIR(840);
  delayMicroseconds(2120);
  pulseIR(840);
  delayMicroseconds(2120);
  pulseIR(800);
  delayMicroseconds(2080);
  pulseIR(880);

}

void sendRed() {
  pulseIR(2920);
  delayMicroseconds(6040);
  pulseIR(3000);
  delayMicroseconds(2000);
  pulseIR(920);
  delayMicroseconds(2040);
  pulseIR(920);
  delayMicroseconds(2040);
  pulseIR(800);
  delayMicroseconds(2120);
  pulseIR(800);
  delayMicroseconds(2120);
  pulseIR(1880);
  delayMicroseconds(2080);
  pulseIR(840);
  delayMicroseconds(2080);
  pulseIR(880);
  delayMicroseconds(2040);
  pulseIR(880);
  delayMicroseconds(2080);
  pulseIR(880);
  delayMicroseconds(2040);
  pulseIR(920);
  delayMicroseconds(2000);
  pulseIR(920);
  delayMicroseconds(2040);
  pulseIR(840);
  delayMicroseconds(2080);
  pulseIR(840);
  delayMicroseconds(2080);
  pulseIR(840);
  delayMicroseconds(2120);
  pulseIR(800);
  delayMicroseconds(2120);
  pulseIR(880);

}

void sendBlue() {
  pulseIR(2800);
  delayMicroseconds(6080);
  pulseIR(2960);
  delayMicroseconds(2040);
  pulseIR(880);
  delayMicroseconds(2160);
  pulseIR(720);
  delayMicroseconds(2120);
  pulseIR(800);
  delayMicroseconds(2120);
  pulseIR(840);
  delayMicroseconds(2080);
  pulseIR(1880);
  delayMicroseconds(2120);
  pulseIR(800);
  delayMicroseconds(2120);
  pulseIR(800);
  delayMicroseconds(2120);
  pulseIR(840);
  delayMicroseconds(2080);
  pulseIR(840);
  delayMicroseconds(2080);
  pulseIR(1920);
  delayMicroseconds(2080);
  pulseIR(840);
  delayMicroseconds(2080);
  pulseIR(880);
  delayMicroseconds(2040);
  pulseIR(840);
  delayMicroseconds(2080);
  pulseIR(840);
  delayMicroseconds(2120);
  pulseIR(800);
  delayMicroseconds(2120);
  pulseIR(840);
}

void LaserXPurple() {

pulseIR(6440);
delayMicroseconds(560);
pulseIR(560);
delayMicroseconds(520);
pulseIR(1640);
delayMicroseconds(480);
pulseIR(560);
delayMicroseconds(600);
pulseIR(1560);
delayMicroseconds(560);
pulseIR(480);
delayMicroseconds(600);
pulseIR(520);
delayMicroseconds(520);
pulseIR(1640);
delayMicroseconds(560);
pulseIR(1600);
}

void LaserXRed() {
  pulseIR(6400);
  delayMicroseconds(600);
  pulseIR(520);
  delayMicroseconds(560);
  pulseIR(1600);
  delayMicroseconds(520);
  pulseIR(560);
  delayMicroseconds(560);
  pulseIR(1600);
  delayMicroseconds(480);
  pulseIR(560);
  delayMicroseconds(560);
  pulseIR(560);
  delayMicroseconds(480);
  pulseIR(1600);
  delayMicroseconds(640);
  pulseIR(520);
}

void LaserXBlue() {
  pulseIR(6520);
  delayMicroseconds(480);
  pulseIR(520);
  delayMicroseconds(600);
  pulseIR(1640);
  delayMicroseconds(520);
  pulseIR(520);
  delayMicroseconds(520);
  pulseIR(1600);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(480);
  pulseIR(560);
  delayMicroseconds(520);
  pulseIR(560);
  delayMicroseconds(560);
  pulseIR(1560);
}

// This procedure sends a 38KHz pulse to the IRledPin
// for a certain # of microseconds. We'll use this whenever we need to send codes
void pulseIR(long microsecs) {
  // we'll count down from the number of microseconds we are told to wait

  cli();  // this turns off any background interrupts

  while (microsecs > 0) {
    // 38 kHz is about 13 microseconds high and 13 microseconds low
    digitalWrite(IRledPin, HIGH);  // this takes about 3 microseconds to happen
    delayMicroseconds(10);         // hang out for 10 microseconds, you can also change this to 9 if its not working
    digitalWrite(IRledPin, LOW);   // this also takes about 3 microseconds
    delayMicroseconds(10);         // hang out for 10 microseconds, you can also change this to 9 if its not working

    // so 26 microseconds altogether
    microsecs -= 26;
  }

  sei();  // this turns them back on
}

void loop() {


  Serial.println("Nerf RED...");
  digitalWrite(STATUS_PIN, HIGH);
  sendRed();
  digitalWrite(STATUS_PIN, LOW);
  delay(1500); // Wait a bit between retransmissions

  Serial.println("Nerf PURPLE...");
  digitalWrite(STATUS_PIN, HIGH);
  sendPurple();
  digitalWrite(STATUS_PIN, LOW);
  delay(1500); // Wait a bit between retransmissions

  Serial.println("Nerf BLUE...");
  digitalWrite(STATUS_PIN, HIGH);
  sendBlue();
  digitalWrite(STATUS_PIN, LOW);
  delay(1500); // Wait a bit between retransmissions


  Serial.println("LaserX RED...");
  digitalWrite(STATUS_PIN, HIGH);
  LaserXRed();
  digitalWrite(STATUS_PIN, LOW);
  delay(1500); // Wait a bit between retransmissions


  Serial.println("LaserX Blue...");
  digitalWrite(STATUS_PIN, HIGH);
  LaserXBlue();
  digitalWrite(STATUS_PIN, LOW);
  delay(1500); // Wait a bit between retransmissions


  Serial.println("LaserX Purple...");
  digitalWrite(STATUS_PIN, HIGH);
  LaserXPurple();
  digitalWrite(STATUS_PIN, LOW);
  delay(1500); // Wait a bit between retransmissions


}
