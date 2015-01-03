#include "fullscreenwindow.h"
#include <QtWidgets/QApplication>

#include "WindowHandling.h"
#include "log.h"


int main(int argc, char *argv[])
{
	initLog();

	Wrapper::WindowHandle* wh = new Wrapper::WindowHandle();
	Wrapper::WindowHandling::getWindowByName(L"VLC media player", wh);
	
	Wrapper::WindowHandling::moveAndResizeWindow(*wh, 100, 300, 500, 200);



	
	QApplication a(argc, argv);
	FullScreenWindow w;
	w.show();
	return a.exec();
}
