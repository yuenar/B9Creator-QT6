/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    b9layout
 * 文件名:     loop.h
 * 模块功能:   循环类头文件，定义切片循环相关类和接口
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
#include <QPoint>
#include "segment.h"
#include "../OS_GL_Wrapper.h"

class Slice;

class Loop
{
public:
	Loop(Segment* startingSeg, Slice* parentSlice);
	~Loop();
	Slice* pSlice;

	std::vector<Segment*> segListp;
    Segment* pOriginSeg;//该循环开始于这个段（指针）
	int numSegs;
	
	
    std::vector<QVector2D> polygonStrip;
    std::vector<QVector2D> triangleStrip;//由triangulator创建的有序列表中顶点将被渲染

	bool isfill;

    //调试标志位
    bool isComplete;//指示循环是否闭合完全。
	bool isPatched;
    double totalAngle;//环路（循环）周围的总角变化
	

	void ResetOrigin();
	
	int Grow();
	
	void AttachSegment(Segment* seg);

	bool SealHole(Segment* pLastSeg);
	
    void Simplify();//移除介于循环的最小段和密封起来的间隙。
	
	bool ThrowoutSmallestSegment();

    int NudgeSharedPoints();//寻找"self touching"分段点然后用这个方法微移(Nudges)
	
    int DetermineTypeBySides();

	void formPolygon();
	
    bool formTriStrip();

    void Destroy();//销毁循环中的所有分段。

    void RenderTriangles();//opengl渲染代码

	int CorrectDoubleBacks();

	bool AttemptSplitUp(Slice* pslice);

private:

};
