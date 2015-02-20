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
	// Updates the monitor list with the current informations from the system
	void monitor_updateList();
	// Returns a pointer to the monitor with the specified name
	// If it does not exist, returns a pointer to the primary monitor
	Monitor* getMonitorByName(std::wstring monitorName);


	std::vector<Profile>* proList;
	// Returns the default profile
	Profile* getDefaultProfile();

	std::vector<Window>* winList;
	void removeWindow(Window*);
};

