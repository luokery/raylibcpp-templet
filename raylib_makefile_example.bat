::批处理 raylib_makefile_example.bat

::@echo off
:: .
:: Compile your examples using:  raylib_makefile_example.bat core/core_basic_window
:: .
:: > Setup required Environment
:: -------------------------------------
set PROJECT_NAME=raylibcpp-templet
set RAYLIB_HOME=C:\kunkka\repository\raylib
set RAYLIB_INCLUDE_DIR=%RAYLIB_HOME%\src
set RAYLIB_LIB_DIR=%RAYLIB_HOME%\src
set RAYLIB_RES_FILE=%RAYLIB_HOME%\src\raylib.rc.data
set COMPILER_DIR=C:\sdk\w64devkit\bin
set PATH=%PATH%;%COMPILER_DIR%
set FILENAME=%1
set FILENAME_FULL_PATH=%~f1
cd %~dp0
:: .
:: > Cleaning latest build
:: ---------------------------
cmd /c if exist %FILENAME_FULL_PATH%.exe del /F %FILENAME_FULL_PATH%.exe
:: .
:: > Compiling program
:: --------------------------
:: -B  : Force make recompilation despite file not changed
:: 原始
::mingw32-make %FILENAME% -B PLATFORM=PLATFORM_DESKTOP 

:: 改造: BUILD_MODE=DEBUG 配置DEBUG或RELEASE
mingw32-make %FILENAME% -B PLATFORM=PLATFORM_DESKTOP  RAYLIB_PATH=C:/kunkka/repository/raylib PROJECT_NAME=%PROJECT_NAME% OBJS= BUILD_MODE=RELEASE 
:: .
:: > Executing program
:: -------------------------
cmd /c if exist %FILENAME_FULL_PATH%.exe %FILENAME_FULL_PATH%.exe