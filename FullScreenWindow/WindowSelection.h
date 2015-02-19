#pragma once
#include "main.h"

#include <QtWidgets/QListView>
#include <QStringListModel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLineEdit>

#include "Engine.h"


class WindowSelection
{
public:
	WindowSelection();
	WindowSelection(QMainWindow* mainWindow, Engine* engine,
		QListView* listView_WindowSelection,
		QPushButton* pushButton_wAdd,
		QPushButton* pushButton_wRemove,
		QPushButton* pushButton_wRename,
		QComboBox* comboBox_ProfileSelection,
		QLineEdit* lineEdit_ProcessName
		);
	~WindowSelection();

	QMainWindow* mainWindow;
	Engine* engine;

	// Returns a pointer to the window selected in the list, NULL if there is none
	Window* getCurrentWindow();
	// Returns a pointer to the profile selected in the combobox
	Profile* getCurrentProfile();


	QListView* listView_WindowSelection;
	// Updates the list with all the windows recognized by the program
	void updateList();
	// Returns a pointer to the newly selected window
	void on_listView_currentRowChanged(const QModelIndex & current, const QModelIndex & previous);
	// Called when a renaming action is terminated
	void on_listView_EditEnd(QString newValue);


	QPushButton* pushButton_wAdd;
	void on_pushButton_wAdd_pressed();
	QPushButton* pushButton_wRemove;
	void on_pushButton_wRemove_pressed();
	QPushButton* pushButton_wRename;
	void on_pushButton_wRename_pressed();

	


	QComboBox* comboBox_ProfileSelection;
	QString comboBox_ProfileSelection_getSelected();
	void comboBox_ProfileSelection_setSelected(QString profileName);
	void comboBox_ProfileSelection_setSelected(Profile* pro);

	void on_comboBox_ProfileSelection_currentIndexChanged(int index);
	// Updates the selected profile of the combobox
	void comboBox_ProfileSelection_update();


	QLineEdit* lineEdit_ProcessName;
	QString getCurrentProcessName();
	void setCurrentProcessName(QString newProcessName);



private:
	QStringListModel* model;
	Window* currentWindow = NULL;
	Profile* currentProfile = NULL;
};

