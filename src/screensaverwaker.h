/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    utils
 * 文件名:     screensaverwaker.h
 * 模块功能:   屏幕保护唤醒器头文件，定义屏幕唤醒相关类和接口
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/
#pragma once

#include <QObject>
#include <QTimer>

//for use in systems where the application must be "waken" on a routine basis
class ScreenSaverWaker: public QObject
{
    Q_OBJECT

public:
    ScreenSaverWaker(QObject *parent);
    ~ScreenSaverWaker();

    void StartWaking();
    void StopWaking();

private slots:
    void Wake();

private:
    QTimer timer;

};

 
