#ifndef draw_text_ex_h
#define draw_text_ex_h


#include <string>

#include "raylib.h"

/**
 * DrawTextEx实体
 */
class DrawTextExEntity {
    public:

        DrawTextExEntity();

        // 指定字体方式
        // DrawTextExEntity(std::string strFontName, const char *charText, int posX, int posY, float fontSize, float spacing, Color color) : DrawTextExEntity(charText, posX, posY, fontSize, spacing, color);
        DrawTextExEntity(std::string strFontName, const char *charText, int posX, int posY, float fontSize, float spacing, Color color);
        DrawTextExEntity(std::string strFontName, const char *charText, Vector2 position, float fontSize, float spacing, Color color);

        DrawTextExEntity(std::string strFontName, std::string strText, Vector2 position, float fontSize, float spacing, Color color);


        void setStrFontName(std::string strFontName);
        std::string getStrFontName() const;

        // void setFont(Font font);
        // const Font getFont() const;

        void setStrText(std::string strText);
        std::string getStrText() const;
        const char* getCharText() const;


        void setPosition(Vector2 position);
        Vector2 getPosition() const;

        void setFontSize(float fontSize);
        float getFontSize() const;

        void setSpacing(float spacing);
        float getSpacing() const;

        void setColor(Color color);
        Color getColor() const;

    private:
        DrawTextExEntity(const char *charText, int posX, int posY, float fontSize, float spacing, Color color);

    private:

        // 字体名称
        std::string mStrFontName = "";
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


