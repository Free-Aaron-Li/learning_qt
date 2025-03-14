#include "widget.h"

#include "./ui_widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    // setFixedSize(340, 692); /* 固定大小 */
    setWindowFlag(Qt::FramelessWindowHint); /* 无边框显示 */

    /// 1. 创建菜单组件
    _menu_quit = new QMenu(this);
    /// 2. 设置菜单样式
    _menu_quit->setStyleSheet("QMenu::item {color:white}");
    /// 3. 创建菜单项：退出事件
    _menu_quit->addAction(_action_quit);
    connect(_menu_quit, &QMenu::triggered, [this] { this->close(); });

    /// 创建网络访问管理器
    /// 由 QNetworkAccessManager 管理网络
    _manager = new QNetworkAccessManager(this);
    /// 发送网络请求
    const QNetworkRequest request{ QUrl(_request_url) };
    _reply = _manager->get(request);
    /// 网络请求后进行数据读取
    connect(_manager, &QNetworkAccessManager::finished, this,
            &Widget::readHttpReply);
    initWeatherIconMap();
    updateLabel();
}

Widget::~Widget() { delete ui; }
void
Widget::readHttpReply(QNetworkReply* reply) {
    const int request_code =
            reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

    if (reply->error() == QNetworkReply::NoError && request_code == 200) {
        // parseWeatherJsonData(reply->readAll());
        parseDailyWeatherJsonData(reply->readAll());
    } else {
        QMessageBox message_box;
        message_box.setWindowTitle("错误");
        message_box.setText("网络请求失败\n" + reply->errorString());
        message_box.setStyleSheet("QPushButton {color:red};");
        message_box.setStandardButtons(QMessageBox::Ok);
        message_box.exec();
    }
}
void
Widget::on_pushButtonSearch_clicked() {
    const QString city_name_from_user = ui->lineEditSearchContent->text();
    if (const QString city_code =
                city_code_utils_.getCityCodeFromName(city_name_from_user);
        !city_code.isEmpty()) {
        _request_url += "&cityid=" + city_code;
        _manager->get(QNetworkRequest(QUrl(_request_url)));
    } else {
        QMessageBox message_box;
        message_box.setWindowTitle("错误");
        message_box.setText("“" + city_name_from_user + "”城市不存在！");
        message_box.setStyleSheet("QPushButton {color:red};");
        message_box.setStandardButtons(QMessageBox::Ok);
        message_box.exec();
        qDebug() << "地址为：" + city_name_from_user + "，输入地址未知！";
    }
}
void
Widget::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::RightButton) {
        _menu_quit->exec(QCursor::pos());
    }
    if (event->button() == Qt::LeftButton) {
        /// 鼠标当前位置：event->globalPosition()
        /// 窗口当前位置：this->pos()

        /// 1. 当鼠标按下时，获得鼠标与窗口位置的偏移值
        _mouse_window_offset = QPoint(
                static_cast<int>(event->globalPosition().x() - this->pos().x()),
                static_cast<int>(event->globalPosition().y() -
                                 this->pos().y()));
    }
    QWidget::mousePressEvent(event);
}
void
Widget::mouseMoveEvent(QMouseEvent* event) {
    /// 2. 当鼠标移动后，根据偏移值算出窗口应该处于位置
    this->move(static_cast<int>(event->globalPosition().x() -
                                _mouse_window_offset.x()),
               static_cast<int>(event->globalPosition().y() -
                                _mouse_window_offset.y()));
    QWidget::mouseMoveEvent(event);
}
bool
Widget::eventFilter(QObject* watched, QEvent* event) {
    if (watched == ui->widgetBottomTempCurveMax &&
        event->type() == QEvent::Paint) {
        drawTempCurveMax();
    }
    if (watched == ui->widgetBottomTempCurveMin &&
        event->type() == QEvent::Paint) {
        drawTempCurveMin();
    }
    return QWidget::eventFilter(watched, event);
}

void
Widget::parseWeatherJsonData(const QByteArray& data) const {
    if (const QJsonDocument json_document = QJsonDocument::fromJson(data);
        !json_document.isNull() && json_document.isObject()) {
        QJsonObject object_root = json_document.object();
        /// 1. 日期
        ui->labelDate->setText(object_root["date"].toString() + " " +
                               object_root["week"].toString());

        /// 2. 城市名
        ui->labelWeatherLocation->setText(object_root["city"].toString());

        /// 3. 当前温度及温度范围
        ui->labelWeatherTemperatureDegree->setText(
                object_root["tem"].toString() + " ℃");
        ui->labelWeatherTemperatureRange->setText(
                object_root["tem2"].toString() + " ~ " +
                object_root["tem1"].toString() + " ℃");

        /// 4. 天气状况
        ui->labelWeatherContent->setText(object_root["wea"].toString());
        ui->labelMainWeatherIcon->setPixmap(
                _weather_icon_map[object_root["wea"].toString()]);

        /// 5. 感冒指数
        ui->labelColdIndex->setText(object_root["air_tips"].toString());

        /// 6. 风向及风力等级
        ui->labelCenterWindDirectionContent->setText(
                object_root["win"].toString());
        ui->labelCenterWindDirectionLevel->setText(
                object_root["win_speed"].toString());

        /// 7. PM2.5 等级
        ui->labelCenterPm2p5Level->setText(object_root["air_pm25"].toString());

        /// 8. 湿度
        ui->labelCenterHumidityLevel->setText(
                object_root["humidity"].toString());

        /// 9. 空气质量
        ui->labelCenterAirQualityLevel->setText(
                object_root["air_level"].toString());
    }
}
void
Widget::parseDailyWeatherJsonData(const QByteArray& data) {
    if (const QJsonDocument json_document = QJsonDocument::fromJson(data);
        !json_document.isNull() && json_document.isObject()) {
        QJsonObject json_root = json_document.object();
        _days[1]._city = json_root["city"].toString();
        _days[1]._pm2p5 = json_root["aqi"].toObject()["pm25"].toString();
        if (json_root.contains("data") && json_root["data"].isArray()) {
            const auto weather_array = json_root["data"].toArray();
            for (int i = 0; i < weather_array.size(); ++i) {
                QJsonObject weather = weather_array[i].toObject();
                _days[i]._date = weather["date"].toString();
                _days[i]._week = weather["week"].toString();
                _days[i]._temperature = weather["tem"].toString();
                _days[i]._temperature_min = weather["tem2"].toString();
                _days[i]._temperature_max = weather["tem1"].toString();
                _days[i]._weather_type = weather["wea"].toString();
                _days[i]._tip = weather["air_tips"].toString();
                _days[i]._wind_direction =
                        weather["win"].toArray()[0].toString();
                _days[i]._wind_direction_level =
                        weather["win_speed"].toString();
                _days[i]._humidity = weather["humidity"].toString();
                _days[i]._air_quality = weather["air_level"].toString();
            }
        }
    }
    updateUI();
}
void
Widget::initWeatherIconMap() {
    _weather_icon_map.insert("上弦月", ":/weather/上弦月.svg");
    _weather_icon_map.insert("下弦月", ":/weather/下弦月.svg");
    _weather_icon_map.insert("中雨", ":/weather/中雨.svg");
    _weather_icon_map.insert("中雪", ":/weather/中雪.svg");
    _weather_icon_map.insert("多云", ":/weather/多云.svg");
    _weather_icon_map.insert("多云转晴", ":/weather/多云转晴天.svg");
    _weather_icon_map.insert("大雨", ":/weather/大雨.svg");
    _weather_icon_map.insert("大雨转晴", ":/weather/大雨转晴.svg");
    _weather_icon_map.insert("大雪", ":/weather/大雪.svg");
    _weather_icon_map.insert("小雨", ":/weather/小雨.svg");
    _weather_icon_map.insert("小雪", ":/weather/小雪.svg");
    _weather_icon_map.insert("少云", ":/weather/少云.svg");
    _weather_icon_map.insert("张弦月", ":/weather/张弦月.svg");
    _weather_icon_map.insert("扬沙", ":/weather/扬沙.svg");
    _weather_icon_map.insert("新月", ":/weather/新月.svg");
    _weather_icon_map.insert("晚多云", ":/weather/晚多云.svg");
    _weather_icon_map.insert("晚晴天", ":/weather/晚晴天.svg");
    _weather_icon_map.insert("大暴雨", ":/weather/暴雨.svg");
    _weather_icon_map.insert("暴雪", ":/weather/暴雪.svg");
    _weather_icon_map.insert("残月", ":/weather/残月.svg");
    _weather_icon_map.insert("晴", ":/weather/晴天.svg");
    _weather_icon_map.insert("满月", ":/weather/满月.svg");
    _weather_icon_map.insert("特大阵雨", ":/weather/特大阵雨.svg");
    _weather_icon_map.insert("蛾眉月", ":/weather/蛾眉月.svg");
    _weather_icon_map.insert("闪电", ":/weather/闪电.svg");
    _weather_icon_map.insert("阴", ":/weather/阴天.svg");
    _weather_icon_map.insert("小雨转阴", ":/weather/阴天.svg");
    _weather_icon_map.insert("阵雨", ":/weather/阵雨.svg");
    _weather_icon_map.insert("阵雨转晴", ":/weather/阵雨转晴.svg");
    _weather_icon_map.insert("雨夹雪", ":/weather/雨夹雪.svg");
    _weather_icon_map.insert("强雷雨", ":/weather/雷阵雨.svg");
    _weather_icon_map.insert("雷雨", ":/weather/雷阵雨.svg");
    _weather_icon_map.insert("雾", ":/weather/雾.svg");
    _weather_icon_map.insert("霾", ":/weather/雾霾.svg");
    _weather_icon_map.insert("小雨转多云", ":/weather/小雨转多云.svg");
    _weather_icon_map.insert("阴转多云", ":/weather/阴转多云.svg");
}
void
Widget::updateUI() {
    /// 1. 日期
    ui->labelDate->setText(_days[1]._date + " " + _days[1]._week);

    /// 2. 城市名
    ui->labelWeatherLocation->setText(_days[1]._city);

    /// 3. 当前温度及温度范围
    ui->labelWeatherTemperatureDegree->setText(_days[1]._temperature + " ℃");
    ui->labelWeatherTemperatureRange->setText(_days[1]._temperature_min +
                                              " ~ " +
                                              _days[1]._temperature_max + " ℃");

    /// 4. 天气状况
    ui->labelWeatherContent->setText(_days[1]._weather_type);
    ui->labelMainWeatherIcon->setPixmap(
            _weather_icon_map[_days[1]._weather_type]);

    /// 5. 感冒指数
    ui->labelColdIndex->setText(_days[1]._tip);

    /// 6. 风向及风力等级
    ui->labelCenterWindDirectionContent->setText(_days[1]._wind_direction);
    ui->labelCenterWindDirectionLevel->setText(_days[1]._wind_direction_level);

    /// 7. PM2.5 等级
    ui->labelCenterPm2p5Level->setText(_days[1]._pm2p5);

    /// 8. 湿度
    ui->labelCenterHumidityLevel->setText(_days[1]._humidity);

    /// 9. 空气质量
    ui->labelCenterAirQualityLevel->setText(_days[1]._air_quality);
    for (int i = 0; i < 6; ++i) {
        QStringList day_list = _days[i]._date.split("-");
        _unit_date_list[i]->setText(day_list.at(1) + "-" + day_list.at(2));
        _unit_week_list[i]->setText(_days[i]._week);
        /// 缩放图片大小和label大小匹配
        QPixmap pixmap = _weather_icon_map[_days[i]._weather_type];
        pixmap = pixmap.scaled(_unit_weather_icon_list[i]->size(),
                               Qt::KeepAspectRatio, Qt::SmoothTransformation);
        _unit_weather_icon_list[i]->setPixmap(pixmap);
        _unit_weather_content_list[i]->setText(_days[i]._weather_type);
        const QString air_quality = _days[i]._air_quality;
        _unit_air_quality_list[i]->setText(air_quality);
        if (air_quality == "优") {
            _unit_air_quality_list[i]->setStyleSheet(
                    "background-color: rgb(150,213,32);border-radius: "
                    "4px;");
        }
        if (air_quality == "良") {
            _unit_air_quality_list[i]->setStyleSheet(
                    "background-color: rgb(208,107,39);border-radius: "
                    "4px;");
        }
        if (air_quality == "轻度") {
            _unit_air_quality_list[i]->setStyleSheet(
                    "background-color: rgb(255,199,199);border-radius: "
                    "4px;");
        }
        if (air_quality == "中度") {
            _unit_air_quality_list[i]->setStyleSheet(
                    "background-color: rgb(255,17,17);border-radius: 4px;");
        }
        if (air_quality == "重度") {
            _unit_air_quality_list[i]->setStyleSheet(
                    "background-color: rgb(153,0,0);border-radius: 4px;");
        }
        _unit_wind_direction_list[i]->setText(_days[i]._wind_direction);
        _unit_wind_level_list[i]->setText(_days[i]._wind_direction_level);
    }
    _unit_week_list[0]->setText("昨天");
    _unit_week_list[1]->setText("今天");
    _unit_week_list[2]->setText("明天");
    /// 绘图
    ui->widgetBottomTempCurveMax->installEventFilter(this);
    ui->widgetBottomTempCurveMin->installEventFilter(this);
    update();
}
void
Widget::updateLabel() {
    _unit_week_list << ui->labelUnitDay0 << ui->labelUnitDay1
                    << ui->labelUnitDay2 << ui->labelUnitDay3
                    << ui->labelUnitDay4 << ui->labelUnitDay5;

    _unit_date_list << ui->labelUnitDate0 << ui->labelUnitDate1
                    << ui->labelUnitDate2 << ui->labelUnitDate3
                    << ui->labelUnitDate4 << ui->labelUnitDate5;
    _unit_weather_icon_list
            << ui->labelUnitWeatherIcon0 << ui->labelUnitWeatherIcon1
            << ui->labelUnitWeatherIcon2 << ui->labelUnitWeatherIcon3
            << ui->labelUnitWeatherIcon4 << ui->labelUnitWeatherIcon5;
    _unit_weather_content_list
            << ui->labelUnitWeatherContent0 << ui->labelUnitWeatherContent1
            << ui->labelUnitWeatherContent2 << ui->labelUnitWeatherContent3
            << ui->labelUnitWeatherContent4 << ui->labelUnitWeatherContent4;
    _unit_air_quality_list << ui->labelUnitAirQuality0
                           << ui->labelUnitAirQuality1
                           << ui->labelUnitAirQuality2
                           << ui->labelUnitAirQuality3
                           << ui->labelUnitAirQuality4
                           << ui->labelUnitAirQuality5;
    _unit_wind_direction_list << ui->labelUnitWindDirectionContent0
                              << ui->labelUnitWindDirectionContent1
                              << ui->labelUnitWindDirectionContent2
                              << ui->labelUnitWindDirectionContent3
                              << ui->labelUnitWindDirectionContent4
                              << ui->labelUnitWindDirectionContent5;
    _unit_wind_level_list << ui->labelUnitWindDirectionLevel0
                          << ui->labelUnitWindDirectionLevel1
                          << ui->labelUnitWindDirectionLevel2
                          << ui->labelUnitWindDirectionLevel3
                          << ui->labelUnitWindDirectionLevel4
                          << ui->labelUnitWindDirectionLevel5;
}
void
Widget::drawTempCurveMax() {
    QPainter painter(ui->widgetBottomTempCurveMax);
    painter.setBrush(Qt::yellow);
    painter.setPen(Qt::yellow);
    painter.setRenderHint(QPainter::Antialiasing, true);

    int average{ 0 };
    int sum{ 0 };
    int offset{ 0 };
    const int middle = ui->widgetBottomTempCurveMax->height() / 2;
    for (int i = 0; i < 6; ++i) {
        sum += _days[i]._temperature_max.toInt();
    }
    average = sum / 6;

    QPoint temp_points[6];

    /// 1. 绘制点
    for (int i = 0; i < 6; ++i) {
        temp_points[i].setX(_unit_air_quality_list[i]->x() +
                            _unit_air_quality_list[i]->width() / 2);
        offset = (_days[i]._temperature_max.toInt() - average) * 2;
        temp_points[i].setY(middle - offset);
        painter.drawEllipse(QPoint(temp_points[i]), 2, 2);

        /// 2. 绘制温度
        painter.drawText(temp_points[i].x() - 10, temp_points->y() - 10,
                         _days[i]._temperature_max + " °");
    }
    /// 3. 绘制线
    for (int i = 0; i < 5; ++i) {
        painter.drawLine(temp_points[i], temp_points[i + 1]);
    }
}
void
Widget::drawTempCurveMin() {
    QPainter painter(ui->widgetBottomTempCurveMin);
    painter.setBrush(Qt::yellow);
    painter.setPen(QColor(70, 192, 203));
    painter.setRenderHint(QPainter::Antialiasing, true);

    int average{ 0 };
    int sum{ 0 };
    int offset{ 0 };
    const int middle = ui->widgetBottomTempCurveMin->height() / 2;
    for (int i = 0; i < 6; ++i) {
        sum += _days[i]._temperature_min.toInt();
    }
    average = sum / 6;

    QPoint temp_points[6];

    /// 1. 绘制点
    for (int i = 0; i < 6; ++i) {
        temp_points[i].setX(_unit_air_quality_list[i]->x() +
                            _unit_air_quality_list[i]->width() / 2);
        offset = (_days[i]._temperature_min.toInt() - average) * 2;
        temp_points[i].setY(middle - offset);
        painter.drawEllipse(QPoint(temp_points[i]), 2, 2);

        /// 2. 绘制温度
        painter.drawText(temp_points[i].x() - 10, temp_points->y() - 10,
                         _days[i]._temperature_min + " °");
    }
    /// 3. 绘制线
    for (int i = 0; i < 5; ++i) {
        painter.drawLine(temp_points[i], temp_points[i + 1]);
    }
}

void
Widget::on_lineEditSearchContent_returnPressed() {
    on_pushButtonSearch_clicked();
}
