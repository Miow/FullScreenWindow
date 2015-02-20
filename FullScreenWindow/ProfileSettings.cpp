#include "stdafx.h"
#include "ProfileSettings.h"


ProfileSettings::ProfileSettings(Engine* engine,
	QGroupBox* groupBox_Parameters,
	QGroupBox* groupBox_Size,
	QGroupBox* groupBox_Position,
	QComboBox* comboBox_Monitor,
	QCheckBox* checkBox_CursorClip,
	QCheckBox* checkBox_TitleBar,
	QSpinBox* spinBox_Height,
	QSpinBox* spinBox_Width,
	QCheckBox* checkBox_SizeIsRelative,
	QCheckBox* checkBox_TaskBar,
	QSpinBox* spinBox_Xpos,
	QSpinBox* spinBox_Ypos,
	QComboBox* comboBox_Anchor
	)
{
	this->engine = engine;

	this->groupBox_Parameters = groupBox_Parameters;
	this->groupBox_Size = groupBox_Size;
	this->groupBox_Position = groupBox_Position;


	this->comboBox_Monitor = comboBox_Monitor;
	this->checkBox_CursorClip = checkBox_CursorClip;
	this->checkBox_TitleBar = checkBox_TitleBar;
	this->spinBox_Height = spinBox_Height;
	this->spinBox_Width = spinBox_Width;
	this->checkBox_SizeIsRelative = checkBox_SizeIsRelative;
	this->checkBox_TaskBar = checkBox_TaskBar;
	this->spinBox_Xpos = spinBox_Xpos;
	this->spinBox_Ypos = spinBox_Ypos;
	this->comboBox_Anchor = comboBox_Anchor;


}

ProfileSettings::ProfileSettings()
{
}
ProfileSettings::~ProfileSettings()
{
}


void ProfileSettings::updateAll(Profile* newCurrentProfile)
{
	currentProfile = newCurrentProfile;

	// We disable the settings if this is not a custom profile
	setDisabledAll(!currentProfile->isUserCreated);
	
	update_comboBox_Monitor(currentProfile->getQMonitorName());
	checkBox_CursorClip->setChecked(currentProfile->isCursorCliped);
	checkBox_TitleBar->setChecked(currentProfile->isTitleBarHidden);
	spinBox_Height->setValue(currentProfile->height);
	spinBox_Width->setValue(currentProfile->width);
	checkBox_SizeIsRelative->setChecked(currentProfile->isSizeRelative);
	checkBox_TaskBar->setChecked(currentProfile->isTaskBarShown);
	spinBox_Xpos->setValue(currentProfile->xpos);
	spinBox_Ypos->setValue(currentProfile->ypos);
	comboBox_Anchor_setValue(currentProfile->anchor);
}


void ProfileSettings::setDisabledAll(bool isDisabled)
{
	groupBox_Parameters->setDisabled(isDisabled);
	groupBox_Size->setDisabled(isDisabled);
	groupBox_Position->setDisabled(isDisabled);
}







QString ProfileSettings::comboBox_Monitor_getSelected()
{
	return comboBox_Monitor->currentText();
}

void ProfileSettings::comboBox_Monitor_setSelected(Monitor* mon)
{
	comboBox_Monitor_setSelected(mon->getQName());
}

void ProfileSettings::comboBox_Monitor_setSelected(QString monName)
{
	// Searching the index of the monitor in the list
	int index = comboBox_Monitor->findText(monName);
	// If it is not found, default to primary
	if (index == -1)
	{
		LOG(error) << "Monitor \"" << monName.toStdString() << "\" not found in the combobox, defaulting to primary.";
		index = 0;
	}
	comboBox_Monitor->setCurrentIndex(index);
}


void ProfileSettings::update_comboBox_Monitor()
{
	QString lastSelectedMonitorName = comboBox_Monitor_getSelected();

	// Clears the content of the list
	int nbItems = comboBox_Monitor->count();
	for (int i = 0; i < nbItems; i++)
	{
		comboBox_Monitor->removeItem(0);
	}

	// Updates the monitor list
	engine->monitor_updateList();

	// Fill in the combobox
	comboBox_Monitor->addItem(QPRIMARY); // Adding the primary monitor as the first item of the list

	for (
		auto it = engine->monList->monList->begin()+1; // /!\ We start at index 1
		it != engine->monList->monList->end();
		it++
		)
	{
		QString name = it->getQName();
		if (it->isPrimary)
		{
			name = name + " (" + QPRIMARY + ")";
		}
		comboBox_Monitor->addItem(name);
	}

	comboBox_Monitor_setSelected(lastSelectedMonitorName);
}

void ProfileSettings::update_comboBox_Monitor(Monitor* mon)
{
	update_comboBox_Monitor();
	comboBox_Monitor_setSelected(mon);
}

void ProfileSettings::update_comboBox_Monitor(QString monName)
{
	update_comboBox_Monitor();
	comboBox_Monitor_setSelected(monName);
}




void ProfileSettings::comboBox_Anchor_setValue(Profile::Anchor anchor)
{
	comboBox_Anchor->setCurrentIndex(anchor);
}

Profile::Anchor ProfileSettings::comboBox_Anchor_getValue()
{
	return Profile::Anchor(comboBox_Anchor->currentIndex());
}






void ProfileSettings::on_comboBox_Monitor_currentIndexChanged(int index)
{
	currentProfile->setMonitorName(comboBox_Monitor_getSelected());
}
void ProfileSettings::on_checkBox_CursorClip_stateChanged(int state)
{
	currentProfile->isCursorCliped = (state == Qt::Checked);
}
void ProfileSettings::on_checkBox_TitleBar_stateChanged(int state)
{
	currentProfile->isTitleBarHidden = (state == Qt::Checked);
}
void ProfileSettings::on_spinBox_Height_valueChanged(int i)
{
	currentProfile->height = i;
}
void ProfileSettings::on_spinBox_Width_valueChanged(int i)
{
	currentProfile->width = i;
}
void ProfileSettings::on_checkBox_SizeIsRelative_stateChanged(int state)
{
	currentProfile->isSizeRelative = (state == Qt::Checked);
}
void ProfileSettings::on_checkBox_TaskBar_stateChanged(int state)
{
	currentProfile->isTaskBarShown = (state == Qt::Checked);
}
void ProfileSettings::on_spinBox_Xpos_valueChanged(int i)
{
	currentProfile->xpos = i;
}
void ProfileSettings::on_spinBox_Ypos_valueChanged(int i)
{
	currentProfile->ypos = i;
}
void ProfileSettings::on_comboBox_Anchor_currentIndexChanged(int index)
{
	currentProfile->anchor = comboBox_Anchor_getValue();
}
