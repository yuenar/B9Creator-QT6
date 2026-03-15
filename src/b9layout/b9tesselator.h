/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    b9layout
 * 文件名:     b9tesselator.h
 * 模块功能:   三角剖分类头文件，定义OpenGL三角剖分相关类和接口
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期:  2026-03-15
 *    修改内容:  迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#pragma once

#ifndef CALLBACK
#define CALLBACK
#endif

// Qt相关头文件包含
#include <QVector2D>      // 2D向量类
#include <vector>         // STL向量容器
#include <QtOpenGL>       // Qt OpenGL支持
#include "../OS_GL_Wrapper.h"    // OpenGL包装器

// 项目内部头文件
#include "loop.h"         // 循环相关定义

// 前向声明
class B9Tesselator;

// GLU_TESS的CALLBACK函数声明
// 注意：必须使用CALLBACK声明
void CALLBACK tessBeginCB(GLenum which, void *user_data);    // 三角剖分开始回调
void CALLBACK tessEndCB();    // 三角剖分结束回调
void CALLBACK tessErrorCB(GLenum errorCode, void* user_data);    // 三角剖分错误回调
void CALLBACK tessVertexCB(const GLvoid *data, void *user_data);    // 三角剖分顶点回调
void CALLBACK tessCombineCB(const GLdouble newVertex[3], const GLdouble *neighborVertex[4],
                            const GLfloat neighborWeight[4], GLdouble **outData, void* user_data);    // 三角剖分组合回调





// B9Tesselator类 - OpenGL三角剖分器
class B9Tesselator
{
public:
    B9Tesselator();    // 构造函数
    ~B9Tesselator();   // 析构函数

    // 输入polygonList必须按顺序 - 描绘填充值或void值
    int Triangulate(const std::vector<QVector2D> *polygonList, std::vector<QVector2D> *triangleStrip);    // 三角剖分函数
    std::vector<QVector2D>* GetTrangleStrip();    // 获取三角条带

    // 公共成员变量 - 三角剖分状态信息
    GLenum currentEnumType;           // 当前枚举类型
    bool fanFirstTri;                 // 扇形第一个三角形标志
    bool fanSecondTri;                // 扇形第二个三角形标志
    bool stripFirstTri;               // 条带第一个三角形标志
    bool stripSecondTri;              // 条带第二个三角形标志
    unsigned long int stripCount;      // 条带计数
    QVector2D fanOriginVertex;        // 扇形原点顶点
    QVector2D prevVertex;             // 前一个顶点
    QVector2D prevPrevVertex;         // 前前一个顶点

    // 为三角剖分器建立48兆字节的缓冲区
    unsigned int CombineSize;         // 组合大小
    GLdouble Combinevertices[2048][6]; // 二维数组来存储新创建的顶点（X，Y，Z，R，G，B）通过联合回调
    unsigned int CombineVertexIndex;   // 组合顶点索引
    bool memoryFull;                  // 内存满标志

    int errorAcumulations;            // 错误累积计数

private:
    // 私有成员变量
    unsigned long int numPolyVerts;    // 多边形顶点数量
    GLdouble ** polyverts;            // 指向所有的顶点数据的指针
    std::vector<QVector2D>* triStrip; // 三角条带向量指针
};

 
