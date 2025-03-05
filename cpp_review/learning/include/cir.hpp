//  Copyright (c) 2025. aaron.
//
//  This program is under the GPL-3.0 license.
//  if you have not received it or the program has several bugs, please let me know:
//  <communicate_aaron@outlook.com>.

#ifndef CIR_HPP
#define CIR_HPP

namespace cir {
    /// 派值
    constexpr double PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286;

    /// 获取圆形周长函数
    inline double get_cir_circumference(const double radius) {
        return 2 * PI * radius;
    }

    /// 获取圆形面积函数
    inline double get_cir_area(const double radius) {
        return PI * radius * radius;
    }
}
#endif //CIR_HPP
