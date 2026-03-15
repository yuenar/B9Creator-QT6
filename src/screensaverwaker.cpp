/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    utils
 * 文件名:     screensaverwaker.cpp
 * 模块功能:   屏幕保护唤醒器实现文件，包含屏幕唤醒的具体实现
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#include "screensaverwaker.h"


#ifdef Q_OS_MAC
#include <CoreServices/CoreServices.h>
#endif


ScreenSaverWaker::ScreenSaverWaker(QObject* parent) : QObject(parent)
{
    QObject::connect(&timer,SIGNAL(timeout()),this,SLOT(Wake()));
}
ScreenSaverWaker::~ScreenSaverWaker()
{

}

void ScreenSaverWaker::Wake()
{
    #ifdef Q_OS_MAC
        UpdateSystemActivity(OverallAct);//Mac特定调用
    #endif
    #ifdef Q_OS_LINUX

    #endif
}

void ScreenSaverWaker::StartWaking()
{
    timer.setSingleShot(false);
    timer.start(3000);
}

void ScreenSaverWaker::StopWaking()
{
    timer.stop();
}

