#pragma once
#include "main.h"

#include "Profile.h"

#include <string>
#include <windows.h>

namespace Wrapper
{
	namespace WindowHandling
	{
		// Returns a handle to a window currently open with the specified name
		// Return values are 1 if the window was found, 0 otherwise
		HWND getWindowByName(const std::wstring name);

		
		// Move and resize the specified window to given coordonates and size
		// X and Y are relative to the top left corner of the screen
		void moveAndResizeWindow(HWND hWnd, int newX, int newY, int newWidth, int newHeight);
		// Move and resize the window to the specifications of the profile
		void moveAndResizeWindow(HWND hWnd, const Profile* pro);

		// remove the titlebar and the border of a window
		void removeTitleBar(HWND hWnd);

		// Contrain the cursor to stay within the bound of the window
		void clipCursor(HWND hWnd);

		// Apply the options of the specified profile to the window
		void applyProfile(HWND hWnd, Profile* pro);
	};


};