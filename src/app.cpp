/*******************************************************************************************
*
*   raylib [core] example - window flags
*
*   Example originally created with raylib 3.5, last time updated with raylib 3.5
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2020-2024 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include <iostream>
#include <string>
//#include <cstream>
#include <cstring>


#include "raylib.h"
// 常量
#include "system/Constant.h"
// 屏幕管理
#include "system/ScreenAction.h"

// 绘制文本字体工具
#include "util/FontUtil.h"
// 绘制工具
#include "util/DrawTextUtil.h"
// 绘制文本实体
#include "model/entity/DrawTextExEntity.h"
#include "model/entity/DrawTextEntity.h"

/** 游戏 */
#include "character/ExampleBall.h"

using namespace std;
//----------------------------------------------------------------------------------
// Local Variables Definition (local to this module)
//----------------------------------------------------------------------------------

int framesCounter = 0;


//----------------------------------------------------------------------------------
// Local Functions Declaration 本地函数原型声明
//----------------------------------------------------------------------------------
static void UpdateDrawFrame(void);          // Update and draw one frame

//----------------------------------------------------------------------------------
// Main entry point
//----------------------------------------------------------------------------------

    // 创建一个小球
    ExampleBall* exampleBall;

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //---------------------------------------------------------


    // Possible window flags 配置屏幕创建标记: 如全屏
    // Set configuration flags for window creation
    // SetConfigFlags(FLAG_VSYNC_HINT | FLAG_MSAA_4X_HINT | FLAG_WINDOW_HIGHDPI);
    // SetConfigFlags(FLAG_FULLSCREEN_MODE);
    // SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    
    InitWindow(screenWidth, screenHeight, "raylib [core] example - window flags 例程");

	// 读取字体文件    
    FontEntity fontSimhei("simhei", "c:\\windows\\fonts\\simhei.ttf");
    // 加载字体
    fontUtil.loadFont(&fontSimhei);

    // 设置日志警告级别 LOG_DEBUG  LOG_WARNING
    SetTraceLogLevel(LOG_DEBUG);

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //----------------------------------------------------------

    // 初始化小球在屏幕中央
    exampleBall = new ExampleBall();

    // GetScreenWidth 需要在 InitWindow()后使用
    Vector2 ballPosition = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
    Vector2 ballSpeed = { 15.0f, 14.0f };
    float ballRadius = 20;
    
	exampleBall->setBallPosition(ballPosition);
    exampleBall->setBallSpeed(ballSpeed);
    exampleBall->setBallRadius(ballRadius);

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // 更新和绘制帧
        UpdateDrawFrame();
    }

    //释放加载的文本内容
    textUtil.unloadFontTextData();

	//释放字体文件内容
    fontUtil.unloadFileData();

	// UnloadFileData(fontUtil.getCharfontFileData());
    delete exampleBall;
    // De-Initialization
    //---------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //----------------------------------------------------------

    return 0;
}


// Update and draw game frame
static void UpdateDrawFrame(void)
{

    // Update
    //----------------------------------------------------------------------------------
    // 更新屏幕
    screenAction.Update();

    // 小球更新逻辑
    exampleBall->update();
    //-----------------------------------------------------
 
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------

    BeginDrawing();

        screenAction.Draw();

        // 绘制弹跳小球
        exampleBall->draw();

        // 绘制鼠标小球
        DrawCircleV(GetMousePosition(), 10, DARKBLUE);


    EndDrawing();
    //----------------------------------------------------------------------------------
    // //释放字体
    // UnloadFont(font);

}
