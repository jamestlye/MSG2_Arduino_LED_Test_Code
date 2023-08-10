#include <FastLED.h>

#define LED_PIN_1   2
#define LED_PIN_2   3
#define NUM_STRIPS  2
#define NUM_LEDS_PER_STRIP    106
CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2813, LED_PIN_1, GRB>(leds[0], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<WS2813, LED_PIN_2, GRB>(leds[1], NUM_LEDS_PER_STRIP);
  FastLED.clear(true);
} 

void loop() {
  for(int x = 0; x < NUM_STRIPS; x++) {
    uint16_t sinBeat   = beatsin16(30, 0, NUM_LEDS_PER_STRIP - 1, 0, 0);
    uint16_t sinBeat2  = beatsin16(30, 0, NUM_LEDS_PER_STRIP - 1, 0, 21845);
    uint16_t sinBeat3  = beatsin16(30, 0, NUM_LEDS_PER_STRIP - 1, 0, 43690);
    leds[x][sinBeat]   = CRGB::Blue;
    leds[x][sinBeat2]  = CRGB::Red;
    leds[x][sinBeat3]  = CRGB::White;
    fadeToBlackBy(leds[x], NUM_LEDS_PER_STRIP, 10);
    FastLED.show();
  }
}
