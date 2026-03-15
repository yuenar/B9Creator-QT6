/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    model
 * 文件名:     b9modelwriter.h
 * 模块功能:   模型写入器头文件，定义模型数据写入相关类和接口
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
#include <QFile>
#include <QDataStream>



//用法: 创建一个B9ModelWriter对象要有文件名同时可读写,
//在使用WriteNextTri()方法时，开始填充三角数据;
//当完成填充模型三角数据操作后调用Finalize()方法;


class Triangle3D;
class B9ModelWriter : public QObject
{
    Q_OBJECT
public:

    explicit B9ModelWriter(QString filename, bool &readyWrite, QObject *parent = 0);
    ~B9ModelWriter();


signals:

    //void PercentCompletedUpdate(qint64 frac, qint64 total);

public:
    void WriteNextTri(Triangle3D* pTri);
    void Finalize();//追溯到文件的开头，写三个计数。

private:
    QFile binOUT;
    QDataStream binStream;
    unsigned long int triCount;

    void WriteHeader(quint32 triCount);


};
 