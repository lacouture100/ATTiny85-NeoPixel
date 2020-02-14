// NeoPixel Ring simple sketch created in 2013 by Shae Erisson
// Adapted by Alvaro Lacouture for use with potentiometer

#include <Adafruit_NeoPixel.h> // Adafruit NeoPixel library
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define PIN        4 // Pin on the Arduino connected to the NeoPixels
#define NUMPIXELS 12 // NeoPixel ring size

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int sensorPin = A1; //Potentiometer input pin
int sensorValue = 0; //Potentiometer inout value

void setup() {
  pixels.begin(); // INITIALIZE NeoPixel strip object 
}

void loop() {
  sensorValue = analogRead(sensorPin);
  pixels.clear(); // Set all pixel colors to 'off'

  for(int i=0; i<NUMPIXELS; i++) { // Loop through the pixels available
    pixels.setPixelColor(i, pixels.Color(0, 150, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(sensorValue); // Pause before next pass through loop
  }
}
