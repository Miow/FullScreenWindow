#pragma once
#include "main.h"

#include "MonitorList.h"

#include <string>
#include <windows.h>

class MonitorList;

namespace Wrapper
{
	namespace MonitorHandling
	{
		// Populate the MonitorList with the informations from every active monitor
		void getMonitors(std::vector<Monitor>* monList);


		// Callback function for the EnumDisplayMonitors function
		BOOL CALLBACK MonitorEnumProc(
			_In_  HMONITOR hMonitor,
			_In_  HDC hdcMonitor,
			_In_  LPRECT lprcMonitor,
			_In_  LPARAM dwData
			);

		
	};

};