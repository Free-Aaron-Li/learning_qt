//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me
//   know: <communicate_aaron@outlook.com>.
//

#ifndef WIDGET_H
#define WIDGET_H

#include <QPainter>
#include <QPoint>
#include <QTimer>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
    class Widget;
}
QT_END_NAMESPACE

class Widget final : public QWidget {
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;

    void
    paintEvent(QPaintEvent *event) override;

private:
    Ui::Widget *ui;
    QTimer *_timer{};
    /**
     * @brief 当前计数值
     */
    int _current_time{ 0 };

    /**
     * @brief 指针是否逆转
     *
     * 该变量用于指示指针是否需要逆转。如果为true，则指针需要逆转；
     * 如果为false，则指针按正常方向旋转。
     */
    bool _pointer_rotation{ false };

    /**
     * @brief 指针旋转角度
     *
     * 该常量表示指针旋转的角度，单位为度。在此例中，指针旋转角度为150度。
     */
    static constexpr int _rotation_angle{ 150 };

    /**
     * @brief 刻度盘总角度
     *
     * 该常量表示刻度盘的总角度，单位为度。在此例中，刻度盘总角度为240度。
     */
    static constexpr double _scale_angle{ 240.0 };

    /**
     * @brief 总刻度数
     *
     * 该常量表示刻度盘上的总刻度数。在此例中，总刻度数为60。
     */
    static constexpr int _scale{ 60 };

    /**
     * @brief 单位刻度值
     *
     * 这个静态常量表达式 `_angle` 用于表示单位刻度值。
     * 它是通过将 `_scale_angle` 除以 `_scale` 计算得到的。
     *
     * 例如，如果 `_scale_angle` 表示一个完整的圆周角度数（如360度），
     * 而 `_scale` 表示将圆周分割成的份数（如12），那么 `_angle` 就表示
     * 每个刻度对应的角度值（如30度）。
     */
    static constexpr double _angle = _scale_angle / _scale;

    /**
     * @brief 中心表盘半径
     *
     * 该常量表示中心表盘的半径，单位为像素。在此例中，中心表盘半径为60像素。
     */
    static constexpr int _middle_board_radius{ 60 };

    /**
     * @brief  设置运行时间。
     * @return 无返回值。
     */
    auto
    setTime() -> void;

    /**
     * @brief 初始化画布
     *
     * 该函数用于初始化画布，设置绘图环境。函数参数为QPainter对象引用，
     * 通过该对象可以在绘图设备上进行绘图操作。
     *
     * @param painter QPainter对象，用于执行绘图操作。
     *
     * @return 无返回值。
     */
    void
    initCanvas(QPainter &painter) const;

    /**
     * @brief 绘制中心表盘
     *
     * 该函数用于在给定的绘图设备上绘制一个中心表盘。
     * 表盘的半径由参数radius指定，绘制时使用QPainter对象。
     *
     * @param painter QPainter对象，用于执行绘图操作。
     * @param radius 中心表盘的半径，以像素为单位。
     *
     * @return 无返回值。
     */
    static auto
    drawMiddleBoard(QPainter &painter, int radius) -> void;

    /**
     * @brief 绘制当前时速
     *
     * 该函数用于在给定的绘图设备上绘制当前时速的指示器。
     *
     * @param painter QPainter对象，用于执行绘图操作。
     * @param current_time 当前时间，用于计算当前时速。
     *
     * @return 无返回值。
     */
    static auto
    drawCurrentSpeed(QPainter &painter, int current_time) -> void;

    /**
     * @brief 绘制刻度线
     *
     * 该函数用于在绘图设备上绘制刻度线。
     *
     * @param painter QPainter 对象，用于执行绘图操作。
     * @param radius 刻度盘的半径，以像素为单位。
     * @return 无返回值。
     */
    static auto
    drawScaleLine(QPainter &painter, int radius) -> void;

    /**
     * @brief 绘制刻度值

     * 该函数用于在指定半径的位置绘制刻度值。
     *
     * @param painter  QPainter对象，用于执行绘图操作。
     * @param radius  刻度值的半径，表示刻度值距离中心点的距离。
     *                该参数决定了刻度值在绘制时的位置。
     *@return 无返回值。
     */
    static auto
    drawScaleText(QPainter &painter, int radius) -> void;

    /**
     * @brief 绘制指针
     *
     * 该函数用于在给定的绘图设备上绘制一个指针，指针的大小由半径参数决定。
     *
     * @param painter QPainter对象，用于执行绘图操作。
     * @param radius 指针的半径，决定了指针的大小。
     * @param current_time 当前时间，用于计算指针的位置。
     * @return 无返回值。
     */
    static auto
    drawPointer(QPainter &painter, int radius, int current_time) -> void;

    /**
     * @brief 绘制渐变扇
     *
     * 该函数用于在给定的画布上绘制一个渐变效果的扇形。
     *
     * @param painter QPainter对象，用于在画布上进行绘制操作。
     * @param radius 扇形的半径。
     * @param current_time 当前时间，用于计算绘制扇形结束位置。
     *
     * @return 无返回值。
     */
    static auto
    drawPie(QPainter &painter, int radius, int current_time) -> void;

    /**
     * @brief 内圈绘制
     */
    static auto
    drawEllipseInner(QPainter &painter, int inner_radius) -> void;

    /**
     * @brief 绘制内圈光环
     */
    static auto
    drawEllipseInnerShine(QPainter &painter, int inner_radius) -> void;

    /**
     * @brief 绘制外圈光环
     */
    static auto
    drawEllipseOuterShine(QPainter &painter, int outer_radius) -> void;

    /**
     * @brief 绘制汽车Logo
     */
    static auto
    drawLogo(QPainter &painter,int radius)->void;
};
#endif  // WIDGET_H
