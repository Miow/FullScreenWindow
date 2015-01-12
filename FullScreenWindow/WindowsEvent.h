#pragma once
#include "main.h"

#include "Engine.h"
#include "WindowHandling.h"

#include <Windows.h>

class Engine;

namespace Wrapper
{
	class WindowsEvent
	{
	public:
		static WindowsEvent* getInstance();
		~WindowsEvent();
		
		// Initialize the class, this function should be called before anything else
		void init(Engine* engine);

		Engine* engine;

		TCHAR* windowNameBuffer;
		const int windowNameBufferSize = 250;


		// Start hooking the EVENT_SYSTEM_FOREGROUND event
		void enableHook();
		// Stops the hook
		void disableHook();

		static VOID CALLBACK WinEventProcCallback(HWINEVENTHOOK hWinEventHook, DWORD dwEvent, HWND hwnd, LONG idObject, LONG idChild, DWORD dwEventThread, DWORD dwmsEventTime);

	private:
		WindowsEvent();
		static WindowsEvent* instance;

		HWINEVENTHOOK hook;
	};
};

