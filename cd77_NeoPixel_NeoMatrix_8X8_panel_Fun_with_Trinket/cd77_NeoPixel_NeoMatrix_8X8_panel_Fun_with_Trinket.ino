

// For an Adafruit Trinket and NeoPixel NeoMatrix 8X8 panel created by Chemdoc77 (aka Dr. K. White) 
// Published 10/14/2014
// Works on Arduino Uno and Nano but remember to change PIN to 6.
// Based on Adafruit's ColorWipe function.
// Thanks to all of the great people at Adafruit.com for their amazing products, great tutorials and outstanding forum help.

/*This is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as
published by the Free Software Foundation, either version 3 of
the License, or (at your option) any later version.
This software is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License, see
http://www.gnu.org/licenses/, for more details.
*/


#include <Adafruit_NeoPixel.h>
   
    #define PIN 1         // Parameter 1 = number of pixels in strip
                          // Parameter 2 = pin number (most are valid)
                          // Parameter 3 = pixel type flags, add together as needed:
                          // NEO_KHZ800 800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
                          // NEO_KHZ400 400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
                          // NEO_GRB Pixels are wired for GRB bitstream (most NeoPixel products)
                          // NEO_RGB Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
    Adafruit_NeoPixel strip = Adafruit_NeoPixel(64, PIN, NEO_GRB + NEO_KHZ800);
   
    
   // arrays for forward spiral
      uint8_t x;  // number of elements in an array
      uint8_t boxarray1[] = {0, 1, 2, 3, 4, 5, 6, 7, 15, 23, 31, 39, 47, 55, 63, 62, 61, 60, 59, 58, 57, 56, 48, 40, 32, 24, 16, 8};
      uint8_t boxarray2[] = {9, 10, 11, 12, 13, 14, 22, 30, 38, 46, 54, 53, 52, 51, 50, 49, 41, 33, 25, 17};
      uint8_t boxarray3[] = {18, 19, 20, 21, 29, 37, 45, 44, 43, 42, 34, 26};
      uint8_t boxarray4[] = {27, 28, 36, 35};
   // array of the number of elements in each array above
      uint8_t boxtotalarray[] = {28, 20, 12, 4}; 
   // array of the above arrays 
      const unsigned char * bigboxarray[] ={boxarray1, boxarray2, boxarray3, boxarray4}; 
   
  // arrays for reverse spiral
     uint8_t revboxarray1[] = {35, 36, 28, 27};
     uint8_t revboxarray2[] = {26, 34, 42, 43, 44, 45, 37, 29, 21, 20, 19, 18}; 
     uint8_t revboxarray3[] = {17, 25, 33, 41, 49, 50, 51, 52, 53, 54, 46, 38, 30, 22, 14, 13, 12, 11, 10, 9};
     uint8_t revboxarray4[] = {8, 16, 24,  32, 40, 48, 56, 57, 58, 59, 60, 61, 62, 63, 55, 47, 39, 31, 23, 15, 7, 6, 5, 4, 3, 2, 1, 0};
  // array of the number of elements in each array above
     uint8_t revboxtotalarray[] = {4, 12, 20, 28};
  // array of the above arrays 
     const unsigned char * revbigboxarray[] ={revboxarray1, revboxarray2, revboxarray3, revboxarray4}; 
 
  

// the setup routine runs once when you press reset:
    void setup() {
    strip.begin();
    strip.show();                // initialize all pixels to 'off'    
 }

// the loop routine runs over and over again forever;
void loop() {
  
    //forward spiral
      cd77_8X8_spiral_colorWipe(strip.Color(50, 0, 0), 50); //red spiral 
      cd77_8X8_spiral_colorWipe(strip.Color(0, 0, 50), 50); //blue spiral
      cd77_8X8_spiral_colorWipe(strip.Color(50, 0, 0), 50); //red spiral
      cd77colorallfill(strip.Color(0, 0, 0), 250);          // clears color
  
    // Generates box colorWipe - one full square at a time - all with same color
    // All blue squares
      cd77_8X8_box_colorWipe(strip.Color(0, 0, 50), 750); // blue boxes       
      cd77colorallfill(strip.Color(0, 0, 0), 250); // clears color 
        
    // All red squares
      cd77_8X8_box_colorWipe(strip.Color(50, 0, 0), 750); // red boxes      
      cd77colorallfill(strip.Color(0, 0, 0), 250); // clears color    
        
    // Generates Box colorWipe - one full square at a time - all with different colors        
      cd77_fullallbox_colorWipe(strip.Color(0, 0, 50), 750, boxarray4, 4); // single blue box
      cd77_fullallbox_colorWipe(strip.Color(50, 0, 0), 750, boxarray3, 12); // single red box
      cd77_fullallbox_colorWipe(strip.Color(0, 0, 50), 750, boxarray2, 20); // single blue box
      cd77_fullallbox_colorWipe(strip.Color(50, 0, 0), 750, boxarray1, 28); // single red box       
      cd77colorallfill(strip.Color(0, 0, 0), 250); // clears color 
  
        
}


// Functions for loop -----------------------------------------------------------------


// Fills the NeoMatrix 8X8 panel in a spiral -  one neopixel after the other
void cd77_8X8_spiral_colorWipe(uint32_t c, uint16_t wait) {    
  
  for(uint16_t j=0; j<4; j++) {
     uint16_t x=boxtotalarray[j];
  for(uint16_t k=0; k<x; k++) {
      strip.setPixelColor(bigboxarray[j][k], c);     
      strip.show();
      delay(wait);
   }
  }
}




// Fills the NeoMatrix 8X8 panel in a squares -  one square after the other
void cd77_8X8_box_colorWipe(uint32_t c, uint16_t wait) {    
  
  for(uint16_t j=0; j<4; j++) {
     uint16_t x=boxtotalarray[j];
  for(uint16_t k=0; k<x; k++) {
      strip.setPixelColor(bigboxarray[j][k], c);            
   } 
     strip.show();
     delay(wait); 
  }
   
}



 
// Fill the NeoMatrix 8X8 panel - one square at a time
void cd77_fullallbox_colorWipe(uint32_t c, uint16_t wait, uint8_t* boxarray, int x) { // Note: boxarray is the name of the array being used.  x is the number of members in the array being used.
  
   for(uint16_t i=0; i<x; i++) {
      strip.setPixelColor(boxarray[i], c);     
   }   
      strip.show();
      delay(wait);   
  }
  

// Fills all of the NeoPixels of the matrix at the same time 
void cd77colorallfill(uint32_t c, uint16_t wait) {  
      for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);      
      }       
      strip.show();
      delay(wait);
}      
  
    
    
    
    


