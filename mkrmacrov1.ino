// this code is also based on another persons work I am not the sole creator of this code here but unable to find the author to credit them here.
//I will look more in my history to find out who it was but if you find out please email me at gam3t3ch@gmail.com so I can credit them on this.
//my appologies I was unsure of how far I was going to go with mkrzero macro keyboard.
//-Gam3t3ch

//slowly working on a lcd screen addon will update more once I get another board together with proper setup with hardware.

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Keyboard.h>
#include <Arduino.h>
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x3F,20,4);


#define buttonAmount 10 // How many buttons do you have total
// 10 button pinout
int buttonPins[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // Pins the buttons are connected to
int keyCodes[] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57}; // ASCII codes for each of the above buttons (http://www.asciitable.com/) 

void setup() {
  lcd.init();
  lcd.backlight();

{
  for (int i = 0; i < buttonAmount; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP); // Make all the buttons inputs and turn on the pullup resistor
  }
  Keyboard.begin(); // Initialise keyboard control
}

}

void loop() {
  
  lcd.setCursor(2,0);
  lcd.print("Hello World!");
  lcd.setCursor(2,1);
  lcd.print("LCD 4x20");
  lcd.setCursor(2,2);
  lcd.print("test");
  lcd.setCursor(2,3);
  lcd.print("the final line...");

{
  for (int i = 0; i < buttonAmount; i++) {
    buttonState[i] = digitalRead(buttonPins[i]);
    if (buttonState[i] == LOW){ // Check if a button has been pressed, and if so, perform the combo + the initialised button's associated ASCII code
      // Modifiers for key combos (https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardmodifiers)
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press(keyCodes[i]);
      delay(100);
      Keyboard.releaseAll();
      delay(1000); // Ghetto-debouncer (Only allows one button press per second)
    }
  }
}}
