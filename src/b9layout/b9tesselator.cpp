/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    b9layout
 * 文件名:     b9tesselator.cpp
 * 模块功能:   三角剖分类实现文件，包含OpenGL三角剖分的具体实现
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期:  2026-03-15
 *    修改内容:  迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#include "b9tesselator.h"
#include <QtOpenGL>           // Qt OpenGL支持
#include "../OS_GL_Wrapper.h" // OpenGL包装器

// B9Tesselator构造函数 - 初始化三角剖分器
B9Tesselator::B9Tesselator()
{
    memoryFull = false;    // 初始化内存满标志为false
    CombineSize = 2048;    // 设置组合大小为2048
}

// B9Tesselator析构函数 - 清理资源
B9Tesselator::~B9Tesselator()
{
    unsigned long int i;    // 循环计数器

    // 释放所有顶点数据内存
    for(i = 0; i < numPolyVerts; i++)
    {
        delete[] polyverts[i];    // 删除每个顶点数组
    }
    delete[] polyverts;    // 删除顶点指针数组
}

// 三角剖分函数 - 输入polygonList必须按顺序 - 描绘填充值或void值
int B9Tesselator::Triangulate(const std::vector<QVector2D>* polygonList, std::vector<QVector2D> *triangleStrip)
{
    unsigned long int i;    // 循环计数器
    // 暂时禁用GLU三角剖分器功能
    return 0;
}
std::vector<QVector2D>* B9Tesselator::GetTrangleStrip()
{
    return triStrip;
}

//密铺回调
void CALLBACK tessBeginCB(GLenum which, void* user_data)
{
    B9Tesselator* tess = (B9Tesselator*)user_data;
    //密铺可以使用所有三角数据 条带行，扇形，或简单的三角形。
    tess->currentEnumType = which;

    if(which == GL_TRIANGLE_FAN)
    {
        tess->fanFirstTri = true;
        tess->fanSecondTri = false;
    }
    else if(which == GL_TRIANGLE_STRIP)
    {
        tess->stripFirstTri = true;
        tess->stripSecondTri = false;
        tess->stripCount = 0;
    }


}






void CALLBACK tessVertexCB(const GLvoid *data, void *user_data)
{

    GLdouble* vertData = (GLdouble*)data;
    QVector2D vert;
    vert.setX(vertData[0]);
    vert.setY(vertData[1]);
    B9Tesselator* tess = (B9Tesselator*)user_data;


    if(tess->currentEnumType == GL_TRIANGLES)
    {
         tess->GetTrangleStrip()->push_back(vert);
    }
    else if(tess->currentEnumType == GL_TRIANGLE_FAN)
    {

        if(tess->fanFirstTri)
        {
            tess->fanOriginVertex = vert;
            tess->fanFirstTri = false;
            tess->fanSecondTri = true;

            return;
        }
        else if(tess->fanSecondTri)
        {
            tess->fanFirstTri = false;
            tess->fanSecondTri = false;

            tess->prevVertex = vert;
        }
        else
        {
            tess->GetTrangleStrip()->push_back(tess->fanOriginVertex);
            tess->GetTrangleStrip()->push_back(tess->prevVertex);
            tess->GetTrangleStrip()->push_back(vert);
            tess->prevVertex = vert;
        }

    }
    else if(tess->currentEnumType == GL_TRIANGLE_STRIP)
    {
        if(tess->stripFirstTri)
        {

            tess->prevPrevVertex = vert;
            tess->stripFirstTri = false;
            tess->stripSecondTri = true;
            return;
        }
        else if(tess->stripSecondTri)
        {
            tess->prevVertex = vert;
            tess->stripFirstTri = false;
            tess->stripSecondTri = false;
        }
        else
        {
            if(tess->stripCount%2)//odd
            {
                tess->GetTrangleStrip()->push_back(tess->prevVertex);
                tess->GetTrangleStrip()->push_back(tess->prevPrevVertex);
                tess->GetTrangleStrip()->push_back(vert);

            }
            else
            {
                tess->GetTrangleStrip()->push_back(tess->prevPrevVertex);
                tess->GetTrangleStrip()->push_back(tess->prevVertex);
                tess->GetTrangleStrip()->push_back(vert);

            }
            tess->prevPrevVertex = tess->prevVertex;
            tess->prevVertex = vert;
        }
        tess->stripCount++;
    }
    else
    {
        qDebug() << "B9Tesselator: WARNING! un-implemented OpenGl Triangle Enum!";
    }




}

void CALLBACK tessCombineCB(const GLdouble newVertex[3], const GLdouble *neighborVertex[4],
                            const GLfloat neighborWeight[4], GLdouble **outData, void* user_data)
{
    B9Tesselator* tess = (B9Tesselator*)user_data;


    if(tess->CombineVertexIndex >= tess->CombineSize)
    {
        tess->memoryFull = true;
        return;
    }


    // 复制新的相交顶点到局部数组
    //因为新的顶点创建后已不能被密铺调用直到下次顶点回调时才行，所以它必须被拷贝到APP的安全位置暂存。
    //一旦gluTessEndPolygon()调用, 那么你可以安全地释放数组.
    tess->Combinevertices[tess->CombineVertexIndex][0] = newVertex[0];
    tess->Combinevertices[tess->CombineVertexIndex][1] = newVertex[1];
    tess->Combinevertices[tess->CombineVertexIndex][2] = newVertex[2];



    // 返回输出数据（顶点线等）
    *outData = tess->Combinevertices[tess->CombineVertexIndex];   // 分配新的相交顶点的地址

    tess->CombineVertexIndex++;  // 为下一个顶点数据提升索引值

}

void CALLBACK tessEndCB()
{

}


void CALLBACK tessErrorCB(GLenum errorCode, void* user_data)
{
    B9Tesselator* tess = (B9Tesselator*)user_data;
    qDebug() << "onTessError";
    tess->errorAcumulations++;
}









