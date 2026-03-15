/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    b9layout
 * 文件名:     b9layoutprojectdata.h
 * 模块功能:   布局项目数据类头文件，定义布局项目数据相关类和接口
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#pragma once

#include <QStringList>
#include <QVector3D>
#include <QVector2D>
#include <QString>
#include <QList>
#include <QColor>
#include <QPixmap>
#include <QImage>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QSettings>
#include <QStandardPaths>
#include <QApplication>
#include <QMessageBox>
#include <QFileDialog>
#include "b9layout.h"

#define LAYOUT_FILE_VERSION 15

class B9ModelInstance;
class B9SupportStructure;
class B9Layout;
class B9LayoutProjectData : public QObject
{
	Q_OBJECT
public:
    B9LayoutProjectData();
    ~B9LayoutProjectData();

    //文件访问:
    void New();//清除了内部项目的数据，创建一个新使用默认值
    bool Open(QString filepath, bool withoutVisuals = false); //返回成功
    bool Save(QString filepath); //返回成功
    //结构访问:
    //获取
	bool IsDirtied();
    QString GetFileName();//无标题如果之前没有保存过
	QStringList GetModelFileList();
	QVector3D GetBuildSpace();
	double GetPixelSize();
    double GetPixelThickness();
	QVector2D GetResolution();
    double GetAttachmentSurfaceThickness(){return attachmentSurfaceThickness;}
    QString GetJobName();
    QString GetJobDescription();

    //设置
	void SetDirtied(bool dirt);

	void SetBuildSpaceSize(QVector3D size);
	void SetPixelSize(double size);
    void SetPixelThickness(double thick);
	void SetResolution(QVector2D dim);
    void SetAttachmentSurfaceThickness(double thick){attachmentSurfaceThickness = thick;}
    void SetJobName(QString);
    void SetJobDescription(QString);

	void CalculateBuildArea();
    void UpdateZSpace();//计算出的Z框的大小基于实例的边界
	
    B9Layout* pMain;
signals:
	void DirtChanged(bool dirt);
	void ProjectLoaded();

private:
	

	bool dirtied;
    QString mfilename;
	QStringList modelfilelist;
	QVector3D dimentions;
	QVector2D resolution;
	double xypixel;
	double zthick;
    double attachmentSurfaceThickness;
    QString jobExportName;//切片保存到工作文件时使用。
    QString jobExportDesc;
    QMessageBox *msgBox;

    void LoadDefaults();

    void PromptFindLostModel(B9ModelInstance* &pinst, QString modelPath);//提示用户寻找丢失模型，如果找到了返回为真。

    void StreamOutSupportInfo(B9SupportStructure* sup, QTextStream &out);
    void StreamInSupportInfo(B9ModelInstance* pinst, QTextStream &in, bool asFoundation = false);

};
 