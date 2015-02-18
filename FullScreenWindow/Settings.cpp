#include "stdafx.h"
#include "Settings.h"


Settings::Settings(QMainWindow* mainWindow, Ui::FullScreenWindowClass* ui, Engine* engine)
{
	this->mainWindow = mainWindow;
	this->ui = ui;
	this->engine = engine;

	windowSelection = WindowSelection(
		mainWindow,
		engine,
		ui->listView_WindowSelection,
		ui->comboBox_ProfileSelection,
		ui->lineEdit_ProcessName
		);
	profileSelector = ProfileSelector(
		engine,
		ui->comboBox_ProfileSelection_2,
		ui->pushButton_Profile_Save,
		ui->pushButton_Profile_Delete,
		ui->pushButton_Profile_Duplicate
		); 
	parameters = Parameters(
		engine,
		ui->comboBox_Monitor
		);

}

Settings::Settings()
{
}


Settings::~Settings()
{
}


Window* Settings::getCurrentWindow()
{
	return windowSelection.getCurrentWindow();
}

Profile* Settings::getCurrentProfile()
{
	return windowSelection.getCurrentProfile();
}