#include "stdafx.h"
#include "Parameters.h"


Parameters::Parameters(Engine* engine, QComboBox* combobox_Monitor)
{
	this->engine = engine;
	
	this->combobox_Monitor = combobox_Monitor;
}

Parameters::Parameters()
{
}
Parameters::~Parameters()
{
}



QString Parameters::comboBox_Monitor_getSelected()
{
	return combobox_Monitor->currentText();
}

void Parameters::comboBox_Monitor_setSelected(Monitor* mon)
{
	comboBox_Monitor_setSelected(mon->getQName());
}

void Parameters::comboBox_Monitor_setSelected(QString monName)
{
	// Searching the index of the monitor in the list
	int index = combobox_Monitor->findText(monName);
	// If it is not found, default to primary
	if (index == -1)
	{
		LOG(error) << "Monitor \"" << monName.toStdString() << "\" not found in the combobox, defaulting to primary.";
		index = 0;
	}
	combobox_Monitor->setCurrentIndex(index);
}


void Parameters::on_comboBox_Monitor_currentIndexChanged(int index)
{	
	
}



void Parameters::update_comboBox_Monitor()
{
	QString lastSelectedMonitorName = comboBox_Monitor_getSelected();

	// Clears the content of the list
	int nbItems = combobox_Monitor->count();
	for (int i = 0; i < nbItems; i++)
	{
		combobox_Monitor->removeItem(0);
	}

	// Updates the monitor list
	engine->monitor_updateList();

	// Fill in the combobox
	combobox_Monitor->addItem(QPRIMARY); // Adding the primary monitor as the first item of the list

	for (
		auto it = engine->monList->monList->begin()+1; // /!\ We start at index 1
		it != engine->monList->monList->end();
		it++
		)
	{
		QString name = it->getQName();
		if (it->isPrimary)
		{
			name = name + " (" + QPRIMARY + ")";
		}
		combobox_Monitor->addItem(name);
	}

	comboBox_Monitor_setSelected(lastSelectedMonitorName);
}

void Parameters::update_comboBox_Monitor(Monitor* mon)
{
	update_comboBox_Monitor();
	comboBox_Monitor_setSelected(mon);
}