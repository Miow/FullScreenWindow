#include "fullscreenwindow.h"

static const QString QPRIMARY = QString::fromWCharArray(PRIMARY);

FullScreenWindow::FullScreenWindow(QWidget *parent)
	: QMainWindow(parent)
{
	Engine engine = Engine();

	ui.setupUi(this);

	preview = new Preview(ui.graphicsView_Preview);
	preview->defaultView();


	// Connections
	//connect(ui.comboBox_Monitor, static_cast<void (QComboBox::*)(int)>(&QComboBox::), this, &FullScreenWindow::on_comboBox_Monitor_activated);
	connect(ui.pushButton_toggleProfilesSettings, &QPushButton::clicked, this, &FullScreenWindow::on_pushButton_toggleProfilesSettings_clicked);


	UpdateFromProfile(engine.proList[0]);
}

FullScreenWindow::~FullScreenWindow()
{
	
}


void FullScreenWindow::UpdateFromProfile(const std::shared_ptr<Profile> pro)
{

	// Update monitor selection box
	Monitor* mon = engine.monList->getMonitorByName(pro->screenName);
	update_comboBox_Monitor();
	// TODO: UPDATE SELECTED MONITOR
}



void FullScreenWindow::on_pushButton_toggleProfilesSettings_clicked()
{
	if (ui.groupBox_ProfileSettings->isHidden())
	{
		ui.groupBox_ProfileSettings->show();
	}
	else
	{
		ui.groupBox_ProfileSettings->hide();
	}
}


// MONITOR

void FullScreenWindow::on_comboBox_Monitor_activated(int index)
{
	// The index 0 is just a link to the primary monitor
	if (index == 0)
	{
		engine.monList->getPrimaryMonitor();
	}
	else
	{
		engine.monList->monList[index-1];
	}
	update_comboBox_Monitor();
}

void FullScreenWindow::update_comboBox_Monitor()
{
	// Clears the content of the list
	int nbItems = ui.comboBox_Monitor->count();
	for (int i = 0; i < nbItems; i++)
	{
		ui.comboBox_Monitor->removeItem(0);
	}
	
	// Updates the monitor list
	engine.monitor_updateList();

	// Add the primary monitor on top of the others
	ui.comboBox_Monitor->addItem(QPRIMARY);

	// Fill in the combobox
	for (auto it = engine.monList->monList.begin(); it != engine.monList->monList.end(); it++)
	{
		QString name = QString::fromWCharArray((*it)->name.c_str());
		if ((*it)->isPrimary)
		{
			name = name + " (" + QPRIMARY + ")";
		}
		ui.comboBox_Monitor->addItem(name);
	}
}



