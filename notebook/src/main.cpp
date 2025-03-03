//  Copyright (c) 2025. aaron.
//
//  This program is under the GPL-3.0 license.
//  if you have not received it or the program has several bugs, please let me know:
//  <communicate_aaron@outlook.com>.

#include "../ui/widget.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    /// 设置高 DPI 缩放相关属性
    /// Qt5/Qt6 通用写法（需在 QApplication 实例化前调用）
    /// Qt5 需手动启用高 DPI 支持
    // QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    /// 管理应用程序的许多核心功能 \n
    /// 1. 事件循环
    /// 2. 全局设置
    /// 3. GUI 初始化
    /// 4. 命令行参数处理
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return QApplication::exec();
}
