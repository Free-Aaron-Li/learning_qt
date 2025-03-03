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
}

Widget::~Widget() { delete ui; }
