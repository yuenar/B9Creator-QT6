/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    system
 * 文件名:     helpsystem.h
 * 模块功能:   帮助系统头文件，定义应用程序帮助相关类和接口
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#pragma once

#include <QtCore/QString>

QT_BEGIN_NAMESPACE
class QProcess;
QT_END_NAMESPACE

class HelpSystem
{
public:
    HelpSystem();
    ~HelpSystem();
    void showHelpFile(const QString &file);

private:
    bool startHelp();
    QProcess *pHelpProcess;
};
 