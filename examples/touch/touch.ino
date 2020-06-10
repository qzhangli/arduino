// 
// Modified by Rich Obermeyer 1/14/2014.
// Modified by Jonathan Doerr 4/9/2014.
// Copyright 2013 - Under creative commons license 3.0:
//        Attribution-ShareAlike CC BY-SA
//
// This software is furnished "as is", without technical support, and with no 
// warranty, express or implied, as to its usefulness for any purpose.
/*
 * touch.ino example for touch functions
 */

#include <ezLCDLib.h>

ezLCD3 lcd;

void setup()
{
  lcd.begin( EZM_BAUD_RATE );
  lcd.font(0); 
  lcd.cls(WHITE, BLACK); // clear screen to white
  lcd.xy("ct");
  lcd.print("Touch the Screen\" \"ct");
}

void loop()
{
  /* It is recommended you look for every other event but not pressed.
   * The reason for this is because the loop runs so tight, only occasionally
   *   does lcd.touchS() return MOVED(1), PRESSED(2), RELEASED(4).
   * If you need specific actions such as those look into using touchzones and wstack.
   *
   * The following if condition could also be writen as follows:
   * if(lcd.touchS() = 1 || lcd.touchS() == 2 || lcd.touchS() == 3 || lcd.touchS() == 4)
   */
  if (lcd.touchS() != 0) {
    // clear screen
    lcd.cls(WHITE, BLACK);
    // grab x and y values
    int x = lcd.touchX();
    int y = lcd.touchY();
    // draw a circle where the display was touched
    lcd.circle(x, y, 25, 0);
    // move the cursor and print where the display was touched at
    lcd.xy(5,0);
    lcd.print("Touch = \(");
    lcd.print(x);
    lcd.print(", ");
    lcd.print(y);
    lcd.print(")");
  }
}

