/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    b9edit
 * 文件名:     DrawingContext.h
 * 模块功能:   绘图上下文头文件，定义切片编辑绘图相关类和接口
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/
#pragma once

#include <QtGui>
#include <QWidget>
#include <QImage>

class SliceEditView;
class DrawingContext : public QWidget
{
	Q_OBJECT
public:
	DrawingContext(QWidget *parent = 0);
	~DrawingContext();

	SliceEditView* pEditView;
	QImage* pActiveImage;
	QImage* pLowerImage;

    QString currDrawTool;//字符串指示当前所选的绘制工具.
    QString currSupportTool;//字符串指示当前所选的支撑工具.

	int PenWidth;
	int supportSize;
	bool deletemode;
	bool fastsupportmode;
	void SetPenColor(QColor color);
	void SetPenWidth(int w);

public slots:
    void SetUpperImg(QImage* img); //显示所传递图像到屏幕.
    void SetLowerImg(QImage* img); //设置要显示的图像在顶层之下..
	void GenerateLogicImage();
	void GenerateGreenImage();

protected:
	 void mousePressEvent(QMouseEvent *event);
     void mouseMoveEvent(QMouseEvent *event);
     void mouseReleaseEvent(QMouseEvent *event);
     void paintEvent(QPaintEvent *event);

private:
	void drawLineTo(const QPoint &endPoint);

	
    bool scribbling; //当按下鼠标按键，并且涂鸦
	
    QColor PenColor;
	QPoint lastPoint;
};
 
