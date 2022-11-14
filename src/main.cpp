#include <Arduino.h>

#include <config.h>
#include <access_point.h>
#include <tcs3200.h>
#include <web_server.h>

void setup(void)
{
	pinMode(LED_BUILTIN, OUTPUT);
	Serial.begin(9600);

	if (!init_ap())
		return;
	tcs3200_init();
	init_web_server();
}

void loop(void)
{
	tcs3200_detect_color();
	delay(100);

	web_server_handle_client();
}
