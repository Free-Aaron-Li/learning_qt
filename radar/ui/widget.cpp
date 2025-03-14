//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me
//   know: <communicate_aaron@outlook.com>.
//

#include "widget.h"

#include "./ui_widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    _timer = new QTimer(this);
    connect(_timer, &QTimer::timeout, [=] {
        _start_angle += 30;
        if (_start_angle >= 360) {
            _start_angle = 0;
        }
        update();
    });
    _timer->start(100);
    _timer->start();
}

Widget::~Widget() { delete ui; }

void
Widget::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    /// 0. 全局绘制
    painter.setBrush(QBrush(Qt::black));
    painter.drawRect(rect());

    /// 1. 平移坐标轴到窗口
    painter.translate(rect().center());

    /// 2. 设置笔与笔刷
    painter.setPen(QPen(Qt::green, 4));
    painter.setBrush(Qt::NoBrush); /* 画圆前丢弃笔刷，防止覆盖 */

    /// 3. 绘制
    /// 3.1 绘制圆形
    const auto radius = height() / 2 / 7;
    for (int i = 1; i <= 7; ++i) {
        painter.drawEllipse(QPoint(0, 0), radius * i, radius * i);
    }
    /// 3.2 绘制坐标线
    painter.drawLine(-radius * 7, 0, radius * 7, 0);
    painter.drawLine(0, -radius * 7, 0, radius * 7);

    /// 3.3 绘制渐变
    QConicalGradient conical_gradient(0, 0, -_start_angle);
    conical_gradient.setColorAt(0, QColor(0, 255, 0, 200));
    conical_gradient.setColorAt(0.1, QColor(0, 255, 0, 100));
    conical_gradient.setColorAt(0.2, QColor(0, 255, 0, 0));
    conical_gradient.setColorAt(1, QColor(0, 255, 0, 0));
    painter.setBrush(QBrush(conical_gradient));
    painter.setPen(Qt::NoPen); /* 去除扇形边框 */

    /// 3.4 绘制扇形
    const auto arc = radius * 7; /* 使用height()/2 会导致除不尽，导致线条突出 */
    painter.drawPie(QRect(-arc, -arc, arc * 2, arc * 2), -_start_angle * 16,
                    70 * 16);
}
