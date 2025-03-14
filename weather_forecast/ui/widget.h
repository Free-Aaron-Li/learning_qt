#ifndef WIDGET_H
#define WIDGET_H

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QList>
#include <QMenu>
#include <QMessageBox>
#include <QMouseEvent>
#include <QNetworkReply>
#include <QPoint>
#include <QPainter>
#include <QWidget>
#include <iostream>

#include "../include/CityCodeUtils.hpp"
#include "../include/Day.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
    class Widget;
}
QT_END_NAMESPACE

class Widget final : public QWidget {
    Q_OBJECT

public:
    Day _days[7];
    QList<QLabel *> _unit_week_list;
    QList<QLabel *> _unit_date_list;
    QList<QLabel *> _unit_weather_icon_list;
    QList<QLabel *> _unit_weather_content_list;
    QList<QLabel *> _unit_air_quality_list;
    QList<QLabel *> _unit_wind_direction_list;
    QList<QLabel *> _unit_wind_level_list;

    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;


protected:
    /**
     * @brief 重写鼠标右击事件
     *
     * 该函数用于处理鼠标左右击事件。当鼠标左击时移动窗口，鼠标右击时执行退出事件。
     *
     * @param event
     * 指向QMouseEvent对象的指针，包含有关鼠标事件的所有信息，如位置、按钮状态等。
     */
    void
    mousePressEvent(QMouseEvent *event) override;

    /**
     * @brief 重写鼠标移动事件
     *
     * 该函数用于处理鼠标右击时移动窗口。
     *
     * @param event
     * 指向QMouseEvent对象的指针，包含有关鼠标事件的所有信息，如位置、按钮状态等。
     */
    void
    mouseMoveEvent(QMouseEvent *event) override;

    bool eventFilter(QObject* watched, QEvent* event) override;

private slots:
    void
    readHttpReply(QNetworkReply *reply);

    void
    on_pushButtonSearch_clicked();

    void on_lineEditSearchContent_returnPressed();

private:
    Ui::Widget *ui;
    /**
     * @brief 退出菜单
     */
    QMenu *_menu_quit{};

    /**
     * @brief 退出事件
     */
    QAction *_action_quit =
            new QAction(QIcon(":/action/close.svg"), "退出", this);

    /**
     * @brief 鼠标当前位置与窗口位置偏移值
     */
    QPoint _mouse_window_offset{ 0, 0 };

    QNetworkAccessManager *_manager;

    QNetworkReply *_reply{};

    QString _request_url =
            "https://gfeljm.tianqiapi.com/"
            "api?unescape=1&version=v9&appid=94394461&appsecret=Xz94wJnw";
    void
    parseWeatherJsonData(const QByteArray &data) const;
    void
    parseDailyWeatherJsonData(const QByteArray &data);

    CityCodeUtils city_code_utils_;

    QMap<QString, QString> _weather_icon_map;

    void
    initWeatherIconMap();

    void
    updateUI();

    void
    updateLabel();

    void drawTempCurveMax();

    void drawTempCurveMin();

    /// 七天天气预报：https://devapi.qweather.com/v7/weather/7d?location=101010100&key=
    /// 空气质量预报：https://devapi.qweather.com/v7/air/now?location=101010100&key=
};
#endif  // WIDGET_H
