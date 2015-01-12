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

	const std::wstring getName();
	const QString getQName();

private:
	std::wstring name;
	QString qname;
};

