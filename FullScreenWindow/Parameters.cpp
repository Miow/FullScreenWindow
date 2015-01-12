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


void Parameters::on_comboBox_Monitor_currentIndexChanged(int index)
{
	// The index 0 is just a link to the primary monitor
	if (index == 0)
	{
		engine->monList->getPrimaryMonitor();
	}
	else
	{
		engine->monList->monList[index - 1];
	}
	update_comboBox_Monitor();
}




void Parameters::update_comboBox_Monitor()
{
	// Clears the content of the list
	int nbItems = combobox_Monitor->count();
	for (int i = 0; i < nbItems; i++)
	{
		combobox_Monitor->removeItem(0);
	}

	// Updates the monitor list
	engine->monitor_updateList();

	// Add the primary monitor on top of the others
	combobox_Monitor->addItem(QPRIMARY);

	// Fill in the combobox
	for (auto it = engine->monList->monList.begin(); it != engine->monList->monList.end(); it++)
	{
		QString name = QString::fromWCharArray((*it)->name.c_str());
		if ((*it)->isPrimary)
		{
			name = name + " (" + QPRIMARY + ")";
		}
		combobox_Monitor->addItem(name);
	}
}

void Parameters::update_comboBox_Monitor(const Monitor* mon)
{
	update_comboBox_Monitor();

	// Searching the index of the monitor in the list
	int index = combobox_Monitor->findText(QString::fromWCharArray(mon->name.c_str()));
	// If it is not found, default to primary
	if (index == -1)
	{
		index = 0;
	}
	combobox_Monitor->setCurrentIndex(index);
}