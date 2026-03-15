/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    utils
 * 文件名:     OS_Wrapper_Functions.h
 * 模块功能:   操作系统包装函数头文件，定义跨平台兼容性函数接口
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/

//This Header is for application wide convenience functions.

#pragma once


#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QWidget>
#include "b9updateentry.h"



//OPERATING SYSTEM COMPATIBILITY HELPER FUNCTIONS::
//dialog compatibility
QString CROSS_OS_GetSaveFileName(QWidget * parent = 0,
                                 const QString & caption = QString(),
                                 const QString & directory = QString(),
                                 const QString & filter = QString(),
                                 const QStringList &saveAbleExtensions = QStringList() );
//File Location Compatibility
QString CROSS_OS_GetDirectoryFromLocationTag(QString locationtag);

//Screen Saver Disabling
bool CROSS_OS_DisableSleeps(bool disable = 1);


//FILE HANDING HELPER FUNCTIONS
//streams in "some random text with spaces" from the opened text file.
QString StreamInTextQuotes(QTextStream &stream);



//Cursor waiting
void Enable_User_Waiting_Cursor();
void Disable_User_Waiting_Cursor();

 