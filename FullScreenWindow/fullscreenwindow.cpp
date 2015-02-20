#include "stdafx.h"
#include "fullscreenwindow.h"


FullScreenWindow::FullScreenWindow(QWidget *parent)
	: QMainWindow(parent), ui(new Ui::FullScreenWindowClass)
{
	ui->setupUi(this);
	engine = new Engine();

	settings = new Settings(this, ui, engine);

	preview = new Preview(ui->graphicsView_Preview);
	preview->defaultView(NULL);


	// CONNECTIONS
	connect(
		ui->pushButton_toggleProfilesSettings,
		SIGNAL(pressed()),
		this,
		SLOT(on_pushButton_toggleProfilesSettings_clicked())
		);



	// // WindowSelection
	// // // ListView
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
	// // // Buttons
	connect(
		ui->pushButton_wAdd,
		SIGNAL(pressed()),
		this,
		SLOT(on_pushButton_wAdd_pressed())
		);
	connect(
		ui->pushButton_wRemove,
		SIGNAL(pressed()),
		this,
		SLOT(on_pushButton_wRemove_pressed())
		);
	connect(
		ui->pushButton_wRename,
		SIGNAL(pressed()),
		this,
		SLOT(on_pushButton_wRename_pressed())
		);
	// // // Settings
	connect(
		ui->comboBox_ProfileSelection,
		SIGNAL(currentIndexChanged(int)),
		this,
		SLOT(on_comboBox_ProfileSelection_currentIndexChanged(int))
		);
	connect(
		ui->lineEdit_ProcessName,
		SIGNAL(editingFinished()),
		this,
		SLOT(on_lineEdit_ProcessName_editingFinished())
		);



	// // Settings
	connect(
		ui->comboBox_ProfileSelection_2,
		SIGNAL(currentIndexChanged(int)),
		this,
		SLOT(on_comboBox_ProfileSelection_2_currentIndexChanged(int))
		);
	// // // ProfileSettings
	connect(
		ui->comboBox_Monitor,
		SIGNAL(currentIndexChanged(int)),
		this,
		SLOT(on_comboBox_Monitor_currentIndexChanged(int))
		);
	connect(
		ui->comboBox_Monitor,
		SIGNAL(currentIndexChanged(int)),
		this,
		SLOT(on_comboBox_Monitor_currentIndexChanged(int))
		);
	connect(
		ui->checkBox_CursorClip,
		SIGNAL(stateChanged(int)),
		this,
		SLOT(on_checkBox_CursorClip_stateChanged(int))
		);
	connect(
		ui->checkBox_TitleBar,
		SIGNAL(stateChanged(int)),
		this,
		SLOT(on_checkBox_TitleBar_stateChanged(int))
		);
	connect(
		ui->spinBox_Height,
		SIGNAL(valueChanged(int)),
		this,
		SLOT(on_spinBox_Height_valueChanged(int))
		);
	connect(
		ui->spinBox_Width,
		SIGNAL(valueChanged(int)),
		this,
		SLOT(on_spinBox_Width_valueChanged(int))
		);
	connect(
		ui->checkBox_SizeIsRelative,
		SIGNAL(stateChanged(int)),
		this,
		SLOT(on_checkBox_SizeIsRelative_stateChanged(int))
		);
	connect(
		ui->checkBox_TaskBar,
		SIGNAL(stateChanged(int)),
		this,
		SLOT(on_checkBox_TaskBar_stateChanged(int))
		);
	connect(
		ui->spinBox_Xpos,
		SIGNAL(valueChanged(int)),
		this,
		SLOT(on_spinBox_Xpos_valueChanged(int))
		);
	connect(
		ui->spinBox_Ypos,
		SIGNAL(valueChanged(int)),
		this,
		SLOT(on_spinBox_Ypos_valueChanged(int))
		);
	connect(
		ui->comboBox_Anchor,
		SIGNAL(currentIndexChanged(int)),
		this,
		SLOT(on_comboBox_Anchor_currentIndexChanged(int))
		);


	// EVENT FILTER
	ui->comboBox_Monitor->view()->installEventFilter(this);




	// TESTING
	Window win;
	win.pro = &(*engine->proList)[1];
	win.setName(L"VLC media player");
	engine->winList->push_back(win);
	win.setName(L"VLC media player2");
	engine->winList->push_back(win);

	////////////////////////////////////////

	updateAll();
	preview->defaultView(NULL);
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
	settings->windowSelection.update_comboBox_ProfileSelection();

	settings->profileSelector.update_comboBox_ProfileSelection_2();
	settings->profileSettings.update_comboBox_Monitor();

}

void FullScreenWindow::updatePreview()
{
	Profile* currentProfile = settings->getCurrentProfile();
	preview->update(
		currentProfile,
		engine->getMonitorByName(currentProfile->getMonitorName())
		);
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
void FullScreenWindow::on_pushButton_wAdd_pressed()
{
	settings->windowSelection.on_pushButton_wAdd_pressed();
}
void FullScreenWindow::on_pushButton_wRemove_pressed()
{
	settings->windowSelection.on_pushButton_wRemove_pressed();
}
void FullScreenWindow::on_pushButton_wRename_pressed()
{
	settings->windowSelection.on_pushButton_wRename_pressed();
}
void FullScreenWindow::on_comboBox_ProfileSelection_currentIndexChanged(int index)
{
	settings->windowSelection.on_comboBox_ProfileSelection_currentIndexChanged(index);
	updatePreview();
}
void FullScreenWindow::on_lineEdit_ProcessName_editingFinished()
{
	settings->windowSelection.on_lineEdit_ProcessName_editingFinished();
}

// // Settings
void FullScreenWindow::on_comboBox_ProfileSelection_2_currentIndexChanged(int index)
{
	settings->profileSelector.on_comboBox_ProfileSelection_2_currentIndexChanged(index);
	settings->profileSettings.updateAll(settings->profileSelector.getCurrentProfile());
}

// // // ProfileSettings
void FullScreenWindow::on_comboBox_Monitor_currentIndexChanged(int index)
{
	settings->profileSettings.on_comboBox_Monitor_currentIndexChanged(index);
	updatePreview();
}
void FullScreenWindow::on_checkBox_CursorClip_stateChanged(int state)
{
	settings->profileSettings.on_checkBox_CursorClip_stateChanged(state);
}
void FullScreenWindow::on_checkBox_TitleBar_stateChanged(int state)
{
	settings->profileSettings.on_checkBox_TitleBar_stateChanged(state);
	updatePreview();
}
void FullScreenWindow::on_spinBox_Height_valueChanged(int i)
{
	settings->profileSettings.on_spinBox_Height_valueChanged(i);
	updatePreview();
}
void FullScreenWindow::on_spinBox_Width_valueChanged(int i)
{
	settings->profileSettings.on_spinBox_Width_valueChanged(i);
	updatePreview();
}
void FullScreenWindow::on_checkBox_SizeIsRelative_stateChanged(int state)
{
	settings->profileSettings.on_checkBox_SizeIsRelative_stateChanged(state);
	updatePreview();
}
void FullScreenWindow::on_checkBox_TaskBar_stateChanged(int state)
{
	settings->profileSettings.on_checkBox_TaskBar_stateChanged(state);
	updatePreview();
}
void FullScreenWindow::on_spinBox_Xpos_valueChanged(int i)
{
	settings->profileSettings.on_spinBox_Xpos_valueChanged(i);
	updatePreview();
}
void FullScreenWindow::on_spinBox_Ypos_valueChanged(int i)
{
	settings->profileSettings.on_spinBox_Ypos_valueChanged(i);
	updatePreview();
}
void FullScreenWindow::on_comboBox_Anchor_currentIndexChanged(int index)
{
	settings->profileSettings.on_comboBox_Anchor_currentIndexChanged(index);
	updatePreview();
}









bool FullScreenWindow::eventFilter(QObject *target, QEvent *event)
{ // The return value is true if we interecept the event

	if (target == ui->comboBox_Monitor->view())
	{
		switch (event->type())
		{
		case QEvent::Show:
			// The ComboBox has been shown and needs to be updated
			settings->profileSettings.update_comboBox_Monitor();
			return false;
		default:
			break;
		};
	}
	return false;
}