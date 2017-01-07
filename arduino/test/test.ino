#include <Time.h>
#include <TimeLib.h>


#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6
#define BRIGHTNESS 100

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(150, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {


  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  Serial.begin(9600);
  setTime(11,29,55,25,7,2016);
  Serial.println("Start");
  strip.begin();
  strip.setBrightness(BRIGHTNESS);

  strip.show(); // Initialize all pixels to 'off'
//  int x = 255;
//  int y = 105;
//  int z = 0;
//   sunset(x,y,z,50);
//   fade(5);

}

void loop() {
  if (hourFormat12() == 8 and minute() == 20) {
    fade(255,100,0);
    sunset(255,100,0,50);
    fade(0,0,0);
  }

  else if (hourFormat12() == 8 and minute() == 35){
    sunrise(0,50,255,3);
    fade(0,0,0);
  }

Serial.println("Done total");
}


void test1(uint8_t x, uint8_t wait) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i,strip.Color(125,255,0));
  }
  strip.show();
  delay(5000);
 
}

void sunset(uint8_t x, uint8_t y, uint8_t z, uint8_t wait) {
  while(y > 0 and z < 255) {
    for (int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i,strip.Color(x,y,z));
  }
  strip.show();
  y = y - 1;
  z = z + 2; 
  Serial.println(y);
  Serial.println(z);
  delay(500);
  }
  z = 255;
  while (x != 5) {
    x = x - 10;
    for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i,strip.Color(x,y,z));
    }
    strip.show();
    Serial.println(x);
    delay(500);
  } 
Serial.println("Finishes");

}


void sunrise(uint8_t x, uint8_t y, uint8_t z, uint8_t wait) {
   strip.setBrightness(20);
  while ( y < 245) {
    for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i,strip.Color(x,y,z));
    }
    y = y +1;
    strip.show();
    delay(4000);
    Serial.println(y);
  }
   strip.setBrightness(40);
  Serial.println("Phase1");
  while(z >5) {
    for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i,strip.Color(x,y,z));
    }
    z = z-1;
    strip.show();
    delay(4000);
  }
 strip.setBrightness(60);
while(x < 245) {
    for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i,strip.Color(x,y,z));
    }
    x = x+1;
    strip.show();
    delay(4000);
  }
  delay(10000);
}

void fade(uint8_t a,uint8_t y,uint8_t z) {
  for (int i = 0; i < strip.numPixels()/15; i++) {
    for (int x = i; x < strip.numPixels();x = x + 10){
      strip.setPixelColor(x,strip.Color(a,y,z));
        delay(100);
  }
  strip.show();
  }
  Serial.println("Done");

  }
