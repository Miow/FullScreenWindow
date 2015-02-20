#pragma once
#include "main.h"

#include "ui_fullscreenwindow.h"

#include "Engine.h"

#include "ProfileSettings.h"
#include "ProfileSelector.h"

#include "WindowSelection.h"

class Settings
{
public:
	Settings();
	Settings(QMainWindow* mainWindow, Ui::FullScreenWindowClass* ui, Engine* engine);
	~Settings();

	QMainWindow* mainWindow;
	Ui::FullScreenWindowClass* ui;
	Engine* engine;

	ProfileSettings profileSettings;
	WindowSelection windowSelection;
	ProfileSelector profileSelector;
	

	// Returns a pointer to the currently selected window or NULL if there is none
	Window* getCurrentWindow();
	Profile* getCurrentProfile();
};

