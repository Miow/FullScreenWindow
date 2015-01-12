#pragma once

#include "main.h"
#include "Profile.h"

#include <qstring.h>
#include <string>

class Window
{
public:
	Window();
	~Window();

	std::wstring processName;

	Profile* pro;

	void setName(std::wstring newName);
	void setName(QString newName);

	std::wstring getName();
	QString getQName();

private:
	std::wstring name;
	QString qname;
};

