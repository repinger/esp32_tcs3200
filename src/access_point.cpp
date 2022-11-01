#include <WiFi.h>
#include <WiFiAP.h>

#include <access_point.h>
#include <config.h>

bool init_ap(void)
{
	bool configure_ssid;
	const int blink = 5;

	IPAddress local_ip(10, 0, 8, 254);
	IPAddress gateway(10, 0, 8, 254);
	IPAddress subnet(255, 255, 255, 0);

	/* Start AP */
	debug("Initializing AP . . .");
	configure_ssid = WiFi.softAP(SSID_NAME, SSID_PASSWORD)
			 && WiFi.softAPConfig(local_ip,
			 		      gateway, subnet);
	if (!configure_ssid) {
		debug("Failed to initialize AP; aborting . . .");
		return false;
	}

	debug(WiFi.softAPIP());
	debug(WiFi.softAPSubnetCIDR());
	debug(WiFi.softAPmacAddress());
	debug("LED on!");
	for (int i = 0 ; i < blink; i++) {
		digitalWrite(LED_BUILTIN, HIGH);
		delay(300);
		digitalWrite(LED_BUILTIN, LOW);
		delay(300);
	}
	debug("AP initialized!");

	return true;
}
