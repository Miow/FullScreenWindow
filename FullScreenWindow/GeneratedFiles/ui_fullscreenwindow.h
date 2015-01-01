/********************************************************************************
** Form generated from reading UI file 'fullscreenwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FULLSCREENWINDOW_H
#define UI_FULLSCREENWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FullScreenWindowClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FullScreenWindowClass)
    {
        if (FullScreenWindowClass->objectName().isEmpty())
            FullScreenWindowClass->setObjectName(QStringLiteral("FullScreenWindowClass"));
        FullScreenWindowClass->resize(600, 400);
        menuBar = new QMenuBar(FullScreenWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        FullScreenWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(FullScreenWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        FullScreenWindowClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(FullScreenWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        FullScreenWindowClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(FullScreenWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        FullScreenWindowClass->setStatusBar(statusBar);

        retranslateUi(FullScreenWindowClass);

        QMetaObject::connectSlotsByName(FullScreenWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *FullScreenWindowClass)
    {
        FullScreenWindowClass->setWindowTitle(QApplication::translate("FullScreenWindowClass", "FullScreenWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class FullScreenWindowClass: public Ui_FullScreenWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FULLSCREENWINDOW_H
