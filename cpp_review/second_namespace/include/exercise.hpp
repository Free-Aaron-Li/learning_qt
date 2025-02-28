//  Copyright (c) 2025. aaron.
//
//  This program is under the GPL-3.0 license.
//  if you have not received it or the program has several bugs, please let me know:
//  <communicate_aaron@outlook.com>.

//
// Created by aaron on 25-2-27.
//

#ifndef EXERCISE_HPP
#define EXERCISE_HPP

#include <iostream>
#include <string>

/**
 * @brief 1. 加减乘除运算
 */
void calculator();

/**
 * @brief 2. 银行案例：初识权限
 * @details 银行账户是一个模板，是一个类，由存款人信息和额度，而具体的存款人视为对象，
 * 一个对象不能私自修改账户额度，需要通过一个操作流程，比如去ATM或柜台进行操作才能修改账户额度。
 * 所以，存款人信息和额度设计成私有权限，通过公有操作流程（公有函数）操作私有变量。
 * 基于这个场景，实现细节。
 */
class BankAccount {
    /// 存款人信息
    /// 默认：私有
    std::string _name;
    std::string _address;
    int _age{ 0 };
    double _balance{ 0 };

    /// 公有函数
public:
    /// 注册账户
    void registerMessage(const std::string &name, const std::string &address, const int &age, const double &balance);
    /// 取款
    void withdraw(const double &amount);
    /// 存款
    void deposit(const double &amount);
    /// 查询余额
    ///
    /// [[nodiscard]] 属性的作用是对函数的返回值进行约束，强制调用者必须显式处理返回值，否则编译器会发出警告。
    /// [[nodiscard]] 标记的返回值不可被忽略。如果调用 getBalance()
    /// 后未使用返回值（例如未赋值给变量、未参与计算或未转换为 void），编译器会生成警告。
    [[nodiscard]] double getBalance() const { return _balance; }
    /// 打印账户信息
    /// 该函数为常量成员函数，其核心作用是限制函数对对象状态的修改权限
    void printMessage() const;
};

class Person {
public:
    std::string _name;
    int _age;
    bool operator==(const Person &person_temp) const;
};

class Point {
public:
    int _x;
    int _y;
    /// const 表明该重载函数不会修改调用它的 Point 对象。
    /// 它只是读取对象的 x 和 y 成员，并返回一个新的 Point 对象。
    /// 确保某些函数不会意外改变对象的状态，也同时使得这个函数可以在常量对象上被调用。
    Point operator+(const Point &point_temp) const;
};

class Car {
public:
    std::pmr::string _brand;
    int _year{ 0 };
    Car() { std::cout << "构造函数被调用" << std::endl; }
    Car(const std::string &brand, const int &year) : _brand(brand), _year(year) {
        std::cout << "带参数的构造函数被调用" << std::endl;
        std::cout << this << std::endl; /// 打印 this 指针的地址
    }

    void display() const { std::cout << "品牌：" << _brand << ", 年份：" << _year << std::endl; }

    Car &setYear(const int &year) {
        this->_year = year;
        return *this; /// 返回调用对象的指针
    }
};
#endif // EXERCISE_HPP
