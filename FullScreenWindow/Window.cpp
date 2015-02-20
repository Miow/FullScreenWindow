#include "Window.h"


Window::Window()
{
}


Window::~Window()
{
}


void Window::setName(std::wstring newName)
{
	name = newName;
	qname = QString::fromWCharArray(newName.c_str());
}

void Window::setName(QString newName)
{
	qname = newName;
	name = newName.toStdWString();
}

const std::wstring Window::getName()
{
	return name;
}

const QString Window::getQName()
{
	return qname;
}



void Window::setProcessName(std::wstring newProcessName)
{
	processName = newProcessName;
}

void Window::setProcessName(QString newProcessName)
{
	processName = newProcessName.toStdWString();
}

const std::wstring Window::getProcessName()
{
	return processName;
}

const QString Window::getQProcessName()
{
	return QString::fromWCharArray(processName.c_str());
}