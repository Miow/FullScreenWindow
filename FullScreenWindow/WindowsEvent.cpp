#include "stdafx.h"
#include "WindowsEvent.h"


namespace Wrapper
{

	WindowsEvent* WindowsEvent::instance = NULL;

	WindowsEvent* WindowsEvent::getInstance()
	{
		if (!instance)
			instance = new WindowsEvent;

		return instance;
	}

	WindowsEvent::WindowsEvent()
	{
	}
	WindowsEvent::~WindowsEvent()
	{
		disableHook();
		delete windowNameBuffer;
		delete instance;
	}

	void WindowsEvent::init(Engine* engine)
	{
		this->engine = engine;
		windowNameBuffer = new TCHAR[windowNameBufferSize];
	}

	

	void WindowsEvent::enableHook()
	{
		hook = SetWinEventHook(
			EVENT_SYSTEM_FOREGROUND,
			EVENT_SYSTEM_FOREGROUND,
			NULL,
			WindowsEvent::WinEventProcCallback,
			0,
			0,
			WINEVENT_OUTOFCONTEXT | WINEVENT_SKIPOWNPROCESS
			);
	}

	void WindowsEvent::disableHook()
	{
		BOOL res = UnhookWinEvent(hook);
		if (res == FALSE) {
			LOG(error) << "Unable to release the hook.";
		}
	}

	VOID CALLBACK WindowsEvent::WinEventProcCallback(HWINEVENTHOOK hWinEventHook, DWORD dwEvent, HWND hWnd, LONG idObject, LONG idChild, DWORD dwEventThread, DWORD dwmsEventTime)
	{
		WindowsEvent* inst = getInstance();
		GetWindowText(hWnd, inst->windowNameBuffer, inst->windowNameBufferSize);

		auto winList = inst->engine->winList;
		for (auto it = winList->begin(); it != winList->end(); it++)
		{
			if (wcscmp(inst->windowNameBuffer, it->getName().c_str()) == 0)
			{
				WindowHandling::applyProfile(hWnd, it->pro, inst->engine->getMonitorByName(it->pro->getMonitorName()));
				break;
			}
		}
			

	}

};