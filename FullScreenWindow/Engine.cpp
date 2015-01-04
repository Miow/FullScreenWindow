#include "Engine.h"


Engine::Engine()
{
	monList = std::shared_ptr<MonitorList>(new MonitorList);
	monitor_updateList();
	
	proList = ProfileList();
	Profile::initDefaults(&proList);
}


Engine::~Engine()
{
}


void Engine::monitor_updateList()
{
	monList->update();
}

