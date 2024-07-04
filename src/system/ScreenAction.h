#ifndef screen_action_h
#define screen_action_h


#include <string>

#include "raylib.h"
// 绘制文本实体
#include "model/entity/DrawTextExEntity.h"
#include "model/entity/DrawTextEntity.h"
    /*
    FLAG_VSYNC_HINT
    FLAG_FULLSCREEN_MODE    -> not working properly -> wrong scaling! // 有issue表示,因为实际分辨率大了1px导致
    FLAG_WINDOW_RESIZABLE
    FLAG_WINDOW_UNDECORATED
    FLAG_WINDOW_TRANSPARENT
    FLAG_WINDOW_HIDDEN
    FLAG_WINDOW_MINIMIZED   -> Not supported on window creation
    FLAG_WINDOW_MAXIMIZED   -> Not supported on window creation
    FLAG_WINDOW_UNFOCUSED
    FLAG_WINDOW_TOPMOST
    FLAG_WINDOW_HIGHDPI     -> errors after minimize-resize, fb size is recalculated
    FLAG_WINDOW_ALWAYS_RUN
    FLAG_MSAA_4X_HINT
    */

/**
 * 屏幕处理
 * c++11特性下的单例模式: 内部静态变量的懒汉单例（C++11 线程安全）
 */
class ScreenAction {

    public:
        // 获取单实例对象
        static ScreenAction &getInstance();

        // 打印实例地址
        void Print();

        void Draw();

        void Update();

    private:
        // 禁止外部构造
        ScreenAction();

        // 禁止外部析构
        ~ScreenAction();

        // 禁止外部复制构造
        ScreenAction(const ScreenAction &signal);

        // 禁止外部赋值操作
        const ScreenAction &operator=(const ScreenAction &signal);
    private:
        DrawTextEntity mScreenResolutionText;
};
#endif