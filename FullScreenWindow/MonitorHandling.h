#pragma once

#include "Monitor.h"

#include <string>
#include <windows.h>


namespace Wrapper
{
	namespace MonitorHandling
	{
		// Populate the MonitorList with the informations from every active monitor
		// note that the dimentions of the monitor might not be populated instanteneously
		void getMonitors(Monitorlist* monList);


		// Callback function for the EnumDisplayMonitors function
		BOOL CALLBACK MonitorEnumProc(
			_In_  HMONITOR hMonitor,
			_In_  HDC hdcMonitor,
			_In_  LPRECT lprcMonitor,
			_In_  LPARAM dwData
			);


	};

};