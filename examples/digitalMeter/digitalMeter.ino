// 
// Modified by Rich Obermeyer 1/14/2014.
// Modified by Jonathan Doerr 4/8/2014.
// Copyright 2013 - Under creative commons license 3.0:
//        Attribution-ShareAlike CC BY-SA
//
// This software is furnished "as is", without technical support, and with no 
// warranty, express or implied, as to its usefulness for any purpose.
/*
*  To see this example live, put a jumper between A0 and 3.3V, 5V or GND.
*/
 
#include <ezLCDLib.h>

ezLCD3 lcd;

int xPos = 110;  // horizontal position
int yPos = 80;   // vertical position
int width = 100;
int height = 30;
int option = 14;  // 1=draw, 2=disabled, 3=ring, 4=accuracy
                  //  1=left, 2=disabled, 3=right, 4=center, 11=left framed, 12=disable framed,
                  //  13=right framed, 14=center framed, 6=redraw.
int digits = 3;  
int dp = 2;


void setup()
{
  lcd.begin( EZM_BAUD_RATE );
  lcd.font( 0 );
  lcd.cls( BLACK );
  lcd.color(WHITE);
  lcd.xy("cc");
  lcd.print("Volts on Analog Pin 0\" \"ct");
  lcd.digitalMeter( 1, xPos,yPos, width, height, option, 0, digits, dp, 1);
}

void loop()
{
   float value = analogRead(0);
   float volts = (5.00 * value) / 10.23;
   lcd.wvalue(1, volts);
   delay(500); //update every 1/2 second   
}

