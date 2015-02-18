#ifndef FULLSCREENWINDOW_H
#define FULLSCREENWINDOW_H
#include "main.h"

#include "Engine.h"

#include <QStringListModel>
#include <QtWidgets/QMainWindow>
#include "ui_fullscreenwindow.h"

#include "Preview.h"
#include "Settings.h"

class FullScreenWindow : public QMainWindow
{
	Q_OBJECT

public:
	FullScreenWindow(QWidget *parent = 0);
	~FullScreenWindow();

	Preview* preview;

private:
	Ui::FullScreenWindowClass* ui; 
	Engine* engine;
	Settings* settings;

	void updateAll();
	void updateView();
	void updateProfilesSettings(const Profile* pro);

private slots:
	void on_listView_WindowSelection_currentRowChanged(const QModelIndex & current, const QModelIndex & previous);
	void on_listView_WindowSelection_EditEnd(QWidget *editor, QAbstractItemDelegate::EndEditHint hint);


	void on_pushButton_toggleProfilesSettings_clicked();
	void on_comboBox_ProfileSelection_currentIndexChanged(int index);
	void on_comboBox_ProfileSelection_2_currentIndexChanged(int index);
	void on_comboBox_Monitor_currentIndexChanged(int index);

protected:
	bool eventFilter(QObject *target, QEvent *event);

};

#endif // FULLSCREENWINDOW_H
