/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnClose;
    QPushButton *btnUi;
    QPushButton *btnQObj;
    QPushButton *btnLambda;
    QPushButton *btnPointer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(705, 473);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        btnClose = new QPushButton(centralwidget);
        btnClose->setObjectName("btnClose");
        btnClose->setGeometry(QRect(280, 60, 80, 26));
        btnUi = new QPushButton(centralwidget);
        btnUi->setObjectName("btnUi");
        btnUi->setGeometry(QRect(30, 190, 80, 26));
        btnQObj = new QPushButton(centralwidget);
        btnQObj->setObjectName("btnQObj");
        btnQObj->setGeometry(QRect(150, 190, 80, 26));
        btnLambda = new QPushButton(centralwidget);
        btnLambda->setObjectName("btnLambda");
        btnLambda->setGeometry(QRect(280, 190, 80, 26));
        btnPointer = new QPushButton(centralwidget);
        btnPointer->setObjectName("btnPointer");
        btnPointer->setGeometry(QRect(420, 190, 80, 26));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 705, 19));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(btnClose, &QPushButton::clicked, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnClose->setText(QCoreApplication::translate("MainWindow", "close", nullptr));
        btnUi->setText(QCoreApplication::translate("MainWindow", "No1 UI", nullptr));
        btnQObj->setText(QCoreApplication::translate("MainWindow", "No2 QObj", nullptr));
        btnLambda->setText(QCoreApplication::translate("MainWindow", "No3 Lambda", nullptr));
        btnPointer->setText(QCoreApplication::translate("MainWindow", "No4 Pointer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
