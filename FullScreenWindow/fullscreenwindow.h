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
	void updatePreview();

private slots:
	void on_listView_WindowSelection_currentRowChanged(const QModelIndex & current, const QModelIndex & previous);
	void on_listView_WindowSelection_EditEnd(QWidget *editor, QAbstractItemDelegate::EndEditHint hint);
	void on_pushButton_wAdd_pressed();
	void on_pushButton_wRemove_pressed();
	void on_pushButton_wRename_pressed();
	void on_pushButton_toggleProfilesSettings_clicked();
	void on_comboBox_ProfileSelection_currentIndexChanged(int index);
	void on_lineEdit_ProcessName_editingFinished();
	void on_comboBox_ProfileSelection_2_currentIndexChanged(int index);
	void on_comboBox_Monitor_currentIndexChanged(int index);
	void on_checkBox_CursorClip_stateChanged(int state);
	void on_checkBox_TitleBar_stateChanged(int state);
	void on_spinBox_Height_valueChanged(int i);
	void on_spinBox_Width_valueChanged(int i);
	void on_checkBox_SizeIsRelative_stateChanged(int state);
	void on_checkBox_TaskBar_stateChanged(int state);
	void on_spinBox_Xpos_valueChanged(int i);
	void on_spinBox_Ypos_valueChanged(int i);
	void on_comboBox_Anchor_currentIndexChanged(int index);

protected:
	bool eventFilter(QObject *target, QEvent *event);

};

#endif // FULLSCREENWINDOW_H
