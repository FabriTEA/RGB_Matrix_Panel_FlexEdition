// testcolors demo for Adafruit RGBmatrixPanel library.
// Renders 512 colors on our 16x32 RGB LED matrix:
// http://www.adafruit.com/products/420
// Library supports 4096 colors, but there aren't that many pixels!  :)

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
  uint8_t r=0, g=0, b=0;

  // Draw top half
  for (uint8_t x=0; x < 64; x++) {      
    for (uint8_t y=0; y < 8; y++) {  
      matrix.drawPixel(x, y, matrix.Color333(r, g, b));
      r++;
      if (r == 8) {
        r = 0;
        g++;
        if (g == 8) {
          g = 0;
          b++;
        }
      }
    }
  }

  // Draw bottom half
  for (uint8_t x=0; x < 64; x++) {      
    for (uint8_t y=8; y < 16; y++) {  
      matrix.drawPixel(x, y, matrix.Color333(r, g, b));
      r++;
      if (r == 8) {
        r = 0;
        g++;
        if (g == 8) {
          g = 0;
          b++;
        }
      }
    }
  }
}

void loop() {
  // do nothing
}

