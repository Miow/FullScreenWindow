#include "Monitor.h"

Monitor::Monitor()
{
}

Monitor::Monitor(const std::wstring name, bool isPrimary, int left, int top, int right, int bottom)
{
	this->name = name;
	this->isPrimary = isPrimary;
	this->left = left;
	this->top = top;
	this->right = right;
	this->bottom = bottom;
}


Monitor::~Monitor()
{
}

