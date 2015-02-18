#pragma once
#include "main.h"

#include "Monitor.h"
#include "MonitorHandling.h"

#include <vector>


class MonitorList
{
public:
	MonitorList();
	~MonitorList();

	// Populate the list with monitor informations from the system
	void update();

	// Returns the monitor with the specified name
	// if not found, returns the primary monitor
	Monitor* getMonitorByName(const std::wstring name);
	Monitor* getMonitorByName(QString name);
	// Returns the pointer to the primary monitor
	Monitor* getPrimaryMonitor();

	// ONLY FOR READ ACCESS, please
	std::vector < Monitor >* monList;


};
