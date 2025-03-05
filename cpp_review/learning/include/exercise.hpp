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
#include <utility>

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

class MyClass {
public:
    /// 对象数量
    static int _static_member;
    int _datas{ 0 };
    MyClass() { _static_member++; }
    ~MyClass() { _static_member--; }
    void printInfo() const;
    static int getStaticMember() { return _static_member; }
};

class Vehicle { /* 交通工具：车，抽象的概念 */
public:
    std::string _type;
    std::string _country;
    std::string _color;
    double _price{ 0 };
    int _num_of_wheel{ 4 };
    Vehicle() = default;
    Vehicle(std::string type, std::string country, std::string color, const double &price, const int num_of_wheel) :
        _type(std::move(type)), _country(std::move(country)), _color(std::move(color)), _price(price),
        _num_of_wheel(num_of_wheel) {}

    void run() const;
    void stop() const;
};

/// 派生类，子类
class Roadster : public Vehicle { /* 跑车，但比父类感觉上范围缩小了 */
public:
    Roadster();
    /// 派生类初始化基类
    Roadster(std::string type, std::string country, std::string color, const double &price, const int num_of_wheel) :
        Vehicle(std::move(type), std::move(country), std::move(color), price, num_of_wheel) {}
    void openCarDoors();
};

/// 基类：遥控器
class RemoteControl {
    /// 基类析构函数为 protected 的原因有：\n
    /// 1. 被声明为 protected，意味着无法通过基类指针直接删除对象。\n
    /// a. 这种设计强制用户只能通过派生类指针操作对象，从而绕过多态删除可能导致的资源泄漏问题。
    /// 2. 避免虚函数表开销。\n
    /// a.
    /// 若基类析构函数非虚，则基类不会生产虚函数表（vtable），从而减少内存占用和运行开销，这在基类无需多态行为时是合理的。
protected:
    ~RemoteControl() = default;

public:
    /// 公共销毁接口
    virtual void destroy() { delete this; }
    virtual void openUtils();
};

/// 派生类：电视遥控器
class TVRemoteControl final : public RemoteControl {
public:
    /// 1. 派生类被标记为 final，表示其不能进一步继承。此时派生类的虚析构函数实际上无多态必要性。但是出于以下考虑：\n
    /// a. <b>代码规范</b>：遵循“析构函数应为虚函数”的通用建议。\n
    /// b. <b>防御性编程</b>：防止未来移除 final 限定符后可能引发的资源泄漏风险。\n
    /// 2. 虚析构的自动传递性 \n
    /// a. 如果基类析构函数为虚函数，则派生类的析构函数也会自动继承该虚析构函数。\n
    /// b. 此例中，基类析构非虚，因此派生类必须显式声明为虚析构函数，此为宂于操作。\n
    virtual ~TVRemoteControl();
    void openUtils() override;
};

/// 派生类：音响遥控器
class StereoRemoteControl final : public RemoteControl {
public:
    virtual ~StereoRemoteControl();
    void openUtils() override;
};

/// 派生类：灯光遥控器
class LightRemoteControl final : public RemoteControl {
public:
    virtual ~LightRemoteControl();
    void openUtils() override;
};

/// 打印模板类
template<typename T>
class PrintEverything {
private:
    T _data;

public:
    void print() const { std::cout << _data << std::endl; }
    void setData(const T &data) { _data = data; }
};

#endif // EXERCISE_HPP
