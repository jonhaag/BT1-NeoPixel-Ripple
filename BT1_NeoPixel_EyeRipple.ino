#include <Adafruit_NeoPixel.h>
//define NeoPixel Pin and Number of LEDs
#define PIN 2
#define NUM_LEDS 37
#define RIPPLE_BRIGHTNESS 200
#define RIPPLE_DELAY 5
//create a NeoPixel strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);
//global LED array
int ledArray[NUM_LEDS][2];
void setup() {
// start the strip and blank it out
strip.begin();
strip.show();
//seed RND generator
randomSeed(analogRead(0));
//populate the LED array with RND values and light it up
for (int i = 0; i <= NUM_LEDS - 1; i++) {
ledArray[i][0] = random(0,RIPPLE_BRIGHTNESS);
strip.setPixelColor(i,ledArray[i][0],0,0);
ledArray[i][1] = random(0,2);
}
strip.show();
}
void loop() {
ripple();
}
void ripple() {
for (int i = 0; i <= NUM_LEDS - 1; i++) {
if (ledArray[i][1] == 0) {
//fade down
ledArray[i][0]--;
}
else {
//fade up
ledArray[i][0]++;
}
if (ledArray[i][0] <= -RIPPLE_BRIGHTNESS) {
ledArray[i][1] = 1;
}
if (ledArray[i][0] >= RIPPLE_BRIGHTNESS) {
ledArray[i][1] = 0;
}
int brightness = ledArray[i][0];
if (brightness < 0) {
brightness = 0;
}
strip.setPixelColor(i, brightness, 0, 0);
}
strip.show();
delay(RIPPLE_DELAY);
}
