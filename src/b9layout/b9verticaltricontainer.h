/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    b9layout
 * 文件名:     b9verticaltricontainer.h
 * 模块功能:   垂直三角形容器头文件，定义三角形垂直分层容器相关类和接口
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期:  2026-03-15
 *    修改内容:  迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#ifndef B9VERTICALTRICONTAINER_H
#define B9VERTICALTRICONTAINER_H

// STL相关头文件
#include <vector>    // STL向量容器

// 项目内部头文件
#include "triangle3d.h"    // 3D三角形类

// 三角形容器容差定义
#define TRICONTAINER_PLAY 0.001    // 三角形容器的容差值

// B9VerticalTriContainer类 - 垂直三角形容器，用于按Z轴分层管理三角形
class B9VerticalTriContainer
{
public:
    B9VerticalTriContainer();    // 构造函数

    // 容器的Z轴范围
    double maxZ;    // 最大Z值
    double minZ;    // 最小Z值

    // 相邻容器指针
    B9VerticalTriContainer* upContainer;    // 上层容器指针
    B9VerticalTriContainer* downContainer;  // 下层容器指针

    // 三角形列表
    std::vector<Triangle3D*> tris;    // 存储在此容器中的三角形指针列表

    // 检查三角形是否适合此容器
    bool TriangleFits(Triangle3D* tri)
    {
        // 测试三角形数据是否有任何部分在此容器中
        if((tri->maxBound.z() >= (minZ - TRICONTAINER_PLAY))    // 三角形最大Z值大于容器最小Z值减去容差
          &&
          (tri->minBound.z() <= (maxZ + TRICONTAINER_PLAY)))    // 三角形最小Z值小于容器最大Z值加上容差

           return true;    // 三角形适合此容器

        return false;    // 三角形不适合此容器
    }

};

#endif // B9VERTICALTRICONTAINER_H
