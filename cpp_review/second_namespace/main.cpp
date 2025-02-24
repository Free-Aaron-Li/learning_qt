//  Copyright (c) 2024. aaron.
//
//  This program is under the GPL-3.0 license.
//  if you have not received it or the program has several bugs, please let me know:
//  <communicate_aaron@outlook.com>.

#include <iostream>
#include <cstdio>
#include "cir.hpp"

using namespace std; /// 将标准库（std）中的所有名称引入当前作用域

int main() {
    constexpr double my_radius = 5.0;
    cout << "Hello World!" << endl;
    printf("my_radius = %f, area = %f, circumference = %f\n", my_radius, cir::get_cir_circumference(my_radius),
           cir::get_cir_area(my_radius)); /// 包含头文件cir.hpp中的命名空间cir
    return 0;
}
