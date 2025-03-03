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

void MainWindow::on_btnReadFile_clicked() {
    /// 1. 打开文件
    QFile file(":/docs/test.txt");
    /// 若未检查此状态直接调用read()，可能导致未定义行为（如读取失败或程序崩溃）
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "打开文件失败：" << file.errorString(); // 输出具体错误[1,4](@ref)
        return;
    }
    /// 2. 读取文件
    char content[100] = {};
    file.read(content, 100);
    /// 3. 输出文件内容
    std::cout << "file content: " << content << std::endl;
    /// 4. 关闭文件
    file.close();
}

void MainWindow::on_btnWriteFile_clicked() {
    /// 1. 打开文件
    /// 1.1 相对路径
    /// 相对于当前可执行文件所在的目录
    QFile file("../first_demo/resources/docs/test_write.txt");
    /// 1.2 使用资源文件中的相对路径，会报："Unknown error"
    /// 因为Qt 资源文件会在编译时被嵌入到可执行文件中，默认是<b>只读</b>，无法写入。
    // QFile file(":/docs/test_write.txt");
    // QFile file(":/docs/test.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "打开文件失败：" << file.errorString();
        return;
    }
    /// 2. 写入文件
    file.write("Hello, World too!\n你好👋，世界🌏！\n");
    /// 3. 关闭文件
    file.close();
}

void MainWindow::on_btnStreamRead_clicked() {
    /// 1. 打开文件
    QFile file("../first_demo/resources/docs/test.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "打开文件失败：" << file.errorString();
        return;
    }
    /// 2. 读取文件
    QTextStream in(&file);
    /// 2.1 读取方式1：
    // const QString content = in.read(file.size());
    /// 2.2 读取方式2：
    const QString content = in.readAll();

    /// 从Qt6.7.2 开始移除了 QTextCodec 类，因此 in.setCodec("UTF-8") 不再可用。
    /// Qt 6 默认使用 UTF-8 编码，因此不需要设置编码。
    /// 可以使用 QStringDecoder 改变编码。
    QStringDecoder decoder(QStringDecoder::Utf8);
    const QString content1 = decoder.decode(file.readAll());

    // in.setCodec("UTF-8");
    std::cout << "file content: \n" << content.toStdString() << std::endl;
    std::cout << "file content: \n" << content1.toStdString() << std::endl;

    /// 3. 关闭文件
    file.close();
}


void MainWindow::on_btnStreamWrite_clicked() {
    QFile file("../first_demo/resources/docs/test_write.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "打开文件失败：" << file.errorString();
        return;
    }
    QTextStream out(&file);
    QStringDecoder decoder(QStringDecoder::Utf8);
    out << decoder.decode("Hello, World!\n你好👋，世界🌏！\n");
    file.close();
}

void MainWindow::on_btnQFileDialogOpen_clicked() {
    /// 打开方式1：
    /// 选择取消，返回nullptr
    const QString file_name =
            QFileDialog::getOpenFileName(this, tr("打开文件"), ".", tr("文本文件(*.txt);;所有文件(*.*)"));
    std::cout << "file_name: " << file_name.toStdString() << std::endl;
    /// 打开方式2：
    /// 分步骤打开
    QFileDialog dialog;
    dialog.setWindowTitle(tr("打开文件"));
    dialog.setDirectory(".");
    dialog.setFileMode(QFileDialog::ExistingFiles); /* 如果需要多文件选择，则参数应为QFileDialog::ExistingFiles */
    dialog.setNameFilter(tr("文本文件(*.txt);;所有文件(*.*)"));
    dialog.exec();
    /// 注意：dialog.selectedFiles() 要写在 dialog.exec() 之后，否则无输出结果
    for (const QStringList names = dialog.selectedFiles(); const auto &name: names) {
        std::cout << "file_name: " << name.toStdString() << std::endl;
    }

    /*
    /// 读取文件
    QFile file(file_name);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "打开文件失败：" << file.errorString();
        return;
    }
    QTextStream in(&file);
    const QString content = in.readAll();
    std::cout << "文件内容：\n" << content.toStdString() << std::endl;
    file.close();
    */
}

void MainWindow::on_btnSaveFile_clicked() {
    /// 返回的文件默认不带后缀，如果需要指定后缀，则需要 dialog.setDefaultSuffix("txt");
    const QString file_name =
            QFileDialog::getSaveFileName(this, tr("保存文件"), ".", tr("文本文件 (*.txt);;所有文件 (*)"));
    std::cout << "file_name: " << file_name.toStdString() << std::endl;
    QFile file(file_name);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "打开文件失败：" << file.errorString();
        return;
    }
    QTextStream out(&file);
    QStringDecoder decoder(QStringDecoder::Utf8);
    out << decoder.decode("Hello, World!\n你好👋，世界🌏！\n");
    file.close();
}
