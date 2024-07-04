#include "DrawTextUtil.h"


DrawTextUtil::DrawTextUtil()
{
    // std::cout << "构造函数" << std::endl;
}

DrawTextUtil::~DrawTextUtil()
{
    // std::cout << "析构函数" << std::endl;
}

DrawTextUtil &DrawTextUtil::getInstance()
{
    // 局部静态特性的方式实现单实例
    static DrawTextUtil signal;
    return signal;
}

void DrawTextUtil::Print()
{
    // std::cout << "我的实例内存地址是:" << this << std::endl;
}

/**
 * 绘制
 */
bool DrawTextUtil::drawText(DrawTextEntity drawTextEntity){
    DrawText(drawTextEntity.getCharText(), drawTextEntity.getPosX(), drawTextEntity.getPosY(), drawTextEntity.getFontSize(), drawTextEntity.getColor());
    return true;
}

/**
 * 绘制
 */
bool DrawTextUtil::drawTextEx(DrawTextExEntity drawTextExEntity){

    TextUtil &textUtil = TextUtil::getInstance();

    // std::string strFontName = drawTextExEntity.getStrFontName();

    Font font = textUtil.loadFontTextByDrawTextExEntity(drawTextExEntity);
    // Font fonta = (*font);
    DrawTextEx(font, drawTextExEntity.getCharText(), drawTextExEntity.getPosition(), drawTextExEntity.getFontSize(), drawTextExEntity.getSpacing(), drawTextExEntity.getColor());
    
    return true;
}

std::string DrawTextUtil::toString(DrawTextEntity drawTextEntity){
    
    // std::string res = res + std::__cxx11::to_string( drawTextEntity.getCharText());
    // std::string res = res + std::__cxx11::to_string( drawTextEntity.getPosX());
    // std::string res = res + std::__cxx11::to_string( drawTextEntity.getPosY());
    // std::string res = res + std::__cxx11::to_string( drawTextEntity.getFontSize());
    // std::string res = res + std::__cxx11::to_string( drawTextEntity.getColor());
    return "";
}

std::string DrawTextUtil::toString(DrawTextExEntity drawTextExEntity){
    return "";
}