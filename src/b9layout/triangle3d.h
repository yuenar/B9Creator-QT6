/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    b9layout
 * 文件名:     triangle3d.h
 * 模块功能:   3D三角形类头文件，定义3D三角形相关类和接口
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#pragma once



#include <QVector3D>

class Triangle3D
{
public:
	QVector3D normal;
	QVector3D vertex[3];

	//specs
	QVector3D maxBound;
	QVector3D minBound;

	Triangle3D();
    ~Triangle3D();

	void UpdateBounds();
    void UpdateNormalFromGeom();//重新计算从顶点到法线
    bool IsBad(); //如果三角形没有“区域”或边界限返回true。
	bool ParallelXYPlane();
	bool IntersectsXYPlane(double realAltitude);

    static bool GreaterTopAltitude(Triangle3D* t1, Triangle3D* t2)
    {
        return (t1->maxBound.z() < t2->maxBound.z());
    }

    static bool GreaterBottomAltitude(Triangle3D* t1, Triangle3D* t2)
    {
        return (t1->minBound.z() < t2->minBound.z());
    }
};

 