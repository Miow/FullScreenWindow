#pragma once

#include "main.h"
#include "Monitor.h"

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

class Profile;
typedef std::vector<std::unique_ptr<Profile>> ProfileList;

class Profile
{
public:
	Profile();
	~Profile();

	static void initDefaults(ProfileList* proList);
	
	// A profile is identified by its name which is unique
	std::wstring name = L"";

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
	std::wstring screenName = PRIMARY;
	bool isCursorCliped = false;
	bool isTitleBarHidden = false;

};


