#include <WebServer.h>

#define WEB_SERVER_PORT	80

WebServer server(WEB_SERVER_PORT);

extern void init_web_server(void);
