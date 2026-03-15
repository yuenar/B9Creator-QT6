/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    b9layout
 * 文件名:     slicecontext.cpp
 * 模块功能:   切片上下文类实现文件，包含切片渲染相关的具体实现
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#include "slicecontext.h"
#include "../OS_GL_Wrapper.h"
#include "b9layoutprojectdata.h"
#include <QPoint>
#include <QVector2D>


SliceContext::SliceContext(QWidget *parent, B9LayoutProjectData *pmain) : QOpenGLWidget(parent)
{
    projectData = pmain;
    pSlice = NULL;
    // No need for setAutoBufferSwap in Qt6

}
SliceContext::~SliceContext()
{
}

QPixmap SliceContext::renderPixmap()
{
    // Create a QPixmap from the current OpenGL context
    return grab();
}




void SliceContext::SetSlice(Slice* slice)
{
	pSlice = slice;
}



void SliceContext::initializeGL()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glEnable(GL_BLEND);

    glDisable(GL_CULL_FACE);
    glDisable(GL_DEPTH_TEST);

    glViewport(0, 0, projectData->GetResolution().x(), projectData->GetResolution().y());
    glMatrixMode(GL_PROJECTION);
    // TODO: Replace with RHI orthographic projection
    // gluOrtho2D(-projectData->GetBuildSpace().x()/2.0,
    //            projectData->GetBuildSpace().x()/2.0,
    //            -projectData->GetBuildSpace().y()/2.0,
    //            projectData->GetBuildSpace().y()/2.0);
    // For now, set up basic orthographic projection manually
    glLoadIdentity();
    float left = -projectData->GetBuildSpace().x()/2.0f;
    float right = projectData->GetBuildSpace().x()/2.0f;
    float bottom = -projectData->GetBuildSpace().y()/2.0f;
    float top = projectData->GetBuildSpace().y()/2.0f;
    
    float orthoMatrix[16] = {
        2.0f/(right-left), 0, 0, 0,
        0, 2.0f/(top-bottom), 0, 0,
        0, 0, -2.0f/(1.0f-(-1.0f)), 0,
        -(right+left)/(right-left), -(top+bottom)/(top-bottom), -1.0f-(-1.0f)/(1.0f-(-1.0f)), 1
    };
    glMultMatrixf(orthoMatrix);
	glMatrixMode(GL_MODELVIEW);
}

void SliceContext::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();//重置矩阵运算
	
	if(pSlice)
	{
        pSlice->Render();
	}

}




