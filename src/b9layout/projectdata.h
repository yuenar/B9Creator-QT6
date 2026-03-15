/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    b9layout
 * 文件名:     projectdata.h
 * 模块功能:   项目数据类头文件，定义布局项目数据相关类和接口
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期:  2026-03-15
 *    修改内容:  迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#pragma once

// Qt相关头文件包含
#include <QStringList>    // 字符串列表
#include <QVector3D>      // 3D向量
#include <QVector2D>      // 2D向量
#include <vector>         // STL向量容器

// 项目内部头文件
#include "b9layout.h"      // 布局类

// 布局文件版本定义
#define LAYOUT_FILE_VERSION 14

// 前向声明
class B9Layout;

// ProjectData类 - 项目数据管理类，继承自QObject
class ProjectData : public QObject
{
	Q_OBJECT
public:
	ProjectData();    // 构造函数
	~ProjectData();   // 析构函数

	// 文件访问相关方法
	void New();    // 清空内部项目数据，创建一个带有默认值的新项目
	bool Open(QString filepath);    // 打开项目文件，返回成功状态
	bool Save(QString filepath);    // 保存项目文件，返回成功状态

	// 结构访问相关方法
	// 获取方法
	bool IsDirtied();    // 检查项目是否已修改
	QString GetFileName();    // 获取文件名（如果未保存则返回"untitled"）
	QStringList GetModelFileList();    // 获取模型文件列表
	QVector3D GetBuildSpace();    // 获取构建空间尺寸
	double GetPixelSize();    // 获取像素尺寸
    double GetPixelThickness();    // 获取像素厚度
	QVector2D GetResolution();    // 获取分辨率
    QString GetJobName();    // 获取作业名称
    QString GetJobDescription();    // 获取作业描述

	// 设置方法
	void SetDirtied(bool dirt);    // 设置修改状态

	void SetBuildSpaceSize(QVector3D size);    // 设置构建空间尺寸
	void SetPixelSize(double size);    // 设置像素尺寸
    void SetPixelThickness(double thick);    // 设置像素厚度
	void SetResolution(QVector2D dim);    // 设置分辨率
    void SetJobName(QString);    // 设置作业名称
    void SetJobDescription(QString);    // 设置作业描述

	void CalculateBuildArea();    // 计算构建区域
	void UpdateZSpace();    // 根据实例边界计算Z轴空间大小
	
    B9Layout* pMain;    // 主布局指针

signals:
	void DirtChanged(bool dirt);    // 修改状态改变信号
	void ProjectLoaded();    // 项目加载完成信号

private:
	// 私有成员变量
	bool dirtied;    // 修改状态标志
    QString mfilename;    // 文件名
	QStringList modelfilelist;    // 模型文件列表
	QVector3D dimentions;    // 尺寸（3D向量）
	QVector2D resolution;    // 分辨率（2D向量）
	double xypixel;    // XY像素尺寸
	double zthick;    // Z轴厚度
    QString jobExportName;    // 作业导出名称（用于切片到作业文件时）
    QString jobExportDesc;    // 作业导出描述

	void SetDefaults();    // 设置默认值
};

 