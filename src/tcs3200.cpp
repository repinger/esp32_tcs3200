#include <Arduino.h>

#include <config.h>
#include <tcs3200.h>

static int get_color(int color_code)
{
	int color_freq = 0;
	int color_min, color_max;

	switch (color_code) {
	case RED_CODE:
		digitalWrite(S2, LOW);
		digitalWrite(S3, LOW);

		color_freq = get_freq();
		color_min = RED_MIN;
		color_max = RED_MAX;
		goto ret;
	case GREEN_CODE:
		digitalWrite(S2, HIGH);
  		digitalWrite(S3, HIGH);

		color_freq = get_freq();
		color_min = GREEN_MIN;
		color_max = GREEN_MAX;
		goto ret;
	case BLUE_CODE:
		digitalWrite(S2, LOW);
  		digitalWrite(S3, HIGH);

		color_freq = get_freq();
		color_min = BLUE_MIN;
		color_max = BLUE_MAX;
		goto ret;
	default:
		return EINVAL;
		break;
	}

ret:
	return map(color_freq, color_min, color_max, 255, 0);
}

String tcs3200_detect_color(void)
{
	int red_color, green_color, blue_color;
	String color;

	red_color = get_color(RED_CODE);
	sensor_delay();
	green_color = get_color(GREEN_CODE);
	sensor_delay();
	blue_color = get_color(BLUE_CODE);
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
