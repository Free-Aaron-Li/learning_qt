//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me
//   know: <communicate_aaron@outlook.com>.

#include "widget.h"

#include "./ui_widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    _timer = new QTimer(this);
    connect(_timer, &QTimer::timeout, [this] {
        if (!_pointer_rotation) {
            _current_time++;
            if (_current_time >= (_scale + 1)) {
                _pointer_rotation = true;
            }
        }
        if (_pointer_rotation) {
            _current_time--;
            if (_current_time <= 0) {
                _pointer_rotation = false;
            }
        }
        update();
    });
    _timer->start(50);
}

Widget::~Widget() { delete ui; }

void
Widget::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    constexpr int rotation_angle{ 150 };
    constexpr double scale_angle{ 240.0 };

    /// 1. 绘制背景
    painter.setBrush(Qt::black);
    painter.drawRect(rect());

    /// 2. 绘制圆形
    painter.translate(rect().center());
    /// 2.1 绘制渐变
    /// 2.2 绘制大圆
    painter.drawEllipse(QPoint(0, 0), height() / 2, height() / 2);
    painter.setBrush(Qt::NoBrush);
    /// 2.3 绘制小圆
    painter.setPen(QPen(Qt::white, 2));
    painter.drawEllipse(QPoint(0, 0), 60, 60);
    /// 2.4 绘制当前值
    painter.setFont(QFont("Noto Serif CJK SC", 20));
    painter.drawText(QRect(-60, -60, 120, 120), Qt::AlignCenter,
                     QString::number(_current_time * 4));

    /// 3. 绘制刻度
    /// 3.1 算出一个刻度需要旋转的角度
    constexpr double angle = scale_angle / _scale;
    /// 3.2 设置低一个刻度的位置
    painter.save(); /* 保存当前状态 */
    painter.rotate(rotation_angle);
    painter.setFont(QFont("Noto Serif CJK SC", 16));
    for (int i = 0; i <= _scale; ++i) {
        if (i % 5 == 0) { /* 绘制长刻度线及字符*/
            if (rotation_angle + angle * i < 270) { /* 左侧字符翻转 */
                painter.rotate(180);
                painter.drawText(-(height() / 2 - 30), 7,
                                 QString::number(i * 4));
                painter.rotate(-180);
            } else {
                painter.drawText(height() / 2 - 60, 7, QString::number(i * 4));
            }
            painter.drawLine(height() / 2 - 20, 0, height() / 2 - 2, 0);
        } else {
            painter.drawLine(height() / 2 - 8, 0, height() / 2 - 2, 0);
        }
        painter.rotate(angle); /* 坐标轴顺时针旋转 */
    }

    /// 4. 绘制指针
    painter.restore(); /* 恢复之前保存的状态 */
    painter.save();
    painter.rotate(rotation_angle + angle * _current_time);
    painter.drawLine(60, 0, height() / 2 - 70, 0);

    /// 5. 绘制扇形
    painter.restore();
    const QRect rectangle(-height() / 2, -height() / 2, height(), height());
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(77, 54, 33, 100));
    painter.drawPie(
            rectangle, (360 - rotation_angle) * 16,
            static_cast<int>(_current_time * -angle *
                             16));  // angle取扶植，为了使其顺时针方向绘制
}
