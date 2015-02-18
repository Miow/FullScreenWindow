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
	Profile* currentPro = &(engine->proList->at(index));
	//TODO: ici faut check et tout et griser les boutons qui servent a rien
}
/*
void ProfileSelector::update_comboBox_ProfileSelection();
{

}
*/
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