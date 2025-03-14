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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_5;
    QWidget *widgetTopTop;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEditSearchContent;
    QPushButton *pushButtonSearch;
    QSpacerItem *horizontalSpacerSearachToDate;
    QLabel *labelDate;
    QWidget *widgetTopBottom;
    QHBoxLayout *horizontalLayout;
    QLabel *labelMainWeatherIcon;
    QGridLayout *gridLayout_2;
    QLabel *labelWeatherContent;
    QLabel *labelWeatherTemperatureRange;
    QLabel *labelWeatherTemperatureDegree;
    QLabel *labelWeatherLocation;
    QSpacerItem *horizontalSpacerTempToLoca;
    QWidget *widgetCenter;
    QVBoxLayout *verticalLayout;
    QLabel *labelColdIndex;
    QWidget *widgetCenterInner;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayoutHumidity;
    QLabel *labelHumidityIcon;
    QVBoxLayout *verticalLayoutHumidity;
    QLabel *labelCenterHumidityContent;
    QLabel *labelCenterHumidityLevel;
    QHBoxLayout *horizontalLayoutWindDirection;
    QLabel *labelWindDirectionIcon;
    QVBoxLayout *verticalLayoutWindDirection;
    QLabel *labelCenterWindDirectionContent;
    QLabel *labelCenterWindDirectionLevel;
    QHBoxLayout *horizontalLayoutAirQuality;
    QLabel *labelAirQualityIcon;
    QVBoxLayout *verticalLayoutAirQuality;
    QLabel *labelCenterAirQualityContent;
    QLabel *labelCenterAirQualityLevel;
    QHBoxLayout *horizontalLayoutPm2p5;
    QLabel *labelPm2p5Icon;
    QVBoxLayout *verticalLayoutPm2p5;
    QLabel *labelCenterPm2p5Content;
    QLabel *labelCenterPm2p5Level;
    QWidget *widgetBottom;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_7;
    QWidget *widgetBottomDayAndDate;
    QGridLayout *gridLayout_3;
    QLabel *labelUnitDay0;
    QLabel *labelUnitDay1;
    QLabel *labelUnitDay2;
    QLabel *labelUnitDay3;
    QLabel *labelUnitDay4;
    QLabel *labelUnitDay5;
    QLabel *labelUnitDate0;
    QLabel *labelUnitDate1;
    QLabel *labelUnitDate2;
    QLabel *labelUnitDate3;
    QLabel *labelUnitDate4;
    QLabel *labelUnitDate5;
    QVBoxLayout *verticalLayout_2;
    QWidget *widgetBottomWeather;
    QGridLayout *gridLayout_4;
    QLabel *labelUnitWeatherContent3;
    QLabel *labelUnitWeatherContent0;
    QLabel *labelUnitWeatherContent1;
    QLabel *labelUnitWeatherIcon4;
    QLabel *labelUnitWeatherContent4;
    QLabel *labelUnitWeatherIcon3;
    QLabel *labelUnitWeatherIcon5;
    QLabel *labelUnitWeatherIcon1;
    QLabel *labelUnitWeatherIcon2;
    QLabel *labelUnitWeatherIcon0;
    QLabel *labelUnitWeatherContent5;
    QLabel *labelUnitWeatherContent2;
    QWidget *widgetBottomAirQuality;
    QGridLayout *gridLayout_6;
    QLabel *labelUnitAirQuality3;
    QLabel *labelUnitAirQuality0;
    QLabel *labelUnitAirQuality5;
    QLabel *labelUnitAirQuality1;
    QLabel *labelUnitAirQuality2;
    QLabel *labelUnitAirQuality4;
    QVBoxLayout *verticalLayout_3;
    QWidget *widgetBottomTempCurveMax;
    QWidget *widgetBottomTempCurveMin;
    QWidget *widgetBottomWindDirection;
    QGridLayout *gridLayout_5;
    QLabel *labelUnitWindDirectionContent0;
    QLabel *labelUnitWindDirectionContent1;
    QLabel *labelUnitWindDirectionContent2;
    QLabel *labelUnitWindDirectionContent3;
    QLabel *labelUnitWindDirectionContent4;
    QLabel *labelUnitWindDirectionContent5;
    QLabel *labelUnitWindDirectionLevel0;
    QLabel *labelUnitWindDirectionLevel1;
    QLabel *labelUnitWindDirectionLevel2;
    QLabel *labelUnitWindDirectionLevel3;
    QLabel *labelUnitWindDirectionLevel4;
    QLabel *labelUnitWindDirectionLevel5;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(418, 669);
        Widget->setStyleSheet(QString::fromUtf8("background-color: rgb(22, 22, 22);"));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 2, 401, 661));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        widgetTopTop = new QWidget(layoutWidget);
        widgetTopTop->setObjectName("widgetTopTop");
        widgetTopTop->setStyleSheet(QString::fromUtf8("color: rgb(230, 230, 230);"));
        horizontalLayout_2 = new QHBoxLayout(widgetTopTop);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lineEditSearchContent = new QLineEdit(widgetTopTop);
        lineEditSearchContent->setObjectName("lineEditSearchContent");
        lineEditSearchContent->setMaximumSize(QSize(180, 16777215));
        lineEditSearchContent->setStyleSheet(QString::fromUtf8(" QLineEdit {\n"
"	color: rgb(0, 0, 0);\n"
"     border: 2px solid gray;\n"
"     border-radius: 4px;\n"
"     padding: 0 8px;\n"
"     background: white;\n"
"     selection-background-color: darkgray;\n"
" }\n"
""));

        horizontalLayout_2->addWidget(lineEditSearchContent);

        pushButtonSearch = new QPushButton(widgetTopTop);
        pushButtonSearch->setObjectName("pushButtonSearch");
        pushButtonSearch->setMinimumSize(QSize(20, 20));
        pushButtonSearch->setMaximumSize(QSize(20, 20));
        pushButtonSearch->setStyleSheet(QString::fromUtf8("border-radius: 10px"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/weather/\346\220\234\347\264\242.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButtonSearch->setIcon(icon);
        pushButtonSearch->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(pushButtonSearch);

        horizontalSpacerSearachToDate = new QSpacerItem(20, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacerSearachToDate);

        labelDate = new QLabel(widgetTopTop);
        labelDate->setObjectName("labelDate");

        horizontalLayout_2->addWidget(labelDate);


        verticalLayout_5->addWidget(widgetTopTop);

        widgetTopBottom = new QWidget(layoutWidget);
        widgetTopBottom->setObjectName("widgetTopBottom");
        widgetTopBottom->setStyleSheet(QString::fromUtf8("color: rgb(230, 230, 230);"));
        horizontalLayout = new QHBoxLayout(widgetTopBottom);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(10, 4, 10, 4);
        labelMainWeatherIcon = new QLabel(widgetTopBottom);
        labelMainWeatherIcon->setObjectName("labelMainWeatherIcon");
        labelMainWeatherIcon->setMinimumSize(QSize(60, 60));
        labelMainWeatherIcon->setMaximumSize(QSize(60, 60));
        labelMainWeatherIcon->setPixmap(QPixmap(QString::fromUtf8(":/weather/\346\231\264\345\244\251.svg")));
        labelMainWeatherIcon->setScaledContents(true);

        horizontalLayout->addWidget(labelMainWeatherIcon);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(8, -1, 0, -1);
        labelWeatherContent = new QLabel(widgetTopBottom);
        labelWeatherContent->setObjectName("labelWeatherContent");
        labelWeatherContent->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(labelWeatherContent, 1, 0, 1, 1);

        labelWeatherTemperatureRange = new QLabel(widgetTopBottom);
        labelWeatherTemperatureRange->setObjectName("labelWeatherTemperatureRange");

        gridLayout_2->addWidget(labelWeatherTemperatureRange, 1, 1, 1, 1);

        labelWeatherTemperatureDegree = new QLabel(widgetTopBottom);
        labelWeatherTemperatureDegree->setObjectName("labelWeatherTemperatureDegree");
        QFont font;
        font.setPointSize(30);
        labelWeatherTemperatureDegree->setFont(font);

        gridLayout_2->addWidget(labelWeatherTemperatureDegree, 0, 0, 1, 2);

        labelWeatherLocation = new QLabel(widgetTopBottom);
        labelWeatherLocation->setObjectName("labelWeatherLocation");

        gridLayout_2->addWidget(labelWeatherLocation, 0, 3, 1, 1);

        horizontalSpacerTempToLoca = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacerTempToLoca, 1, 2, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 3);

        verticalLayout_5->addWidget(widgetTopBottom);

        widgetCenter = new QWidget(layoutWidget);
        widgetCenter->setObjectName("widgetCenter");
        widgetCenter->setStyleSheet(QString::fromUtf8("color: rgb(230,230,230)"));
        verticalLayout = new QVBoxLayout(widgetCenter);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(4, 4, 4, 4);
        labelColdIndex = new QLabel(widgetCenter);
        labelColdIndex->setObjectName("labelColdIndex");

        verticalLayout->addWidget(labelColdIndex);

        widgetCenterInner = new QWidget(widgetCenter);
        widgetCenterInner->setObjectName("widgetCenterInner");
        widgetCenterInner->setStyleSheet(QString::fromUtf8("background-color: rgb(186, 96, 6);\n"
"border-radius: 10px"));
        gridLayout = new QGridLayout(widgetCenterInner);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(30);
        gridLayout->setVerticalSpacing(10);
        gridLayout->setContentsMargins(10, 6, 10, 4);
        horizontalLayoutHumidity = new QHBoxLayout();
        horizontalLayoutHumidity->setObjectName("horizontalLayoutHumidity");
        labelHumidityIcon = new QLabel(widgetCenterInner);
        labelHumidityIcon->setObjectName("labelHumidityIcon");
        labelHumidityIcon->setMinimumSize(QSize(35, 35));
        labelHumidityIcon->setMaximumSize(QSize(45, 45));
        labelHumidityIcon->setPixmap(QPixmap(QString::fromUtf8(":/weather/\346\271\277\345\272\246.svg")));
        labelHumidityIcon->setScaledContents(true);

        horizontalLayoutHumidity->addWidget(labelHumidityIcon);

        verticalLayoutHumidity = new QVBoxLayout();
        verticalLayoutHumidity->setObjectName("verticalLayoutHumidity");
        labelCenterHumidityContent = new QLabel(widgetCenterInner);
        labelCenterHumidityContent->setObjectName("labelCenterHumidityContent");
        labelCenterHumidityContent->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayoutHumidity->addWidget(labelCenterHumidityContent);

        labelCenterHumidityLevel = new QLabel(widgetCenterInner);
        labelCenterHumidityLevel->setObjectName("labelCenterHumidityLevel");
        labelCenterHumidityLevel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayoutHumidity->addWidget(labelCenterHumidityLevel);


        horizontalLayoutHumidity->addLayout(verticalLayoutHumidity);


        gridLayout->addLayout(horizontalLayoutHumidity, 1, 0, 1, 1);

        horizontalLayoutWindDirection = new QHBoxLayout();
        horizontalLayoutWindDirection->setObjectName("horizontalLayoutWindDirection");
        labelWindDirectionIcon = new QLabel(widgetCenterInner);
        labelWindDirectionIcon->setObjectName("labelWindDirectionIcon");
        labelWindDirectionIcon->setMinimumSize(QSize(35, 35));
        labelWindDirectionIcon->setMaximumSize(QSize(45, 45));
        labelWindDirectionIcon->setPixmap(QPixmap(QString::fromUtf8(":/weather/\351\243\216\345\220\221.svg")));
        labelWindDirectionIcon->setScaledContents(true);

        horizontalLayoutWindDirection->addWidget(labelWindDirectionIcon);

        verticalLayoutWindDirection = new QVBoxLayout();
        verticalLayoutWindDirection->setObjectName("verticalLayoutWindDirection");
        labelCenterWindDirectionContent = new QLabel(widgetCenterInner);
        labelCenterWindDirectionContent->setObjectName("labelCenterWindDirectionContent");
        labelCenterWindDirectionContent->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayoutWindDirection->addWidget(labelCenterWindDirectionContent);

        labelCenterWindDirectionLevel = new QLabel(widgetCenterInner);
        labelCenterWindDirectionLevel->setObjectName("labelCenterWindDirectionLevel");
        labelCenterWindDirectionLevel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayoutWindDirection->addWidget(labelCenterWindDirectionLevel);


        horizontalLayoutWindDirection->addLayout(verticalLayoutWindDirection);


        gridLayout->addLayout(horizontalLayoutWindDirection, 0, 0, 1, 1);

        horizontalLayoutAirQuality = new QHBoxLayout();
        horizontalLayoutAirQuality->setSpacing(0);
        horizontalLayoutAirQuality->setObjectName("horizontalLayoutAirQuality");
        labelAirQualityIcon = new QLabel(widgetCenterInner);
        labelAirQualityIcon->setObjectName("labelAirQualityIcon");
        labelAirQualityIcon->setMinimumSize(QSize(35, 35));
        labelAirQualityIcon->setMaximumSize(QSize(45, 45));
        labelAirQualityIcon->setPixmap(QPixmap(QString::fromUtf8(":/weather/\347\251\272\346\260\224\350\264\250\351\207\217.svg")));
        labelAirQualityIcon->setScaledContents(true);

        horizontalLayoutAirQuality->addWidget(labelAirQualityIcon);

        verticalLayoutAirQuality = new QVBoxLayout();
        verticalLayoutAirQuality->setSpacing(0);
        verticalLayoutAirQuality->setObjectName("verticalLayoutAirQuality");
        labelCenterAirQualityContent = new QLabel(widgetCenterInner);
        labelCenterAirQualityContent->setObjectName("labelCenterAirQualityContent");
        labelCenterAirQualityContent->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayoutAirQuality->addWidget(labelCenterAirQualityContent);

        labelCenterAirQualityLevel = new QLabel(widgetCenterInner);
        labelCenterAirQualityLevel->setObjectName("labelCenterAirQualityLevel");
        labelCenterAirQualityLevel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayoutAirQuality->addWidget(labelCenterAirQualityLevel);


        horizontalLayoutAirQuality->addLayout(verticalLayoutAirQuality);


        gridLayout->addLayout(horizontalLayoutAirQuality, 1, 1, 1, 1);

        horizontalLayoutPm2p5 = new QHBoxLayout();
        horizontalLayoutPm2p5->setObjectName("horizontalLayoutPm2p5");
        labelPm2p5Icon = new QLabel(widgetCenterInner);
        labelPm2p5Icon->setObjectName("labelPm2p5Icon");
        labelPm2p5Icon->setMinimumSize(QSize(35, 35));
        labelPm2p5Icon->setMaximumSize(QSize(45, 45));
        labelPm2p5Icon->setPixmap(QPixmap(QString::fromUtf8(":/weather/PM2.5.svg")));
        labelPm2p5Icon->setScaledContents(true);

        horizontalLayoutPm2p5->addWidget(labelPm2p5Icon);

        verticalLayoutPm2p5 = new QVBoxLayout();
        verticalLayoutPm2p5->setObjectName("verticalLayoutPm2p5");
        labelCenterPm2p5Content = new QLabel(widgetCenterInner);
        labelCenterPm2p5Content->setObjectName("labelCenterPm2p5Content");
        labelCenterPm2p5Content->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayoutPm2p5->addWidget(labelCenterPm2p5Content);

        labelCenterPm2p5Level = new QLabel(widgetCenterInner);
        labelCenterPm2p5Level->setObjectName("labelCenterPm2p5Level");
        labelCenterPm2p5Level->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayoutPm2p5->addWidget(labelCenterPm2p5Level);


        horizontalLayoutPm2p5->addLayout(verticalLayoutPm2p5);


        gridLayout->addLayout(horizontalLayoutPm2p5, 0, 1, 1, 1);


        verticalLayout->addWidget(widgetCenterInner);


        verticalLayout_5->addWidget(widgetCenter);

        widgetBottom = new QWidget(layoutWidget);
        widgetBottom->setObjectName("widgetBottom");
        layoutWidget1 = new QWidget(widgetBottom);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(-2, 9, 401, 351));
        verticalLayout_4 = new QVBoxLayout(layoutWidget1);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(4, 0, 4, 0);
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName("gridLayout_7");
        widgetBottomDayAndDate = new QWidget(layoutWidget1);
        widgetBottomDayAndDate->setObjectName("widgetBottomDayAndDate");
        widgetBottomDayAndDate->setStyleSheet(QString::fromUtf8("color: rgb(230, 230, 230);"));
        gridLayout_3 = new QGridLayout(widgetBottomDayAndDate);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setHorizontalSpacing(4);
        gridLayout_3->setVerticalSpacing(0);
        gridLayout_3->setContentsMargins(0, 4, 0, 4);
        labelUnitDay0 = new QLabel(widgetBottomDayAndDate);
        labelUnitDay0->setObjectName("labelUnitDay0");
        labelUnitDay0->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 162, 162);\n"
"border-radius: 4px;\n"
"border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
""));
        labelUnitDay0->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignHCenter);

        gridLayout_3->addWidget(labelUnitDay0, 0, 0, 1, 1);

        labelUnitDay1 = new QLabel(widgetBottomDayAndDate);
        labelUnitDay1->setObjectName("labelUnitDay1");
        labelUnitDay1->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 162, 162);\n"
"border-radius: 4px;\n"
"border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
""));
        labelUnitDay1->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignHCenter);

        gridLayout_3->addWidget(labelUnitDay1, 0, 1, 1, 1);

        labelUnitDay2 = new QLabel(widgetBottomDayAndDate);
        labelUnitDay2->setObjectName("labelUnitDay2");
        labelUnitDay2->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 162, 162);\n"
"border-radius: 4px;\n"
"border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
""));
        labelUnitDay2->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignHCenter);

        gridLayout_3->addWidget(labelUnitDay2, 0, 2, 1, 1);

        labelUnitDay3 = new QLabel(widgetBottomDayAndDate);
        labelUnitDay3->setObjectName("labelUnitDay3");
        labelUnitDay3->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 162, 162);\n"
"border-radius: 4px;\n"
"border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
""));
        labelUnitDay3->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignHCenter);

        gridLayout_3->addWidget(labelUnitDay3, 0, 3, 1, 1);

        labelUnitDay4 = new QLabel(widgetBottomDayAndDate);
        labelUnitDay4->setObjectName("labelUnitDay4");
        labelUnitDay4->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 162, 162);\n"
"border-radius: 4px;\n"
"border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
""));
        labelUnitDay4->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignHCenter);

        gridLayout_3->addWidget(labelUnitDay4, 0, 4, 1, 1);

        labelUnitDay5 = new QLabel(widgetBottomDayAndDate);
        labelUnitDay5->setObjectName("labelUnitDay5");
        labelUnitDay5->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 162, 162);\n"
"border-radius: 4px;\n"
"border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
""));
        labelUnitDay5->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignHCenter);

        gridLayout_3->addWidget(labelUnitDay5, 0, 5, 1, 1);

        labelUnitDate0 = new QLabel(widgetBottomDayAndDate);
        labelUnitDate0->setObjectName("labelUnitDate0");
        labelUnitDate0->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 162, 162);\n"
"border-radius: 4px;\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;"));
        labelUnitDate0->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);

        gridLayout_3->addWidget(labelUnitDate0, 1, 0, 1, 1);

        labelUnitDate1 = new QLabel(widgetBottomDayAndDate);
        labelUnitDate1->setObjectName("labelUnitDate1");
        labelUnitDate1->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 162, 162);\n"
"border-radius: 4px;\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;"));
        labelUnitDate1->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);

        gridLayout_3->addWidget(labelUnitDate1, 1, 1, 1, 1);

        labelUnitDate2 = new QLabel(widgetBottomDayAndDate);
        labelUnitDate2->setObjectName("labelUnitDate2");
        labelUnitDate2->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 162, 162);\n"
"border-radius: 4px;\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;"));
        labelUnitDate2->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);

        gridLayout_3->addWidget(labelUnitDate2, 1, 2, 1, 1);

        labelUnitDate3 = new QLabel(widgetBottomDayAndDate);
        labelUnitDate3->setObjectName("labelUnitDate3");
        labelUnitDate3->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 162, 162);\n"
"border-radius: 4px;\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;"));
        labelUnitDate3->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);

        gridLayout_3->addWidget(labelUnitDate3, 1, 3, 1, 1);

        labelUnitDate4 = new QLabel(widgetBottomDayAndDate);
        labelUnitDate4->setObjectName("labelUnitDate4");
        labelUnitDate4->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 162, 162);\n"
"border-radius: 4px;\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;"));
        labelUnitDate4->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);

        gridLayout_3->addWidget(labelUnitDate4, 1, 4, 1, 1);

        labelUnitDate5 = new QLabel(widgetBottomDayAndDate);
        labelUnitDate5->setObjectName("labelUnitDate5");
        labelUnitDate5->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 162, 162);\n"
"border-radius: 4px;\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;"));
        labelUnitDate5->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);

        gridLayout_3->addWidget(labelUnitDate5, 1, 5, 1, 1);


        gridLayout_7->addWidget(widgetBottomDayAndDate, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        widgetBottomWeather = new QWidget(layoutWidget1);
        widgetBottomWeather->setObjectName("widgetBottomWeather");
        widgetBottomWeather->setStyleSheet(QString::fromUtf8("color: rgb(230, 230, 230);"));
        gridLayout_4 = new QGridLayout(widgetBottomWeather);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setVerticalSpacing(0);
        gridLayout_4->setContentsMargins(0, 4, 0, 4);
        labelUnitWeatherContent3 = new QLabel(widgetBottomWeather);
        labelUnitWeatherContent3->setObjectName("labelUnitWeatherContent3");
        labelUnitWeatherContent3->setStyleSheet(QString::fromUtf8("background-color: rgb(37, 37, 37);\n"
"border-radius: 4px;\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;"));
        labelUnitWeatherContent3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(labelUnitWeatherContent3, 1, 3, 1, 1);

        labelUnitWeatherContent0 = new QLabel(widgetBottomWeather);
        labelUnitWeatherContent0->setObjectName("labelUnitWeatherContent0");
        labelUnitWeatherContent0->setStyleSheet(QString::fromUtf8("background-color: rgb(37, 37, 37);\n"
"border-radius: 4px;\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;"));
        labelUnitWeatherContent0->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(labelUnitWeatherContent0, 1, 0, 1, 1);

        labelUnitWeatherContent1 = new QLabel(widgetBottomWeather);
        labelUnitWeatherContent1->setObjectName("labelUnitWeatherContent1");
        labelUnitWeatherContent1->setStyleSheet(QString::fromUtf8("background-color: rgb(37, 37, 37);\n"
"border-radius: 4px;\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;"));
        labelUnitWeatherContent1->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(labelUnitWeatherContent1, 1, 1, 1, 1);

        labelUnitWeatherIcon4 = new QLabel(widgetBottomWeather);
        labelUnitWeatherIcon4->setObjectName("labelUnitWeatherIcon4");
        labelUnitWeatherIcon4->setStyleSheet(QString::fromUtf8("image: url(:/weather/\345\244\232\344\272\221.svg);\n"
"background-color: rgb(37, 37, 37);\n"
"border-radius: 4px;\n"
"border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
""));
        labelUnitWeatherIcon4->setScaledContents(false);
        labelUnitWeatherIcon4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(labelUnitWeatherIcon4, 0, 4, 1, 1);

        labelUnitWeatherContent4 = new QLabel(widgetBottomWeather);
        labelUnitWeatherContent4->setObjectName("labelUnitWeatherContent4");
        labelUnitWeatherContent4->setStyleSheet(QString::fromUtf8("background-color: rgb(37, 37, 37);\n"
"border-radius: 4px;\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;"));
        labelUnitWeatherContent4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(labelUnitWeatherContent4, 1, 4, 1, 1);

        labelUnitWeatherIcon3 = new QLabel(widgetBottomWeather);
        labelUnitWeatherIcon3->setObjectName("labelUnitWeatherIcon3");
        labelUnitWeatherIcon3->setStyleSheet(QString::fromUtf8("image: url(:/weather/\345\244\232\344\272\221.svg);\n"
"background-color: rgb(37, 37, 37);\n"
"border-radius: 4px;\n"
"border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
""));
        labelUnitWeatherIcon3->setScaledContents(false);
        labelUnitWeatherIcon3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(labelUnitWeatherIcon3, 0, 3, 1, 1);

        labelUnitWeatherIcon5 = new QLabel(widgetBottomWeather);
        labelUnitWeatherIcon5->setObjectName("labelUnitWeatherIcon5");
        labelUnitWeatherIcon5->setStyleSheet(QString::fromUtf8("image: url(:/weather/\345\244\232\344\272\221.svg);\n"
"background-color: rgb(37, 37, 37);\n"
"border-radius: 4px;\n"
"border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
""));
        labelUnitWeatherIcon5->setScaledContents(false);
        labelUnitWeatherIcon5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(labelUnitWeatherIcon5, 0, 5, 1, 1);

        labelUnitWeatherIcon1 = new QLabel(widgetBottomWeather);
        labelUnitWeatherIcon1->setObjectName("labelUnitWeatherIcon1");
        labelUnitWeatherIcon1->setStyleSheet(QString::fromUtf8("image: url(:/weather/\345\244\232\344\272\221.svg);\n"
"background-color: rgb(37, 37, 37);\n"
"border-radius: 4px;\n"
"border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
""));
        labelUnitWeatherIcon1->setScaledContents(false);
        labelUnitWeatherIcon1->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(labelUnitWeatherIcon1, 0, 1, 1, 1);

        labelUnitWeatherIcon2 = new QLabel(widgetBottomWeather);
        labelUnitWeatherIcon2->setObjectName("labelUnitWeatherIcon2");
        labelUnitWeatherIcon2->setStyleSheet(QString::fromUtf8("image: url(:/weather/\345\244\232\344\272\221.svg);\n"
"background-color: rgb(37, 37, 37);\n"
"border-radius: 4px;\n"
"border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
""));
        labelUnitWeatherIcon2->setScaledContents(false);
        labelUnitWeatherIcon2->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignHCenter);

        gridLayout_4->addWidget(labelUnitWeatherIcon2, 0, 2, 1, 1);

        labelUnitWeatherIcon0 = new QLabel(widgetBottomWeather);
        labelUnitWeatherIcon0->setObjectName("labelUnitWeatherIcon0");
        labelUnitWeatherIcon0->setStyleSheet(QString::fromUtf8("image: url(:/weather/\345\244\232\344\272\221.svg);\n"
"background-color: rgb(37, 37, 37);\n"
"border-radius: 4px;\n"
"border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
""));
        labelUnitWeatherIcon0->setScaledContents(false);
        labelUnitWeatherIcon0->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(labelUnitWeatherIcon0, 0, 0, 1, 1);

        labelUnitWeatherContent5 = new QLabel(widgetBottomWeather);
        labelUnitWeatherContent5->setObjectName("labelUnitWeatherContent5");
        labelUnitWeatherContent5->setStyleSheet(QString::fromUtf8("background-color: rgb(37, 37, 37);\n"
"border-radius: 4px;\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;"));
        labelUnitWeatherContent5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(labelUnitWeatherContent5, 1, 5, 1, 1);

        labelUnitWeatherContent2 = new QLabel(widgetBottomWeather);
        labelUnitWeatherContent2->setObjectName("labelUnitWeatherContent2");
        labelUnitWeatherContent2->setStyleSheet(QString::fromUtf8("background-color: rgb(37, 37, 37);\n"
"border-radius: 4px;\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;"));
        labelUnitWeatherContent2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(labelUnitWeatherContent2, 1, 2, 1, 1);


        verticalLayout_2->addWidget(widgetBottomWeather);

        widgetBottomAirQuality = new QWidget(layoutWidget1);
        widgetBottomAirQuality->setObjectName("widgetBottomAirQuality");
        widgetBottomAirQuality->setStyleSheet(QString::fromUtf8("color: rgb(230, 230, 230);"));
        gridLayout_6 = new QGridLayout(widgetBottomAirQuality);
        gridLayout_6->setObjectName("gridLayout_6");
        gridLayout_6->setVerticalSpacing(0);
        gridLayout_6->setContentsMargins(0, 4, 0, 4);
        labelUnitAirQuality3 = new QLabel(widgetBottomAirQuality);
        labelUnitAirQuality3->setObjectName("labelUnitAirQuality3");
        labelUnitAirQuality3->setMinimumSize(QSize(0, 0));
        labelUnitAirQuality3->setStyleSheet(QString::fromUtf8("background-color: rgb(121, 184, 0);\n"
"border-radius: 4px;"));
        labelUnitAirQuality3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_6->addWidget(labelUnitAirQuality3, 0, 3, 1, 1);

        labelUnitAirQuality0 = new QLabel(widgetBottomAirQuality);
        labelUnitAirQuality0->setObjectName("labelUnitAirQuality0");
        labelUnitAirQuality0->setMinimumSize(QSize(0, 0));
        labelUnitAirQuality0->setStyleSheet(QString::fromUtf8("background-color: rgb(121, 184, 0);\n"
"border-radius: 4px;"));
        labelUnitAirQuality0->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_6->addWidget(labelUnitAirQuality0, 0, 0, 1, 1);

        labelUnitAirQuality5 = new QLabel(widgetBottomAirQuality);
        labelUnitAirQuality5->setObjectName("labelUnitAirQuality5");
        labelUnitAirQuality5->setMinimumSize(QSize(0, 0));
        labelUnitAirQuality5->setStyleSheet(QString::fromUtf8("background-color: rgb(121, 184, 0);\n"
"border-radius: 4px;"));
        labelUnitAirQuality5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_6->addWidget(labelUnitAirQuality5, 0, 5, 1, 1);

        labelUnitAirQuality1 = new QLabel(widgetBottomAirQuality);
        labelUnitAirQuality1->setObjectName("labelUnitAirQuality1");
        labelUnitAirQuality1->setMinimumSize(QSize(0, 0));
        labelUnitAirQuality1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 187, 23);\n"
"border-radius: 4px;"));
        labelUnitAirQuality1->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_6->addWidget(labelUnitAirQuality1, 0, 1, 1, 1);

        labelUnitAirQuality2 = new QLabel(widgetBottomAirQuality);
        labelUnitAirQuality2->setObjectName("labelUnitAirQuality2");
        labelUnitAirQuality2->setMinimumSize(QSize(0, 0));
        labelUnitAirQuality2->setStyleSheet(QString::fromUtf8("background-color: rgb(121, 184, 0);\n"
"border-radius: 4px;"));
        labelUnitAirQuality2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_6->addWidget(labelUnitAirQuality2, 0, 2, 1, 1);

        labelUnitAirQuality4 = new QLabel(widgetBottomAirQuality);
        labelUnitAirQuality4->setObjectName("labelUnitAirQuality4");
        labelUnitAirQuality4->setMinimumSize(QSize(0, 0));
        labelUnitAirQuality4->setStyleSheet(QString::fromUtf8("background-color: rgb(121, 184, 0);\n"
"border-radius: 4px;"));
        labelUnitAirQuality4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_6->addWidget(labelUnitAirQuality4, 0, 4, 1, 1);


        verticalLayout_2->addWidget(widgetBottomAirQuality);

        verticalLayout_2->setStretch(0, 2);
        verticalLayout_2->setStretch(1, 1);

        gridLayout_7->addLayout(verticalLayout_2, 1, 0, 1, 1);

        gridLayout_7->setRowMinimumHeight(0, 1);
        gridLayout_7->setRowMinimumHeight(1, 2);

        verticalLayout_4->addLayout(gridLayout_7);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        widgetBottomTempCurveMax = new QWidget(layoutWidget1);
        widgetBottomTempCurveMax->setObjectName("widgetBottomTempCurveMax");
        widgetBottomTempCurveMax->setMinimumSize(QSize(0, 60));
        widgetBottomTempCurveMax->setStyleSheet(QString::fromUtf8("background-color: rgb(37, 37, 37);\n"
"border-radius: 4px;\n"
"border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
""));

        verticalLayout_3->addWidget(widgetBottomTempCurveMax);

        widgetBottomTempCurveMin = new QWidget(layoutWidget1);
        widgetBottomTempCurveMin->setObjectName("widgetBottomTempCurveMin");
        widgetBottomTempCurveMin->setMinimumSize(QSize(0, 60));
        widgetBottomTempCurveMin->setStyleSheet(QString::fromUtf8("background-color: rgb(37, 37, 37);\n"
"border-radius: 4px;\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;"));

        verticalLayout_3->addWidget(widgetBottomTempCurveMin);


        verticalLayout_4->addLayout(verticalLayout_3);

        widgetBottomWindDirection = new QWidget(layoutWidget1);
        widgetBottomWindDirection->setObjectName("widgetBottomWindDirection");
        widgetBottomWindDirection->setStyleSheet(QString::fromUtf8("color: rgb(230, 230, 230);"));
        gridLayout_5 = new QGridLayout(widgetBottomWindDirection);
        gridLayout_5->setObjectName("gridLayout_5");
        gridLayout_5->setHorizontalSpacing(4);
        gridLayout_5->setVerticalSpacing(0);
        gridLayout_5->setContentsMargins(0, 4, 0, 0);
        labelUnitWindDirectionContent0 = new QLabel(widgetBottomWindDirection);
        labelUnitWindDirectionContent0->setObjectName("labelUnitWindDirectionContent0");
        labelUnitWindDirectionContent0->setStyleSheet(QString::fromUtf8("background-color: rgb(37, 37, 37);\n"
"border-radius: 4px;\n"
"border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
""));
        labelUnitWindDirectionContent0->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignHCenter);

        gridLayout_5->addWidget(labelUnitWindDirectionContent0, 0, 0, 1, 1);

        labelUnitWindDirectionContent1 = new QLabel(widgetBottomWindDirection);
        labelUnitWindDirectionContent1->setObjectName("labelUnitWindDirectionContent1");
        labelUnitWindDirectionContent1->setStyleSheet(QString::fromUtf8("background-color: rgb(37, 37, 37);\n"
"border-radius: 4px;\n"
"border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
""));
        labelUnitWindDirectionContent1->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignHCenter);

        gridLayout_5->addWidget(labelUnitWindDirectionContent1, 0, 1, 1, 1);

        labelUnitWindDirectionContent2 = new QLabel(widgetBottomWindDirection);
        labelUnitWindDirectionContent2->setObjectName("labelUnitWindDirectionContent2");
        labelUnitWindDirectionContent2->setStyleSheet(QString::fromUtf8("background-color: rgb(37, 37, 37);\n"
"border-radius: 4px;\n"
"border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
""));
        labelUnitWindDirectionContent2->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignHCenter);

        gridLayout_5->addWidget(labelUnitWindDirectionContent2, 0, 2, 1, 1);

        labelUnitWindDirectionContent3 = new QLabel(widgetBottomWindDirection);
        labelUnitWindDirectionContent3->setObjectName("labelUnitWindDirectionContent3");
        labelUnitWindDirectionContent3->setStyleSheet(QString::fromUtf8("background-color: rgb(37, 37, 37);\n"
"border-radius: 4px;\n"
"border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
""));
        labelUnitWindDirectionContent3->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignHCenter);

        gridLayout_5->addWidget(labelUnitWindDirectionContent3, 0, 3, 1, 1);

        labelUnitWindDirectionContent4 = new QLabel(widgetBottomWindDirection);
        labelUnitWindDirectionContent4->setObjectName("labelUnitWindDirectionContent4");
        labelUnitWindDirectionContent4->setStyleSheet(QString::fromUtf8("background-color: rgb(37, 37, 37);\n"
"border-radius: 4px;\n"
"border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
""));
        labelUnitWindDirectionContent4->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignHCenter);

        gridLayout_5->addWidget(labelUnitWindDirectionContent4, 0, 4, 1, 1);

        labelUnitWindDirectionContent5 = new QLabel(widgetBottomWindDirection);
        labelUnitWindDirectionContent5->setObjectName("labelUnitWindDirectionContent5");
        labelUnitWindDirectionContent5->setStyleSheet(QString::fromUtf8("background-color: rgb(37, 37, 37);\n"
"border-radius: 4px;\n"
"border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
""));
        labelUnitWindDirectionContent5->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignHCenter);

        gridLayout_5->addWidget(labelUnitWindDirectionContent5, 0, 5, 1, 1);

        labelUnitWindDirectionLevel0 = new QLabel(widgetBottomWindDirection);
        labelUnitWindDirectionLevel0->setObjectName("labelUnitWindDirectionLevel0");
        labelUnitWindDirectionLevel0->setStyleSheet(QString::fromUtf8("background-color: rgb(37, 37, 37);\n"
"border-radius: 4px;\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;"));
        labelUnitWindDirectionLevel0->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_5->addWidget(labelUnitWindDirectionLevel0, 1, 0, 1, 1);

        labelUnitWindDirectionLevel1 = new QLabel(widgetBottomWindDirection);
        labelUnitWindDirectionLevel1->setObjectName("labelUnitWindDirectionLevel1");
        labelUnitWindDirectionLevel1->setStyleSheet(QString::fromUtf8("background-color: rgb(37, 37, 37);\n"
"border-radius: 4px;\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;"));
        labelUnitWindDirectionLevel1->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_5->addWidget(labelUnitWindDirectionLevel1, 1, 1, 1, 1);

        labelUnitWindDirectionLevel2 = new QLabel(widgetBottomWindDirection);
        labelUnitWindDirectionLevel2->setObjectName("labelUnitWindDirectionLevel2");
        labelUnitWindDirectionLevel2->setStyleSheet(QString::fromUtf8("background-color: rgb(37, 37, 37);\n"
"border-radius: 4px;\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;"));
        labelUnitWindDirectionLevel2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_5->addWidget(labelUnitWindDirectionLevel2, 1, 2, 1, 1);

        labelUnitWindDirectionLevel3 = new QLabel(widgetBottomWindDirection);
        labelUnitWindDirectionLevel3->setObjectName("labelUnitWindDirectionLevel3");
        labelUnitWindDirectionLevel3->setStyleSheet(QString::fromUtf8("background-color: rgb(37, 37, 37);\n"
"border-radius: 4px;\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;"));
        labelUnitWindDirectionLevel3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_5->addWidget(labelUnitWindDirectionLevel3, 1, 3, 1, 1);

        labelUnitWindDirectionLevel4 = new QLabel(widgetBottomWindDirection);
        labelUnitWindDirectionLevel4->setObjectName("labelUnitWindDirectionLevel4");
        labelUnitWindDirectionLevel4->setStyleSheet(QString::fromUtf8("background-color: rgb(37, 37, 37);\n"
"border-radius: 4px;\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;"));
        labelUnitWindDirectionLevel4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_5->addWidget(labelUnitWindDirectionLevel4, 1, 4, 1, 1);

        labelUnitWindDirectionLevel5 = new QLabel(widgetBottomWindDirection);
        labelUnitWindDirectionLevel5->setObjectName("labelUnitWindDirectionLevel5");
        labelUnitWindDirectionLevel5->setStyleSheet(QString::fromUtf8("background-color: rgb(37, 37, 37);\n"
"border-radius: 4px;\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;"));
        labelUnitWindDirectionLevel5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_5->addWidget(labelUnitWindDirectionLevel5, 1, 5, 1, 1);


        verticalLayout_4->addWidget(widgetBottomWindDirection);

        verticalLayout_4->setStretch(0, 4);
        verticalLayout_4->setStretch(1, 4);
        verticalLayout_4->setStretch(2, 1);

        verticalLayout_5->addWidget(widgetBottom);

        verticalLayout_5->setStretch(0, 1);
        verticalLayout_5->setStretch(1, 3);
        verticalLayout_5->setStretch(2, 3);
        verticalLayout_5->setStretch(3, 12);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        lineEditSearchContent->setText(QString());
        pushButtonSearch->setText(QString());
        labelDate->setText(QCoreApplication::translate("Widget", "2025/3/16  \346\230\237\346\234\237\346\227\245", nullptr));
        labelMainWeatherIcon->setText(QString());
        labelWeatherContent->setText(QCoreApplication::translate("Widget", "\346\231\264\345\244\251", nullptr));
        labelWeatherTemperatureRange->setText(QCoreApplication::translate("Widget", "20 ~ 26 \342\204\203 ", nullptr));
        labelWeatherTemperatureDegree->setText(QCoreApplication::translate("Widget", "23", nullptr));
        labelWeatherLocation->setText(QCoreApplication::translate("Widget", "\346\267\261\345\234\263\345\270\202", nullptr));
        labelColdIndex->setText(QCoreApplication::translate("Widget", "\346\204\237\345\206\222\346\214\207\346\225\260\357\274\232\345\220\204\347\261\273\344\272\272\347\276\244\345\217\257\350\207\252\347\224\261\346\264\273\345\212\250", nullptr));
        labelHumidityIcon->setText(QString());
        labelCenterHumidityContent->setText(QCoreApplication::translate("Widget", "\346\271\277\345\272\246", nullptr));
        labelCenterHumidityLevel->setText(QCoreApplication::translate("Widget", "85%", nullptr));
        labelWindDirectionIcon->setText(QString());
        labelCenterWindDirectionContent->setText(QCoreApplication::translate("Widget", "\344\270\234\345\215\227\351\243\216", nullptr));
        labelCenterWindDirectionLevel->setText(QCoreApplication::translate("Widget", "2 \347\272\247", nullptr));
        labelAirQualityIcon->setText(QString());
        labelCenterAirQualityContent->setText(QCoreApplication::translate("Widget", "\347\251\272\346\260\224\350\264\250\351\207\217", nullptr));
        labelCenterAirQualityLevel->setText(QCoreApplication::translate("Widget", "\344\274\230", nullptr));
        labelPm2p5Icon->setText(QString());
        labelCenterPm2p5Content->setText(QCoreApplication::translate("Widget", "PM 2.5", nullptr));
        labelCenterPm2p5Level->setText(QCoreApplication::translate("Widget", "24", nullptr));
        labelUnitDay0->setText(QCoreApplication::translate("Widget", "\346\230\250\345\244\251", nullptr));
        labelUnitDay1->setText(QCoreApplication::translate("Widget", "\346\230\250\345\244\251", nullptr));
        labelUnitDay2->setText(QCoreApplication::translate("Widget", "\346\230\250\345\244\251", nullptr));
        labelUnitDay3->setText(QCoreApplication::translate("Widget", "\346\230\250\345\244\251", nullptr));
        labelUnitDay4->setText(QCoreApplication::translate("Widget", "\346\230\250\345\244\251", nullptr));
        labelUnitDay5->setText(QCoreApplication::translate("Widget", "\346\230\250\345\244\251", nullptr));
        labelUnitDate0->setText(QCoreApplication::translate("Widget", "03/16", nullptr));
        labelUnitDate1->setText(QCoreApplication::translate("Widget", "03/16", nullptr));
        labelUnitDate2->setText(QCoreApplication::translate("Widget", "03/16", nullptr));
        labelUnitDate3->setText(QCoreApplication::translate("Widget", "03/16", nullptr));
        labelUnitDate4->setText(QCoreApplication::translate("Widget", "03/16", nullptr));
        labelUnitDate5->setText(QCoreApplication::translate("Widget", "03/16", nullptr));
        labelUnitWeatherContent3->setText(QCoreApplication::translate("Widget", "\345\244\232\344\272\221", nullptr));
        labelUnitWeatherContent0->setText(QCoreApplication::translate("Widget", "\345\244\232\344\272\221", nullptr));
        labelUnitWeatherContent1->setText(QCoreApplication::translate("Widget", "\345\244\232\344\272\221", nullptr));
        labelUnitWeatherIcon4->setText(QString());
        labelUnitWeatherContent4->setText(QCoreApplication::translate("Widget", "\345\244\232\344\272\221", nullptr));
        labelUnitWeatherIcon3->setText(QString());
        labelUnitWeatherIcon5->setText(QString());
        labelUnitWeatherIcon1->setText(QString());
        labelUnitWeatherIcon2->setText(QString());
        labelUnitWeatherIcon0->setText(QString());
        labelUnitWeatherContent5->setText(QCoreApplication::translate("Widget", "\345\244\232\344\272\221", nullptr));
        labelUnitWeatherContent2->setText(QCoreApplication::translate("Widget", "\345\244\232\344\272\221", nullptr));
        labelUnitAirQuality3->setText(QCoreApplication::translate("Widget", "\344\274\230", nullptr));
        labelUnitAirQuality0->setText(QCoreApplication::translate("Widget", "\344\274\230", nullptr));
        labelUnitAirQuality5->setText(QCoreApplication::translate("Widget", "\344\274\230", nullptr));
        labelUnitAirQuality1->setText(QCoreApplication::translate("Widget", "\350\211\257", nullptr));
        labelUnitAirQuality2->setText(QCoreApplication::translate("Widget", "\344\274\230", nullptr));
        labelUnitAirQuality4->setText(QCoreApplication::translate("Widget", "\344\274\230", nullptr));
        labelUnitWindDirectionContent0->setText(QCoreApplication::translate("Widget", "\344\270\234\345\215\227\351\243\216", nullptr));
        labelUnitWindDirectionContent1->setText(QCoreApplication::translate("Widget", "\344\270\234\345\215\227\351\243\216", nullptr));
        labelUnitWindDirectionContent2->setText(QCoreApplication::translate("Widget", "\344\270\234\345\215\227\351\243\216", nullptr));
        labelUnitWindDirectionContent3->setText(QCoreApplication::translate("Widget", "\344\270\234\345\215\227\351\243\216", nullptr));
        labelUnitWindDirectionContent4->setText(QCoreApplication::translate("Widget", "\344\270\234\345\215\227\351\243\216", nullptr));
        labelUnitWindDirectionContent5->setText(QCoreApplication::translate("Widget", "\344\270\234\345\215\227\351\243\216", nullptr));
        labelUnitWindDirectionLevel0->setText(QCoreApplication::translate("Widget", "2 \347\272\247", nullptr));
        labelUnitWindDirectionLevel1->setText(QCoreApplication::translate("Widget", "2 \347\272\247", nullptr));
        labelUnitWindDirectionLevel2->setText(QCoreApplication::translate("Widget", "2 \347\272\247", nullptr));
        labelUnitWindDirectionLevel3->setText(QCoreApplication::translate("Widget", "2 \347\272\247", nullptr));
        labelUnitWindDirectionLevel4->setText(QCoreApplication::translate("Widget", "2 \347\272\247", nullptr));
        labelUnitWindDirectionLevel5->setText(QCoreApplication::translate("Widget", "2 \347\272\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
