/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    b9layout
 * 文件名:     modeldata.h
 * 模块功能:   模型数据类头文件，定义3D模型数据相关类和接口
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
#include "b9layout.h"
#include "triangle3d.h"

#include <vector>

// 前向声明避免循环依赖
class B9ModelInstance;
class B9Layout;
class aiScene;
class ModelData {

    friend class B9ModelInstance;

public:
    ModelData(B9Layout* main, bool bypassDisplayLists = false);
	~ModelData();
	
	QString GetFilePath();
	QString GetFileName();
	
    //数据导入
    bool LoadIn(QString filepath); //返回成功
	
    //实例
	B9ModelInstance* AddInstance();
	int loadedcount;


//渲染的模型可以潜在地拥有多个显示列表，让显卡驱动程序，以便更好地分配需要非常大的模型记忆。在需要的时候生成这些翻转列表。
//递归实现
    std::vector<unsigned int> normDispLists;
    std::vector<unsigned int> flippedDispLists;

    bool FormFlippedDisplayLists();
    bool FormNormalDisplayLists();

    //geometry
    std::vector<Triangle3D> triList;
	QVector3D maxbound;
	QVector3D minbound;

	std::vector<B9ModelInstance*> instList;
    B9Layout* pMain;
private:
	
	
	
    QString filepath;//物理文件路径
    QString filename;//文件名(larry.stl)

    //效用
    void CenterModel();//此方法实现导入模型后调整其位置在0,0,0元心
	
	const aiScene* pScene;

    //渲染

    int displaySkipping; // 渲染巨大的对象时跳过多少个三角数据。。
    bool bypassDispLists;
	
    int GetGLError();

};
 
