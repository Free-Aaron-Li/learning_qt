
//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me
//   know: <communicate_aaron@outlook.com>.
//

#ifndef CITYCODEUTILS_H
#define CITYCODEUTILS_H
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMap>
#include <QString>

class CityCodeUtils {
public:
    CityCodeUtils() = default;
    /**
     * @brief 城市名称、代码存储图
     */
    QMap<QString, QString> _city_map = {};
    /**
     * @brief 检索城市代码
     *
     * @param name 输入名称
     * @return 城市代码
     */
    QString
    getCityCodeFromName(const QString& name);

private:
    /**
     * @brief 初始化图
     */
    void
    initCityMap();

    /**
     * @brief 城市后缀名
     */
    const QStringList _suffixes = { "市",     "区",     "县", "自治州",
                                    "自治县", "自治旗", "盟", "旗" };
};
#endif  // CITYCODEUTILS_H
