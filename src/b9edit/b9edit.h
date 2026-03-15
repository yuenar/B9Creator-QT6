/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    b9edit
 * 文件名:     b9edit.h
 * 模块功能:   编辑器模块头文件，定义切片编辑器相关类和接口
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/
#pragma once


#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include "ui_b9edit.h"
#include "../crushbitmap.h"
#include "SliceEditView.h"
#include "aboutbox.h"
#include <QCloseEvent>


class B9Edit : public QMainWindow
{
	Q_OBJECT

public:
    B9Edit(QWidget *parent = 0, Qt::WindowFlags flags = Qt::Window, QString inputfile = "");
    ~B9Edit();

public slots:
    //文件
	void newJob();
    void openJob(QString infile = "");
	void saveJob();
	void saveJobAs();
    //导入
    void importSlices();//按钮接入 , 细分为 firstfile() or loadsvg()
	void importSlicesFromFirstFile(QString firstfile);
    void importSlicesFromSvg(QString file,double pixelsizemicrons = -1.0);
    void importSlicesFromSlc(QString file,double pixelsizemicrons = -1.0);
    void CancelLoading(); //当进度条过早取消时调用.
	 
    //导出
	void ExportToFolder();

    //相对路径
	void SetDir(QString dir);
	QString GetDir();
	
	void updateVersion(QString s){sVersion=s; cPJ.setVersion(s); dirtied = true; updateWindowTitle();}
	void updateName(QString s){sName=s; cPJ.setName(s); dirtied = true; updateWindowTitle();}
	void updateDescription(QString s){sDescription=s; cPJ.setDescription(s); dirtied = true; updateWindowTitle();}
	void updateXY(QString s){XYPixel=s; cPJ.setXYPixel(s); dirtied = true; updateWindowTitle();}
    void updateZ(QString s){ZLayer=s; cPJ.setZLayer(QString::number(s.toDouble()/1000.0,'f',6)); dirtied = true; updateWindowTitle();}
	void updateSliceIndicator();
	void updateWindowTitle();
	
     //切片编辑视图
	void ShowSliceWindow();
	void HideSliceWindow();

    void PatchJobData(QImage* pNewImg, int slicenumber);//被编辑视图调用，表示一个图像已被修改并需要再压缩到数据结构
	void SetDirty();

signals:
    void eventHiding();
    void selectedDirChanged(QString s);
	void setVersion(QString s);	
	void setName(QString s);
	void setDescription(QString s);
	void setXYPixel(QString s);
	void setZLayer(QString s);
	void setSliceIndicator(QString s);

protected:
	void closeEvent(QCloseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);

private:
    void hideEvent(QHideEvent *event);
    Ui::B9EditClass ui;

    //创建SliceEditView指针
	SliceEditView* pEditView;

    //创建aboutbox指针
    aboutbox* pAboutBox;

	QString sVersion;
	QString sName;
	QString sDescription;
	QString XYPixel;
	QString ZLayer;
	QString sDirPath;

	bool dirtied;
	bool continueLoading;
	QString currJobFile;

	CrushedPrintJob cPJ;

	int PromptSaveOnQuit();

}; 






