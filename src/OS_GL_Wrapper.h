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


// Qt6 OpenGL headers - use modern OpenGL approach
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QOpenGLContext>

// Basic OpenGL constants and types for compatibility
#ifndef GL_MULTISAMPLE
#define GL_MULTISAMPLE 0x809D
#endif

// OpenGL constants that may be needed
#ifndef GL_TRIANGLES
#define GL_TRIANGLES 0x0004
#endif
#ifndef GL_LINES
#define GL_LINES 0x0001
#endif
#ifndef GL_BLEND
#define GL_BLEND 0x0BE2
#endif
#ifndef GL_CULL_FACE
#define GL_CULL_FACE 0x0B44
#endif
#ifndef GL_DEPTH_TEST
#define GL_DEPTH_TEST 0x0B71
#endif
#ifndef GL_NORMALIZE
#define GL_NORMALIZE 0x0BA1
#endif
#ifndef GL_LINE_SMOOTH
#define GL_LINE_SMOOTH 0x0B20
#endif
#ifndef GL_COLOR_MATERIAL
#define GL_COLOR_MATERIAL 0x0B57
#endif
#ifndef GL_LIGHTING
#define GL_LIGHTING 0x0B50
#endif
#ifndef GL_LIGHT0
#define GL_LIGHT0 0x4000
#endif
#ifndef GL_SRC_ALPHA
#define GL_SRC_ALPHA 0x0302
#endif
#ifndef GL_ONE_MINUS_SRC_ALPHA
#define GL_ONE_MINUS_SRC_ALPHA 0x0303
#endif
#ifndef GL_DST_ALPHA
#define GL_DST_ALPHA 0x0304
#endif
#ifndef GL_COLOR_BUFFER_BIT
#define GL_COLOR_BUFFER_BIT 0x00004000
#endif

 
