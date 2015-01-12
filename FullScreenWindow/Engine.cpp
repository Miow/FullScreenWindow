#include "Engine.h"


Engine::Engine()
{
	monList = std::shared_ptr<MonitorList>(new MonitorList);
	monitor_updateList();
	
	proList = new ProfileList();
	Profile::initDefaults(proList);

	winList = new std::vector<Window*>();
}


Engine::~Engine()
{
	delete proList;
	delete winList;
}


void Engine::monitor_updateList()
{
	monList->update();
}

