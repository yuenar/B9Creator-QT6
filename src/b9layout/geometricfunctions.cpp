/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    b9layout
 * 文件名:     geometricfunctions.cpp
 * 模块功能:   几何函数实现文件，包含3D几何计算的具体实现
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#include "geometricfunctions.h"
#include "math.h"
#include <algorithm>
#include "qmath.h"
#include "segment.h"
#include <QVector2D>
#include <QVector3D>

//应用函数实现
bool IsZero(double number, double tolerance)
{
	if(fabs(number) <= tolerance)
	{
		return true;
	}
	return false;
}

bool PointsShare(QVector2D point1, QVector2D point2, double tolerance)
{

	if(IsZero(point2.x() - point1.x(), tolerance) && IsZero(point2.y() - point1.y(),tolerance))
	{
		return true;
	}
	return false;
}
int PointLineCompare(QVector2D pointm, QVector2D dir, QVector2D quarrypoint)//如果点在右则返回1，如果点在左，则返回-1
{
	//double MAx = (quarrypoint.x() - pointm.x());
	//double MAy = (quarrypoint.y() - pointm.y());

	double position = (dir.x()*(quarrypoint.y() - pointm.y())) - (dir.y()*(quarrypoint.x() - pointm.x()));
	return -int(ceil(position));
}

bool SegmentIntersection(QVector2D &result, QVector2D seg11, QVector2D seg12, QVector2D seg21, QVector2D seg22)
{
    // 保存这个数值以便快速访问并简化公式到代码的转换
	double x1 = seg11.x(), x2 = seg12.x(), x3 = seg21.x(), x4 = seg22.x();
	double y1 = seg11.y(), y2 = seg12.y(), y3 = seg21.y(), y4 = seg22.y();
 
	double d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
    //如果d是零，没有交集
	if (d == 0) return NULL;

    // 获取x和y的值
	double pre = (x1*y2 - y1*x2), post = (x3*y4 - y3*x4);
	double x = ( pre * (x3 - x4) - (x1 - x2) * post ) / d;
	double y = ( pre * (y3 - y4) - (y1 - y2) * post ) / d;
 
    // 检查，x和y坐标是否都在两条轴线内里
	if ( x < std::min(x1, x2) || x > std::max(x1, x2) ||
	x < std::min(x3, x4) || x > std::max(x3, x4) ) return false;
	if ( y < std::min(y1, y2) || y > std::max(y1, y2) ||
	y < std::min(y3, y4) || y > std::max(y3, y4) ) return false;
 
    // 返回交点坐标
	result.setX(x);
	result.setY(y);
	return true;
}

bool SegmentsAffiliated(Segment* seg1, Segment* seg2, double epsilon)
{
	if(Distance2D(seg1->p2,seg2->p1) < epsilon || Distance2D(seg1->p1,seg2->p1) < epsilon || Distance2D(seg1->p2,seg2->p2) < epsilon || Distance2D(seg1->p1,seg2->p2) < epsilon)
			return true;

	return false;
}

double Distance2D(QVector2D point1, QVector2D point2)
{
	return sqrt( pow((point2.x()-point1.x()),2) + pow((point2.y()-point1.y()),2));
}

double Distance3D(QVector3D point1, QVector3D point2)
{
	return sqrt( pow((point2.x()-point1.x()),2) + pow((point2.y()-point1.y()),2) + pow((point2.z()-point1.z()),2));
}

bool VectorComponentsEqual(QVector3D &vec)
{
    if((vec.x() == vec.y()) && vec.x() == vec.z())
        return true;

    return false;
}

//返回向量（容器）中的最大组件的长度。
double VectorMaxComponentLength(QVector3D vec)
{
    double max = -1.0;

    if(abs(vec.x()) > max)
        max = abs(vec.x());
    if(abs(vec.y()) > max)
        max = abs(vec.y());
    if(abs(vec.z()) > max)
        max = abs(vec.z());


    return max;
}

//返回两个三维向量的角度
double MinAngleBetweenVectors(QVector3D a, QVector3D b)
{
    double dot = QVector3D::dotProduct(a,b);
    if(dot > 1)
        dot = 1;
    if(dot < -1)
        dot = -1;

    return acos(dot);
}
