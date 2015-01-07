#include "fullscreenwindow.h"

FullScreenWindow::FullScreenWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	engine = Engine();
	settings = Settings(&ui, &engine);
	ui.setupUi(this);

	preview = new Preview(ui.graphicsView_Preview);
	preview->defaultView();


	// CONNECTIONS
	connect(ui.pushButton_toggleProfilesSettings, &QPushButton::clicked, this, &FullScreenWindow::on_pushButton_toggleProfilesSettings_clicked);
	// // Settings
	// // // Parameters
	connect(ui.comboBox_Monitor, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &FullScreenWindow::on_comboBox_Monitor_currentIndexChanged);

	


	UpdateFromProfile(engine.proList[0]);
}

FullScreenWindow::~FullScreenWindow()
{
	
}


void FullScreenWindow::UpdateFromProfile(const std::shared_ptr<Profile> pro)
{

	// Update monitor selection box
	Monitor* mon = engine.monList->getMonitorByName(pro->screenName);
	settings.parameters.update_comboBox_Monitor(mon);
	// TODO: UPDATE SELECTED MONITOR
}



// CONNECT

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


void FullScreenWindow::on_comboBox_Monitor_currentIndexChanged(int index)
{

}