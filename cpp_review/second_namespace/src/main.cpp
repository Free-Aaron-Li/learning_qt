//  Copyright (c) 2025. aaron.
//
//  This program is under the GPL-3.0 license.
//  if you have not received it or the program has several bugs, please let me know:
//  <communicate_aaron@outlook.com>.

#include <climits>
#include <cstdio>
#include <iostream>

#include "../include/animal.hpp"
#include "../include/cir.hpp"
#include "../include/exercise.hpp"
#include "../include/lion.hpp"

using namespace std; /// 将标准库（std）中的所有名称引入当前作用域

bool compare(const int a, const int b) { return a > b; }

/// 回调函数
int getMax(const int a, const int b, bool (*pcompare)(int a, int b)) {
    if (pcompare(a, b)) {
        return a;
    }
    return b;
}

/// 测试函数
void test() {
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
}

/// 引用
double values[] = { 1, 2, 3, 4, 5 };
double &setValue(const int &i) {
    double &ref = values[i];
    return ref;
}

int main() {
    // test();
    /// 练习1：加减乘除
    // calculator();

    /// 练习2：银行
    // BankAccount user1;
    // user1.registerMessage("Aaron", "China", 18, 20000);
    // user1.printMessage();
    // user1.deposit(10000);
    // user1.withdraw(5000);
    // user1.printMessage();
    // user1.withdraw(120000);

    /// 练习3：引用
    // setValue(3) = 120.1; /// 函数被当作左值
    // cout << values[3] << endl;

    /// 练习4：重载
    /// 4.1 Person
    // Person p1;
    // p1._name = "张三";
    // p1._age = 18;
    //
    // Person p2;
    // p2._name = "李四";
    // p2._age = 20;
    //
    /// 需要实现等号运算符重载
    // const bool result = p1 == p2;
    // std::cout << result << std::endl;

    /// 4.2 Point
    // Point p1{};
    // p1._x = 1;
    // p1._y = 2;
    //
    // Point p2{};
    // p2._x = 3;
    // p2._y = 4;
    //
    // Point p3 = p1 + p2;
    // std::cout << "p3 x is: " << p3._x << ", p3 y is: " << p3._y << std::endl;

    /// 练习5：构造函数
    // Car car1;
    // car1.display();
    // Car *p_car1 = new Car;
    // Car *p_car2 = new Car(); /// 都会调用构造函数
    // Car *p_car3 = new Car("BMW", 2020);
    // // p_car3->display();
    //
    // std::cout << "\nthis 指针特点：" << std::endl;
    // Car car2("奔驰", 2020);
    // std::cout << &car2 << std::endl; /// this 指向当前对象
    // Car car3("宝马", 2020);
    // std::cout << &car3 << std::endl;
    //
    // /// 链式调用
    // car3.setYear(2024).display();
    // delete p_car1;
    // delete p_car2;
    // delete p_car3;
    // delete &car1;
    // delete &car2;
    // delete &car3;

    /// 练习6：静态成员变量
    // 通过类名调用
    // std::cout << MyClass::_static_member << std::endl;
    // // 通过静态函数调用
    // std::cout << MyClass::getStaticMember() << std::endl;
    //
    // // 查看创建的对象数目
    // const MyClass my_class1;
    // const MyClass my_class2;
    // std::cout << MyClass::_static_member << std::endl; /* 2 */
    // {
    //     const MyClass my_class3;
    //     std::cout << MyClass::_static_member << std::endl; /* 3 */
    // }
    // const MyClass *my_class4 = new MyClass;
    // std::cout << MyClass::_static_member << std::endl; /* 3 */
    // delete my_class4;
    // std::cout << MyClass::_static_member << std::endl; /* 2 */

    /// 练习7：继承
    // const ANIMAL animal1;
    // animal1.eat();
    // animal1.sound();
    //
    // Lion lion1;
    // lion1.sound();
    // lion1.hunting();

    /// 练习8：多态
    RemoteControl *p_remote_control1 = new TVRemoteControl;
    RemoteControl *p_remote_control1_1 = new LightRemoteControl;
    p_remote_control1->openUtils();

    auto *p_remote_control2 = new LightRemoteControl;
    p_remote_control2->openUtils();

    auto *p_remote_control3 = new StereoRemoteControl;
    p_remote_control3->openUtils();

    /// 由于基类析构函数是 protected，实际上无法通过基类指针销毁。
    /// delete p_remote_control1;
    /// 解决方法1：采用派生类指针显式删除 \n
    /// 使用 dynamic_cast 而非 static_cast 的原因在于类型安全性和运行时检查。\n
    /// 1. static_cast 在编译期间完成类型转换，<b>不会检查对象的实际类型</b>。\n
    /// 2. dynamic_cast 在运行时完成类型转换，<b>会检查对象的实际类型</b>，确保转换合法。\n
    /// a. 若类型不匹配，返回 nullptr（对指针类型）或抛出异常（对引用类型）。\n
    delete dynamic_cast<TVRemoteControl *>(p_remote_control1);
    /// 解决方法2：在基类中提供公共销毁接口
    p_remote_control1_1->destroy();
    delete p_remote_control2;
    delete p_remote_control3;

    return 0;
}
