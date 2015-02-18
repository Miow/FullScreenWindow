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


