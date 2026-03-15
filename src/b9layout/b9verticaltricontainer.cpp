/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    b9layout
 * 文件名:     b9verticaltricontainer.cpp
 * 模块功能:   垂直三角形容器实现文件，包含三角形垂直分层容器的具体实现
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期:  2026-03-15
 *    修改内容:  迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#include "b9verticaltricontainer.h"    // 垂直三角形容器头文件

// B9VerticalTriContainer构造函数 - 初始化垂直三角形容器
B9VerticalTriContainer::B9VerticalTriContainer()
{
    upContainer = NULL;    // 初始化上层容器指针为空
    downContainer = NULL;  // 初始化下层容器指针为空
}
