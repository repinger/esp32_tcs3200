#include <Arduino.h>

#include <access_point.h>
#include <config.h>

void setup(void)
{
	pinMode(LED_BUILTIN, OUTPUT);
	Serial.begin(9600);

	if (!init_ap())
		return;
}

void loop(void)
{
}
