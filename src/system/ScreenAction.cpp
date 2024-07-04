#include "ScreenAction.h"

#include "Constant.h"

ScreenAction::ScreenAction() {
}

ScreenAction::~ScreenAction() {

}

ScreenAction &ScreenAction::getInstance()
{
    // 局部静态特性的方式实现单实例
    static ScreenAction signal;
    return signal;
}

    // 打印实例地址
    void ScreenAction::Print(){
        
    }
    void ScreenAction::Draw(){
        DrawFPS(10, 10);

        DrawText(TextFormat("Screen Size: [%i, %i]", GetScreenWidth(), GetScreenHeight()), 10, 40, 10, GREEN);

        if (IsWindowState(FLAG_WINDOW_TRANSPARENT)) ClearBackground(BLANK);
        else ClearBackground(RAYWHITE);

        // Draw window state info
        DrawText("Following flags can be set after window creation:", 10, 60, 10, GRAY);
        if (IsWindowState(FLAG_FULLSCREEN_MODE)) DrawText("[F] FLAG_FULLSCREEN_MODE: on", 10, 80, 10, LIME);
        else DrawText("[F] FLAG_FULLSCREEN_MODE: off", 10, 80, 10, MAROON);
        if (IsWindowState(FLAG_WINDOW_RESIZABLE)) DrawText("[R] FLAG_WINDOW_RESIZABLE: on", 10, 100, 10, LIME);
        else DrawText("[R] FLAG_WINDOW_RESIZABLE: off", 10, 100, 10, MAROON);
        if (IsWindowState(FLAG_WINDOW_UNDECORATED)) DrawText("[D] FLAG_WINDOW_UNDECORATED: on", 10, 120, 10, LIME);
        else DrawText("[D] FLAG_WINDOW_UNDECORATED: off", 10, 120, 10, MAROON);
        if (IsWindowState(FLAG_WINDOW_HIDDEN)) DrawText("[H] FLAG_WINDOW_HIDDEN: on", 10, 140, 10, LIME);
        else DrawText("[H] FLAG_WINDOW_HIDDEN: off", 10, 140, 10, MAROON);
        if (IsWindowState(FLAG_WINDOW_MINIMIZED)) DrawText("[N] FLAG_WINDOW_MINIMIZED: on", 10, 160, 10, LIME);
        else DrawText("[N] FLAG_WINDOW_MINIMIZED: off", 10, 160, 10, MAROON);
        if (IsWindowState(FLAG_WINDOW_MAXIMIZED)) DrawText("[M] FLAG_WINDOW_MAXIMIZED: on", 10, 180, 10, LIME);
        else DrawText("[M] FLAG_WINDOW_MAXIMIZED: off", 10, 180, 10, MAROON);
        if (IsWindowState(FLAG_WINDOW_UNFOCUSED)) DrawText("[G] FLAG_WINDOW_UNFOCUSED: on", 10, 200, 10, LIME);
        else DrawText("[U] FLAG_WINDOW_UNFOCUSED: off", 10, 200, 10, MAROON);
        if (IsWindowState(FLAG_WINDOW_TOPMOST)) DrawText("[T] FLAG_WINDOW_TOPMOST: on", 10, 220, 10, LIME);
        else DrawText("[T] FLAG_WINDOW_TOPMOST: off", 10, 220, 10, MAROON);
        if (IsWindowState(FLAG_WINDOW_ALWAYS_RUN)) DrawText("[A] FLAG_WINDOW_ALWAYS_RUN: on", 10, 240, 10, LIME);
        else DrawText("[A] FLAG_WINDOW_ALWAYS_RUN: off", 10, 240, 10, MAROON);
        if (IsWindowState(FLAG_VSYNC_HINT)) DrawText("[V] FLAG_VSYNC_HINT: on", 10, 260, 10, LIME);
        else DrawText("[V] FLAG_VSYNC_HINT: off", 10, 260, 10, MAROON);

        DrawText("Following flags can only be set before window creation:", 10, 300, 10, GRAY);
        if (IsWindowState(FLAG_WINDOW_HIGHDPI)) DrawText("FLAG_WINDOW_HIGHDPI: on", 10, 320, 10, LIME);
        else DrawText("FLAG_WINDOW_HIGHDPI: off", 10, 320, 10, MAROON);
        if (IsWindowState(FLAG_WINDOW_TRANSPARENT)) DrawText("FLAG_WINDOW_TRANSPARENT: on", 10, 340, 10, LIME);
        else DrawText("FLAG_WINDOW_TRANSPARENT: off", 10, 340, 10, MAROON);
        if (IsWindowState(FLAG_MSAA_4X_HINT)) DrawText("FLAG_MSAA_4X_HINT: on", 10, 360, 10, LIME);
        else DrawText("FLAG_MSAA_4X_HINT: off", 10, 360, 10, MAROON);


        DrawText( TextFormat("screen: %d * %d ", screenWidth, screenHeight), 10, 430, 10, MAROON);

        DrawText( TextFormat("screen: current: %d * %d ", GetScreenWidth(), GetScreenHeight()), 10, 450, 10, MAROON);
        // int monitor = GetCurrentMonitor();
        // DrawText( TextFormat("screen: GetCurrentMonitor: %02.02f * %02.02f ", GetMonitorWidth(monitor), GetMonitorHeight(monitor)), 10, 460, 10, MAROON);
        // TextFormat("Font size: %02.02f", msg.GetFontSize())
        
        //将要输出的内容放到字符串中（必须是utf8编码）
        char text0[]="世界，你好！";
        char text1[]="的口袋空空的";
        char text2[]="1的口袋空空的";
        char text3[]="a的口袋空空的";

        // DrawTextEx(font0, text0,(Vector2){50, 460 + (32*1)},32,5, RED);
        DrawTextExEntity drawTextExEntity0("simhei", text0, (Vector2){50, 460 + (32*1)}, 32, 5, RED);
        // drawTextUtil.drawTextEx(drawTextExEntity0);


        // DrawTextEx(font1, text1, (Vector2){10, 460 + (32*2)}, 32, 5, MAROON);
        DrawTextExEntity drawTextExEntity1("simhei", text1, (Vector2){50, 460 + (32*2)}, 32, 5, MAROON);
        // drawTextUtil.drawTextEx(drawTextExEntity1);
        // DrawTextEx(font2, text2, (Vector2){10, 460 + (32*3)}, 32, 5, MAROON);
        DrawTextExEntity drawTextExEntity2("simhei", text2, (Vector2){50, 460 + (32*3)}, 32, 5, MAROON);
        // drawTextUtil.drawTextEx(drawTextExEntity2);
        // DrawTextEx(font3, text3, (Vector2){10, 460 + (32*4)}, 32, 5, MAROON);
        DrawTextExEntity drawTextExEntity3("simhei", text3, (Vector2){50, 460 + (32*4)}, 32, 5, MAROON);
        // drawTextUtil.drawTextEx(drawTextExEntity3);

        // Font font0 = fontUtil.loadTextFontCn("",text0);
        // Font font1 = fontUtil.loadTextFontCn(text1);
        // Font font2 = fontUtil.loadTextFontCn(text2);
        // Font font3 = fontUtil.loadTextFontCn(text3);

        drawTextUtil.drawText(mScreenResolutionText);

        drawTextUtil.drawTextEx(drawTextExEntity0);
        drawTextUtil.drawTextEx(drawTextExEntity1);
        drawTextUtil.drawTextEx(drawTextExEntity2);
        drawTextUtil.drawTextEx(drawTextExEntity3);
        //     DrawTextExEntity fontText0(font0, text0, (Vector2){50, 460},32,5, RED);
        // drawTextUtil.drawTextEx(fontText0);
        //     // DrawTextEx(font0, text0,(Vector2){50, 460 + (32*1)},32,5, RED);

        //     DrawTextEx(font1, text1, (Vector2){10, 460 + (32*2)}, 32, 5, MAROON);
        //     DrawTextEx(font2, text2, (Vector2){10, 460 + (32*3)}, 32, 5, MAROON);
        //     DrawTextEx(font3, text3, (Vector2){10, 460 + (32*4)}, 32, 5, MAROON);
    }

    void ScreenAction::Update(){

        // 当前屏幕的分辨率: 多监视器的情况下
        int monitor = GetCurrentMonitor();
        mScreenResolutionText = DrawTextEntity(TextFormat("screen: GetCurrentMonitor: %d * %d", GetMonitorWidth(monitor), GetMonitorHeight(monitor)), 10, 460, 10, MAROON);

        if (IsKeyPressed(KEY_F)){

            // const int monitorIndex = GetCurrentMonitor();
            // SetWindowSize(GetMonitorWidth(monitorIndex), GetMonitorHeight(monitorIndex));

            SetWindowSize(screenWidth, screenHeight);
            PollInputEvents();
            ToggleFullscreen();
            // ToggleFullscreen();  // modifies window size when scaling!, 切换有问题, 需要多次点击最小化的任务栏才行.有时候还切换不了全屏幕. 可能与缩放有关.
        }

        // if (IsKeyPressed(KEY_F)) ToggleBorderlessWindowed(); // 无边框全屏"这种方式切换快速,而且没有全屏模式来的问题; 但是直接切换为屏幕分辨率了. 窗口1080->2k
        if (IsWindowFullscreen()) {
            mScreenResolutionText.setColor(LIME);
            SetWindowSize(screenWidth, screenHeight);
        }else{
            mScreenResolutionText.setColor(MAROON);
        }

        if (IsKeyPressed(KEY_F11)) {
            if (IsWindowFullscreen()) {
                SetWindowSize(screenWidth, screenHeight);
                WaitTime(0.1);
                ToggleFullscreen();
            } else {
                // 为啥全屏1080->1074: // 1920 1080;1920 1074
                int monitor = GetCurrentMonitor();
                SetWindowSize(GetMonitorWidth(monitor), GetMonitorHeight(monitor));
                WaitTime(0.1);
                SetWindowSize(screenWidth, screenHeight);
                WaitTime(0.1);
                PollInputEvents();
                ToggleFullscreen();
            }
        }
    }

