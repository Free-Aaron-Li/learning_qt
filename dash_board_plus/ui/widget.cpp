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
    setFixedSize(800, 600); /* 固定窗口大小 */
    setTime();
}

Widget::~Widget() { delete ui; }

void
Widget::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    int radius = height() / 2;

    initCanvas(painter);
    drawMiddleBoard(painter, _middle_board_radius);
    drawScaleLine(painter, radius);
    drawScaleText(painter, radius);
    drawPointer(painter, radius, _current_time);
    drawPie(painter, radius + 25, _current_time);
    drawEllipseInnerShine(painter, radius / 3);
    drawEllipseInner(painter, radius / 4);
    drawCurrentSpeed(painter, _current_time);
    drawEllipseOuterShine(painter, radius + 25);
    drawLogo(painter, radius);
}

auto
Widget::setTime() -> void {
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
void
Widget::initCanvas(QPainter& painter) const {
    /// 1. 绘制背景
    painter.setBrush(Qt::black);
    painter.drawRect(rect());

    /// 2 确定表盘中心
    const QPoint center(rect().width() / 2,
                        static_cast<int>(rect().height() * 0.6));
    painter.translate(center);
}
void
Widget::drawMiddleBoard(QPainter& painter, const int radius) {
    painter.setPen(QPen(Qt::white, 2));
    painter.drawEllipse(QPoint(0, 0), radius, radius);
}
auto
Widget::drawCurrentSpeed(QPainter& painter, const int current_time) -> void {
    painter.setPen(QPen(Qt::white, 5));

    /// 1. 绘制当前时速
    QFont font("Noto Serif CJK SC", 30);
    font.setBold(true);
    painter.setFont(font);
    painter.drawText(QRect(-_middle_board_radius, -_middle_board_radius,
                           _middle_board_radius * 2, _middle_board_radius),
                     Qt::AlignCenter, QString::number(current_time * 4));

    /// 2. 绘制单位
    QFont font2("Noto Serif CJK SC", 13);
    font2.setBold(true);
    painter.setFont(font2);
    painter.drawText(
            QRect(-_middle_board_radius, -_middle_board_radius,
                  _middle_board_radius * 2, _middle_board_radius * 2 + 40),
            Qt::AlignCenter, "Km/h");
}
auto
Widget::drawScaleLine(QPainter& painter, const int radius) -> void {
    painter.save(); /* 保存当前状态，此刻在原点，x在3点钟方向 */
    painter.rotate(_rotation_angle);

    QFont scale_font("Noto Serif CJK SC", 14);
    scale_font.setBold(true);
    painter.setFont(scale_font);
    painter.setPen(QPen(Qt::white, 5));

    /// 绘制刻度
    for (int i = 0; i <= _scale; ++i) {
        if (i >= 40) { /* 当时速大于160，刻度变红 */
            painter.setPen(QPen(QColor(252, 46, 46, 255), 5));
        }
        /// 绘制刻度线
        if (i % 5 == 0) { /* 绘制长刻度线 */
            painter.drawLine(radius - 20, 0, radius - 2, 0);
        } else { /* 绘制短刻度线*/
            painter.drawLine(radius - 8, 0, radius - 2, 0);
        }
        painter.rotate(_angle); /* 坐标轴顺时针旋转 */
    }

    painter.restore(); /* 恢复之前保存的状态 */
}
auto
Widget::drawScaleText(QPainter& painter, const int radius) -> void {
    /// 偏移坐标x值
    int del_x{ 0 };
    /// 偏移坐标y值
    int del_y{ 0 };

    painter.setFont(QFont("Noto Serif CJK SC", 15));
    const int current_radius = radius - 40;
    for (int i = 0; i <= _scale; ++i) {
        if (i % 5 == 0) {
            /// 0. 保存坐标系
            painter.save();
            try {
                /// 1. 算出平移点
                del_x = static_cast<int>(
                        qCos((210 - _angle * i) * M_PI / 180) *
                        current_radius);  /// Qt中正余弦计算参数为弧度，需要进行转换
                del_y = static_cast<int>(
                        qSin(qDegreesToRadians(210 - _angle * i)) *
                        current_radius);
                /// 2. 平移坐标系
                painter.translate(del_x, -del_y);
                /// 3. 旋转坐标系
                painter.rotate(
                        _angle * i -
                        120); /* 当 angle = 4，i = 30时，刻度值为
                                       120，正常显示，反推即可的应该旋转：angle*i
                                       - 120
                                    */
                /// 4. 绘制刻度值
                painter.drawText(-24, -20, 50, 30, Qt::AlignCenter,
                                 QString::number(i * 4));
            } catch (...) { /* 捕获所有异常 */
                painter.restore();
                throw; /* 重新抛出异常，交由上层处理 */
            }
            /// 5. 恢复坐标系
            painter.restore();
        }
    }
}
auto
Widget::drawPointer(QPainter& painter, const int radius, const int current_time)
        -> void {
    painter.save();
    painter.rotate(_rotation_angle + _angle * current_time);
    painter.setBrush(Qt::white);
    painter.setPen(Qt::NoPen);
    constexpr QPointF points[] = {
        QPointF(20.0, -10.0),
        QPointF(220.0, -1.1),
        QPointF(220.0, 1.1),
        QPointF(20.0, 10.0),
    };
    painter.drawPolygon(points, 4);
    painter.restore();
}
auto
Widget::drawPie(QPainter& painter, const int radius, const int current_time)
        -> void {
    const QRect rectangle(-radius, -radius, radius * 2, radius * 2);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(50, 0, 0, 200));
    painter.drawPie(rectangle, (360 - _rotation_angle) * 16,
                    static_cast<int>(current_time * -_angle *
                                     16));  // angle取负植，为使其顺时针方向绘制
}
auto
Widget::drawEllipseInner(QPainter& painter, const int inner_radius) -> void {
    painter.setBrush(Qt::black);
    painter.setPen(Qt::NoPen);
    painter.drawEllipse(QPoint(0, 0), inner_radius, inner_radius);
}
auto
Widget::drawEllipseInnerShine(QPainter& painter, const int inner_radius)
        -> void {
    QRadialGradient radial_gradient(0, 0, inner_radius);
    radial_gradient.setColorAt(0.0, QColor(255, 0, 0, 200));
    radial_gradient.setColorAt(1.0, QColor(0, 0, 0, 100));
    painter.setBrush(radial_gradient);
    painter.drawEllipse(QPoint(0, 0), inner_radius, inner_radius);
}
auto
Widget::drawEllipseOuterShine(QPainter& painter, const int outer_radius)
        -> void {
    const QRect rectangle(-outer_radius, -outer_radius, outer_radius * 2,
                          outer_radius * 2);
    painter.setPen(Qt::NoPen);
    QRadialGradient radial_gradient(0, 0, outer_radius);
    radial_gradient.setColorAt(1, QColor(255, 0, 0, 200));
    radial_gradient.setColorAt(0.97, QColor(255, 0, 0, 70));
    radial_gradient.setColorAt(0.9, QColor(0, 0, 0, 0));
    radial_gradient.setColorAt(0, QColor(0, 0, 0, 0));
    painter.setBrush(radial_gradient);
    painter.drawPie(rectangle, (360 - _rotation_angle) * 16,
                    static_cast<int>((_scale + 1) * -_angle *
                                     16));  // angle取负植，为使其顺时针方向绘制
}
auto
Widget::drawLogo(QPainter& painter, const int radius) -> void {
    const QRect rectangle(-80, static_cast<int>(radius * 0.38), 171, 76);
    painter.drawPixmap(rectangle, QPixmap(":/logo/jaguar.jpg"));
}
