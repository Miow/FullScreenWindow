#include "Profile.h"


Profile::Profile()
{
}


Profile::~Profile()
{
}


void Profile::initDefaults(ProfileList* proList)
{
	Profile pro;

	// DISABLED
	pro = Profile();
	pro.name = L"Disabled";

	pro.width = 0;
	pro.height = 0;
	pro.isSizeRelative = true;

	pro.xpos = 0;
	pro.ypos = 0;
	pro.anchor = Anchor::TOPLEFT;

	pro.screenName = PRIMARY;
	pro.isCursorCliped = false;
	pro.isTitleBarHidden = false;

	proList->push_back(std::unique_ptr<Profile>(new Profile(pro)));


	// FULLSCREEN
	pro = Profile();
	pro.name = L"Fullscreen";

	pro.width = 0;
	pro.height = 0;
	pro.isSizeRelative = true;

	pro.xpos = 0;
	pro.ypos = 0;
	pro.anchor = Anchor::TOPLEFT;

	pro.screenName = PRIMARY;
	pro.isCursorCliped = false;
	pro.isTitleBarHidden = true;

	proList->push_back(std::unique_ptr<Profile>(new Profile(pro)));

}