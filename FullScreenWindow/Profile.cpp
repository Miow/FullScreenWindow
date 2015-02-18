#include "Profile.h"


Profile::Profile()
{
}


Profile::~Profile()
{
}

void Profile::setName(std::wstring newName)
{
	name = newName;
	qname = QString::fromWCharArray(newName.c_str());
}

void Profile::setName(QString newName)
{
	qname = newName;
	name = newName.toStdWString();
}

const std::wstring Profile::getName()
{
	return name;
}

const QString Profile::getQName()
{
	return qname;
}

void Profile::initDefaults(std::vector<Profile>* proList, MonitorList* monList)
{
	Profile pro;

	// DISABLED
	pro = Profile();
	pro.setName(L"Disabled");

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
	pro.setName(L"Fullscreen");

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