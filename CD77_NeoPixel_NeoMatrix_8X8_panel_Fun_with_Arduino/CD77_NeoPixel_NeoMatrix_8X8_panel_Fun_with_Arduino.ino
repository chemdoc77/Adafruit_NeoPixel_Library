                      

// For Arduino Nano or Uno along with the NeoPixel NeoMatrix 8X8 panel by Chemdoc77
// Published 10/15/2014
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
   
    #define PIN 6         // Parameter 1 = number of pixels in strip
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
 
  // arrays for split box
     uint8_t splitboxarray1[] = {24, 16, 8, 0, 1, 2, 3, 4, 5, 6, 7, 15, 23, 31};
     uint8_t splitboxarray2[] = {32, 40, 48, 56, 57, 58, 59, 60, 61, 62,	63, 55, 47, 39};
     uint8_t splitboxarray3[] = {25, 17, 9, 10, 11, 12, 13, 14, 22, 30};
     uint8_t splitboxarray4[] = {33, 41,	49, 50, 51, 52,	53, 54,	46, 38};
     uint8_t splitboxarray5[] = {26, 18,	19, 20,	21, 29};
     uint8_t splitboxarray6[] = {34, 42,	43, 44,	45, 37};
     uint8_t splitboxarray7[] = {27, 28};
     uint8_t splitboxarray8[] = {35, 36};  
  // array of the number of elements in each array above
     uint8_t splitboxtotalarray[] = {14, 14, 10, 10, 6, 6, 2, 2};
  // array of the above arrays 
     const unsigned char * splitbigboxarray[] ={splitboxarray1, splitboxarray2, splitboxarray3, splitboxarray4, splitboxarray5, splitboxarray6, splitboxarray7, splitboxarray8}; 
 
  // 4X4 boxes arrays 
     uint8_t fourarray1[]= {0, 1, 2, 3, 11, 19, 27, 26, 25, 24, 16, 8, 9, 10, 18, 17};
     uint8_t fourarray2[]= {4, 5, 6, 7, 15, 23, 31, 30, 29, 28, 20, 12, 13, 14, 22, 21};
     uint8_t fourarray3[]= {36, 37, 38, 39, 47, 55, 63, 62, 61, 60, 52, 44, 45, 46, 54, 53};
     uint8_t fourarray4[]= {32, 33, 34, 35, 43, 51, 59, 58, 57, 56, 48, 40, 41, 42, 50, 49};
  // array of the above arrays
     const unsigned char * bigfourarray[]={fourarray1, fourarray2, fourarray3, fourarray4};
   
    

// the setup routine runs once when you press reset:
    void setup() {
    strip.begin();
    strip.show();                // initialize all pixels to 'off'    
 }

// the loop routine runs over and over again forever;
void loop() {
  
      // Fills the NeoMatrix 8X8 panel in a spiral -  one neopixel after the other
         cd77_8X8_spiral_colorWipe(strip.Color(50, 0, 0), 50); //red spiral 
         cd77_8X8_spiral_colorWipe(strip.Color(0, 0, 50), 50); //blue spiral
         cd77_8X8_spiral_colorWipe(strip.Color(50, 0, 0), 50); //red spiral
         cd77colorallfill(strip.Color(0, 0, 0), 250);          // clears color
  
      // Fills the NeoMatrix 8X8 panel in a reverse spiral -  one neopixel after the other
         cd77_8X8_reverse_spiral_colorWipe(strip.Color(50, 0, 0), 50); //red reverse spiral
         cd77_8X8_reverse_spiral_colorWipe(strip.Color(0, 0, 50), 50); //blue reverse spiral 
         cd77_8X8_reverse_spiral_colorWipe(strip.Color(50, 0, 0), 50); //red reverse spiral
         cd77colorallfill(strip.Color(0, 0, 0), 250);          // clears color
  
      // Fills the NeoMatrix 8X8 panel using both spirals -  one neopixel after the other
         cd77_8X8_spiral_colorWipe(strip.Color(50, 0, 0), 50); //red spiral 
         cd77_8X8_reverse_spiral_colorWipe(strip.Color(0, 0, 50), 50); //blue reverse spiral
         cd77_8X8_spiral_colorWipe(strip.Color(50, 0, 0), 50); //red spiral 
         cd77colorallfill(strip.Color(0, 0, 0), 250);          // clears color
  
        
      // Fills the NeoMatrix 8X8 panel using one 4X4 minimatrix at a time in the 8X8 panel
         cd77_8X8_fourmatrixes_colorWipe(strip.Color(50, 0, 0), 50); // red
         cd77_8X8_fourmatrixes_colorWipe(strip.Color(0, 0, 50), 50); //blue
         cd77_8X8_fourmatrixes_colorWipe(strip.Color(50, 0, 0), 50); //red
         cd77colorallfill(strip.Color(0, 0, 0), 250);          // clears color
     
        
      // Fills the NeoMatrix 8X8 panel using all of the 4X4 minimatrix at the same time in the 8X8 panel
         cd77_8X8_fourmatrixes_same_colorWipe(strip.Color(50, 0, 0), 110); // red
         cd77_8X8_fourmatrixes_same_colorWipe(strip.Color(0, 0, 50), 110); //blue
         cd77_8X8_fourmatrixes_same_colorWipe(strip.Color(50, 0, 0), 110); // red
         cd77colorallfill(strip.Color(0, 0, 0), 250);          // clears color
 
       
    
            
        // Fills the NeoMatrix 8X8 panel with - one full square at a time - all with same color
        // All blue squares
        cd77_8X8_box_colorWipe(strip.Color(0, 0, 50), 750); // blue boxes       
        cd77colorallfill(strip.Color(0, 0, 0), 250); // clears color 
        
        // All red squares
        cd77_8X8_box_colorWipe(strip.Color(50, 0, 0), 750); // red boxes      
        cd77colorallfill(strip.Color(0, 0, 0), 250); // clears color    
        
        //  Fills the NeoMatrix 8X8 panel with one full square at a time - all with same color one full square at a time - all with different colors        
        cd77_fullallbox_colorWipe(strip.Color(0, 0, 50), 750, boxarray4, 4); // single blue box
        cd77_fullallbox_colorWipe(strip.Color(50, 0, 0), 750, boxarray3, 12); // single red box
        cd77_fullallbox_colorWipe(strip.Color(0, 0, 50), 750, boxarray2, 20); // single blue box
        cd77_fullallbox_colorWipe(strip.Color(50, 0, 0), 750, boxarray1, 28); // single red box       
        cd77colorallfill(strip.Color(0, 0, 0), 250); // clears color 
  
        // Fills the NeoMatrix 8X8 panel with with split spiral one full box at a time  
       cd77_8X8_split_spiral_colorWipe(strip.Color(50, 0, 0), 100); //red reverse spiral   
       cd77_8X8_split_spiral_colorWipe(strip.Color(0, 0, 50), 100); //blue reverse spiral
       cd77_8X8_split_spiral_colorWipe(strip.Color(50, 0, 0), 100); //red reverse spiral 
       cd77colorallfill(strip.Color(0, 0, 0), 250);          // clears color
     
     
 
}


// Functions for loop -----------------------------------------------------------------


// Fills the NeoMatrix 8X8 panel with in a spiral -  one neopixel after the other
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

// Fills the NeoMatrix 8X8 panel with in a reverse spiral -  one neopixel after the other
void cd77_8X8_reverse_spiral_colorWipe(uint32_t c, uint16_t wait) {    
  
  for(uint16_t j=0; j<4; j++) {
     uint16_t x=revboxtotalarray[j];
  for(uint16_t k=0; k<x; k++) {
      strip.setPixelColor(revbigboxarray[j][k], c);      
      strip.show();
      delay(wait);
   }
  }
}

// Fills the each of 4 seperate 4X4 matrixes in the NeoMatrix 8X8 panel with in a spiral -  one neopixel after the other
void cd77_8X8_fourmatrixes_colorWipe(uint32_t c, uint16_t wait) {    
  
   for(uint16_t j=0; j<4; j++) {
     
  for(uint16_t k=0; k<16; k++) {
      strip.setPixelColor(bigfourarray[j][k], c);     
      strip.show();
      delay(wait);
    }
  }
}  

// Fills the all of the 4 seperate 4X4 matrixes in the NeoMatrix 8X8 panel in a spiral -  one neopixel after the other
void cd77_8X8_fourmatrixes_same_colorWipe(uint32_t c, uint16_t wait) { 
    
  for(uint16_t k=0; k<16; k++) {
      strip.setPixelColor(bigfourarray[0][k], c);    
      strip.setPixelColor(bigfourarray[1][k], c); 
      strip.setPixelColor(bigfourarray[2][k], c); 
      strip.setPixelColor(bigfourarray[3][k], c);  
      strip.show();
      delay(wait);
    }
}  


//Fills the NeoMatrix 8X8 panel half a side at a time together

void cd77_8X8_split_spiral_colorWipe(uint32_t c, uint16_t wait) {    
  
  for(uint16_t j=0; j<8; j+=2) {
     uint16_t x=splitboxtotalarray[j];
  for(uint16_t k=0; k<x; k++) {
      strip.setPixelColor(splitbigboxarray[j][k], c);  
     strip.setPixelColor(splitbigboxarray[j+1][k], c);    
      strip.show();
      delay(wait);
   }
  }
}





// Fills the NeoMatrix 8X8 panel in a spiral -  one neopixel after the other with only one neoPixel light at a time
void cd77_8X8_onepixel_spiral_colorWipe(uint32_t c, uint16_t wait) {    
  
  for(uint16_t j=0; j<4; j++) {
     uint16_t x=boxtotalarray[j];
  for(uint16_t k=0; k<x; k++) {
      strip.setPixelColor(bigboxarray[j][k], c);      
      strip.show();
      delay(wait);
      strip.setPixelColor(bigboxarray[j][k], 0);      
      strip.show();
      
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



 
// Fills the NeoMatrix 8X8 panel - one square at a time
void cd77_fullallbox_colorWipe(uint32_t c, uint16_t wait, uint8_t* boxarray, int x) { // Note: boxarray is the name of the array being used.  x is the number of members in the array being used.
  
   for(uint16_t i=0; i<x; i++) {
      strip.setPixelColor(boxarray[i], c);     
   }   
      strip.show();
      delay(wait);   
  } 




 

// Fills the NeoMatrix 8X8 panel with all of the NeoPixes at one time 
void cd77colorallfill(uint32_t c, uint16_t wait) {  
      for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);      
      }       
      strip.show();
      delay(wait);
}      


    
    


