/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    utils
 * 文件名:     OS_GL_Wrapper.h
 * 模块功能:   OpenGL包装器头文件，定义OpenGL相关函数和接口
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/

//OpenGL has different headers across different platforms - this header adjusts accordingly
//When you need to use openGL, include this header.
#pragma once


// Qt6 OpenGL headers - avoid GLU conflicts
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <GL/gl.h>

// Basic OpenGL constants and types
#ifndef GL_MULTISAMPLE
#define GL_MULTISAMPLE 0x809D
#endif

 
