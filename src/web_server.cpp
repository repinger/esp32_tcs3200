#include <config.h>
#include <web_server.h>

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

void init_web_server(void)
{
	debug("Initializing web server . . .");
	server.begin();

	/* Web uri */
	server.on("/", root_webpage);
}
