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
	std::shared_ptr<Monitor> getMonitorByName(const std::wstring name);
	std::shared_ptr<Monitor> getPrimaryMonitor();

	void add(std::shared_ptr<Monitor> mon);

	// Made public only for sequential read access
	std::vector < std::shared_ptr<Monitor> > monList;

};
