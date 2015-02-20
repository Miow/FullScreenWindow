#pragma once

#include "main.h"
#include "Monitor.h"
#include "MonitorList.h"

#include <qstring.h>
#include <string>
#include <vector>

#define PROFILE_DEFAULT_DISABLED L"Disabled"
#define PROFILE_DEFAULT_FULLSCREEN L"Fullscreen"

class Profile
{
public:
	enum Anchor
	{
		TOPLEFT,
		TOPRIGHT,
		CENTER,
		BOTTOMLEFT,
		BOTTOMRIGHT
	};

	Profile();
	~Profile();

	static void initDefaults(std::vector<Profile>* proList, MonitorList* monList);
	
	bool isUserCreated = true;

	// Name
	void setName(std::wstring newName);
	void setName(QString newName);
	const std::wstring getName();
	const QString getQName();

	// Size
	int width = 0;
	int height = 0;
	// Determine if the width and height are absolute or a percentage of the screen size
	bool isSizeRelative = true;

	// Position
	int xpos = 0;
	int ypos = 0;
	Anchor anchor = Anchor::TOPLEFT;

	// Settings
	bool isCursorCliped = false;
	bool isTitleBarHidden = false;
	bool isTaskBarShown = false;

	// Monitor
	void setMonitorName(std::wstring newMonitorName);
	void setMonitorName(QString newMonitorName);
	const std::wstring getMonitorName();
	const QString getQMonitorName();

private:
	// A profile is identified by its name which is unique
	std::wstring name = L"";
	QString qname;

	std::wstring monitorName = L"";
	QString qmonitorName;
};


