#include "stdafx.h"
#include "WindowSelection.h"


WindowSelection::WindowSelection(QMainWindow* mainWindow, Engine* engine, QListView* listView_WindowSelection)
{
	this->mainWindow = mainWindow;
	this->engine = engine;

	this->listView_WindowSelection = listView_WindowSelection;

	model = new QStringListModel(mainWindow);
	listView_WindowSelection->setModel(model);
	updateList();
}

WindowSelection::WindowSelection()
{
}
WindowSelection::~WindowSelection()
{
	//delete model;
}



void WindowSelection::on_listView_currentRowChanged(const QModelIndex & current, const QModelIndex & previous)
{
	
}


void WindowSelection::on_listView_EditEnd(QString newValue)
{
	QModelIndex index = listView_WindowSelection->currentIndex();
	int currentRow = index.row();

	std::vector<Window> winList = *engine->winList;
	// Just checking the index is not out of bound
	if (currentRow >= 0 && (uint)currentRow < engine->winList->size())
	{
		LOG(info) << "Window \"" << engine->winList->at(currentRow).getName() << "\" has been renamed to \"" << newValue.toStdString() << "\".";
		engine->winList->at(currentRow).setName(newValue);
	}
	else
	{
		LOG(fatal) << "Index " << currentRow << " of the window selection list has just been edited to \"" << newValue.toStdString() << "\" and the index is out of bound.";
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
