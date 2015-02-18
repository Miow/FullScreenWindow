#pragma once
#include "main.h"

#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>

#include <qstring>

#include "Engine.h"


class Parameters
{
public:
	Parameters();
	Parameters(Engine* engine, QComboBox* combobox_Monitor);
	~Parameters();

	Engine* engine;

	QComboBox* combobox_Monitor;

	
	QString comboBox_Monitor_getSelected();
	void comboBox_Monitor_setSelected(Monitor* mon);
	void comboBox_Monitor_setSelected(QString monName);

	void on_comboBox_Monitor_currentIndexChanged(int index);
	// Updates the content of the combobox
	void update_comboBox_Monitor();
	// Updates the content of the combobox and tries to select
	// the specified monitor (defaults to Primary)
	void update_comboBox_Monitor(Monitor* mon);




};

