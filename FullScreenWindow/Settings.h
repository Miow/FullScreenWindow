#pragma once
#include "main.h"

#include "ui_fullscreenwindow.h"

#include "Engine.h"

#include "Parameters.h"
#include "WindowSelection.h"

class Settings
{
public:
	Settings();
	Settings(QMainWindow* mainWindow, Ui::FullScreenWindowClass* ui, Engine* engine);
	~Settings();

	QMainWindow* mainWindow;
	Ui::FullScreenWindowClass* ui;
	Engine* engine;

	Parameters parameters;
	WindowSelection windowSelection;

	QComboBox* comboBox_ProfileSelection;
	QPushButton* pushButton_Profile_Save;
	QPushButton* pushButton_Profile_Delete;
	QPushButton* pushButton_Profile_Duplicate;

	
	void on_comboBox_Monitor_currentIndexChanged(int index);
	// Updates the combobox to reflect the profile list
	void update_comboBox_ProfileSelection();
	// Returns a pointer to the currently selected profile
	Profile* getCurrentProfile();
	// Updates the current settings into the selected profile
	void saveCurrentProfile();
	// Saves the current settings as a new profile
	void saveCurrentProfileAs(QString newName);
	// Delete the current profile
	void deleteCurrentProfile();
};

