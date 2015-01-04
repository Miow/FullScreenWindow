#include "MonitorList.h"


MonitorList::MonitorList()
{
	monList = std::vector < std::shared_ptr<Monitor> >();
	update();
}

MonitorList::~MonitorList()
{
}


void MonitorList::update()
{
	Wrapper::MonitorHandling::getMonitors(this);
}



std::shared_ptr<Monitor> MonitorList::getMonitorByName(const std::wstring name)
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

std::shared_ptr<Monitor> MonitorList::getPrimaryMonitor()
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

void MonitorList::add(std::shared_ptr<Monitor> mon)
{
	monList.push_back(mon);
}