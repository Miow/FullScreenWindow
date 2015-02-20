#include "Profile.h"


Profile::Profile()
{
}


Profile::~Profile()
{
}


// Name

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


// Monitor name

void Profile::setMonitorName(std::wstring newMonitorName)
{
	monitorName = newMonitorName;
	qmonitorName = QString::fromWCharArray(newMonitorName.c_str());
}

void Profile::setMonitorName(QString newMonitorName)
{
	qmonitorName = newMonitorName;
	monitorName = newMonitorName.toStdWString();
}

const std::wstring Profile::getMonitorName()
{
	return monitorName;
}

const QString Profile::getQMonitorName()
{
	return qmonitorName;
}








void Profile::initDefaults(std::vector<Profile>* proList, MonitorList* monList)
{
	Profile pro;

	// DISABLED
	pro = Profile();
	pro.isUserCreated = false;
	pro.setName(PROFILE_DEFAULT_DISABLED);

	pro.width = 0;
	pro.height = 0;
	pro.isSizeRelative = true;

	pro.xpos = 0;
	pro.ypos = 0;
	pro.anchor = Anchor::TOPLEFT;

	pro.setMonitorName(monList->getPrimaryMonitor()->getName());

	pro.isCursorCliped = false;
	pro.isTitleBarHidden = false;
	pro.isTaskBarShown = false;

	proList->push_back(pro);


	// FULLSCREEN
	pro = Profile();
	pro.isUserCreated = false;
	pro.setName(PROFILE_DEFAULT_FULLSCREEN);

	pro.width = 0;
	pro.height = 0;
	pro.isSizeRelative = true;

	pro.xpos = 0;
	pro.ypos = 0;
	pro.anchor = Anchor::TOPLEFT;

	pro.setMonitorName(monList->getPrimaryMonitor()->getName());

	pro.isCursorCliped = false;
	pro.isTitleBarHidden = true;
	pro.isTaskBarShown = false;

	proList->push_back(pro);

	// TEST
	pro = Profile();
	pro.setName(L"Test");

	pro.width = 300;
	pro.height = 200;
	pro.isSizeRelative = false;

	pro.xpos = 500;
	pro.ypos = 200;
	pro.anchor = Anchor::TOPLEFT;

	pro.setMonitorName(monList->getPrimaryMonitor()->getName());

	pro.isCursorCliped = false;
	pro.isTitleBarHidden = true;
	pro.isTaskBarShown = false;

	proList->push_back(pro);

}