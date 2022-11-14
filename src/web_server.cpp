#include <config.h>
#include <web_server.h>

WebServer server(WEB_SERVER_PORT);

static void root_webpage(void)
{
	const char web_content[] =
		"<html>\
			<head>\
				<title> Heyy </title>\
			</head>\
			<body>\
				<h1> Halo, cuy </h1>\
			</body>\
		</html>";

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
