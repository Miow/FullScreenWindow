#pragma once
#include "main.h"

#include <QtWidgets/QComboBox>
#include <QtWidgets/QPushButton>

#include "Engine.h"

class ProfileSelector
{
public:
	ProfileSelector();
	ProfileSelector(Engine* engine,
		QComboBox* comboBox_ProfileSelection_2,
		QPushButton* pushButton_Profile_Save,
		QPushButton* pushButton_Profile_Delete,
		QPushButton* pushButton_Profile_Duplicate
		);
	~ProfileSelector();

	Engine* engine;

	QComboBox* comboBox_ProfileSelection_2;
	QPushButton* pushButton_Profile_Save;
	QPushButton* pushButton_Profile_Delete;
	QPushButton* pushButton_Profile_Duplicate;


	void on_comboBox_ProfileSelection_2_currentIndexChanged(int index);
	// Updates the combobox to reflect the profile list
	void update_comboBox_ProfileSelection_2();
	// Returns a pointer to the currently selected profile
	Profile* getCurrentProfile();
	// Updates the current settings into the selected profile
	void saveCurrentProfile();
	// Saves the current settings as a new profile
	void saveCurrentProfileAs(QString newName);
	// Delete the current profile
	void deleteCurrentProfile();
};

