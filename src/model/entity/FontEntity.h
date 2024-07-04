#ifndef font_h
#define font_h

#include <string>

#include "raylib.h"

/**
 * 字体实体
 * 用来保存加载的字体信息, 避免重复加载, 统一管理
 */
class FontEntity {

    public:

        FontEntity();

        FontEntity(std::string strFontName, std::string strFontPath);

        void setStrFontName(std::string strFontName);
        std::string getStrFontName() const;

        void setStrFontPath(std::string strFontPath);
        std::string getStrFontPath() const;

        void setNumFileSize(int numFileSize);
        int getNumFileSize() const;

        void setCharFontFileData(unsigned char *charFontFileData);
        unsigned char * getCharFontFileData() const;

    private:

        // 字体名称
        std::string mStrFontName = "";
        // 字体路径
        std::string mStrFontPath = "";

        /** 读取字体文件*/
        // 字体文件大小 (加载字体时使用:非手动操作字段)
        int mNumFileSize;
        // 加载字体 (加载字体时使用:非手动操作字段)
        unsigned char *mCharFontFileData = nullptr;
};

#endif


