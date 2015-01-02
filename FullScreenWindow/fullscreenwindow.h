#ifndef FULLSCREENWINDOW_H
#define FULLSCREENWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_fullscreenwindow.h"

class FullScreenWindow : public QMainWindow
{
	Q_OBJECT

public:
	FullScreenWindow(QWidget *parent = 0);
	~FullScreenWindow();

private:
	Ui::FullScreenWindowClass ui;

private slots:
	void FullScreenWindow::on_pushButton_wAdd_clicked();
};

#endif // FULLSCREENWINDOW_H
