#pragma once
#include "main.h"

#include "Window.h"
#include "MonitorList.h"
#include "Profile.h"

#include <vector>

class Engine
{
public:
	Engine();
	~Engine();

	std::shared_ptr<MonitorList> monList;
	// Updates the monitor list
	void monitor_updateList();

	ProfileList* proList;
	std::vector<Window*>* winList;

private:
	
	

};

