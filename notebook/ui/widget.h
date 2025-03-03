//  Copyright (c) 2025. aaron.
//
//  This program is under the GPL-3.0 license.
//  if you have not received it or the program has several bugs, please let me know:
//  <communicate_aaron@outlook.com>.

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

/// QT_BEGIN_NAMESPACE 是 Qt 框架中用于支持命名空间的宏定义。Qt
/// 使用这些宏来确保其库中的类和函数不会与其他库中的同名类和函数冲突。
QT_BEGIN_NAMESPACE
namespace Ui {
    /// 前向声明，允许在 `.cpp` 源文件中引用由 Qt Designer 创建的 UI 界面，而不需要在头文件中包含完整的 UI
    /// 类定义。这种分离方法有助于减少编译依赖性并保持代码的清晰和组织。
    class Widget;
} // namespace Ui
QT_END_NAMESPACE

/// QWidget 是一个非常大的 Qt 组件
class Widget final : public QWidget {
    /// Q_OBJECT 是 Qt 框架中非常重要的宏，用于启用 Qt 对象的元对象系统。
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
