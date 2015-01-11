#pragma once
#include "main.h"

#include "ui_fullscreenwindow.h"

#include "Engine.h"

#include "Parameters.h"
#include "WindowSelection.h"

class Settings
{
public:
	Settings();
	Settings(Ui::FullScreenWindowClass* ui, Engine* engine);
	~Settings();

	Ui::FullScreenWindowClass* ui;
	Engine* engine;

	Parameters parameters;
	WindowSelection windowSelection;



};

