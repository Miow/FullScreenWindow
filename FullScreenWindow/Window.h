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

	Profile* pro;

	void setName(std::wstring newName);
	void setName(QString newName);

	const std::wstring getName();
	const QString getQName();

	void setProcessName(std::wstring newProcessName);
	void setProcessName(QString newProcessName);

	const std::wstring getProcessName();
	const QString getQProcessName();

private:
	std::wstring name;
	QString qname;

	std::wstring processName;
};

