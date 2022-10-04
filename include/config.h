/* 
 * Config header
 */

#define DEBUG		1

#define LED_BUILTIN	2

#if DEBUG
#define debug(x) \
	Serial.println(); \
	Serial.println(x);
#else
#define debug(x)
#endif
