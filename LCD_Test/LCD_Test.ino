/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */

// Include Libraries
#include <Wire.h>
#include <Adafruit_MCP23017.h>
#include <Adafruit_RGBLCDShield.h>

// Defines
#define RED 0x1
#define YELLOW 0x3
#define GREEN 0x2
#define TEAL 0x6
#define BLUE 0x4
#define VIOLET 0x5
#define WHITE 0x7

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int updateTime=200;
int blinkTime=500;
unsigned long updateTimer=millis();
unsigned long blinkTimer=millis();
int backlightColor=BLUE;
boolean starting = true;
int time=millis();
Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  lcd.begin(16, 2);
  
  Serial.begin(9600);
  while (!Serial){
    ;
  }
  Serial.println("Starting");
  lcd.print("Starting");
  
;
  
  
    
}

// the loop routine runs over and over again forever:
void loop() {
  time=millis()-time/1000;
  Serial.print(time);
  Serial.print("\n");
  time=time+1;

  uint8_t buttons = lcd.readButtons();

  if (buttons) {
    lcd.clear();
    lcd.setCursor(0,0);
    if (buttons & BUTTON_UP) {
      lcd.print("UP ");
      lcd.setBacklight(RED);
    }
    if (buttons & BUTTON_DOWN) {
      lcd.print("DOWN ");
      lcd.setBacklight(YELLOW);
    }
    if (buttons & BUTTON_LEFT) {
      lcd.print("LEFT ");
      lcd.setBacklight(GREEN);
    }
    if (buttons & BUTTON_RIGHT) {
      lcd.print("RIGHT ");
      lcd.setBacklight(TEAL);
    }
    if (buttons & BUTTON_SELECT) {
      lcd.print("SELECT ");
      lcd.setBacklight(VIOLET);
    }
  }

  if (millis()-updateTimer>updateTime){
    lcd.setCursor(0,1);
    lcd.print(millis()/1000);
    updateTimer=millis();
 }

if (millis()-blinkTimer>blinkTime){
   
switch (backlightColor) {
  case BLUE:
    lcd.setBacklight(RED);
    backlightColor=RED;
  break;
  case RED:
    lcd.setBacklight(BLUE);
    backlightColor=BLUE;
  break;
  
}
    
    blinkTimer=millis();
  }
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
//  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW  
//  delay(1000);               // wait for a second
}
