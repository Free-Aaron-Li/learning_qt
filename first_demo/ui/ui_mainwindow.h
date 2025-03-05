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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "mybutton.h"

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
    QPushButton *btnReadFile;
    QPushButton *btnWriteFile;
    QPushButton *btnStreamRead;
    QPushButton *btnStreamWrite;
    QPushButton *btnQFileDialogOpen;
    QPushButton *btnSaveFile;
    QComboBox *comboBox;
    MyButton *widgetMy;
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
        btnReadFile = new QPushButton(centralwidget);
        btnReadFile->setObjectName("btnReadFile");
        btnReadFile->setGeometry(QRect(30, 260, 80, 20));
        btnWriteFile = new QPushButton(centralwidget);
        btnWriteFile->setObjectName("btnWriteFile");
        btnWriteFile->setGeometry(QRect(150, 260, 80, 20));
        btnStreamRead = new QPushButton(centralwidget);
        btnStreamRead->setObjectName("btnStreamRead");
        btnStreamRead->setGeometry(QRect(280, 260, 80, 20));
        btnStreamWrite = new QPushButton(centralwidget);
        btnStreamWrite->setObjectName("btnStreamWrite");
        btnStreamWrite->setGeometry(QRect(420, 260, 80, 20));
        btnQFileDialogOpen = new QPushButton(centralwidget);
        btnQFileDialogOpen->setObjectName("btnQFileDialogOpen");
        btnQFileDialogOpen->setGeometry(QRect(20, 310, 101, 21));
        btnSaveFile = new QPushButton(centralwidget);
        btnSaveFile->setObjectName("btnSaveFile");
        btnSaveFile->setGeometry(QRect(150, 310, 80, 20));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(280, 310, 81, 21));
        widgetMy = new MyButton(centralwidget);
        widgetMy->setObjectName("widgetMy");
        widgetMy->setGeometry(QRect(530, 30, 120, 80));
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
        btnReadFile->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\217\226\346\226\207\344\273\266", nullptr));
        btnWriteFile->setText(QCoreApplication::translate("MainWindow", "\345\206\231\345\205\245\346\226\207\344\273\266", nullptr));
        btnStreamRead->setText(QCoreApplication::translate("MainWindow", "Stream \350\257\273\345\217\226", nullptr));
        btnStreamWrite->setText(QCoreApplication::translate("MainWindow", "Stream \345\206\231\345\205\245", nullptr));
        btnQFileDialogOpen->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266\351\200\211\346\213\251\346\241\206", nullptr));
        btnSaveFile->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\346\226\207\344\273\266", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "GBK", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "UTF-8", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "ANSI", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "UTF-16", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "UTF-16LE", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "UTF-16BE", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("MainWindow", "GB2312", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
