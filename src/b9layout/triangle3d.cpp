/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    b9layout
 * 文件名:     triangle3d.cpp
 * 模块功能:   3D三角形类实现文件，包含3D三角形的具体实现
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#include "triangle3d.h"
#include "geometricfunctions.h"
#include <QDebug>

Triangle3D::Triangle3D()
{
	int i;
    normal*=0.0;//让法线位置在0,0,0

	for(i=0; i < 3; i++)
	{
        vertex[i]*= 0.0;//使顶点都驻留在0,0,0
	}

	maxBound.setX(-99999999.0);
	maxBound.setY(-99999999.0);
	maxBound.setZ(-99999999.0);

	minBound.setX(99999999.0);
	minBound.setY(99999999.0);
	minBound.setZ(99999999.0);

}

Triangle3D::~Triangle3D()
{

}


void Triangle3D::UpdateBounds()
{
	int i;
	
    //重置边界范围：
	maxBound.setX(-99999999.0);
	maxBound.setY(-99999999.0);
	maxBound.setZ(-99999999.0);

	minBound.setX(99999999.0);
	minBound.setY(99999999.0);
	minBound.setZ(99999999.0);

	for(i=0; i < 3; i++)
	{
        //最大值
		if(vertex[i].x() > maxBound.x())
		{
			maxBound.setX(vertex[i].x());
		}
		if(vertex[i].y() > maxBound.y())
		{
			maxBound.setY(vertex[i].y());
		}
		if(vertex[i].z() > maxBound.z())
		{
			maxBound.setZ(vertex[i].z());
		}

        //最小值
		if(vertex[i].x() < minBound.x())
		{
			minBound.setX(vertex[i].x());
		}
		if(vertex[i].y() < minBound.y())
		{
			minBound.setY(vertex[i].y());
		}
		if(vertex[i].z() < minBound.z())
		{
			minBound.setZ(vertex[i].z());
		}	
	}


}
void Triangle3D::UpdateNormalFromGeom()
{
    normal = QVector3D::crossProduct(vertex[1] - vertex[0], vertex[2] - vertex[0]);
    normal.normalize();
}

bool Triangle3D::IsBad()
{
	double d = Distance3D(maxBound,minBound);
    if(IsZero(d,0.00001))//可能的双重错误。
	{	
		return true;
	}
	return false;
}

bool Triangle3D::IntersectsXYPlane(double realAltitude)
{
	if(IsBad() || ParallelXYPlane())
	{	
		return false;
	}
	if(maxBound.z() > realAltitude && minBound.z() <= realAltitude)
	{
		return true;
	}

    //三角数据是没有边界可言：
	return false;
}

bool Triangle3D::ParallelXYPlane()
{
	if((vertex[0].z() == vertex[1].z())&&(vertex[0].z() == vertex[2].z()))
	{
		return true;
	}
	return false;
}
