#include "stdafx.h"
#include "Settings.h"


Settings::Settings(QMainWindow* mainWindow, Ui::FullScreenWindowClass* ui, Engine* engine)
{
	this->mainWindow = mainWindow;
	this->ui = ui;
	this->engine = engine;

	parameters = Parameters(engine, ui->comboBox_Monitor);
	windowSelection = WindowSelection(mainWindow, engine, ui->listView_WindowSelection);
}

Settings::Settings()
{
}


Settings::~Settings()
{
}
