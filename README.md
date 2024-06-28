# 这个模板改造自Raylib官方库的例子.
### 详细信息请访问以下网站:  
~~~ txt
 raylib官方: www.raylib.com
 raylib官方github: https://github.com/raysan5/raylib
~~~

# **编译环境配置**
# 1.下载
## raylib安装: 
### c语言库: 此为官方库, c/c++都支持

* 使用git或直接去github下载zip, 解压就可以用

[Github Raylib地址: https://github.com/raysan5/raylib](https://github.com/raysan5/raylib)


### cpp语言库:

* 使用git或直接去github下载zip, 解压就可以用
  
[Github Raylib-cpp地址: https://github.com/robloach/raylib-cpp](https://github.com/robloach/raylib-cpp)



### 官方库 (**个人强烈不推荐**)

![图片描述](readme/raylib官方库与环境下载.PNG)
* raylib 5.0 Windows Installer 64bit (MinGW compiler) (118 MB)

[raylib网站: www.raylib.com](www.raylib.com)

## w64devkit安装

* 去github下载, 也是解压可用: w64devkit-1.23.0.zip

---
# 2.配置环境

- raylib: 解压到或git到 C:\kunkka\repository\raylib
  
- raylib-cpp: 解压到或git到 C:\kunkka\repository\raylib-cpp

- w64devkit: 解压到 C:\sdk\w64devkit; 如果你要用命令行编译, 需要把C:\sdk\w64devkit\放到PATH环境变量中

---

# 3.配置Makefile文件
# 3.1. 配置raylib路径

~~~ makefile
# Define required raylib variables
PROJECT_NAME       ?= vscode-raylibcpp
RAYLIB_VERSION     ?= 3.0.0
RAYLIB_API_VERSION ?= 300
RAYLIB_PATH        ?= C:/kunkka/repository/raylib
~~~

# 3.2. 配置编译器路径: 这里为w64devkit

~~~ makefile
# Define compiler path on Windows
COMPILER_PATH      ?= C:/sdk/w64devkit/bin
~~~

# 3.3. 添加头文件路径: raylib-cpp

## 查找注释, 在下方添加raylib-cpp的include

~~~ makefile
# Define include paths for required headers

# 自定义:raylib-cpp include path
INCLUDE_PATHS += -IC:/kunkka/repository/raylib-cpp/include
~~~

# **构建项目方式**

## *注意： 以下都是使用Makefile,此文件很重要.*

## 1. vscode构建方式:

* 修改tasks.json中的raylib路径

~~~ json
RAYLIB_PATH=C:/sdk/w64devkit/lib

// 改为raylib安装目录
RAYLIB_PATH=C:/kunkka/repository/raylib

// 项目名称 编译的程序名
PROJECT_NAME=raylibcpp-templet
~~~

## 2. makefile构建方式
~~~ makefile
# 项目名称 编译的程序名
PROJECT_NAME       ?= raylibcpp-templet
# 项目路径
PROJECT_PATH       ?= C:/kunkka/repository/raylibcpp-templet
~~~

## 3. 批处理构建
~~~
# raylib库路径
RAYLIB_PATH        ?= C:/kunkka/repository/raylib
# 编译环境路径
COMPILER_PATH      ?= C:/raylib/w64devkit/bin
~~~

### 多项目配置

~~~ makefile
# Define all object files from source files
#源文件路径：
SRC = $(wildcard *.cpp* ${PROJECT_PATH}/${SRC_DIR}/*.cpp*)

# obj对象路径: 置空
OBJS ?= 
~~~
### 执行批处理
~~~ bat
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

~~~
