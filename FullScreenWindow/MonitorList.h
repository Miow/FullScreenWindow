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
	// if it is not found, returns the primary monitor
	Monitor* getMonitorByName(const std::wstring name);
	Monitor* getPrimaryMonitor();

	void add(Monitor mon);

	// Made public only for sequential read access
	std::vector <Monitor*> monList;

};
