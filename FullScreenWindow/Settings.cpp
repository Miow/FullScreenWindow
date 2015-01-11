#include "stdafx.h"
#include "Settings.h"


Settings::Settings(Ui::FullScreenWindowClass* ui, Engine* engine)
{
	this->ui = ui;
	this->engine = engine;

	parameters = Parameters();
	parameters.engine = engine;
	parameters.combobox_Monitor = ui->comboBox_Monitor;

	windowSelection = WindowSelection();
	windowSelection.engine = engine;
	windowSelection.listView_WindowSelection = ui->listView_WindowSelection;
}

Settings::Settings()
{
}


Settings::~Settings()
{
}
