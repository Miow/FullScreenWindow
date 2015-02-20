#pragma once
#include "main.h"

#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QSpinBox>

#include <qstring>

#include "Engine.h"


class ProfileSettings
{
public:
	ProfileSettings();
	ProfileSettings(Engine* engine,
		QGroupBox* groupBox_Parameters,
		QGroupBox* groupBox_Size,
		QGroupBox* groupBox_Position,
		QComboBox* comboBox_Monitor,
		QCheckBox* checkBox_CursorClip,
		QCheckBox* checkBox_TitleBar,
		QSpinBox* spinBox_Height,
		QSpinBox* spinBox_Width,
		QCheckBox* checkBox_SizeIsRelative,
		QCheckBox* checkBox_TaskBar,
		QSpinBox* spinBox_Xpos,
		QSpinBox* spinBox_Ypos,
		QComboBox* comboBox_Anchor
		);
	~ProfileSettings();

	Engine* engine;

	QGroupBox* groupBox_Parameters;
	QGroupBox* groupBox_Size;
	QGroupBox* groupBox_Position;

	QComboBox* comboBox_Monitor;
	QCheckBox* checkBox_CursorClip;
	QCheckBox* checkBox_TitleBar;
	QSpinBox* spinBox_Height;
	QSpinBox* spinBox_Width;
	QCheckBox* checkBox_SizeIsRelative;
	QCheckBox* checkBox_TaskBar;
	QSpinBox* spinBox_Xpos;
	QSpinBox* spinBox_Ypos;
	QComboBox* comboBox_Anchor;


	Profile* currentProfile = NULL;
	void updateAll(Profile* newCurrentProfile);
	void setDisabledAll(bool isDisabled);


	QString comboBox_Monitor_getSelected();
	void comboBox_Monitor_setSelected(Monitor* mon);
	void comboBox_Monitor_setSelected(QString monName);


	// Updates the content of the combobox and tries to select
	// the specified monitor (defaults to Primary)
	void update_comboBox_Monitor();
	void update_comboBox_Monitor(Monitor* mon);
	void update_comboBox_Monitor(QString monName);

	void comboBox_Anchor_setValue(Profile::Anchor);
	Profile::Anchor comboBox_Anchor_getValue();



	void on_comboBox_Monitor_currentIndexChanged(int index);
	void on_checkBox_CursorClip_stateChanged(int state);
	void on_checkBox_TitleBar_stateChanged(int state);
	void on_spinBox_Height_valueChanged(int i);
	void on_spinBox_Width_valueChanged(int i);
	void on_checkBox_SizeIsRelative_stateChanged(int state);
	void on_checkBox_TaskBar_stateChanged(int state);
	void on_spinBox_Xpos_valueChanged(int i);
	void on_spinBox_Ypos_valueChanged(int i);
	void on_comboBox_Anchor_currentIndexChanged(int index);

};

