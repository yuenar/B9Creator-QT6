/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    system
 * 文件名:     b9updateentry.h
 * 模块功能:   更新条目头文件，定义更新条目相关结构和接口
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#ifndef B9UPDATEENTRY_H
#define B9UPDATEENTRY_H
#include <QString>




struct B9UpdateEntry
{
    QString localLocationTag;
    QString fileName;
    int version;
    QString OSDir;//使用标志位提醒，从子目录下载。
};


#endif // B9UPDATEENTRY_H
