/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    utils
 * 文件名:     logfilemanager.h
 * 模块功能:   日志文件管理器头文件，定义日志管理相关类和接口
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#pragma once

#include <QString>

class LogFileManager
{
public:
    LogFileManager(QString sLogfile = "LogFile.txt", QString sHeader = "Log File Entries");
    ~LogFileManager();
    void openLogFileInFolder();
    void setPrinting(bool bPrinting);
};

 