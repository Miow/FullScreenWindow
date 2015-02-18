#pragma once
#include "main.h"

#include <qstring.h>
#include <string>

#define PRIMARY L"Primary"
static const QString QPRIMARY = QString::fromWCharArray(PRIMARY);

class Monitor
{
public:
	Monitor();
	Monitor(
		const std::wstring name,
		bool isPrimary,
		int left,
		int top,
		int right,
		int bottom
		);
	~Monitor();


	bool isPrimary;

	int width;
	int height;

	int left;
	int top;
	int right;
	int bottom;

	void setName(std::wstring newName);
	void setName(QString newName);

	std::wstring getName();
	QString getQName();

private:
	std::wstring name;
	QString qname;
};
