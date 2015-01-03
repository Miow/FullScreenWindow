#include "fullscreenwindow.h"
#include <QtWidgets/QApplication>

#include "WindowHandling.h"
#include "MonitorHandling.h"

#include "Monitor.h"
#include "MonitorList.h"

int main(int argc, char *argv[])
{
	initLog();

	Wrapper::WindowHandle* wh = new Wrapper::WindowHandle();
	Wrapper::WindowHandling::getWindowByName(L"VLC media player", wh);
	
	Wrapper::WindowHandling::moveAndResizeWindow(*wh, -1000, 300, 500, 200);

	std::shared_ptr<MonitorList> monList(new MonitorList());
	Wrapper::MonitorHandling::getMonitors(monList);

	
	QApplication a(argc, argv);
	FullScreenWindow w;
	w.show();
	return a.exec();
}
