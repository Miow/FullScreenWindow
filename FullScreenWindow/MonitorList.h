#pragma once

#include "Monitor.h"

#include <vector>

class MonitorList
{
public:
	MonitorList();
	~MonitorList();

	// Returns the monitor with the specified name, if it is not found, returns the primary monitor
	std::shared_ptr<Monitor> getMonitorByName(const std::wstring name);
	std::shared_ptr<Monitor> getPrimaryMonitor();

	void add(std::shared_ptr<Monitor> mon);

private:
	std::vector < std::shared_ptr<Monitor> > monList;

};
