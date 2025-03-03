/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widgetButtons;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayoutButtons;
    QPushButton *btnOpen;
    QPushButton *btnSave;
    QPushButton *btnClose;
    QSpacerItem *hSpacer;
    QTextEdit *textEdit;
    QWidget *widgetBottom;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacerLeft;
    QLabel *labelPosition;
    QLabel *labelEncoding;
    QSpacerItem *horizontalSpacerRight;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(799, 599);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resource/icon/note.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Widget->setWindowIcon(icon);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 0, 801, 601));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widgetButtons = new QWidget(layoutWidget);
        widgetButtons->setObjectName("widgetButtons");
        widgetButtons->setMinimumSize(QSize(0, 50));
        widgetButtons->setStyleSheet(QString::fromUtf8("background-color: rgb(74, 74, 74)"));
        layoutWidget1 = new QWidget(widgetButtons);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(0, 0, 801, 51));
        horizontalLayoutButtons = new QHBoxLayout(layoutWidget1);
        horizontalLayoutButtons->setSpacing(0);
        horizontalLayoutButtons->setObjectName("horizontalLayoutButtons");
        horizontalLayoutButtons->setContentsMargins(0, 0, 0, 0);
        btnOpen = new QPushButton(layoutWidget1);
        btnOpen->setObjectName("btnOpen");
        btnOpen->setMinimumSize(QSize(35, 35));
        btnOpen->setStyleSheet(QString::fromUtf8("QPushButton {border-image: url(:/icon/o1.png);}\n"
"QPushButton::hover {border-image: url(:/icon/o2.png);}\n"
"QPushButton::pressed {border-image: url(:/icon/o3.png);}"));

        horizontalLayoutButtons->addWidget(btnOpen);

        btnSave = new QPushButton(layoutWidget1);
        btnSave->setObjectName("btnSave");
        btnSave->setMinimumSize(QSize(40, 40));
        btnSave->setStyleSheet(QString::fromUtf8("QPushButton { border-image: url(:/icon/s1.png); }\n"
"QPushButton::hover { border-image: url(:/icon/s2.png); }\n"
"QPushButton::pressed { border-image: url(:/icon/s3.png); }"));

        horizontalLayoutButtons->addWidget(btnSave);

        btnClose = new QPushButton(layoutWidget1);
        btnClose->setObjectName("btnClose");
        btnClose->setMinimumSize(QSize(40, 40));
        btnClose->setStyleSheet(QString::fromUtf8("QPushButton { border-image: url(:/icon/c1.png); }\n"
"QPushButton::hover { border-image: url(:/icon/c2.png); }\n"
"QPushButton::pressed { border-image: url(:/icon/c3.png); }"));

        horizontalLayoutButtons->addWidget(btnClose);

        hSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayoutButtons->addItem(hSpacer);


        verticalLayout->addWidget(widgetButtons);

        textEdit = new QTextEdit(layoutWidget);
        textEdit->setObjectName("textEdit");

        verticalLayout->addWidget(textEdit);

        widgetBottom = new QWidget(layoutWidget);
        widgetBottom->setObjectName("widgetBottom");
        widgetBottom->setMinimumSize(QSize(0, 30));
        widgetBottom->setStyleSheet(QString::fromUtf8("background-color: rgb(74, 74, 74)"));
        horizontalLayout = new QHBoxLayout(widgetBottom);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacerLeft = new QSpacerItem(625, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacerLeft);

        labelPosition = new QLabel(widgetBottom);
        labelPosition->setObjectName("labelPosition");
        labelPosition->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(labelPosition);

        labelEncoding = new QLabel(widgetBottom);
        labelEncoding->setObjectName("labelEncoding");

        horizontalLayout->addWidget(labelEncoding);

        horizontalSpacerRight = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacerRight);


        verticalLayout->addWidget(widgetBottom);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\350\256\260\344\272\213\346\234\254", nullptr));
        btnOpen->setText(QString());
        btnSave->setText(QString());
        btnClose->setText(QString());
        labelPosition->setText(QCoreApplication::translate("Widget", "\347\254\254 1 \350\241\214 \347\254\254 1 \345\210\227 ", nullptr));
        labelEncoding->setText(QCoreApplication::translate("Widget", "UTF-8", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
