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

std::wstring Window::getName()
{
	return name;
}

QString Window::getQName()
{
	return qname;
}