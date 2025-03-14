//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me
//   know: <communicate_aaron@outlook.com>.
//
#include "../include/CityCodeUtils.hpp"


QString
CityCodeUtils::getCityCodeFromName(const QString& name) {
    if (_city_map.isEmpty()) {
        initCityMap();
    }

    /// 1. 先尝试直接匹配全称（如 “北京市”）
    if (const auto it = _city_map.find(name); it != _city_map.end()) {
        return it.value();
    }

    /// 2. 若未找到，尝试去除后缀匹配（如 “北京”）
    for (const auto& suffix: _suffixes) {
        if (name.endsWith(suffix)) {
            auto short_name = name.left(name.length() - suffix.length());
            if (const auto short_it = _city_map.find(short_name);
                short_it != _city_map.end()) {
                return short_it.value();
            }
        }
    }

    /// 3. 未找到
    return {};
}
void
CityCodeUtils::initCityMap() {
    const QString file_name = ":/json/citycode.json";
    QFile file(file_name);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "文件：“" + file_name + "”不存在";
    }
    const auto data = QJsonDocument::fromJson(file.readAll());
    file.close();

    if (!data.isArray()) {
        qDebug() << "错误JSON数据：根节点不存在数组形式！";
        return;
    }


    QString city_name{};
    QString city_code{};

    for (const QJsonValue city: data.array()) {
        if (!city.isObject()) {
            continue;
        }
        city_name = city["city_name"].toString();
        city_code = city["city_code"].toString();

        /// 1. 插入原始名称（如“北京市”）
        _city_map.insert(city_name, city_code);

        /// 2. 自动生成并插入简称（如“北京”）
        for (const auto& suffix: _suffixes) {
            if (city_name.endsWith(suffix)) {
                QString short_name =
                        city_name.left(city_name.length() - suffix.length());
                if (!_city_map.contains(short_name)) { /* 避免覆盖已有数据 */
                    _city_map.insert(short_name, city_code);
                }
                break; /* 处理一个有效后缀即可 */
            }
        }
    }
}
