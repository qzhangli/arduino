// 
// Modified by Jonathan Doerr 4/8/2012.
// Copyright 2013 - Under creative commons license 3.0:
//        Attribution-ShareAlike CC BY-SA
//
// This software is furnished "as is", without technical support, and with no 
// warranty, express or implied, as to its usefulness for any purpose.
//
#include <ezLCDLib.h>

ezLCD3 lcd; // create lcd object

void setup()
{
  lcd.begin( EZM_BAUD_RATE );
  lcd.cls();  // clear screen to black
}

void loop(){
  delay(500); 
  lcd.cls(random(0,150)); // clear screen to random color
}
