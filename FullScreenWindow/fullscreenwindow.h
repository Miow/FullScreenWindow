#ifndef FULLSCREENWINDOW_H
#define FULLSCREENWINDOW_H
#include "main.h"

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
	Ui::FullScreenWindowClass ui;

private slots:
	void FullScreenWindow::on_pushButton_toggleProfilesSettings_clicked();
};

#endif // FULLSCREENWINDOW_H
