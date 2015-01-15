#include "Profile.h"


Profile::Profile()
{
}


Profile::~Profile()
{
}


void Profile::initDefaults(std::vector<Profile>* proList, MonitorList* monList)
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

	pro.mon = monList->getPrimaryMonitor();

	pro.isCursorCliped = false;
	pro.isTitleBarHidden = false;
	pro.isTaskBarShown = false;

	proList->push_back(pro);


	// FULLSCREEN
	pro = Profile();
	pro.name = L"Fullscreen";

	pro.width = 0;
	pro.height = 0;
	pro.isSizeRelative = true;

	pro.xpos = 0;
	pro.ypos = 0;
	pro.anchor = Anchor::TOPLEFT;

	pro.mon = monList->getPrimaryMonitor();

	pro.isCursorCliped = false;
	pro.isTitleBarHidden = true;
	pro.isTaskBarShown = false;

	proList->push_back(pro);

}