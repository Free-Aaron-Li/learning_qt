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
void BankAccount::registerMessage(const std::string &name, const std::string &address, const int &age,
                                  const double &balance) {
    this->_name = name;
    this->_address = address;
    this->_age = age;
    this->_balance = balance;
}
void BankAccount::withdraw(const double &amount) {
    if (amount > _balance) {
        throw std::invalid_argument("取款金额大于余额！");
    }
    if (amount <= 0) {
        throw std::invalid_argument("取款金额必须为正数!");
    }
    _balance -= amount;
}
void BankAccount::deposit(const double &amount) {
    if (amount <= 0) {
        throw std::invalid_argument("存款金额必须为正数!");
    }
    _balance += amount;
}
void BankAccount::printMessage() const {
    std::cout << "姓名：" << _name << "，地址：" << _address << "，年龄：" << _age << "，余额：" << _balance
              << std::endl;
}
bool Person::operator==(const Person &person_temp) const {
    return this->_age == person_temp._age && this->_name == person_temp._name;
}
Point Point::operator+(const Point &point_temp) const {
    Point point_temp_new{};
    point_temp_new._x = this->_x + point_temp._x;
    point_temp_new._y = this->_y + point_temp._y;
    return point_temp_new;
}
int MyClass::_static_member = 0;
void MyClass::printInfo() const { std::cout << "数据：" << _datas << std::endl; }
void Vehicle::run() const { std::cout << "车跑起来了" << std::endl; }
void Vehicle::stop() const { std::cout << "车停了" << std::endl; }
void RemoteControl::openUtils() { std::cout << "打开遥控器" << std::endl; }
TVRemoteControl::~TVRemoteControl() { std::cout << "关闭电视📺" << std::endl; }
void TVRemoteControl::openUtils() { std::cout << "打开电视📺" << std::endl; }
StereoRemoteControl::~StereoRemoteControl() { std::cout << "关闭音响📢" << std::endl; }
void StereoRemoteControl::openUtils() { std::cout << "打开音响📢" << std::endl; }
LightRemoteControl::~LightRemoteControl() { std::cout << "关闭灯💡" << std::endl; }
void LightRemoteControl::openUtils() { std::cout << "打开灯💡" << std::endl; }
