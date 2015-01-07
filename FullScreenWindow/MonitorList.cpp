#include "MonitorList.h"


MonitorList::MonitorList()
{
	monList = std::vector < Monitor* >();
}

MonitorList::~MonitorList()
{
}


void MonitorList::update()
{
	monList.clear();
	Wrapper::MonitorHandling::getMonitors(this);
}



Monitor* MonitorList::getMonitorByName(const std::wstring name)
{
	if (name == PRIMARY)
	{
		return getPrimaryMonitor();
	}

	for (auto it = monList.begin(); it != monList.end(); it++)
	{
		if ((*it)->name == name)
		{
			return *it;
		}
	}

	LOG(error) << "Monitor \"" << name << "\" not found, defaulting to primary.";
	return getPrimaryMonitor();
}

Monitor* MonitorList::getPrimaryMonitor()
{
	for (auto it = monList.begin(); it != monList.end(); it++)
	{
		if ((*it)->isPrimary)
		{
			return *it;
		}
	}

	LOG(fatal) << "No primary monitor found while searching the list.";
	return NULL;
}

void MonitorList::add(Monitor mon)
{
	monList.push_back(new Monitor(mon));
}