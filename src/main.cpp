#include <Arduino.h>

#include <config.h>
#include <access_point.h>
#include <web_server.h>

void setup(void)
{
	pinMode(LED_BUILTIN, OUTPUT);
	Serial.begin(9600);

	if (!init_ap())
		return;
	init_web_server();
}

void loop(void)
{
	server.handleClient();
}
