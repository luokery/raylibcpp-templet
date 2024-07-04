#include "Constant.h"

// 487  362;800 600;1280 1024; 1600 900;1600 1024; 1920 1080;1920 1440;2560 1440: 800*600支持最好
// 16:9 分辨率有许多常见的尺寸，如 1280 720;1366 768;1920 1080; 16*9很好, 但是1920 1080不行; 突然都行了
// 1280 720;1366 768;1600 900;1920 1080;2560 1440;3840 2160
const int screenWidth = 800;
const int screenHeight = 600;

// 屏幕处理对象
ScreenAction &screenAction = ScreenAction::getInstance();

// 字体工具: 加载字体, 全局管理加载的字体
FontUtil &fontUtil = FontUtil::getInstance();
// 文本工具: 加载文本, 全局管理加载的文本
TextUtil &textUtil = TextUtil::getInstance();

// 绘制文本工具
DrawTextUtil &drawTextUtil = DrawTextUtil::getInstance();



