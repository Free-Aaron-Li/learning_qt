//  Copyright (c) 2025. aaron.
//
//  This program is under the GPL-3.0 license.
//  if you have not received it or the program has several bugs, please let me know:
//  <communicate_aaron@outlook.com>.
#include "../include/exercise.hpp"

auto add = [](const int a, const int b) -> int { return a + b; };
auto sub = [](const int a, const int b) -> int { return a - b; };
auto mul = [](const int a, const int b) -> int { return a * b; };
auto divi = [](const int a, const int b) -> int {
    if (b == 0) {
        throw std::runtime_error("除数不能为0");
    }
    return a / b;
};

int computer(const int a, const int b, int (*p)(const int a, const int b)) {
    std::cout << "开始计算" << std::endl;
    return p(a, b);
}

void calculator() {
    int a = 0;
    int b = 0;
    char cal;
    char go_to_continue = 'y';
    std::cout << "加减乘除计算" << std::endl;
    while (go_to_continue == 'y' || go_to_continue == 'Y') {
        std::cout << "请输入两个数：" << std::endl;
        std::cin >> a;
        std::cin >> b;
        std::cout << "请输入运算符（+、-、*、/）：";
        std::cin >> cal;
        switch (cal) {
            case '+':
                /// 回调
                std::cout << computer(a, b, [](const int a, const int b) -> int { return a + b; }) << std::endl;
                break;
            case '-':
                std::cout << sub(a, b) << std::endl;
                break;
            case '*':
                std::cout << mul(a, b) << std::endl;
                break;
            case '/':
                std::cout << divi(a, b) << std::endl;
                break;
            default:
                std::cerr << "输入错误" << std::endl;
                break;
        }
        std::cout << "是否继续（y/n）" << std::endl;
        std::cin >> go_to_continue;
    }
}
