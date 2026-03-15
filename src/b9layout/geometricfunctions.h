/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    b9layout
 * 文件名:     geometricfunctions.h
 * 模块功能:   几何函数头文件，定义3D几何计算相关函数接口
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#pragma once


#include "math.h"
#include "qmath.h"
#include <QVector2D>
#include <QVector3D>


#define TO_RAD 0.01745329251994329
#define SIMPLIFY_THRESH 0.001

class QVector2D;
class QVector3D;
class Segment;

//实用原型
bool IsZero(double number, double tolerance);
bool PointsShare(QVector2D point1, QVector2D point2, double tolerance);
int PointLineCompare(QVector2D pointm, QVector2D dir, QVector2D quarrypoint);//返回-1,0,1为线的一侧，一行，和线的另一侧。
double Distance2D(QVector2D point1, QVector2D point2);
double Distance3D(QVector3D point1, QVector3D point2);
inline void RotateVector(QVector3D &vec, double angledeg, QVector3D axis)//单次选择旋转1个轴..
{
    double prevx;
    double prevy;
    double prevz;
    double cosval = qCos( angledeg * TO_RAD );
    double sinval = qSin( angledeg * TO_RAD );

    if(axis.x())
    {
        prevx = vec.x();
        prevy = vec.y();
        prevz = vec.z();
        vec.setY( prevy * cosval - prevz * sinval);
        vec.setZ( prevy * sinval + prevz * cosval);
    }

    if(axis.y())
    {
        prevx = vec.x();
        prevy = vec.y();
        prevz = vec.z();
        vec.setZ( prevz * cosval - prevx * sinval);
        vec.setX( prevz * sinval + prevx * cosval);
    }

    if(axis.z())
    {
        prevx = vec.x();
        prevy = vec.y();
        prevz = vec.z();
        vec.setX( prevx * cosval - prevy * sinval);
        vec.setY( prevx * sinval + prevy * cosval);
    }
}
bool VectorComponentsEqual(QVector3D &vec);
double VectorMaxComponentLength(QVector3D vec);
bool SegmentIntersection(QVector2D &result, QVector2D seg11, QVector2D seg12, QVector2D seg21, QVector2D seg22) ;
bool SegmentsAffiliated(Segment* seg1, Segment* seg2, double epsilon);
double MinAngleBetweenVectors(QVector3D a, QVector3D b);
 