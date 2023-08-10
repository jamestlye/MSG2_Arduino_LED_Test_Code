#include <FastLED.h>

#define LED_PIN     2
#define NUM_LEDS    106

CRGB leds[NUM_LEDS];

uint8_t paletteIndex = 0;

CRGBPalette16 purplePalette = CRGBPalette16 (
    CRGB::DarkViolet,
    CRGB::DarkViolet,
    CRGB::DarkViolet,
    CRGB::DarkViolet,
    
    CRGB::Magenta,
    CRGB::Magenta,
    CRGB::Linen,
    CRGB::Linen,
    
    CRGB::Magenta,
    CRGB::Magenta,
    CRGB::DarkViolet,
    CRGB::DarkViolet,

    CRGB::DarkViolet,
    CRGB::DarkViolet,
    CRGB::Linen,
    CRGB::Linen
); 

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2813, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.clear(true);

} 

void loop() {
  // for (int i = 0; i < NUM_LEDS; i += 2){
  //   leds[i] = CRGB::Green;
  // }
  // FastLED.show();
  // delay(5000);

  // for (int i = 0; i < NUM_LEDS; i += 2){
  //   leds[i] = CRGB::Yellow;
  // }
  // FastLED.show();
  // delay(2000);

  // for (int i = 0; i < NUM_LEDS; i += 2){
  //   if (i < 33){
  //     leds[i] = CRGB::Red;
  //   } else {
  //     leds[i] = CRGB::Yellow;
  //   }
  // }
  // FastLED.show();
  // delay(300);

  // for (int i = 0; i < NUM_LEDS; i += 2){
  //   leds[i] = CRGB::Yellow;
  // }
  // FastLED.show();
  // delay(300);

  // for (int i = 0; i < NUM_LEDS; i += 2){
  //   if (i < 33){
  //     leds[i] = CRGB::Red;
  //   } else {
  //     leds[i] = CRGB::Yellow;
  //   }
  // }
  // FastLED.show();
  // delay(300);


  // // put your main code here, to run repeatedly:
  // fill_solid(leds, NUM_LEDS, CRGB::Green);
  // FastLED.show();
  // delay(5000);

  // fill_solid(leds, NUM_LEDS, CRGB::Yellow);
  // FastLED.show();
  // delay(2000);

  // fill_solid(leds, NUM_LEDS, CRGB::Red);
  // FastLED.show();
  // delay(300);

  // fill_solid(leds, NUM_LEDS, CRGB::Yellow);
  // FastLED.show();
  // delay(300);

  // fill_solid(leds, NUM_LEDS, CRGB::Red);
  // FastLED.show();
  // delay(300);

  // // fill_soild(leds, NUM_LEDS, CRGB::Aqua);
  // // FastLED.show();
  // // delay(1000);

  // //First Scenario End

  // fill_solid(leds, NUM_LEDS, CRGB::Green);
  // FastLED.show();
  // delay(5000);

  // fill_solid(leds, NUM_LEDS, CRGB::Yellow);
  // FastLED.show();
  // delay(2000);

  // for (int i = 0; i < NUM_LEDS; i++){
  //   if (i < 33){
  //     leds[i] = CRGB::Red;
  //   } else {
  //     leds[i] = CRGB::Yellow;
  //   }
  // }
  // FastLED.show();
  // delay(300);

  // fill_solid(leds, NUM_LEDS, CRGB::Yellow);
  // FastLED.show();
  // delay(300);

  // for (int i = 0; i < NUM_LEDS; i++){
  //   if (i < 33){
  //     leds[i] = CRGB::Red;
  //   } else {
  //     leds[i] = CRGB::Yellow;
  //   }
  // }
  // FastLED.show();
  // delay(300);

  // fill_soild(leds, NUM_LEDS, CRGB::Aqua);
  // FastLED.show();
  // delay(1000);
  //Second Scenario End

  // fill_palette(leds, NUM_LEDS, paletteIndex, 255 / NUM_LEDS, purplePalette, 255, LINEARBLEND);
  
  // EVERY_N_MILLISECONDS(10){
  //   paletteIndex++;
  // }

  // uint16_t beatA = beatsin16(30, 0, 255);
  // uint16_t beatB = beatsin16(20, 0, 255);
  // fill_rainbow(leds, NUM_LEDS, (beatA+beatB)/2, 8);
    
  // FastLED.show();
  
  uint16_t sinBeat   = beatsin16(30, 0, NUM_LEDS - 1, 0, 0);
  uint16_t sinBeat2  = beatsin16(30, 0, NUM_LEDS - 1, 0, 21845);
  uint16_t sinBeat3  = beatsin16(30, 0, NUM_LEDS - 1, 0, 43690);

  leds[sinBeat]   = CRGB::Blue;
  leds[sinBeat2]  = CRGB::Red;
  leds[sinBeat3]  = CRGB::White;
  
  fadeToBlackBy(leds, NUM_LEDS, 10);

  FastLED.show();

}
