#pragma once
#include "main.h"

#include "MonitorList.h"
#include "Profile.h"

class Engine
{
public:
	Engine();
	~Engine();

	std::shared_ptr<MonitorList> monList;
	// Updates the monitor list
	void monitor_updateList();

	ProfileList proList;
	

private:
	


};

