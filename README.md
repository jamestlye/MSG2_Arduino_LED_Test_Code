# MSG2_Arduino_LED_Test_Code

Make sure to install the FastLED library first. 

FastLED_sinewave_two_independent_strips.ino controls both strips independently, but is currently displaying the same animation. 
There are some commented codes that show other animations and the uncommented code shows a colourful sine wave animation to see if data is sent properly. 

The code assumes 106 LEDs per strip because that is how many LEDs I counted that can cover the full height of the MSG2 tower. Even if the actual strip has less than the indicated amount in the code, it doesn't affect the LEDs. If more, the LEDs after the stated amount wouldn't turn on. 
