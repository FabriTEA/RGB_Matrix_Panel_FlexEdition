// Print your text passing it through the serial.
// Max length = 10 chars * n panels.
// Default example n=2

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

char inChar;                // Temp char storage
char inData1[5 * n + 1];    // First line array (+1 for '\0')
char inData2[5 * n + 1];    // Second line array (+1 for '\0')
uint8_t index = 0;          
bool newPrint;


void setup() {

    // Matrix Initialization
    matrix.begin();
        
    // Set Text Properties
    matrix.setTextSize(1);                                          // size 1 == 8 pixels high
    matrix.setTextColor(matrix.ColorHSV(2048, 255, 255, true));     // Billiant Green

    // Turn off all leds
    matrix.fillScreen(matrix.Color333(0, 0, 0));

    // Init Serial
    Serial.begin(9600);
    Serial.write("Welcome!");
    Serial.write('\n');
    Serial.write("Send your text to the RGB Matrix...");
    Serial.write('\n');
}

void loop() {
    // Check the availability of new input
    while(Serial.available())
    {
        if(index < (5 * n))                 // Store in a string the first 5*n chars (first line)
        {
            inChar = Serial.read();         // Read a character
            inData1[index] = inChar;        // Store it
            index++;                        // Increment where to write next
            inData1[index] = '\0';          // Null terminate the string
            delay(10);
        }
        else                                // Store in a string the second 5*n chars (second line)
        {
            inChar = Serial.read();         // Read a character
            inData2[index - 10] = inChar;   // Store it
            index++;                        // Increment where to write next
            inData2[index - 10] = '\0';     // Null terminate the string
            delay(10);
        }
        newPrint = true;                    // New RGB print enabled
    }
    if(newPrint)
    {
        matrix.fillScreen(matrix.Color333(0, 0, 0));    // Delete the whole panel
        matrix.setCursor(2,0);                          // Set the top left position of the first line
        matrix.print(inData1);                          // First line on 
        matrix.setCursor(2,8);                          // Set the top left position of the second line
        matrix.print(inData2);                          // Second line on
        newPrint = false;                               // New RGB print disabled
        inData1[0] = '\0';                              // String erase
        inData2[0] = '\0';                              // String erase
    }
    index = 0;                              // Restart the storage of characters from 0
}
