//  Copyright (c) 2025. aaron.
//
//  This program is under the GPL-3.0 license.
//  if you have not received it or the program has several bugs, please let me know:
//  <communicate_aaron@outlook.com>.
#include "../include/exercise.hpp"

int add(const int a, const int b) { return a + b; }
int sub(const int a, const int b) { return a - b; }
int mul(const int a, const int b) { return a * b; }
double divi(const int a, const int b) {
    if (b == 0) {
        std::cerr << "除数不能为0" << std::endl;
        return -1;
    }
    return a / b;
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
                std::cout << add(a, b) << std::endl;
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
