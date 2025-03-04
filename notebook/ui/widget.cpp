//  Copyright (c) 2025. aaron.
//
//  This program is under the GPL-3.0 license.
//  if you have not received it or the program has several bugs, please let me know:
//  <communicate_aaron@outlook.com>.

#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    /// 初始化列表构造函数
    /// 设置 Qt Designer 里面的 UI 关联到 Widget 类的私有变量 ui 里面
    ui->setupUi(this);
    /// 虽然上面一行代码进行 widget 和 ui 的窗口关联，但是如果发生窗口大小变化的时候，里面的布局不会随之变化。
    /// 显式调用该窗口下的顶层布局，让窗口变化时，其布局及其子控件随之调整。
    this->setLayout(ui->verticalLayout);

    /// 编码下拉列表
    connect(ui->comboBox, &QComboBox::currentIndexChanged, this, &Widget::in_comboBox_currentIndexChanged);
    connect(ui->textEdit, &QTextEdit::cursorPositionChanged, this, &Widget::in_textEdit_cursorPositionChanged);
}

Widget::~Widget() { delete ui; }

void Widget::on_btnOpen_clicked() {
    const QString file_name = QFileDialog::getOpenFileName(this, tr("打开文件"), QDir::currentPath(),
                                                           tr("文本文件(*.txt);;所有文件(*.*)"));
    ui->textEdit->clear(); /* 重新选择，清空内容 */
    _file.setFileName(file_name);
    if (!_file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "文件打开失败";
    }
    QStringDecoder decoder(ui->comboBox->currentText());
    const QString text = decoder.decode(_file.readAll());
    // ui->textEdit->setText(text); /* 存在覆盖情况 */
    this->setWindowTitle(file_name);
    ui->textEdit->append(text);
}


void Widget::on_btnSave_clicked() {
    const QString file_name = QFileDialog::getSaveFileName(this, tr("保存文件"), QDir::currentPath(),
                                                           tr("文本文件(*.txt);;所有文件(*.*)"));
    _file.setFileName(file_name);
    if (!_file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "文件打开失败";
    }
    QTextStream out(&_file);
    this->setWindowTitle(file_name);
    out << ui->textEdit->toPlainText().toUtf8();
}


void Widget::on_btnClose_clicked() {
    if (_file.isOpen()) {
        ui->textEdit->clear();
        _file.close();
    }
}
void Widget::in_comboBox_currentIndexChanged(int index) {
    ui->textEdit->clear();
    if (_file.isOpen()) {
        QStringDecoder decoder(ui->comboBox->currentText());
        _file.seek(0); /* 光标回到文件内容头，重新读取文件 */
        ui->textEdit->append(decoder.decode(_file.readAll()));
    }
}
void Widget::in_textEdit_cursorPositionChanged() const {
    ui->labelPosition->setText(QString(" 行%1 列%2 ")
                                       .arg(ui->textEdit->textCursor().blockNumber() + 1)
                                       .arg(ui->textEdit->textCursor().columnNumber() + 1));
}
