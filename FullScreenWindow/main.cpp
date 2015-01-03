#include "fullscreenwindow.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
	initLog();
	/*
	ProfileList proList;
	Profile::initDefaults(&proList);
	*/
	
	QApplication a(argc, argv);
	FullScreenWindow w;
	w.show();
	return a.exec();
}
