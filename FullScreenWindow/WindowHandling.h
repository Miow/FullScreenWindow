#pragma once
#include "main.h"

#include <string>
#include <windows.h>

namespace Wrapper
{

	struct WindowHandle
	{
	public:
		std::wstring name;
		HWND hWnd;
	};


	namespace WindowHandling
	{
		// Returns a handle to a window currently open with the specified name
		// Return values are 1 if the window was found, 0 otherwise
		int getWindowByName(const std::wstring name, WindowHandle* wh);

		// Move and resize the specified window to given coordonates and size
		// X and Y are relative to the top left corner of the screen
		void moveAndResizeWindow(WindowHandle wh, int newX, int newY, int newWidth, int newHeight);

		// Toggle the titlebar and the border of a window, depending on the boolean
		void toggleTitleBar(WindowHandle wh, bool toggle);

		// Contrain the cursor to stay within the bound of the window
		void clipCursor(WindowHandle wh);
	};


};