/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    b9layout
 * 文件名:     slice.h
 * 模块功能:   切片类头文件，定义3D打印切片相关类和接口
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#pragma once

#include "b9modelinstance.h"
#include "segment.h"
#include "loop.h"
#include "SlcExporter.h"
#include <vector>

class Triangle3D;
class Loop;

class Slice
{

public:
	

    Slice(double alt, int layerIndx);
	~Slice();

	void AddSegment(Segment* pSeg);
	
    int GenerateSegments(B9ModelInstance* inputInstance);//返回初始段的数值

    void SortSegmentsByX();

    void ConnectSegmentNeighbors(); //返回微移的数量
	
	int GenerateLoops();

    void Render();//OpenGL渲染代码 - 渲染全部切片.
    void RenderOutlines();
    void DebugRender(bool normals = true, bool connections = true, bool fills = true, bool outlines = true);//渲染可见调试信息


    //导出助手
	void WriteToSlc(SlcExporter* pslc);


    std::vector<Segment*> segmentList;//分段列表
	
	std::vector<Loop> loopList;
	int numLoops;

	double realAltitude;//in mm;
    int layerIndx;//在Job工程中指数层的进展（或类似结构）
    bool inProccessing;//多线程帮助...
    QImage* pImg;//对于rasturing帮助..
private:
	bool TestIntersection(QVector2D &vec,Segment* seg1, Segment* seg2);
    void GetTrianglesAroundZ(std::vector<Triangle3D*> &outList, double z);
    void GetSegmentsAroundX(std::vector<Segment*> &outList, double x);

};
 