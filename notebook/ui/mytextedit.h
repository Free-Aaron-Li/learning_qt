//  Copyright (c) 2025. aaron.
//
//  This program is under the GPL-3.0 license.
//  if you have not received it or the program has several bugs, please let me know:
//  <communicate_aaron@outlook.com>.

#ifndef MYTEXTEDIT_H
#define MYTEXTEDIT_H

#include <QWheelEvent>
#include "widget.h"

class MyTextEdit final : public QTextEdit {
    /// Ctrl 按键
    bool _control_key_pressed{ false };

public:
    explicit MyTextEdit(QWidget *parent);

protected:
    void wheelEvent(QWheelEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
};

#endif // MYTEXTEDIT_H
