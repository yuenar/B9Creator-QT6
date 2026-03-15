/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    core
 * 文件名:     main.cpp
 * 模块功能:   主程序入口文件，包含应用程序主函数的具体实现
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#include <QApplication>
#include <QSplashScreen>
#include "b9nativeapp.h"
#include <QDir>

int main(int argc, char *argv[])
{
    B9NativeApp a(argc, argv);

	
    QPixmap pixmap(CROSS_OS_GetDirectoryFromLocationTag("APPLICATION_DIR")+"/"+"splash.png");
    QSplashScreen splash(pixmap,Qt::WindowStaysOnTopHint);
    //processEvents();
    a.mainWindow->setSplash(&splash);
    a.mainWindow->show();
    //a.mainWindow->showSplash();

    a.ProccessArguments();

    return a.exec();
}
