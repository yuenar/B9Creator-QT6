/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    material
 * 文件名:     b9material.cpp
 * 模块功能:   材料类实现文件，包含3D打印材料的具体实现
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#include "b9material.h"
#include "qstring.h"

B9Material::B9Material()
{
    m_sMaterialLabel = "Default Material Name";
    m_sMaterialDescription = "Defualt Material Description";
    AddXYSize(100);
}

B9Material::~B9Material()
{
}

bool B9Material::isFactoryEntry()
{
    return m_sMaterialLabel.left(2)=="!@";
}

QString B9Material::getLabel()
{
    if(isFactoryEntry())return m_sMaterialLabel.right(m_sMaterialLabel.count()-2);
    return m_sMaterialLabel;
}

XYData* B9Material::FindXYData(double xySize)
{
    int i;
    for(i = 0; i < XYSizes.size(); i++)
    {
        if(XYSizes.at(i).size == xySize)
        {
            return &XYSizes[i];
        }
    }
    return NULL;
}


void B9Material::AddXYSize(double xySize)
{
    XYData newData;
    newData.size = xySize;
    newData.attachmentLayers = 0;
    newData.attachmentLayersCureTime = 0;

    XYSizes.append(newData);
}
void B9Material::SetXYAttachmentCureTime(double xySize, double time_s)
{
    XYData* d = FindXYData(xySize);
    if(d==NULL) return;
    d->attachmentLayersCureTime = time_s;
}

void B9Material::SetXYAttachmentLayers(double xySize,  int numberOfLayers)
{
    XYData* d = FindXYData(xySize);
    if(d==NULL) return;
    d->attachmentLayers = numberOfLayers;
}

double B9Material::GetXYAttachmentCureTime(double xySize)
{
    XYData* d = FindXYData(xySize);
    if(d==NULL) return -1;
    else
        return d->attachmentLayersCureTime;
}
