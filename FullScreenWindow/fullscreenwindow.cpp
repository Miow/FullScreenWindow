#include "fullscreenwindow.h"

FullScreenWindow::FullScreenWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	preview = new Preview(ui.graphicsView_Preview);
	preview->defaultView();

	// Connections
	connect(ui.pushButton_toggleProfilesSettings, &QPushButton::clicked, this, &FullScreenWindow::on_pushButton_toggleProfilesSettings_clicked);


}

FullScreenWindow::~FullScreenWindow()
{
	
}



void FullScreenWindow::on_pushButton_toggleProfilesSettings_clicked()
{
	if (ui.groupBox_ProfileSettings->isHidden())
	{
		ui.groupBox_ProfileSettings->show();
	}
	else
	{
		ui.groupBox_ProfileSettings->hide();
	}
}