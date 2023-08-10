# MSG2_Arduino_LED_Test_Code

Make sure to install the FastLED library first. 

The current code, which is flashed on one of the Nano, only controls one strip connected to the d2 pin. Will send a second version that controls both strips. There are some commented codes that show other animations and the uncommented code shows a colourful sine wave animation to see if data is sent properly. 

The code assumes 106 LEDs per strip because that is how many LEDs I counted that can cover the full height of the MSG2 tower. Even if the actual strip has less than the indicated amount in the code, it doesn't affect the LEDs. If more, the LEDs after the stated amount wouldn't turn on. 
