#ifndef FULLSCREENWINDOW_H
#define FULLSCREENWINDOW_H
#include "main.h"

#include "Engine.h"

#include <QtWidgets/QMainWindow>
#include "ui_fullscreenwindow.h"

#include "Preview.h"

class FullScreenWindow : public QMainWindow
{
	Q_OBJECT

public:
	FullScreenWindow(QWidget *parent = 0);
	~FullScreenWindow();

	Preview* preview;

private:
	Engine engine;
	Ui::FullScreenWindowClass ui;

	void UpdateFromProfile(const std::shared_ptr<Profile> pro);

	void update_comboBox_Monitor();

private slots:
	void on_pushButton_toggleProfilesSettings_clicked();
	void on_comboBox_Monitor_activated(int index);
};

#endif // FULLSCREENWINDOW_H
