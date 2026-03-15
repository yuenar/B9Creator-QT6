/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    material
 * 文件名:     b9material.h
 * 模块功能:   材料类头文件，定义3D打印材料相关类和接口
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
#include <QVector>

struct XYData
{
    double size;
    int attachmentLayers;
    double attachmentLayersCureTime;
    QVector<double> cure_times;
    QVector<double> over_cure_times;
};

class B9Material
{
public:
    B9Material();
    ~B9Material();
    QString getLabel();
    void SetLabel(QString newLabel){m_sMaterialLabel = newLabel;}
    QString GetDescription(){return m_sMaterialDescription;}
    void SetDescription(QString newDesc){m_sMaterialDescription = newDesc;}
    void AddXYSize(double xySize);
    void SetXYAttachmentCureTime(double xySize, double time_s);
    void SetXYAttachmentLayers(double xySize,  int numberOfLayers);

    double GetXYAttachmentCureTime(double xySize);

    bool isFactoryEntry();

private:

    QString m_sMaterialLabel, m_sMaterialDescription;
    QVector<XYData> XYSizes;

    XYData* FindXYData(double xySize);
};
 
