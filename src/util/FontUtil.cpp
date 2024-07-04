#include "FontUtil.h"

FontUtil::FontUtil() {
}

FontUtil::~FontUtil() {
    // 解锁
    mMutex.unlock();
}

FontUtil &FontUtil::getInstance()
{
    // 局部静态特性的方式实现单实例
    static FontUtil signal;
    return signal;
}

// FontUtil::FontUtil(const std::string fontName, const std::string fontPath) {
//     mStrfontName = fontName;
//     mStrfontPath = fontPath;
// }
FontEntity FontUtil::getFontEntityByFontName(std::string strFontName) {
    FontEntity* fount = getFontEntityByFontNamePint(strFontName);
    return (*fount);
}

FontEntity* FontUtil::getFontEntityByFontNamePint(std::string strFontName) {

    if( sizeof(strFontName) < 1){
        return nullptr;
    }
    // if( std::is_empty_class<string> == true){
    //     return ;
    // }

    /** 1. 查找释放已经加载的字体库 */
    auto it = mFontEntityMap.find(strFontName);
    if(it != mFontEntityMap.end()){
        FontEntity* font = it->second;
        if(font != nullptr){
            return font;
        }
        return nullptr;
    }
    return nullptr;
}

// Font* FontUtil::getFontByFontText(std::string strFontText) {
//     if( strFontText == ""){
//         return nullptr;
//     }

//     /** 1. 查找释放已经加载的字体库 */
//     auto it = mFontTextMap.find(strFontText);
//     if(it != mFontTextMap.end()){
//         Font* font = it->second;
//         return font;
//     }
//     return nullptr;
// }

bool FontUtil::loadFont(FontEntity* fontEntity) {

    if( !fontEntity || fontEntity == nullptr){
        return false;
    }
    if (fontEntity->getNumFileSize() != 0 && fontEntity->getCharFontFileData() != nullptr)
    {
        return true;
    }

    FontEntity* font = getFontEntityByFontNamePint(fontEntity->getStrFontName());
    if (font != nullptr && font->getCharFontFileData() != nullptr)
    {
        return true;
    }

    try
    {
        // 加时间锁: 100ms
        while (mMutex.try_lock_for(std::chrono::milliseconds(100)))
        {
            /* code */
        }
        if (font != nullptr && font->getCharFontFileData() != nullptr)
        {
            return true;
        }

        /**
         * 	//读取字体文件
         * 	int fileSize;
         * 	int* ptr_safe = static_cast<int*>(&fileSize);
         * 	unsigned char *fontFileData = LoadFileData("c:\\windows\\fonts\\simhei.ttf", ptr_safe);
         */
        /** 读取字体文件*/
        int numFileSize;
        //int* ptr_safe = static_cast<int*>(&numFileSize);
        std::string strFontName = fontEntity->getStrFontName();
        std::string strFontPath = fontEntity->getStrFontPath();
        
        // 加载字体 
        //c:\\windows\\fonts\\simhei.ttf
        // C:/Users/kunkka/Downloads/SourceHanSansCN/SubsetOTF/CN/SourceHanSansCN-Normal.otf
        unsigned char *charFontFileData = LoadFileData(strFontPath.c_str(), &numFileSize);

        fontEntity->setNumFileSize(numFileSize);
        fontEntity->setCharFontFileData(charFontFileData);
        
        mFontEntityMap.insert({strFontName, fontEntity});
        // 解锁
        mMutex.unlock();
    }
    catch(const std::exception& e)
    {
        // std::cerr << e.what() << '\n';
    }
    return true;
}

// /**
//  * 加载中文需要用到的码表字体
//  * 
//  * 1.将本帧要输出的文字内容保存到字符串中
//  * 2.查找字符串中所有字符对应的unicode码点
//  * 3.使用找到的unicode码点列表读取字体
//  * 4.释放码点列表
//  */
// Font FontUtil::loadFontTextByDrawTextExEntity(DrawTextExEntity drawTextExEntity) {

//     std::string strFontName = drawTextExEntity.getStrFontName();
//     std::string strText = drawTextExEntity.getStrText();
//     int fontSize = drawTextExEntity.getFontSize();
// TRACELOGD("FONT: 没找到应该提示错误. 使用了未加载的字体");
// TRACELOGD(TextFormat("loadFontTextByDrawTextExEntity : %s", strFontName));
//     FontEntity* fontEntity = getFontEntityByFontNamePint( strFontName);
//     if (fontEntity == nullptr && fontEntity->getCharFontFileData() == nullptr)
//     {
//         // TODO: 没找到应该提示错误. 使用了未加载的字体.
//         TRACELOGD("FONT: 没找到应该提示错误. 使用了未加载的字体");
//         return { 0 };
//     }

//     // 如果已经加载过, 直接返回
//     std::string strFontText = strText + "_" + strFontName;
//     Font* font = getFontByFontText(strFontText);
//     if ( font != nullptr)
//     {
//         return { *font };
//     }

//     // 将字符串中的字符逐一转换成Unicode码点，得到码点表
//     int codepointsCount;
//     int *codepoints = LoadCodepoints(strText.c_str(), &codepointsCount);

//     int fileSize = fontEntity->getNumFileSize();
//     unsigned char * fontFileData = fontEntity->getCharFontFileData();
    
//     // 读取仅码点表中各字符的字体 .ttf .otf
//     Font fontText = LoadFontFromMemory(".ttf", fontFileData, fileSize, fontSize, codepoints, codepointsCount);

//     // 释放码点表
//     UnloadCodepoints(codepoints);
    

// Font* pFont = new Font(fontText);

//     // Font* pFont = new Font();

//     // pFont->baseSize = fontText.baseSize;
//     // pFont->glyphCount = fontText.glyphCount;
//     // pFont->glyphPadding = fontText.glyphPadding;
//     // pFont->glyphs = fontText.glyphs;
//     // pFont->recs = fontText.recs;
//     // pFont->texture = fontText.texture;
//     mFontTextMap.insert({strFontText, pFont});

//     return (*pFont);
// }

/**
 * 释放字体
 */
void FontUtil::unloadFileData() {
    // 返回桶数
    int nBucketCount = mFontEntityMap.bucket_count();

    for(int i = 0; i < nBucketCount; i++){

        for (auto it = mFontEntityMap.begin(i); it != mFontEntityMap.end(i); it++)
        {
            std::string name = it->first;
            FontEntity* font = it->second;

            if(font->getCharFontFileData() != nullptr){
                UnloadFileData(font->getCharFontFileData());
            }
        }
    }
    // 移除所有元素
    mFontEntityMap.erase(mFontEntityMap.begin(), mFontEntityMap.end());
}
