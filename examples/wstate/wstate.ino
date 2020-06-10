// 
// Modified by Jonathan Doerr 4/21/2014.
// jon@earthlcd.com
// Copyright 2014 - Under creative commons license 3.0:
//        Attribution-ShareAlike CC BY-SA
//
// This software is furnished "as is", without technical support, and with no 
// warranty, express or implied, as to its usefulness for any purpose.
//
#include <ezLCDLib.h>

ezLCD3 lcd;

int touch=0;
volatile boolean ezLCDInt = false;

void setup()
{
  lcd.begin( EZM_BAUD_RATE );
  lcd.sendCommand("cfgio 9 touch_int low quiet");
  lcd.cls( BLACK, WHITE );
  lcd.font("0");
  lcd.xy("ct");
  lcd.print("wstate Test\"CT\"");
  lcd.string(2, "TEST");
  
  lcd.string(3, "New");
  lcd.button(3, 10, 60, 75, 50, 1, 0, 3, 6, 3);
  lcd.string(4, "Delete");
  lcd.button(4, 95, 60, 75, 50, 1, 0, 3, 6, 4);
  lcd.string(5, "Disable");
  lcd.button(5, 10, 120, 75, 50, 1, 0, 3, 6, 5);
  lcd.string(6, "Enable");
  lcd.button(6, 95, 120, 75, 50, 1, 0, 3, 6, 6);

  attachInterrupt(0, ezLCDevent, RISING );  
}

void loop()
{
  if(ezLCDInt){
    ezLCDInt = false;
    touch = lcd.wstack(1);
    if(touch == 3){
      lcd.button(2, 180, 85, 140, 120, 1, 0, 20, 2, 2);}
    else if(touch == 4){
      lcd.wstate(2, 0);}
    else if(touch == 5){
      lcd.wstate(2, 2);}
    else if(touch == 6){
      lcd.wstate(2, 1);}

    lcd.color(BLACK);
    lcd.rect(200, 205, 100, 30, 1);
    lcd.color(WHITE);
    lcd.font(0);
    lcd.xy(200, 205);
    lcd.print("Wstate=");
    int state = lcd.wstate(2);
    lcd.print(state, HEX);
  }
}

void ezLCDevent( void ) {
  ezLCDInt = true;
}
