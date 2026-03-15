/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    material
 * 文件名:     b9printermodeldata.cpp
 * 模块功能:   打印机模型数据实现文件，包含打印机模型数据的具体实现
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#include "b9printermodeldata.h"
#include "b9material.h"
#include <QString>


//////////////////////////////////////////////////////////////////////////
//PrinterModelData Class
b9PrinterModelData::b9PrinterModelData()
{
    m_sModelName = "";

    m_dStepSizeMicrons = 0;
    m_iMaxSteps = 0;

    B9Material startMat;
    AddMaterial(startMat);
}
b9PrinterModelData::b9PrinterModelData(QString modelName)
{
    m_sModelName = modelName;

    m_dStepSizeMicrons = 0;
    m_iMaxSteps = 0;

    B9Material startMat;
    AddMaterial(startMat);
}
b9PrinterModelData::~b9PrinterModelData()
{
}


QString b9PrinterModelData::GetName() const
{
    return m_sModelName;
}


void b9PrinterModelData::ClearMaterials()
{
    m_Materials.clear();
}


void b9PrinterModelData::AddMaterial(B9Material mat)
{
    m_Materials.push_back(mat);
}


QVector<B9Material> *b9PrinterModelData::GetMaterials()
{
    return &m_Materials;
}

B9Material* b9PrinterModelData::FindMaterialByLabel(QString label)
{
    for(int i = 0; i < this->m_Materials.size(); i++)
    {
        if(m_Materials[i].getLabel() == label)
        {
            return &m_Materials[i];
        }
    }
    return NULL;
}

double b9PrinterModelData::GetXYSizeByIndex(int index)
{
    if((m_dXYPixelSizes.size() - 1) < index)
        return -1;
    else
        return m_dXYPixelSizes.at(index);
}


