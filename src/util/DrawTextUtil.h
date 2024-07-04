#ifndef draw_text_util_h
#define draw_text_util_h


#include <string>

#include "raylib.h"

#include "model/entity/DrawTextEntity.h"
#include "model/entity/DrawTextExEntity.h"
//#include "FontUtil.h"
#include "TextUtil.h"

/**
 * 字体加载工具
 * c++11特性下的单例模式: 内部静态变量的懒汉单例（C++11 线程安全）
 */
class DrawTextUtil {

    public:
        // 获取单实例对象
        static DrawTextUtil &getInstance();

        // 打印实例地址
        void Print();

        /**
         * 绘制
         */
        bool drawText(DrawTextEntity drawTextEntity);

        /**
         * 绘制
         */
        bool drawTextEx(DrawTextExEntity drawTextExEntity);

        std::string toString(DrawTextEntity drawTextEntity);

        std::string toString(DrawTextExEntity drawTextExEntity);
    private:
        // 禁止外部构造
        DrawTextUtil();

        // 禁止外部析构
        ~DrawTextUtil();

        // 禁止外部复制构造
        DrawTextUtil(const DrawTextUtil &signal);

        // 禁止外部赋值操作
        const DrawTextUtil &operator=(const DrawTextUtil &signal);
};
#endif