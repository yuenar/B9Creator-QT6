/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    print
 * 文件名:     b9projector.h
 * 模块功能:   投影仪头文件，定义投影仪控制相关类和接口
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#pragma once


#include <QWidget>
#include <QHideEvent>
#include <QImage>
#include <QColor>
#include <QByteArray>
#include "crushbitmap.h"

class B9Projector : public QWidget
{
	Q_OBJECT

public:
    B9Projector(bool bPrintWindow, QWidget *parent = 0, Qt::WindowFlags flags = Qt::WindowMinMaxButtonsHint|Qt::Window|Qt::WindowCloseButtonHint);
    ~B9Projector();

public slots:
    void showProjector(int x, int y, int w, int h);	// 显示自己，当我们发出信号

    void hideCursor(){setCursor(Qt::BlankCursor);}	//隐藏鼠标指针当发出信号

    void setShowGrid(bool bShow);					// 设置bShow为true，如果网格即将绘制
    void setStatusMsg(QString status);				// 要显示设置状态到消息
    void setCPJ(CrushedPrintJob *pCPJ);				//设置指向CMB的指针显示，如果为空则返回NULL
    bool clearTimedPixels(int iLevel);              //根据级别（0〜255），我们清除与TOVER数组值的所有像素<iLevel
    void createToverMap(int iRadius);
    void setXoff(int xOff){m_xOffset = xOff;drawAll();} //X补偿量的层图像
    void setYoff(int yOff){m_yOffset = yOff;drawAll();} //Y补偿量的层图像
    void createNormalizedMask(double XYPS=0.1, double dZ = 257.0, double dOhMM = 91.088); //当我们显示或调整时调用

signals:
    void eventHiding();             // 发出信号到父类，告知我们正在隐藏
    void hideProjector();			// 发出信号到父类，请求将我们隐藏

    void keyReleased (int iKey);	// 发出信号，即一个键被按下和释放
    void newGeometry (int iScreenNumber, QRect geoRect);

private:
    void keyReleaseEvent(QKeyEvent * pEvent);		//处理按键释放事件
    void mouseReleaseEvent(QMouseEvent * pEvent);	// 处理鼠标按钮释放事件
    void mouseMoveEvent(QMouseEvent * pEvent);		// 处理鼠标移动事件
    void paintEvent (QPaintEvent * pEvent);			//处理画板事件
    void resizeEvent ( QResizeEvent * event );      //处理调整大小事件

    void hideEvent(QHideEvent *event);
    void drawAll();			// 刷新整个屏幕
    void blankProjector();	// 填充黑色到整个背景，将覆盖以前的图象数据
    void drawGrid();		// 绘制使用mGridColor栅格图案
    void drawStatusMsg();	//绘制当前状态信息到投影屏幕上
    void drawCBM();			// draws the current CBM pointed to by mpCBM, returns if mpCBM is null

    void createToverMap0();
    void createToverMap1();
    void createToverMap2();
    void createToverMap3();
	
    bool m_bIsPrintWindow;  // 如果我们锁定到全屏窗口时显示，设置为真
    bool m_bGrid;			// 如果为真，网格会被绘制
	CrushedPrintJob* mpCPJ;	// CPJ to inflate CBM from
    QImage mImage;
    QImage mCurSliceImage;  // 当前标准化的切片，可能具有一些或所有像素被清零
    int m_iLevel;
    QImage m_NormalizedMask;
	QString mStatusMsg;
	int m_xOffset, m_yOffset;
    QByteArray m_vToverMap;

};

 