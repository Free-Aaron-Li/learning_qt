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

    /// 快捷键
    const QShortcut *shortcut_open = new QShortcut(QKeySequence(tr("Ctrl+o", "File|Open")), this);
    const QShortcut *shortcut_save = new QShortcut(QKeySequence(tr("Ctrl+s", "File|Save")), this);
    const QShortcut *shortcut_zoom_in = new QShortcut(QKeySequence(tr("Ctrl+=", "View|Zoom In")), this);
    const QShortcut *shortcut_zoom_out = new QShortcut(QKeySequence(tr("Ctrl+-", "View|Zoom Out")), this);
    connect(shortcut_open, &QShortcut::activated, [this] { on_btnOpen_clicked(); });
    connect(shortcut_save, &QShortcut::activated, [this] { on_btnSave_clicked(); });
    connect(shortcut_zoom_in, &QShortcut::activated, [this] { zoomIn(); });
    connect(shortcut_zoom_out, &QShortcut::activated, [this] { zoomOut(); });
}

Widget::~Widget() { delete ui; }

void Widget::on_btnOpen_clicked() {
    const QString file_name = QFileDialog::getOpenFileName(this, tr("打开文件"), QDir::currentPath(),
                                                           tr("文本文件(*.txt);;所有文件(*.*)"));
    ui->textEdit->clear(); /* 重新选择，清空内容 */
    _file.setFileName(file_name);
    if (!_file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qDebug() << "文件打开失败";
    }
    QStringDecoder decoder(ui->comboBox->currentText()); /* 默认按照 UTF-8 方式解码 */
    const QString text = decoder.decode(_file.readAll());
    // ui->textEdit->setText(text); /* 存在覆盖情况 */
    this->setWindowTitle(file_name);
    ui->textEdit->append(text);
}


void Widget::on_btnSave_clicked() {
    if (!_file.isOpen()) {
        const QString file_name = QFileDialog::getSaveFileName(this, tr("保存文件"), QDir::currentPath(),
                                                               tr("文本文件(*.txt);;所有文件(*.*)"));
        _file.setFileName(file_name);
        if (!_file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qDebug() << "文件打开失败";
        }

        this->setWindowTitle(file_name);
    } else {
        _file.resize(0); /* 当前文件内容 */
    }

    QTextStream out(&_file);
    // out<< ui->textEdit->toPlainText(); /* 直接通过UTF-8输出 */
    QStringEncoder encoder(ui->comboBox->currentText());
    out << encoder.encode(ui->textEdit->toPlainText()); /* TODO 输出“锟斤拷” */
}


void Widget::on_btnClose_clicked() {
    /*
    QMessageBox message_box;
    message_box.setWindowTitle("是否关闭文件？");
    message_box.setInformativeText("文件内容未保存，是否关闭？");
    message_box.setStandardButtons(QMessageBox::Yes | QMessageBox::Discard | QMessageBox::No);
    message_box.setDefaultButton(QMessageBox::Yes);
    */

    const auto result =
            QMessageBox::warning(this, tr("是否关闭文件？"), tr("文件内容未保存，是否保存？"),
                                 QMessageBox::Yes | QMessageBox::Discard | QMessageBox::No, QMessageBox::Yes);

    switch (result) {
        case QMessageBox::Yes: /* 保存 */
            on_btnSave_clicked();
            break;
        case QMessageBox::Discard: /* 丢弃 */
            ui->textEdit->clear();
            if (_file.isOpen()) {
                _file.close();
            }
            break;
        default: /* 取消 */
            break;
    }
}
void Widget::in_comboBox_currentIndexChanged(int index) {
    if (!ui->textEdit->toPlainText().isEmpty()) {
        ui->textEdit->clear();
    }
    QStringDecoder decoder(ui->comboBox->currentText());
    _file.seek(0); /* 光标回到文件内容头，重新读取文件 */
    ui->textEdit->append(decoder.decode(_file.readAll()));
}
void Widget::in_textEdit_cursorPositionChanged() {
    /// 输出行列编号
    ui->labelPosition->setText(QString(" 行%1 列%2 ")
                                       .arg(ui->textEdit->textCursor().blockNumber() + 1)
                                       .arg(ui->textEdit->textCursor().columnNumber() + 1));
    /// 设置当前行高亮
    /// 1. 获取当前行
    _selection.cursor = ui->textEdit->textCursor();
    /// 2. 颜色设置
    _selection.format.setBackground(QColor::fromRgb(242, 242, 242));
    _selection.format.setProperty(QTextFormat::FullWidthSelection, true); /* 属性：整行显示 */
    _selection.format.setFontUnderline(true); /* 下划线 */
    _extra_selections.append(_selection);
    ui->textEdit->setExtraSelections(_extra_selections);
}
void Widget::zoomIn() const {
    QFont font = ui->textEdit->font();
    const int font_size = font.pointSize();
    if (font_size == -1) {
        qDebug() << "获取字体失败.";
        return;
    }
    const int new_font_size = font_size + 1;
    font.setPointSize(new_font_size);
    ui->textEdit->setFont(font);
}
void Widget::zoomOut() const {
    QFont font = ui->textEdit->font();
    const int font_size = font.pointSize();
    if (font_size == -1) {
        qDebug() << "获取字体失败.";
        return;
    }
    const int new_font_size = font_size + 1;
    font.setPointSize(new_font_size);
    ui->textEdit->setFont(font);
}
