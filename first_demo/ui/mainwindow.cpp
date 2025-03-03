//  Copyright (c) 2025. aaron.
//
//  This program is under the GPL-3.0 license.
//  if you have not received it or the program has several bugs, please let me know:
//  <communicate_aaron@outlook.com>.

#include "mainwindow.h"
#include "../../notebook/ui/ui_widget.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    /// @brief 方式2：
    /// 通过调用connect()函数来手动连接信号和槽。\n
    /// 最常用的方式，直接通过 QObject::connect 函数连接信号和槽。\n
    /// 在构造函数中进行信号与槽的绑定。\n
    /// 发送方，信号，接收方，槽。\n
    QObject::connect(ui->btnQObj, SIGNAL(clicked()), this, SLOT(on_btnQObj_clickedMyself()));

    /// @brief 方式3：
    /// 使用 lambda表达式来连接信号和槽。\n
    /// 注意：这里需要使用 &QPushButton::clicked，而非宏
    QObject::connect(ui->btnLambda, &QPushButton::clicked, [this] { std::cout << "btnLambda Clicked" << std::endl; });

    /// @brief 方式4：
    /// 使用函数指针直接连接信号和槽。\n
    /// 这种方式类型安全，且可以利用 IDE 的代码补全和错误检查。\n
    QObject::connect(ui->btnPointer, &QPushButton::clicked, this, &MainWindow::in_btnPointer_clicked);

    /// 自定义信号与槽
    connect(this, &MainWindow::mySignal, this, &MainWindow::in_mySignal);
    connect(this, &MainWindow::mySignalParams, this, &MainWindow::in_mySignalParams);
    /// 触发自定义信号
    emit mySignal();
    emit mySignalParams(1);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::in_mySignal() { std::cout << "mySignal" << std::endl; }
void MainWindow::in_mySignalParams(int value) { qDebug() << "mySignalParams: " << value; }
/// @brief 方式1：
/// 通过命名约定（on_<objectName>_<signalName>）来定义自动连接信号和槽。\n
/// 这种方式命名的槽会自动连接到信号。\n
/// 自动连接信号与槽
void MainWindow::on_btnUi_clicked() { std::cout << "btnUi Clicked" << std::endl; }
void MainWindow::on_btnQObj_clickedMyself() { std::cout << "btnQObj Clicked" << std::endl; }
void MainWindow::in_btnPointer_clicked() { std::cout << "btnPointer Clicked" << std::endl; }
