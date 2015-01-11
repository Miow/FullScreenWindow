#include "stdafx.h"
#include "fullscreenwindow.h"


FullScreenWindow::FullScreenWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	engine = Engine();
	settings = Settings(&ui, &engine);
	

	preview = new Preview(ui.graphicsView_Preview);
	preview->defaultView();


	// CONNECTIONS
	connect(ui.pushButton_toggleProfilesSettings, &QPushButton::clicked, this, &FullScreenWindow::on_pushButton_toggleProfilesSettings_clicked);
	// // WindowSelection
	// Flemme de finir ça, la soltuion pour ajouter marche, reste juste a trouver le signal
	// http://falsinsoft.blogspot.fr/2013/11/qlistwidget-and-item-edit-event.html
	connect(ui.listView_WindowSelection, &QListWidget::currentTextChanged, this, &FullScreenWindow::on_listView_WindowSelection_currentTextChanged);
	// // Settings
	// // // Parameters
	connect(ui.comboBox_Monitor, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &FullScreenWindow::on_comboBox_Monitor_currentIndexChanged);


	// temp
	QStringListModel* model = new QStringListModel(this);
	QStringList list;
	list << "ITEM 1" << "ITEM 2" << "ITEM 3" << "ITEM 4"  ;
	model->setStringList(list);

	ui.listView_WindowSelection->setModel(model);
	// /temp

	UpdateFromProfile(engine.proList[0]);
}

FullScreenWindow::~FullScreenWindow()
{
	
}


void FullScreenWindow::UpdateFromProfile(const std::shared_ptr<Profile> pro)
{

	// Update monitor selection box
	Monitor* mon = engine.monList->getMonitorByName(pro->screenName);
	settings.parameters.update_comboBox_Monitor(mon);
	// TODO: UPDATE SELECTED MONITOR
}



// CONNECT
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



// // WindowSelection
void FullScreenWindow::on_listView_WindowSelection_currentTextChanged(const QString & currentText)
{

}



// // Settings
// // // Parameters

void FullScreenWindow::on_comboBox_Monitor_currentIndexChanged(int index)
{

}