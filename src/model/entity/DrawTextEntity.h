#ifndef draw_text_h
#define draw_text_h


#include <string>

#include "raylib.h"


/**
 * DrawTextEx实体
 */
class DrawTextEntity {

    public:

        // 默认字体方式
        DrawTextEntity();

        DrawTextEntity(const char *charText, int posX, int posY, int fontSize, Color color);

        DrawTextEntity(const char *charText, Vector2 position, int fontSize, Color color);

        DrawTextEntity(std::string strText, Vector2 position, float fontSize, Color color);

        void setCharText(char *charText);
        void setStrText(std::string strText);
        std::string getStrText() const;
        const char* getCharText() const;


        void setPosition(Vector2 position);
        Vector2 getPosition() const;

        void setPosX(int posX);
        int getPosX() const;
        void setPosY(int posY);
        int getPosY() const;


        void setFontSize(int fontSize);
        int getFontSize() const;

        void setSpacing(int spacing);
        int getSpacing() const;

        void setColor(Color color);
        Color getColor() const;

    private:
        DrawTextEntity(const char *charText, int fontSize, Color color);

    private:

        // 绘制的文本
        std::string mStrText = "";
        // 绘制的坐标
        Vector2 mPosition;
        // 字体大小
        float mFontSize;
        // 字体间距
        float mSpacing;
        // 字体颜色
        Color mColor;

};

#endif


