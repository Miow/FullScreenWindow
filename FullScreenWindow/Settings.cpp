#include "stdafx.h"
#include "Settings.h"


Settings::Settings(QMainWindow* mainWindow, Ui::FullScreenWindowClass* ui, Engine* engine)
{
	this->mainWindow = mainWindow;
	this->ui = ui;
	this->engine = engine;

	parameters = Parameters(engine, ui->comboBox_Monitor);
	windowSelection = WindowSelection(mainWindow, engine, ui->listView_WindowSelection);

	comboBox_ProfileSelection = ui->comboBox_ProfileSelection_2;
	pushButton_Profile_Save = ui->pushButton_Profile_Save;
	pushButton_Profile_Delete = ui->pushButton_Profile_Delete;
	pushButton_Profile_Duplicate = ui->pushButton_Profile_Duplicate;
}

Settings::Settings()
{
}


Settings::~Settings()
{
}


void on_comboBox_Monitor_currentIndexChanged(int index)
{
	Profile* currentPro = engine->proList->at(index);
	ici faut check et tout et griser les boutons qui servent a rien
}
/*
void Settings::update_comboBox_ProfileSelection();
{

}
*/
Profile* Settings::getCurrentProfile()
{
	int index = comboBox_ProfileSelection->currentIndex();

	if (index < 0 || index > engine->proList->size())
	{
		return NULL;
	}
	else
	{
		return &engine->proList->at(index);
	}
	
}

void Settings::saveCurrentProfile()
{

}

void Settings::saveCurrentProfileAs(QString newName)
{

}

void Settings::deleteCurrentProfile()
{

}