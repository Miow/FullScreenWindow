#pragma once
#include "main.h"

#include <QtWidgets/QCheckBox>
#include <QtWidgets/QListView>

#include "Engine.h"

class WindowSelection
{
public:
	WindowSelection();
	~WindowSelection();

	Engine* engine;

	QListView* listView_WindowSelection;



};

