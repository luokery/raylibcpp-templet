#ifndef text_util_h
#define text_util_h


#include <string>
#include <chrono>
#include <mutex>

#include <map>
#include <type_traits>


#include "raylib.h"
#include "utils.h"

#include "FontUtil.h"

#include "model/entity/FontEntity.h"
#include "model/entity/DrawTextEntity.h"
#include "model/entity/DrawTextExEntity.h"

// std::map<std::string, std::string> namemap;


#include <unordered_map>
// #include <unordered_map>
// std::unordered_map<std::string, std::string> mymap;
// std::__cxx11::hash_map<int, std::string> mymap;
// #include <ext/hash_map>
// __gnu_cxx::hash_map<std::string, FontEntity> mymap;

/**
 * 文本加载工具
 */
class TextUtil {

    public:
        // 获取单实例对象
        static TextUtil &getInstance();

        // 打印实例地址
        void Print();

        /**
         * 加载字体文本
         */
        Font loadFontTextByDrawTextExEntity(DrawTextExEntity drawTextExEntity);

        void unloadFontTextData();

	private:
        // 禁止外部构造
        TextUtil();

        // 禁止外部析构
        ~TextUtil();

        // 禁止外部复制构造
        TextUtil(const TextUtil &signal);

        // 禁止外部赋值操作
        const TextUtil &operator=(const TextUtil &signal);

        Font* getFontByFontText(std::string strFontText);

    private:
        // 存放生成的文本, 避免重复加载. key为字体名称, value是码点表中各字符的字体; 如: "测试样例hello word" , 通过指定字符的码点表生成的字体对象(注意释放);
        std::unordered_map<std::string, Font*> mFontTextMap;

        // static std::mutex mMutex;
        std::timed_mutex mMutex;
};


// /**
//  * 加载中文需要用到的码表字体
//  * 
//  * 1.将本帧要输出的文字内容保存到字符串中
//  * 2.查找字符串中所有字符对应的unicode码点
//  * 3.使用找到的unicode码点列表读取字体
//  * 4.释放码点列表
//  */
// const Font loadFontCn(const std::string text, unsigned char *fontFileData, const int fileSize){

// /**
//  * 	//读取字体文件
//  * 	int fileSize;
//  * 	int* ptr_safe = static_cast<int*>(&fileSize);
//  * 	unsigned char *fontFileData = LoadFileData("c:\\windows\\fonts\\simhei.ttf", ptr_safe);
//  */

// 		// 将字符串中的字符逐一转换成Unicode码点，得到码点表
// 		int codepointsCount;
// 		int *codepoints=LoadCodepoints(text.c_str(),&codepointsCount);
// 		// 读取仅码点表中各字符的字体
// 		Font font = LoadFontFromMemory(".ttf", fontFileData, fileSize, 32, codepoints, codepointsCount);
// 		// 释放码点表
// 		UnloadCodepoints(codepoints);

//     return font;
// }
#endif