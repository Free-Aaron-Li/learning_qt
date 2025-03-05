//  Copyright (c) 2025. aaron.
//
//  This program is under the GPL-3.0 license.
//  if you have not received it or the program has several bugs, please let me know:
//  <communicate_aaron@outlook.com>.

#include "mybutton.h"


MyButton::MyButton(QWidget *parent) : QWidget{ parent } {
    picture.load(":/icon/o1.png"); /* 蓝色 */
    setFixedSize(picture.size());
    update();
}
void MyButton::mousePressEvent(QMouseEvent *event) {
    picture.load(":/icon/o3.png"); /* 灰色 */
    update();
    emit clicked(); /* 发送信号 */
}
void MyButton::leaveEvent(QEvent *event) {
    picture.load(":/icon/o1.png");
    update();
}
void MyButton::enterEvent(QEnterEvent *event) {
    picture.load(":/icon/o2.png");
    update();
}
void MyButton::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.drawPixmap(rect(), picture);
}
