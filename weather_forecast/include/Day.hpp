
//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me
//   know: <communicate_aaron@outlook.com>.
//

#ifndef DAY_H
#define DAY_H
#include <QString>

class Day {
public:
    Day() = default;
    QString _date;
    QString _week;
    QString _city;
    QString _temperature;
    QString _temperature_min;
    QString _temperature_max;
    QString _weather_type;
    QString _tip;
    QString _wind_direction;
    QString _wind_direction_level;
    QString _pm2p5;
    QString _humidity;
    QString _air_quality;
};
#endif  // DAY_H
