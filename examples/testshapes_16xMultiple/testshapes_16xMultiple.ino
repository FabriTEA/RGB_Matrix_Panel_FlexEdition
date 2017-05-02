// testshapes demo for Adafruit RGBmatrixPanel library.
// Demonstrates the drawing abilities of the RGBmatrixPanel library.
// For 16x32 RGB LED matrix:
// http://www.adafruit.com/products/420

// Written by Limor Fried/Ladyada & Phil Burgess/PaintYourDragon
// for Adafruit Industries.
// BSD license, all text above must be included in any redistribution.

#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

#define CLK 11  // MUST be on PORTB! (Use pin 11 on Mega)
#define LAT 10
#define OE  9
#define A   A0
#define B   A1
#define C   A2
#define n   2   // inline panels number
RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false, 32*n);

void setup() {

  matrix.begin();
  
  // draw a pixel in solid white
  matrix.drawPixel(16, 0, matrix.Color333(7, 7, 7)); 
  delay(250);

  // fix the screen with green
  matrix.fillRect(16, 0, 32, 16, matrix.Color333(0, 7, 0));
  delay(250);

  // draw a box in yellow
  matrix.drawRect(16, 0, 32, 16, matrix.Color333(7, 7, 0));
  delay(250);
  
  // draw an 'X' in red
  matrix.drawLine(16, 0, 47, 15, matrix.Color333(7, 0, 0));
  matrix.drawLine(47, 0, 16, 15, matrix.Color333(7, 0, 0));
  delay(250);
  
  // draw a blue circle
  matrix.drawCircle(23, 7, 7, matrix.Color333(0, 0, 7));
  delay(250);
  
  // fill a violet circle
  matrix.fillCircle(39, 7, 7, matrix.Color333(7, 0, 7));
  delay(250);
  
  // fill the screen with 'black'
  matrix.fillScreen(matrix.Color333(0, 0, 0));
  
  // draw some text!
  matrix.setCursor(17, 0);   // start at top left, with one pixel of spacing
  matrix.setTextSize(1);    // size 1 == 8 pixels high

  // draw a box in Green
  matrix.fillRect(0, 0, 16, 16, matrix.Color333(0, 7, 0));
  delay(250);

  // draw a box in white
  matrix.fillRect(16, 0, 32, 16, matrix.Color333(7, 7, 7));
  delay(250);

  // draw a box in Red
  matrix.fillRect(48, 0, 16, 16, matrix.Color333(7, 0, 0));
  delay(250);

  // fill the screen with 'black'
  matrix.fillScreen(matrix.Color333(0, 0, 0));
  
  // print each letter with a rainbow color
  matrix.setTextColor(matrix.Color333(7,0,0));
  matrix.print('1');
  matrix.setTextColor(matrix.Color333(7,4,0)); 
  matrix.print('6');
  matrix.setTextColor(matrix.Color333(7,7,0));
  matrix.print('x');
  matrix.setTextColor(matrix.Color333(4,7,0)); 
  matrix.print('6');
  matrix.setTextColor(matrix.Color333(0,7,0));  
  matrix.print('4');
  
  matrix.setCursor(17, 9);   // next line
  matrix.setTextColor(matrix.Color333(0,7,7)); 
  matrix.print('*');
  matrix.setTextColor(matrix.Color333(0,4,7)); 
  matrix.print('R');
  matrix.setTextColor(matrix.Color333(0,0,7));
  matrix.print('G');
  matrix.setTextColor(matrix.Color333(4,0,7)); 
  matrix.print("B");
  matrix.setTextColor(matrix.Color333(7,0,4)); 
  matrix.print("*");

  // whew!
}

void loop() {
  // do nothing
}
