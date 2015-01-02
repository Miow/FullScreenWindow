#include "fullscreenwindow.h"

FullScreenWindow::FullScreenWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton_wAdd, &QPushButton::clicked, this, &FullScreenWindow::on_pushButton_wAdd_clicked);
}

FullScreenWindow::~FullScreenWindow()
{

}




void FullScreenWindow::on_pushButton_wAdd_clicked()
{
	ui.pushButton_wAdd->setDisabled(true);

}