#pragma once
#include "main.h"

#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>

#include "Engine.h"

static const QString QPRIMARY = QString::fromWCharArray(PRIMARY);

class Parameters
{
public:
	Parameters();
	Parameters(Engine* engine, QComboBox* combobox_Monitor);
	~Parameters();

	Engine* engine;

	QComboBox* combobox_Monitor;

	void on_comboBox_Monitor_currentIndexChanged(int index);
	// Updates the content of the combobox
	void update_comboBox_Monitor();
	// Updates the content of the combobox and tries to select
	// the specified monitor (defaults to Primary)
	void update_comboBox_Monitor(const Monitor* mon);


};

