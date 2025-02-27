//  Copyright (c) 2025. aaron.
//
//  This program is under the GPL-3.0 license.
//  if you have not received it or the program has several bugs, please let me know:
//  <communicate_aaron@outlook.com>.

#include <climits>
#include <cstdio>
#include <iostream>

#include "../include/cir.hpp"
#include "../include/exercise.hpp"

using namespace std; /// 将标准库（std）中的所有名称引入当前作用域

bool compare(const int a, const int b) { return a > b; }

/// 回调函数
int getMax(const int a, const int b, bool (*pcompare)(int a, int b)) {
    if (pcompare(a, b)) {
        return a;
    }
    return b;
}

int main() {
    constexpr double my_radius = 5.0;
    int input_value = 0;
    std::cout << "Hello World!" << std::endl; /// 使用标准库cout输出
    std::cin >> input_value;
    std::cout << input_value << std::endl;
    std::cerr << "error" << std::endl;
    std::clog << "Logging: user entered a number." << std::endl;

    /// 设置本地化以支持宽字符
    std::setlocale(LC_ALL, "");
    // 定义一个宽字符数组并初始化
    // 使用 wcout 输出宽字符数组
    for (constexpr wchar_t wideArray[] = { L'你', L'好', L'世', L'界' }; const wchar_t index: wideArray) {
        std::wcout << index; /// 输出有问题，无法输出中文
    }
    std::wcout << std::endl;

    /// Lambda 表达式
    auto add = [](const int a, const int b) { return a + b; };
    std::cout << add(1, 2) << std::endl;
    auto cir_area = [my_radius]() -> double {
        return cir::get_cir_area(my_radius); /// 注意捕获参数仅读
    };
    std::cout << cir_area() << std::endl;
    int a = 10;
    constexpr int b = 20;
    /// 使用回调函数
    const int max = getMax(a, b, [](const int a, const int b) -> bool { return a > b; });
    std::cout << max << std::endl;
    cout << getMax(a, b, compare) << endl;
    auto add2 = [=]() -> int { return a + b + my_radius; };
    std::cout << add2() << endl;

    auto add3 = [&]() -> int { /// 引用捕获
        a = 13;
        return a;
    };
    std::cout << add3() << endl;

    printf("my_radius = %f, area = %f, circumference = %f\n", my_radius, cir::get_cir_circumference(my_radius),
           cir::get_cir_area(my_radius)); /// 包含头文件cir.hpp中的命名空间cir

    /// 练习1：加减乘除
    calculator();

    return 0;
}
