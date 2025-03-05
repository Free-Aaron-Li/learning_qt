//  Copyright (c) 2025. aaron.
//
//  This program is under the GPL-3.0 license.
//  if you have not received it or the program has several bugs, please let me know:
//  <communicate_aaron@outlook.com>.

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCloseEvent>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <iostream>
#include "mybutton.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow final : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
signals:
    void mySignal();
    void mySignalParams(int value);

private slots:
    void in_mySignal();
    void in_mySignalParams(int value);
    void on_btnUi_clicked();
    void on_btnQObj_clickedMyself();
    void in_btnPointer_clicked();

    void on_btnReadFile_clicked();

    void on_btnWriteFile_clicked();

    void on_btnStreamRead_clicked();

    void on_btnStreamWrite_clicked();

    void on_btnQFileDialogOpen_clicked();

    void on_btnSaveFile_clicked();

    void in_comboBox_currentIndexChanged(int index) const;

    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void closeEvent(QCloseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
