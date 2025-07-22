int BUT1 = D0;  //assigning pin numbers for all the components
int BUT2 = D1;  //these numbers probably won't work for you,
int BUT3 = D2;  //check the XIAO RP2040's pinout and your PCB editor to find yours

int LED1 = D3;
int LED2 = D4;
int LED3 = D5;

void setup() {
  pinMode(BUT1, INPUT_PULLUP);  //you have to do this so Arduino know to set internal pull-up resistors correctly
  pinMode(BUT2, INPUT_PULLUP);  //buttons are inputs (user does an action)
  pinMode(BUT3, INPUT_PULLUP);

  pinMode(LED1, INPUT_PULLUP);  //LEDs are outputs (result of action)
  pinMode(LED2, INPUT_PULLUP);
  pinMode(LED3, INPUT_PULLUP);

  long startTime = millis();  //log official start time (optional)
}

void loop() {
  long but1time;
  long but2time;
  long but3time = 0;

  if (digitalRead(BUT1) == HIGH) {  //this code block says "if button 1 is pressed then turn on LED 1"
    but1time = millis();            //logs time button 1 was pressed
    digitalWrite(LED1, HIGH);       //buttons and LEDs are digital components, so that's why it's digitalRead and digitalWrite
  } else {
    digitalWrite(LED1, LOW);
  }

  if (digitalRead(BUT2) == HIGH) {  //logs time that button 2 was pressed
    but2time = millis();
  }

  if (abs(but2time - but1time) <= 2000) {  //if button 1 and button 2 were pressed within 2 seconds of each other, then LED 2 lights up
    digitalWrite(LED2, HIGH);
  } else {
    digitalWrite(LED2, LOW);  //we have to do this or else LED 2 will always stay on
  }

  if (digitalRead(BUT3) == HIGH) {  //this keeps track of how long button 3 has been pressed
    but3time++;
  } else {
    but3time = 0;  //if not pressed then set time back to 0
  }

  if (but3time >= 800) {  //if it's pressed for more than 800 loops then turn LED3 on
    digitalWrite(LED3, HIGH);
  } else {
    digitalWrite(LED3, LOW);
  }
  
}
