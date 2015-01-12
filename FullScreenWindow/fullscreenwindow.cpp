#include "stdafx.h"
#include "fullscreenwindow.h"


FullScreenWindow::FullScreenWindow(QWidget *parent)
	: QMainWindow(parent), ui(new Ui::FullScreenWindowClass)
{
	ui->setupUi(this);
	engine = new Engine();
	settings = new Settings(this, ui, engine);
	

	preview = new Preview(ui->graphicsView_Preview);
	preview->defaultView();


	// CONNECTIONS
	connect(
		ui->pushButton_toggleProfilesSettings,
		&QPushButton::clicked,
		this,
		&FullScreenWindow::on_pushButton_toggleProfilesSettings_clicked
		);
	// // WindowSelection
	connect(
		ui->listView_WindowSelection->itemDelegate(),
		SIGNAL(closeEditor(QWidget*, QAbstractItemDelegate::EndEditHint)),
		this,
		SLOT(on_listView_WindowSelection_EditEnd(QWidget*, QAbstractItemDelegate::EndEditHint))
		);
	connect(
		ui->listView_WindowSelection,
		SIGNAL(currentRowChanged(QModelIndex, QModelIndex)),
		this,
		SLOT(on_listView_WindowSelection_currentRowChanged(const QModelIndex &, const QModelIndex &))
		);
	// // Settings
	// // // Parameters
	connect(
		ui->comboBox_Monitor,
		SIGNAL(currentIndexChanged(int)),
		this,
		SLOT(on_comboBox_Monitor_currentIndexChanged(int))
		);
	

	UpdateFromProfile((*engine->proList)[0]);
}

FullScreenWindow::~FullScreenWindow()
{
	delete ui;
	delete settings;
	delete engine;
}


void FullScreenWindow::UpdateFromProfile(const std::shared_ptr<Profile> pro)
{

	// Update monitor selection box
	Monitor* mon = engine->monList->getMonitorByName(pro->screenName);
	settings->parameters.update_comboBox_Monitor(mon);
	// TODO: UPDATE SELECTED MONITOR
}



// CONNECT
void FullScreenWindow::on_pushButton_toggleProfilesSettings_clicked()
{
	if (ui->groupBox_ProfileSettings->isHidden())
	{
		ui->groupBox_ProfileSettings->show();
	}
	else
	{
		ui->groupBox_ProfileSettings->hide();
	}
}



// // WindowSelection
void FullScreenWindow::on_listView_WindowSelection_currentRowChanged(const QModelIndex & current, const QModelIndex & previous)
{
	settings->windowSelection.on_listView_currentRowChanged(current, previous);
}
void FullScreenWindow::on_listView_WindowSelection_EditEnd(QWidget *editor, QAbstractItemDelegate::EndEditHint hint)
{
	QString NewValue = reinterpret_cast<QLineEdit*>(editor)->text();
	settings->windowSelection.on_listView_EditEnd(NewValue);
}


// // Settings
// // // Parameters

void FullScreenWindow::on_comboBox_Monitor_currentIndexChanged(int index)
{

}