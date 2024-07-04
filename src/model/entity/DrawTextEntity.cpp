#include "DrawTextEntity.h"

DrawTextEntity::DrawTextEntity() {
	
}

DrawTextEntity::DrawTextEntity(const char *charText, int fontSize, Color color) {
	// 绘制的文本
    mStrText = charText;
    // 字体大小
    mFontSize = fontSize;
    // // 字体间距
    // mSpacing = spacing;
    // 字体颜色
    mColor = color;
}

DrawTextEntity::DrawTextEntity(const char *charText, int posX, int posY, int fontSize, Color color) {
	// 绘制的文本
    mStrText = charText;
    // 绘制的坐标
    Vector2 position = { (float)posX, (float)posY };
    mPosition = position;
    // 字体大小
    mFontSize = fontSize;
    // // 字体间距
    // mSpacing = spacing;
    // 字体颜色
    mColor = color;
}

DrawTextEntity::DrawTextEntity(const char *charText, Vector2 position, int fontSize, Color color) {
	// 绘制的文本
    mStrText = charText;
    // 绘制的坐标
    mPosition = position;
    // 字体大小
    mFontSize = fontSize;
    // // 字体间距
    // mSpacing = spacing;
    // 字体颜色
    mColor = color;
}

DrawTextEntity::DrawTextEntity(std::string strText, Vector2 position, float fontSize, Color color) {
	// 绘制的文本
    mStrText = strText;
    // 绘制的坐标
    mPosition = position;
    // 字体大小
    mFontSize = fontSize;
    // // 字体间距
    // mSpacing = spacing;
    // 字体颜色
    mColor = color;
}

void DrawTextEntity::setCharText(char *charText){
        mStrText = charText;
}

void DrawTextEntity::setStrText(std::string strText){
    mStrText = strText;
}
std::string DrawTextEntity::getStrText() const{
    return mStrText;
}
const char* DrawTextEntity::getCharText() const{
    return mStrText.c_str();
}


void DrawTextEntity::setPosition(Vector2 position){
    mPosition = position;
}
Vector2 DrawTextEntity::getPosition() const{
    return mPosition;
}

void DrawTextEntity::setPosX(int posX){
    mPosition.x = posX;
}
int DrawTextEntity::getPosX() const{
    return mPosition.x;
}
void DrawTextEntity::setPosY(int posY){
    mPosition.y = posY;
}
int DrawTextEntity::getPosY() const{
    return mPosition.y;
}

void DrawTextEntity::setFontSize(int fontSize){
    mFontSize = fontSize;
}
int DrawTextEntity::getFontSize() const{
    return mFontSize;
}

void DrawTextEntity::setSpacing(int spacing){
    mSpacing = spacing;
}
int DrawTextEntity::getSpacing() const{
    return mSpacing;
}

void DrawTextEntity::setColor(Color color){
    mColor = color;
}
Color DrawTextEntity::getColor() const{
    return mColor;
}