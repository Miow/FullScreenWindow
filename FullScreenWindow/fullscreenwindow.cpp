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
		ui->listView_WindowSelection->selectionModel(),
		SIGNAL(currentChanged(QModelIndex, QModelIndex)),
		this,
		SLOT(on_listView_WindowSelection_currentRowChanged(const QModelIndex &, const QModelIndex &))
		);
	connect(
		ui->listView_WindowSelection->itemDelegate(),
		SIGNAL(closeEditor(QWidget*, QAbstractItemDelegate::EndEditHint)),
		this,
		SLOT(on_listView_WindowSelection_EditEnd(QWidget*, QAbstractItemDelegate::EndEditHint))
		);
	connect(
		ui->comboBox_ProfileSelection,
		SIGNAL(currentIndexChanged(int)),
		this,
		SLOT(on_comboBox_ProfileSelection_currentIndexChanged(int))
		);
	// // Settings
	connect(
		ui->comboBox_ProfileSelection_2,
		SIGNAL(currentIndexChanged(int)),
		this,
		SLOT(on_comboBox_ProfileSelection_2_currentIndexChanged(int))
		);
	// // // Parameters
	connect(
		ui->comboBox_Monitor,
		SIGNAL(currentIndexChanged(int)),
		this,
		SLOT(on_comboBox_Monitor_currentIndexChanged(int))
		);
	

	// EVENT FILTER
	ui->comboBox_Monitor->view()->installEventFilter(this);
	ui->comboBox_ProfileSelection->view()->installEventFilter(this);

	// TESTING
	Window win;
	win.pro = &(*engine->proList)[1];
	win.setName(L"VLC media player");
	engine->winList->push_back(win);
	win.setName(L"VLC media player2");
	engine->winList->push_back(win);

	////////////////////////////////////////

	updateAll();
	preview->defaultView();
}

FullScreenWindow::~FullScreenWindow()
{
	delete ui;
	delete settings;
	delete engine;
}


void FullScreenWindow::updateAll()
{

	settings->windowSelection.updateList();
	settings->windowSelection.comboBox_ProfileSelection_update();
	settings->parameters.update_comboBox_Monitor();
}

void FullScreenWindow::updateView()
{
	preview->update(settings->getCurrentProfile());

}

void FullScreenWindow::updateProfilesSettings(const Profile* pro)
{
	//settings->parameters.update_comboBox_Monitor();
	// TODO: UPDATE SELECTED MONITOR

	// Update monitor selection box
	settings->parameters.update_comboBox_Monitor(pro->mon);
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
	updateView();
}
void FullScreenWindow::on_listView_WindowSelection_EditEnd(QWidget *editor, QAbstractItemDelegate::EndEditHint hint)
{
	QString NewValue = reinterpret_cast<QLineEdit*>(editor)->text();
	settings->windowSelection.on_listView_EditEnd(NewValue);
}
void FullScreenWindow::on_comboBox_ProfileSelection_currentIndexChanged(int index)
{
	settings->windowSelection.on_comboBox_ProfileSelection_currentIndexChanged(index);
	updateView();
}

// // Settings
void FullScreenWindow::on_comboBox_ProfileSelection_2_currentIndexChanged(int index)
{
	settings->profileSelector.on_comboBox_ProfileSelection_2_currentIndexChanged(index);
	updateView();
}

// // // Parameters
void FullScreenWindow::on_comboBox_Monitor_currentIndexChanged(int index)
{
	settings->parameters.on_comboBox_Monitor_currentIndexChanged(index);
	updateView();
}









bool FullScreenWindow::eventFilter(QObject *target, QEvent *event)
{ // The return value is true if we interecept the event

	if (target == ui->comboBox_Monitor->view())
	{
		switch (event->type())
		{
		case QEvent::Show:
			// The ComboBox has been shown and needs to be updated
			settings->parameters.update_comboBox_Monitor();
			return false;
		default:
			break;
		};
	}
	else if (target == ui->comboBox_ProfileSelection->view())
	{
		switch (event->type())
		{
		case QEvent::Show:
			// The ComboBox has been shown and needs to be updated
			settings->windowSelection.comboBox_ProfileSelection_update();
			return false;
		default:
			break;
		};
	}

	return false;
}