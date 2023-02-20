#include <Arduino.h>

#include <config.h>
#include <tcs3200.h>

static int get_red(void)
{
	int red_freq = 0;

	digitalWrite(S2, LOW);
	digitalWrite(S3, LOW);
	red_freq = get_freq();

	return map(red_freq, RED_MIN, RED_MAX, 255, 0);
}

static int get_green(void)
{
	int green_freq = 0;

	digitalWrite(S2, HIGH);
  	digitalWrite(S3, HIGH);
	green_freq = get_freq();

	return map(green_freq, GREEN_MIN, GREEN_MAX, 255, 0);
}

static int get_blue(void)
{
	int blue_freq = 0;

	digitalWrite(S2, LOW);
  	digitalWrite(S3, HIGH);
	blue_freq = get_freq();

	return map(blue_freq, BLUE_MIN, BLUE_MAX, 255, 0);
}

String tcs3200_detect_color(void)
{
	int red_color, green_color, blue_color;
	String color;

	red_color = get_red();
	sensor_delay();
	green_color = get_green();
	sensor_delay();
	blue_color = get_blue();
	sensor_delay();

	debug(red_color);
	debug(green_color);
	debug(blue_color);

	/* Handle no color */
	if (red_color < -255 || green_color < -255
	    || blue_color < -255) {
		debug("No color detected!");
		color = "None";
		return color;
	}

	/* Detect color */
	if (red_color > blue_color && red_color > green_color)
		color = "Red";
	else if (green_color > red_color && green_color > blue_color)
		color = "Green";
	else if (blue_color > red_color && blue_color > green_color)
		color = "Blue";

	return color;
}

void tcs3200_init(void)
{
	/* Pin mode set */
	pinMode(S0, OUTPUT);
	pinMode(S1, OUTPUT);
	pinMode(S2, OUTPUT);
	pinMode(S3, OUTPUT);
	pinMode(OUT_SENSOR, INPUT);

	digitalWrite(S0, HIGH);
  	digitalWrite(S1, LOW);
}
