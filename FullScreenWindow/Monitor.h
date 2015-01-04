#pragma once
#include "main.h"

#include <string>

#define PRIMARY L"Primary"

class Monitor
{
public:
	Monitor(
		const std::wstring name,
		bool isPrimary,
		int left,
		int top,
		int right,
		int bottom
		);
	~Monitor();

	std::wstring name;

	bool isPrimary;

	int width;
	int height;

	int left;
	int top;
	int right;
	int bottom;
};
