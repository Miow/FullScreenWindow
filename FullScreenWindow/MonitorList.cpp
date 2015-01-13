#include "MonitorList.h"


MonitorList::MonitorList()
{
	monList = new std::vector < Monitor >();
}

MonitorList::~MonitorList()
{
	delete monList;
}


void MonitorList::update()
{
	monList->clear();
	Wrapper::MonitorHandling::getMonitors(monList);
}



Monitor* MonitorList::getMonitorByName(const std::wstring name)
{
	if (name == PRIMARY)
	{
		return getPrimaryMonitor();
	}

	for (auto it = monList->begin(); it != monList->end(); it++)
	{
		if (it->name == name)
		{
			return &(*it);
		}
	}

	LOG(error) << "Monitor \"" << name << "\" not found, defaulting to primary.";
	return getPrimaryMonitor();
}

Monitor* MonitorList::getPrimaryMonitor()
{
	return &monList->at(0);
}
