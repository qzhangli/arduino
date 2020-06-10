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
}

void loop()
{
  lcd.cls(); 
  int x = 160;
  int y = 120; 
  int size = 20;
  for(int i=0; i < 100; i++)
  {
     lcd.color(i);  
     lcd.circle( x, y, size, NOFILL );  
     size += 4; 
     delay(100);
  } 
}

