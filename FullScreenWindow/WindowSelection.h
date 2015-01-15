#pragma once
#include "main.h"

#include <QtWidgets/QCheckBox>
#include <QtWidgets/QListView>
#include <QStringListModel>

#include "Engine.h"


class WindowSelection
{
public:
	WindowSelection();
	WindowSelection(QMainWindow* mainWindow, Engine* engine, QListView* listView_WindowSelection);
	~WindowSelection();

	QMainWindow* mainWindow;
	Engine* engine;

	QListView* listView_WindowSelection;

	void updateList();

	// Returns a pointer to the newly selected window
	Window* on_listView_currentRowChanged(const QModelIndex & current, const QModelIndex & previous);
	void on_listView_EditEnd(QString newValue);

private:
	QStringListModel* model;
};

