//  Copyright (c) 2025. aaron.
//
//  This program is under the GPL-3.0 license.
//  if you have not received it or the program has several bugs, please let me know:
//  <communicate_aaron@outlook.com>.

#include "mytextedit.h"

MyTextEdit::MyTextEdit(QWidget *parent) : QTextEdit(parent) {}
void MyTextEdit::wheelEvent(QWheelEvent *event) {
    if (_control_key_pressed) {
        if (event->angleDelta().y() > 0) {
            zoomIn();
        } else if (event->angleDelta().y() < 0) {
            zoomOut();
        }
        event->accept(); /* 事件处理完毕 */
    } else {
        QTextEdit::wheelEvent(event); /* 事件处理传至父类 */
    }
}
void MyTextEdit::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Control) {
        _control_key_pressed = true;
    }
    QTextEdit::keyPressEvent(event);
}
void MyTextEdit::keyReleaseEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Control) {
        _control_key_pressed = false;
    }
    QTextEdit::keyPressEvent(event);
}
