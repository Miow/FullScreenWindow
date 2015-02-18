#pragma once

#include "main.h"
#include "Monitor.h"
#include "MonitorList.h"

#include <qstring.h>
#include <string>
#include <vector>

enum Anchor
{
	TOPLEFT,
	TOPRIGHT,
	CENTER,
	BOTTOMLEFT,
	BOTTOMRIGHT
};


class Profile
{
public:
	Profile();
	~Profile();

	static void initDefaults(std::vector<Profile>* proList, MonitorList* monList);
	
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

	Monitor* mon;

private:
	// A profile is identified by its name which is unique
	std::wstring name = L"";
	QString qname;
};


