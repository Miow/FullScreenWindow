#include "stdafx.h"
#include "WindowHandling.h"

namespace Wrapper
{

	HWND WindowHandling::getWindowByName(const std::wstring name)
	{
		HWND hWnd = FindWindow(NULL, name.c_str());

		if (hWnd != NULL)
		{
			LOG(info) << "Window \"" << name.c_str() << "\" found.";
			return hWnd;
		}
		else
		{
			LOG(info) << "Window \"" << name.c_str() << "\" not found.";
			return NULL;
		}
		
	}

	
	void WindowHandling::moveAndResizeWindow(HWND hWnd, int newX, int newY, int newWidth, int newHeight)
	{
		if (hWnd == NULL)
		{
			LOG(error) << "Attempting to resize a window without providing a valid handle.";
			return;
		}
		

		BOOL res = MoveWindow(
			hWnd,
			newX,
			newY,
			newWidth,
			newHeight,
			TRUE		// This boolean mean the function will send a message to repaint the window
			);

		if (res)
		{
			LOG(info) << "Window resized to " << newWidth << "x" << newHeight << " and moved to (" << newX << ", " << newY << ").";
		}
		else
		{
			LOG(error) << "Unable to move and resize window to " << newWidth << "x" << newHeight << " (" << newX << ", " << newY << ").";
		}

		//UpdateWindow(hWnd);
		//RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);

	}

	void WindowHandling::moveAndResizeWindow(HWND hWnd, const Profile* pro)
	{
		// Calculating the dimentions depending on the screen
		
		int x, y, width, height;

		x = pro->xpos + pro->mon->left;
		y = pro->ypos + pro->mon->top;

		if (pro->isSizeRelative)
		{
			width = pro->width + pro->mon->width;
			height = pro->height + pro->mon->height;
		}
		else
		{
			width = pro->width;
			height = pro->height;
		}

		moveAndResizeWindow(hWnd, x, y, width, height);
	}


	void WindowHandling::removeTitleBar(HWND hWnd)
	{
		// Removig title bar and border
		SetWindowLong(hWnd,
			GWL_STYLE,
			// Removing the border from the window's style
			GetWindowLong(hWnd, GWL_STYLE) & ~(WS_BORDER | WS_DLGFRAME | WS_THICKFRAME)
			);
		SetWindowLong(hWnd,
			GWL_EXSTYLE,
			GetWindowLong(hWnd, GWL_EXSTYLE) & ~WS_EX_DLGMODALFRAME
			);
		
	}

	void WindowHandling::clipCursor(HWND hWnd)
	{
		// Getting the rectagle from the window
		RECT clippingRECT;
		GetWindowRect(hWnd, &clippingRECT);

		// Locking the cursor in the recangle
		ClipCursor(&clippingRECT);

		// Bring the window to the foreground and activates it
		//SetActiveWindow(hWnd);
	}


	void WindowHandling::applyProfile(HWND hWnd, Profile* pro)
	{
		// Removing title bars
		if (pro->isTitleBarHidden)
		{
			removeTitleBar(hWnd);
		}

		// Resizeing and moving
		moveAndResizeWindow(hWnd, pro);

		// Cliping the cursor
		if (pro->isCursorCliped)
		{
			clipCursor(hWnd);
		}
	}
}