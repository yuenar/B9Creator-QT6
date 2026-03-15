/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    b9layout
 * 文件名:     segment.cpp
 * 模块功能:   分段类实现文件，包含切片分段的具体实现
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#include "segment.h"
#include "math.h"
#include "qmath.h"
#include "geometricfunctions.h"

#include <QVector2D>


Segment::Segment()
{
	p1.setX(0.0);
	p1.setY(0.0);

	p2.setX(0.0);
	p2.setY(0.0);

	normal.setX(0.0);
	normal.setY(0.0);

	trailingSeg = NULL;
	leadingSeg = NULL;

	pLoop = NULL;

	chucked = false;
}

Segment::Segment(QVector2D point1, QVector2D point2)
{
	p1.setX(point1.x());
	p1.setY(point1.y());

	p2.setX(point2.x());
	p2.setY(point2.y());

	FormNormal();

	trailingSeg = NULL;
	leadingSeg = NULL;

	pLoop = NULL;

	chucked = false;

}

void Segment::FormNormal()
{
	double dx = p2.x() - p1.x();
	double dy = p2.y() - p1.y();

	//double theta = atan2(dy,dx);
	normal.setX(-dy);
	normal.setY(dx);

	normal.normalize(); //unit vector
}



bool Segment::CorrectPointOrder()
{
	double p2x;
	double p2y;

	QVector2D center((p2.x() + p1.x())/2.0,(p2.y() + p1.y())/2.0);
    int side = PointLineCompare(center,normal, p1);//如果点在右则返回1，如果点在左则返回-1
	
	if(side < 0)
	{
        return 0; //我们希望点在左
	}
	else
	{
        //交换点数据
		p2x = p2.x();
		p2y = p2.y();

		p2.setX(p1.x());
		p2.setY(p1.y());

		p1.setX(p2x);
		p1.setY(p2y);

		return 1;
	}


}
