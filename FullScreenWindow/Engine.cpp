#include "Engine.h"


Engine::Engine()
{
	monList = new MonitorList;
	monitor_updateList();
	
	proList = new std::vector<Profile>();
	Profile::initDefaults(proList, monList);

	winList = new std::vector<Window>();

	{ // Start the windows event hook
		Wrapper::WindowsEvent* instance = Wrapper::WindowsEvent::getInstance();
		instance->init(this);
		instance->enableHook();
	}
}


Engine::~Engine()
{
	Wrapper::WindowsEvent::getInstance()->disableHook();
	delete winList;
	delete proList;
	delete monList;
}


void Engine::monitor_updateList()
{
	monList->update();
}


Profile* Engine::getDefaultProfile()
{
	return &(proList->at(0));
}


Monitor* Engine::getMonitorByName(std::wstring monitorName)
{
	return monList->getMonitorByName(monitorName);
}

void Engine::removeWindow(Window* win)
{
	if (win == NULL)
	{
		LOG(fatal) << "Null argument";
		return;
	}

	// Removing the window from the list
	for (auto it = winList->begin(); it != winList->end(); it++)
	{
		if (&(*it) == win)
		{
			winList->erase(it);
			return;
		}
	}

	LOG(fatal) << "Enable to remove the window \"" << win->getName() << "\" from the list because it is not present on it."; 
}

