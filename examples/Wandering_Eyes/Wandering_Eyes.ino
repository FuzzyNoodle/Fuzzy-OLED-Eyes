/*
    Name:       Wandering_Eyes.ino
    Created:	2019/6/5 09:29:37
    Author:     MSI_GS70\georgychen
*/

#include "Fuzzy_OLED_Eyes.h"
#include <Wire.h>
#include "Adafruit_ZeroDMA_For_OLED.h"

//Include the eyes bitmap arrays. Array names are passed in the oled.begin() function.
#include "Eyes_UpperEyelid_128x64.h"
#include "Eyes_Pupil_64x64.h"
#include "Eyes_LowerEyelid_128x64.h"


Fuzzy_OLED_Eyes eyes;

void setup()
{
	Serial.begin(115200);
	//while (!Serial) { ; }// wait for serial port to connect
	Serial.println("Wandering Eyes sketch started.");

	eyes.begin(Eyes_UpperEyelid_128x64, Eyes_Pupil_64x64, Eyes_LowerEyelid_128x64);

	eyes.startAutoMovement();
	eyes.startAutoBlink();
}

void loop()
{
	eyes.update();
}
