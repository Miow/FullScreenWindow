#include "fullscreenwindow.h"
#include <QtWidgets/QApplication>

#include "WindowHandling.h"


int main(int argc, char *argv[])
{


	Wrapper::WindowHandle* wh = new Wrapper::WindowHandle();
	Wrapper::WindowHandling::getWindowByName(L"VLC media player", wh);
	ShowWindow(wh->hWnd, SW_SHOW);




	
	QApplication a(argc, argv);
	FullScreenWindow w;
	w.show();
	return a.exec();
}
