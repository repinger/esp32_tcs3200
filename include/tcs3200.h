/*
 * TCS3200 sensor module header file
 */

/* Pins */
#define S0 		16
#define S1 		17
#define S2 		12
#define S3 		13
#define OUT_SENSOR 	35

#define	RED_CODE	1
#define BLUE_CODE	2
#define GREEN_CODE	3

/* Color calibration value */
#define RED_MIN		103
#define RED_MAX		159
#define GREEN_MIN	172
#define GREEN_MAX	351
#define BLUE_MIN	110
#define BLUE_MAX	189

#define SENSOR_DELAY_MS	150

#define sensor_delay() \
	delay(SENSOR_DELAY_MS);

String tcs3200_detect_color(void);
void tcs3200_init(void);
