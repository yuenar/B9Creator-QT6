/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    b9layout
 * 文件名:     slicecontext.h
 * 模块功能:   切片上下文类头文件，定义切片渲染相关类和接口
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#pragma once


#include <QOpenGLWidget>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QKeyEvent>
#include <QTimer>
#include "b9layoutprojectdata.h"
#include "b9modelinstance.h"
#include "../b9supportstructure.h"
#include "sliceset.h"
#include "slice.h"

class SliceData;
class SliceContext : public QOpenGLWidget
{
	Q_OBJECT

public:
    SliceContext(QWidget *parent, B9LayoutProjectData* pmain);
     ~SliceContext();

	void SetSlice(Slice* slice);
void paintGL();
QPixmap renderPixmap();

private:
	void initializeGL();

	
	
	
    B9LayoutProjectData* projectData;
	Slice* pSlice;


};
 
