/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    material
 * 文件名:     b9printermodelmanager.h
 * 模块功能:   打印机模型管理器头文件，定义打印机模型管理相关类和接口
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
#include "b9printermodeldata.h"

class QString;


class b9PrinterModelManager : public QObject
{
    Q_OBJECT
public:
    explicit b9PrinterModelManager(QObject *parent = 0);
    ~b9PrinterModelManager();

    void ImportDefinitions(QString defFilePath);//从给定的定义类型文件导入

    b9PrinterModelData* GetCurrentOperatingPrinter();
    std::vector<b9PrinterModelData*> GetPrinterModels();
    bool SetCurrentOperatingPrinter(b9PrinterModelData* modelDataPtr);
    bool SetCurrentOperatingPrinter(QString modelName);
    b9PrinterModelData* FindPrinterDataByName(QString modelName);





signals:
    void FilesUpdated();
    
public slots:


private:
    //成员
    std::vector<b9PrinterModelData*> m_PrinterDataList;
    b9PrinterModelData* m_CurrentOperatingPrinter;

    //函数
    b9PrinterModelData* AddPrinterData(QString modelName);





};

 