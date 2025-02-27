# 一、C++ 基础

```table-of-contents
title: 
style: nestedList # TOC style (nestedList|nestedOrderedList|inlineFirstLevel)
minLevel: 0 # Include headings from the specified level
maxLevel: 0 # Include headings up to the specified level
includeLinks: true # Make headings clickable
hideWhenEmpty: false # Hide TOC if no headings are found
debugInConsole: false # Print debug info in Obsidian console
```
## 1.1 Hello World

```c++
#include <iostream>
int main() {
	std::cout << "Hello World!" << std::endl;
}
```

> **C 和 C++ 的区别**
> 
> 1. 兼容性：C++ 在很大程度上是与 C 兼容的，意味着很多 C 程序都可以在 C++ 编译器中编译并运行。
> 2. 面向对象编程（OOP）：C++ 运行使用类和对象，而 C 是过程性语言，支持并不好。
> 3. 模板：允许程序员编写与数据类型无关的代码功能，C 没有该功能。
> 4. 标准库：C++ 有一个更丰富的标准库（STL），对数据结构和算法提供广泛的支持。C 标准库相对较小。
> 5. 类型检查：C++有着更严格的检查。
> 6. 异常处理：C++支持异常处理，C 则没有。
> 7. 命名空间：C++ 支持命名空间，有助于防止名称冲突。
## 1.2 命名空间
### 1.2.1 命名空间作用

 通过命名空间帮助解决名称冲突，特别是在开发大型项目或库时，能够清晰项目结构。

1. 使用类似 `std::` 前缀方式表示右值属于哪个命名空间。
2. 使用 `using namespace std` ，允许不显式指定属于 `std` 命名空间中所有元素。
### 1.2.2 自定义命名空间

参考项目：[cpp_review/second_namespace](../cpp_review/second_namespace)

```c++
/*
 * cir.hpp
 */
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

/*
 * main.cpp
 */
#include "cir.hpp"  
  
using namespace std; /// 将标准库（std）中的所有名称引入当前作用域  
  
int main() {  
    constexpr double my_radius = 5.0;  
    cout << "Hello World!" << endl;  
    printf("my_radius = %f, area = %f, circumference = %f\n", my_radius, cir::get_cir_circumference(my_radius),  
           cir::get_cir_area(my_radius)); /// 包含头文件cir.hpp中的命名空间cir  
    return 0;  
}
```
## 1.3 输入输出

C++ 中的输入和输出主要通过 STL 中的输入输出流实现（如：iostream）。

**标准输出流（cout）**
- 通过操作符 `<<` （插入操作符）向 `cout` 发送数据。
```c++
std::cout << "Hello World!" << std::endl; /// 使用标准库cout输出
```

**标准输出流（cin）**
- 使用操作符 `>>` （提取操作符）从 `cin` 提取数据。
```c++
std::cin >> input_value;
std::cout << input_value << std::endl;
```

**标准错误流（cerr）**
- 输出错误信息，与 `cout` 相比其不会缓存，直接输出信息。

**标准日志流（clog）**
- 类似于 `cout` ，通常用于记录错误和日志信息。

```c++
std::cerr << "error" << std::endl;  
std::clog << "Logging: user entered a number." << std::endl;
```
## 1.4  基本变量类型

在 C++ 中， `<climits>` 标准头文件提供了关于整型限制的信息，这个头文件中定义了各种整型数据类型的属性，如最大值、最小值等，使用这些信息可以帮助了解在特定编译器和平台上各种数据类型的大小和范围。
## 1.5 流程控制

```c++
for (constexpr wchar_t wideArray[] = {L'你', L'好', L'世', L'界'}; const wchar_t index: wideArray) {  
    std::wcout << index; /// 输出有问题，无法输出中文  
}
```

**for-each 语句**

```c++
/// 常规
std::string str = "Hello";
for (char c : str) {
	std::cout << c << " ";
}

/// 特殊化 for
/// !!! C++ >= 20 才支持
for (constexpr int numbers[] = {1,2,3,4,5}; const int& index: numbers) {
     std::cout << index << " ";
 }
```


**跳转语句**
- break 语句：跳出最近的循环。
- continue 语句：跳过当前迭代，开始下一次迭代。
- goto 语句：直接跳转到程序中的另一个点，==不推荐使用==（可能使得代码难以维护）。
## 1.6 函数

```c++
返回类型 函数名(参数类别) {
	/// 函数体
	/// 返回语句（如有返回值）
}
```
### 1.6.1 内联函数

C++ 中一种特殊函数，其定义直接在每个调用点展开，编译器会尝试将函数调用替换为函数本身的代码，减少函数调用的开销。

**特点**
1. **减少函数调用开销**：通常用于优化小型的，频繁调用的函数，以此避免函数调用点常规开销（如参数传递、栈操作等）。
2. **编译器决策**：即使函数被声明为内联，编译器也可决定不进行内联，特别是对于复杂或递归函数。
3. **适用于小型函数**：通常只有简单的、执行时间短的函数适合做内联。
4. **定义在每个使用点**：内联函数的定义必须对每个使用它的文件都可见，意味着通常将内联函数定义在头文件。

```c++
inline int add(int x, int y) {
	return x + y;
}
```

==内联函数是一种用于优化程序性能的工具，但需要合理使用，以确保代码的可维护性和性能的平衡==。
## 1.7 Lambda 表达式

C++ 11 引入的一种**匿名函数**方式。

```c++
[capture clause](parameters) -> return_type {
	/// 函数体
	/// 可以使用捕获列表中的变量
	return expression; /// 可选返回语句
}
```

示例：

```c++
/// Lambda 表达式  
/// 加法
auto add = [](const int a, const int b) { return a + b; };  
std::cout << add(1, 2) << std::endl;  

/// 1. 指定捕获
/// 求圆面积（捕获操作），值传递方式
constexpr double my_radius = 5.0;
auto cir_area = [my_radius]() -> double { 
	return cir::get_cir_area(my_radius); /// 注意捕获参数仅读
};  
std::cout << cir_area() << std::endl;

/// 2. 所有捕获
auto add2 = [=]() -> int { return a + b + my_radius; }; /// 捕获列表为 “=” 表示全部捕获
std::cout << add2() << endl;

/// 3. 引用捕获
auto add3 = [&]() -> int { 
    a = 13;
    return a;
};
std::cout << add3() << endl;
```

==回调函数==：

```c++
bool compare(const int a, const int b) { return a > b; }  
  
/// 回调函数  
int getMax(const int a, const int b, bool (*pcompare)(int a, int b)) {  
    if (pcompare(a, b)) {  
        return a;  
    }  
    return b;  
}  
  
int main() {  
    constexpr int a = 10;  
    constexpr int b = 20;  
    cout << getMax(a, b, compare) << endl;
	/// Lambda 改变
	const int max = getMax(a, b, [](const int a, const int b) -> bool { return a > b; });
    std::cout << max << std::endl;

}
```

|    **特性**    |            **Lambda 函数**            |            **内联函数**             |
| :----------: | :---------------------------------: | :-----------------------------: |
|   ​**定义**​   |       一种匿名函数，通常用于定义在需要它们的地方。        |    一种常规函数，通过 `inline` 关键字定义。    |
|   ​**用途**​   |        提供一种快捷方式来定义临时的、小型的函数。        |       用于优化小型函数，减少函数调用的开销。       |
|   ​**语法**​   | 使用 `[capture](params){body}` 的形式定义。 | 使用常规函数定义语法，但在前面加上 `inline` 关键字。 |
|  ​**生命周期**​  |            在定义它们的作用域内有效。            |          在整个程序执行期间有效。           |
| ​**捕获外部变量**​ |       可以捕获外部作用域中的变量（按值或按引用）。        |      不能直接捕获外部变量，只能通过参数传递。       |
|  ​**调用方式**​  |            作为函数对象，可直接调用。            |           像普通函数一样调用。            |
|   ​**优化**​   |      可以被编译器自动内联化，但这取决于编译器优化策略。      |   明确请求编译器尝试内联，但实际内联化也取决于编译器。    |
|  ​**可见性**​   |         通常只在定义它们的局部作用域内可见。          |        可以在定义它的任何作用域内可见。         |
|  ​**使用场景**​  |      适合一次性使用的场景（如回调、在算法中使用等）。       |          适合频繁调用的小型函数。           |
> Lambda 函数的核心优势在于它们的匿名性和对外部变量的捕获能力，而内联函数则主要关注于提高小型函数的性能。

## 1.8 数组

- 数组的大小必须在编译期已知，且不能更改。
- 数组越界是常见错误，可能会导致未定义行为。
- 对于更复杂的用例，需要使用到其他容器处理。

