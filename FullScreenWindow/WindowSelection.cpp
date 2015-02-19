#include "stdafx.h"
#include "WindowSelection.h"


WindowSelection::WindowSelection(QMainWindow* mainWindow, Engine* engine,
	QListView* listView_WindowSelection,
	QPushButton* pushButton_wAdd,
	QPushButton* pushButton_wRemove,
	QPushButton* pushButton_wRename,
	QComboBox* comboBox_ProfileSelection,
	QLineEdit* lineEdit_ProcessName
	)
{
	this->mainWindow = mainWindow;
	this->engine = engine;

	this->listView_WindowSelection = listView_WindowSelection;
	this->pushButton_wAdd = pushButton_wAdd;
	this->pushButton_wRemove = pushButton_wRemove;
	this->pushButton_wRename = pushButton_wRename;
	this->comboBox_ProfileSelection = comboBox_ProfileSelection;
	this->lineEdit_ProcessName = lineEdit_ProcessName;


	model = new QStringListModel(mainWindow);
	listView_WindowSelection->setModel(model);

	currentProfile = engine->getDefaultProfile();
}

WindowSelection::WindowSelection()
{
}
WindowSelection::~WindowSelection()
{
	//delete model;
}




Window* WindowSelection::getCurrentWindow()
{
	return currentWindow;
}

Profile* WindowSelection::getCurrentProfile()
{
	return currentProfile;
}





void WindowSelection::on_listView_currentRowChanged(const QModelIndex & current, const QModelIndex & previous)
{
	currentWindow = NULL;
	try
	{
		currentWindow = &(engine->winList->at(current.row()));
		currentProfile = currentWindow->pro;
	}
	catch (const std::out_of_range& oor)
	{
		LOG(fatal) << "Unable to find the selected window, index out of bound: " << oor.what();
	}

	comboBox_ProfileSelection_update();
}


void WindowSelection::on_listView_EditEnd(QString newValue)
{
	Window* currentWindow = getCurrentWindow();

	if (currentWindow != NULL)
	{
		LOG(info) << "Window \"" << currentWindow->getName() << "\" has been renamed to \"" << newValue.toStdString() << "\".";
		currentWindow->setName(newValue);
	}
	else
	{
		LOG(fatal) << "The selected line has been edited to \"" << newValue.toStdString() << "\" and the currently selected window was not found.";
	}
	
}


void WindowSelection::updateList()
{
	QStringList list;
	auto winList = engine->winList;

	for (auto it = winList->begin(); it != winList->end(); it++)
	{
		list.append(it->getQName());
	}

	model->setStringList(list);

}






void WindowSelection::on_pushButton_wAdd_pressed()
{
	
}
void WindowSelection::on_pushButton_wRemove_pressed()
{
	// Removing a single row from a QListView is a pain in the neck
	// So we just remove the window from the engine and we update the list
	engine->removeWindow(currentWindow);
	currentWindow = NULL;
	updateList();
}
void WindowSelection::on_pushButton_wRename_pressed()
{
	// We display the lineEdit on the currently selected item
	// If no item is selected it does nothing
	listView_WindowSelection->edit(listView_WindowSelection->currentIndex());
}











void WindowSelection::on_comboBox_ProfileSelection_currentIndexChanged(int index)
{
	Profile* newProfile = NULL;
	
	try
	{
		newProfile = &(engine->proList->at(index));
	}
	catch (const std::out_of_range& oor)
	{
		LOG(fatal) << "Out of range error while trying to change the active profile of a window: " << oor.what();
	}

	Window* currentWindow = getCurrentWindow();
	if (currentWindow != NULL && newProfile != NULL)
	{
		currentWindow->pro = newProfile;
		currentProfile = newProfile;
	}

}

void WindowSelection::comboBox_ProfileSelection_update()
{
	QString lastSelectedProfile;
	if(currentWindow != NULL)
	{
		lastSelectedProfile = currentWindow->pro->getQName();
	}
	else
	{
		lastSelectedProfile = comboBox_ProfileSelection_getSelected();
	}
	

	// Clears the content of the list
	int nbItems = comboBox_ProfileSelection->count();
	for (int i = 0; i < nbItems; i++)
	{
		comboBox_ProfileSelection->removeItem(0);
	}


	for (
		auto it = engine->proList->begin();
		it != engine->proList->end();
	it++
		)
	{
		QString name = it->getQName();
		comboBox_ProfileSelection->addItem(name);
	}


	
	comboBox_ProfileSelection_setSelected(lastSelectedProfile);
}



QString WindowSelection::comboBox_ProfileSelection_getSelected()
{
	return comboBox_ProfileSelection->currentText();
}


void WindowSelection::comboBox_ProfileSelection_setSelected(Profile* pro)
{
	comboBox_ProfileSelection_setSelected(pro->getQName());
}

void WindowSelection::comboBox_ProfileSelection_setSelected(QString profileName)
{
	// Searching the index of the monitor in the list
	int index = comboBox_ProfileSelection->findText(profileName);
	// If it is not found, default to primary
	if (index == -1)
	{
		LOG(error) << "Profile \"" << profileName.toStdString() << "\" not found in the combobox, selecting default.";
		index = 0;
	}
	comboBox_ProfileSelection->setCurrentIndex(index);
}
	


QString WindowSelection::getCurrentProcessName()
{
	return QString();
}
void WindowSelection::setCurrentProcessName(QString newProcessName)
{

}