#include "MonitorHandling.h"

namespace Wrapper
{

	void MonitorHandling::getMonitors(MonitorList* monList)
	{
		BOOL res = 1;

		res = EnumDisplayMonitors(
			NULL,
			NULL,
			&(MonitorHandling::MonitorEnumProc),
			(LPARAM)&monList
			);

	}


	BOOL CALLBACK MonitorHandling::MonitorEnumProc(
		_In_  HMONITOR hMonitor,
		_In_  HDC hdcMonitor, // NULL because we passed NULL to EnumDisplayMonitors
		_In_  LPRECT lprcMonitor,
		_In_  LPARAM dwData // Not changed by EnumDisplayMonitors
		)
	{
		MONITORINFOEX monitorInfoEx;
		monitorInfoEx.cbSize = sizeof(MONITORINFOEX);

		BOOL res = GetMonitorInfo(hMonitor, &monitorInfoEx);

		if (res)
		{
			std::wstring name(monitorInfoEx.szDevice);
			bool isPrimary = monitorInfoEx.dwFlags & MONITORINFOF_PRIMARY;
			RECT rect = monitorInfoEx.rcMonitor;
			int left = rect.left,
				top = rect.top,
				right = rect.right,
				bottom = rect.bottom;

			std::shared_ptr<Monitor> mon(new Monitor(name, isPrimary, left, top, right, bottom));

			MonitorList* monList = (MonitorList*)dwData;
			monList->add(mon);

			LOG(info) << ((isPrimary) ? "PRIMARY " : "") << "Monitor \"" << name.c_str() << "\" found, coordonates: [(" << left << ", " << top << "), (" << right << ", " << bottom << ")].";
		}
		else
		{
			LOG(fatal) << "Unable to fill in monitor info.";
		}

		return TRUE;
	}


};
