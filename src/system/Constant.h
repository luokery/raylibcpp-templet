
#ifndef Constant_h
#define Constant_h

// 屏幕管理
#include "system/ScreenAction.h"
// 绘制字体工具
#include "util/FontUtil.h"
// 绘制文本工具
#include "util/TextUtil.h"
// 绘制工具
#include "util/DrawTextUtil.h"


// 绘制文本实体
#include "model/entity/DrawTextExEntity.h"
#include "model/entity/DrawTextEntity.h"


extern const int screenWidth;
extern const int screenHeight;

// 屏幕处理对象
extern ScreenAction &screenAction;

// 字体工具: 加载字体, 全局管理加载的字体
extern FontUtil &fontUtil;

// 文本工具: 加载文本, 全局管理加载的文本
extern TextUtil &textUtil;

// 绘制文本工具
extern DrawTextUtil &drawTextUtil;




// extern const 

#endif