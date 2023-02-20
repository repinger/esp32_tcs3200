#include <config.h>
#include <web_server.h>
#include <tcs3200.h>

WebServer server(WEB_SERVER_PORT);

static void root_webpage(void)
{
	String web_content;

	web_content += "<html lang=\"en\">";
	web_content += "<head>";
	web_content += "<meta charset=\"UTF-8\">";
	web_content += "<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">";
	web_content += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">";
	web_content += "<title> Color Detector! </title>";
	web_content += "</head>";
	web_content += "<body>";
	web_content += "<h1> Warna </h1>";
	web_content += tcs3200_detect_color();
	web_content += "</body>";

	server.send(200, "text/html", web_content);
}

void web_server_handle_client(void)
{
	server.handleClient();
}

void init_web_server(void)
{
	debug("Initializing web server . . .");
	server.begin();

	/* Web uri */
	server.on("/", root_webpage);
}
