#include "stdafx.h"
#include "WindowHandling.h"

namespace Wrapper
{

	int WindowHandling::getWindowByName(const std::wstring name, WindowHandle* wh)
	{
		wh->name = name;

		HWND hWnd = FindWindow(NULL, name.c_str());

		if (hWnd != NULL)
		{
			LOG(info) << "Window \"" << name.c_str() << "\" found.";
			wh->hWnd = hWnd;
			return 1;
		}
		else
		{
			LOG(info) << "Window \"" << name.c_str() << "\" not found.";
			return 0;
		}
		
	}


	void WindowHandling::moveAndResizeWindow(WindowHandle wh, int newX, int newY, int newWidth, int newHeight)
	{
		if (wh.hWnd == NULL)
		{
			LOG(error) << "Attempting to resize a window without providing a valid handle.";
			return;
		}


		BOOL res = MoveWindow(
			wh.hWnd,
			newX,
			newY,
			newWidth,
			newHeight,
			true		// This boolean mean the function will send a message to repaint the window
			);

		if (res)
		{
			LOG(info) << "Window \"" << wh.name.c_str() << "\" resized to " << newWidth << "x" << newHeight << " and moved to (" << newX << ", " << newY << ").";
		}
		else
		{
			LOG(error) << "Unable to move and resize window \"" << wh.name.c_str() << "\" to " << newWidth << "x" << newHeight << " (" << newX << ", " << newY << ").";
		}
	}

}