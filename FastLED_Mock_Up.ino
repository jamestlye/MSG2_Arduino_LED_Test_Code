#include <FastLED.h>

#define SERIAL_SPEED 9600
#define TIME_INTERVAL 0
#define LOCAL_INTERVAL 2400
#define FLASH_INTERVAL 300
#define OPTICAL_PIN 4
#define LED_PIN_1 2
#define LED_PIN_2 3
#define NUM_STRIPS 2
#define NUM_LEDS_PER_STRIP 107
#define DIM_TRIGGER 49 //ascii "1"
#define BRIGHT_TRIGGER 50 //ascii "2"
#define OPTICAL_TRIGGER 0

unsigned long currentTime = millis();
unsigned long previousTime = millis();
int previousState = HIGH, currentState = HIGH;
int randNum;
int incomingByte;

CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_SPEED);
  pinMode(OPTICAL_PIN, INPUT);
  FastLED.addLeds<WS2813, LED_PIN_1, GRB>(leds[0], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<WS2813, LED_PIN_2, GRB>(leds[1], NUM_LEDS_PER_STRIP);
  FastLED.clear(true);
  randomSeed(analogRead(0));
} 

void loop() {
  //HIGH when optical sensors are align & LOW when broken
  currentState = digitalRead(OPTICAL_PIN);
  if(currentState == HIGH && previousState == LOW){
    Serial.println(OPTICAL_TRIGGER);
    processing();
  }
  brightness();
  idle(); //default green animation

  previousState = currentState;
}

void brightness(){
  if(Serial.available() > 0){
    incomingByte = Serial.read();
    if(incomingByte == DIM_TRIGGER){
      FastLED.setBrightness(0);
    } else if (incomingByte == BRIGHT_TRIGGER){
      FastLED.setBrightness(255);
    }
  }
  Serial.flush();
  //clear serial buffer for new messages
}

void idle(){
  for(int x = 0; x < NUM_STRIPS; x++) {
    fill_solid(leds[x], NUM_LEDS_PER_STRIP, CRGB::Green);
    FastLED.show();
  }
}

void localization(){
  // randNum = random(0,3); //randomly select which area, top, middle, or bottom, to localize
  randNum = random(0,3);
  currentTime = previousTime = millis(); 
  while ((currentTime - previousTime)< LOCAL_INTERVAL){
    for(int x = 0; x < NUM_STRIPS; x++) {
      fill_solid(leds[x]+(randNum*(NUM_LEDS_PER_STRIP/3)), (NUM_LEDS_PER_STRIP/3), CRGB::Red);
      FastLED.show();
    }
    delay(FLASH_INTERVAL);
    for(int x = 0; x < NUM_STRIPS; x++) {
      fill_solid(leds[x], NUM_LEDS_PER_STRIP, CRGB::Yellow);
      FastLED.show();
    }
    delay(FLASH_INTERVAL);
    currentTime = millis();
  }//done one walkthrough!
}

void processing(){
  currentTime = previousTime = millis(); 
  //waits time to "run the model"
  while((currentTime - previousTime) < TIME_INTERVAL){
    for(int x = 0; x < NUM_STRIPS; x++) {
      fill_solid(leds[x], NUM_LEDS_PER_STRIP, CRGB::Yellow);
      FastLED.show();
    }
    currentTime = millis();
  }
  localization();
}
