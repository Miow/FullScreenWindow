#pragma once
#include "main.h"

#include "Window.h"
#include "MonitorList.h"
#include "Profile.h"
#include "WindowsEvent.h"

#include <vector>

class Engine
{
public:
	Engine();
	~Engine();

	MonitorList* monList;
	// Updates the monitor list
	void monitor_updateList();

	std::vector<Profile>* proList;
	std::vector<Window>* winList;

};

