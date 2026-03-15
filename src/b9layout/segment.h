/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    b9layout
 * 文件名:     segment.h
 * 模块功能:   分段类头文件，定义切片分段相关类和接口
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/
#pragma once

#include <QVector2D>


class Loop;


//切片时使用!
class Segment
{
public:
	QVector2D p1;
	QVector2D p2;

	QVector2D normal;

    //相邻
    Segment* trailingSeg; //定义为分段接触点1
    Segment* leadingSeg; //定义为分段接触点2

    //循环
	Loop* pLoop;

    bool CorrectPointOrder();//交换结束点以便匹配法线向量
	Segment();
	Segment(QVector2D point1, QVector2D point2);

	void FormNormal();
	bool chucked;

    //分类
    static bool lessthanX(Segment* i,Segment* j)
    {
        return (i->p1.x() < j->p1.x());
    }



private:


	



	
};
 
