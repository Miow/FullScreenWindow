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
		ui->pushButton_wAdd,
		ui->pushButton_wRemove,
		ui->pushButton_wRename,
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
	profileSettings = ProfileSettings(
		engine,
		ui->groupBox_Parameters,
		ui->groupBox_Size,
		ui->groupBox_Position,
		ui->comboBox_Monitor,
		ui->checkBox_CursorClip,
		ui->checkBox_TitleBar,
		ui->spinBox_Height,
		ui->spinBox_Width,
		ui->checkBox_SizeIsRelative,
		ui->checkBox_TaskBar,
		ui->spinBox_Xpos,
		ui->spinBox_Ypos,
		ui->comboBox_Anchor
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