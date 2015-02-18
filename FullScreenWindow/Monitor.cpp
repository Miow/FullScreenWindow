#include "Monitor.h"

Monitor::Monitor()
{
}

Monitor::Monitor(const std::wstring name, bool isPrimary, int left, int top, int right, int bottom)
{
	setName(name);
	this->isPrimary = isPrimary;
	this->left = left;
	this->top = top;
	this->right = right;
	this->bottom = bottom;

	width = right - left;
	height = bottom - top;
}


Monitor::~Monitor()
{
}

void Monitor::setName(std::wstring newName)
{
	name = newName;
	qname = QString::fromWCharArray(newName.c_str());
}

void Monitor::setName(QString newName)
{
	qname = newName;
	name = newName.toStdWString();
}

std::wstring Monitor::getName()
{
	return name;
}

QString Monitor::getQName()
{
	return qname;
}