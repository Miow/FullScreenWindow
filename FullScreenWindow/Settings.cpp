#include "Settings.h"


Settings::Settings(Ui::FullScreenWindowClass* ui, Engine* engine)
{
	this->ui = ui;
	this->engine = engine;

	parameters = Parameters();
	parameters.engine = engine;
	parameters.combobox_Monitor = ui->comboBox_Monitor;
}

Settings::Settings()
{
}


Settings::~Settings()
{
}
