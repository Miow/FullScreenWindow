#include "stdafx.h"
#include "fullscreenwindow.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
	initLog();
	
	QApplication a(argc, argv);
	FullScreenWindow w;
	w.show();
	return a.exec();
}
