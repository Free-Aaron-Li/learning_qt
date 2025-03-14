//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me
//   know: <communicate_aaron@outlook.com>.
//

#ifndef WIDGET_H
#define WIDGET_H

#include <QRect>
#include <QTimer>
#include <QPainter>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
    class Widget;
}
QT_END_NAMESPACE

class Widget final : public QWidget {
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;
    void
    paintEvent(QPaintEvent *event) override;

private:
    Ui::Widget *ui;
    int _current_time{ 0 };
    QTimer *_timer{};
    bool _pointer_rotation{ false };
};
#endif  // WIDGET_H
