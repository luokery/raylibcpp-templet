#include "TextUtil.h"

TextUtil::TextUtil() {
}

TextUtil::~TextUtil() {
    // 解锁
    mMutex.unlock();
}

TextUtil &TextUtil::getInstance()
{
    // 局部静态特性的方式实现单实例
    static TextUtil signal;
    return signal;
}

Font* TextUtil::getFontByFontText(std::string strFontText) {
    if( strFontText == ""){
        return nullptr;
    }

    /** 1. 查找释放已经加载的字体库 */
    auto it = mFontTextMap.find(strFontText);
    if(it != mFontTextMap.end()){
        Font* font = it->second;
        return font;
    }
    return nullptr;
}

/**
 * 加载中文需要用到的码表字体
 * 
 * 1.将本帧要输出的文字内容保存到字符串中
 * 2.查找字符串中所有字符对应的unicode码点
 * 3.使用找到的unicode码点列表读取字体
 * 4.释放码点列表
 */
Font TextUtil::loadFontTextByDrawTextExEntity(DrawTextExEntity drawTextExEntity) {

    std::string strFontName = drawTextExEntity.getStrFontName();
    std::string strText = drawTextExEntity.getStrText();
    int fontSize = drawTextExEntity.getFontSize();

    FontUtil &fontUtil = FontUtil::getInstance();

    FontEntity* fontEntity = fontUtil.getFontEntityByFontNamePint( strFontName);
    if (fontEntity == nullptr && fontEntity->getCharFontFileData() == nullptr)
    {
        // TODO: 没找到应该提示错误. 使用了未加载的字体.
        TRACELOGD("FONT: 没找到应该提示错误. 使用了未加载的字体");
        return { 0 };
    }

    // 如果已经加载过, 直接返回
    std::string strFontText = strText + "_" + strFontName;
    Font* font = getFontByFontText(strFontText);
    if ( font != nullptr)
    {
        return { *font };
    }

    // 将字符串中的字符逐一转换成Unicode码点，得到码点表
    int codepointsCount;
    int *codepoints = LoadCodepoints(strText.c_str(), &codepointsCount);

    int fileSize = fontEntity->getNumFileSize();
    unsigned char * fontFileData = fontEntity->getCharFontFileData();
    
    // 读取仅码点表中各字符的字体 .ttf .otf
    Font fontText = LoadFontFromMemory(".ttf", fontFileData, fileSize, fontSize, codepoints, codepointsCount);

    // 释放码点表
    UnloadCodepoints(codepoints);

    Font* pFont = new Font(fontText);

    // // 释放字体
    // UnloadFont(fontText);

    mFontTextMap.insert({strFontText, pFont});
    
    return (*pFont);
}

void TextUtil::unloadFontTextData(){

    for (auto it = mFontTextMap.begin(); it != mFontTextMap.end(); it++)
    {
        std::string name = it->first;
        Font* font = it->second;

        if(sizeof(font) > 0){
            //释放字体 FIXME: 如何转换指针到实体
            UnloadFont((*font));
            delete font;
        }
    }
    // 移除所有元素
    mFontTextMap.erase(mFontTextMap.begin(), mFontTextMap.end());
}