#pragma once
#include "main.h"

#include <string>

enum Anchor
{
	TOPLEFT,
	TOPRIGHT,
	CENTER,
	BOTTOMLEFT,
	BOTTOMRIGHT
};

class Screen
{

};

class Profile
{
public:
	Profile();
	~Profile();


private:
	// A profile is identified by its name which is unique
	// The name 'Custom' is reserved for modified profile not yet saved
	std::wstring name;

	// Size
	int width;
	int height;
	// Determine if the width and height are absolute or a percentage of the screen size
	bool isSizeRelative;

	// Position
	int xpos;
	int ypos;
	Anchor anchor;

	// Settings
	Screen screen;
	bool isCursorCliped;
	bool isTitleBarHidden;

};

