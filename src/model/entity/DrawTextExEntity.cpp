#include "DrawTextExEntity.h"

DrawTextExEntity::DrawTextExEntity() {
	
}

DrawTextExEntity::DrawTextExEntity( const char *charText, int posX, int posY, float fontSize, float spacing, Color color) {
    // 绘制的文本
    mStrText = charText;
    // 绘制的坐标
    Vector2 position = { (float)posX, (float)posY };
    mPosition = position;
    // 字体大小
    mFontSize = fontSize;
    // 字体间距
    mSpacing = spacing;
    // 字体颜色
    mColor = color;
}

DrawTextExEntity::DrawTextExEntity(std::string strFontName, const char *charText, int posX, int posY, float fontSize, float spacing, Color color) {
    // DrawTextExEntity( charText, posX, posY, fontSize, spacing, color);
    // 绘制的字体名称
    mStrFontName = strFontName;

    // 绘制的文本
    mStrText = charText;
    // 绘制的坐标
    Vector2 position = { (float)posX, (float)posY };
    mPosition = position;
    // 字体大小
    mFontSize = fontSize;
    // 字体间距
    mSpacing = spacing;
    // 字体颜色
    mColor = color;
}

DrawTextExEntity::DrawTextExEntity(std::string strFontName, const char *charText, Vector2 position, float fontSize, float spacing, Color color) {
    // DrawTextExEntity( charText, position.x, position.y, fontSize, spacing, color);
    // 绘制的字体名称
    mStrFontName = strFontName;
        // 绘制的文本
    mStrText = charText;
    // 绘制的坐标
    mPosition = position;
    // 字体大小
    mFontSize = fontSize;
    // 字体间距
    mSpacing = spacing;
    // 字体颜色
    mColor = color;
}

DrawTextExEntity::DrawTextExEntity(std::string strFontName, std::string strText, Vector2 position, float fontSize, float spacing, Color color) {
    // DrawTextExEntity( strText.c_str(), position.x, position.y, fontSize, spacing, color);
    // 绘制的字体名称
    mStrFontName = strFontName;

    // 绘制的文本
    mStrText = strText;
    // 绘制的坐标
    mPosition = position;
    // 字体大小
    mFontSize = fontSize;
    // 字体间距
    mSpacing = spacing;
    // 字体颜色
    mColor = color;
}

void DrawTextExEntity::setStrFontName(std::string strFontName) {
    mStrFontName = strFontName;
}
std::string DrawTextExEntity::getStrFontName() const {
    return mStrFontName;
}

void DrawTextExEntity::setStrText(std::string strText){
    mStrText = strText;
}
std::string DrawTextExEntity::getStrText() const{
    return mStrText;
}
const char* DrawTextExEntity::getCharText() const{
    return mStrText.c_str();
}


void DrawTextExEntity::setPosition(Vector2 position){
    mPosition = position;
}
Vector2 DrawTextExEntity::getPosition() const{
    return mPosition;
}

void DrawTextExEntity::setFontSize(float fontSize){
    mFontSize = fontSize;
}
float DrawTextExEntity::getFontSize() const{
    return mFontSize;
}

void DrawTextExEntity::setSpacing(float spacing){
    mSpacing = spacing;
}
float DrawTextExEntity::getSpacing() const{
    return mSpacing;
}

void DrawTextExEntity::setColor(Color color){
    mColor = color;
}
Color DrawTextExEntity::getColor() const{
    return mColor;
}