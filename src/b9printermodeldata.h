/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    material
 * 文件名:     b9printermodeldata.h
 * 模块功能:   打印机模型数据头文件，定义打印机模型数据相关类和接口
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
#include <QVector>
#include <QList>
#include "b9material.h"

class QString;



class b9PrinterModelData
{
public:
    b9PrinterModelData();
    b9PrinterModelData(QString modelName);
    ~b9PrinterModelData();

    QString GetName() const;
    void AddXYPixelSize(double size){m_dXYPixelSizes.append(size);}
    void SetZStepSizeMicrons(double stepSize){m_dStepSizeMicrons = stepSize;}
    void SetMaxSteps(int maxSteps){m_iMaxSteps = maxSteps;}


    void ClearMaterials();
    void AddMaterial(B9Material mat);
    QVector<B9Material>* GetMaterials();// 只是返回指向实际材料的指针。
    B9Material* FindMaterialByLabel(QString label);
    double GetXYSizeByIndex(int index);

private:
    QList<double> m_dXYPixelSizes;
    double m_dStepSizeMicrons;
    int m_iMaxSteps;
    QString m_sModelName;//命名 例如B9C1
    QVector<B9Material> m_Materials;//与此打印机关联的材料。
};


 