#pragma once

#include "main.h"
#include "Profile.h"

#include <string>

class Window
{
public:
	Window();
	~Window();

	std::wstring name;
	std::wstring processName;

	Profile* pro;

};

