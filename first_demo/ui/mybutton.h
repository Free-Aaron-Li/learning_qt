//  Copyright (c) 2025. aaron.
//
//  This program is under the GPL-3.0 license.
//  if you have not received it or the program has several bugs, please let me know:
//  <communicate_aaron@outlook.com>.

#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPainter>
#include <QWidget>

class MyButton final : public QWidget {
    Q_OBJECT
    QPixmap picture;

public:
    explicit MyButton(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void enterEvent(QEnterEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
signals:
    void clicked();
};

#endif // MYBUTTON_H
