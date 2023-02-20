#include <Arduino.h>

#include <config.h>
#include <access_point.h>
#include <tcs3200.h>
#include <web_server.h>

void setup(void)
{
	pinMode(LED_BUILTIN, OUTPUT);
#if DEBUG
	Serial.begin(9600);
#endif

	if (!init_ap())
		return;
	tcs3200_init();
	init_web_server();
}

void loop(void)
{
	web_server_handle_client();
}
