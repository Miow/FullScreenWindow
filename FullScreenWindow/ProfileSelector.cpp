#include "stdafx.h"
#include "ProfileSelector.h"


ProfileSelector::ProfileSelector(Engine* engine,
	QComboBox* comboBox_ProfileSelection_2,
	QPushButton* pushButton_Profile_Save,
	QPushButton* pushButton_Profile_Delete,
	QPushButton* pushButton_Profile_Duplicate
	)
{
	this->engine = engine;

	this->comboBox_ProfileSelection_2 = comboBox_ProfileSelection_2;
	this->pushButton_Profile_Save = pushButton_Profile_Save;
	this->pushButton_Profile_Delete = pushButton_Profile_Delete;
	this->pushButton_Profile_Duplicate = pushButton_Profile_Duplicate;
}



ProfileSelector::ProfileSelector()
{
}


ProfileSelector::~ProfileSelector()
{
}



void ProfileSelector::on_comboBox_ProfileSelection_2_currentIndexChanged(int index)
{
	Profile* currentProfile = NULL;
	try
	{
		currentProfile = &(engine->proList->at(index));
	}
	catch (const std::out_of_range& oor)
	{
		LOG(fatal) << "Out of bound while trying to fetch the selected profile: " << oor.what();
		
		// We reset the combobox
		update_comboBox_ProfileSelection_2();
		return;
	}

	// The user can only change the name for custom profiles
	comboBox_ProfileSelection_2->setEditable(currentProfile->isUserCreated);
	

}



void ProfileSelector::update_comboBox_ProfileSelection_2()
{
	QString lastSelectedProfile = comboBox_ProfileSelection_2_getSelected();


	// Clears the content of the list
	int nbItems = comboBox_ProfileSelection_2->count();
	for (int i = 0; i < nbItems; i++)
	{
		comboBox_ProfileSelection_2->removeItem(0);
	}


	for (
		auto it = engine->proList->begin();
		it != engine->proList->end();
		it++
		)
	{
		QString name = it->getQName();
		comboBox_ProfileSelection_2->addItem(name);
	}

	comboBox_ProfileSelection_2_setSelected(lastSelectedProfile);
}

QString ProfileSelector::comboBox_ProfileSelection_2_getSelected()
{
	return comboBox_ProfileSelection_2->currentText();
}
void ProfileSelector::comboBox_ProfileSelection_2_setSelected(Profile* pro)
{
	comboBox_ProfileSelection_2_setSelected(pro->getQName());
}
void ProfileSelector::comboBox_ProfileSelection_2_setSelected(QString profileName)
{
	// Searching the index of the monitor in the list
	int index = comboBox_ProfileSelection_2->findText(profileName);
	// If it is not found, default to primary
	if (index == -1)
	{
		LOG(error) << "Profile \"" << profileName.toStdString() << "\" not found in the combobox, selecting default.";
		index = 0;
	}
	comboBox_ProfileSelection_2->setCurrentIndex(index);
}




Profile* ProfileSelector::getCurrentProfile()
{
	int index = comboBox_ProfileSelection_2->currentIndex();
	try
	{
		return &(engine->proList->at(index));
	}
	catch (const std::out_of_range& oor)
	{
		LOG(fatal) << "Out of bound while trying to query the selected profile: " << oor.what();
		return NULL;
	}
}

void ProfileSelector::saveCurrentProfile()
{

}

void ProfileSelector::saveCurrentProfileAs(QString newName)
{

}

void ProfileSelector::deleteCurrentProfile()
{

}