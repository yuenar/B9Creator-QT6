/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    utils
 * 文件名:     loadingbar.h
 * 模块功能:   加载进度条头文件，定义进度条相关类和接口
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#pragma once


#include <QDialog>
#include <QWidget>
#include <QHBoxLayout>
#include <QProgressBar>
#include <QPushButton>


class LoadingBar : public QDialog
{
	Q_OBJECT

public:
    LoadingBar();
    LoadingBar(int min, int max, bool autoshow = true);
	~LoadingBar();

public slots:
	void setMax(int max);
	void setMin(int min);
	void setValue(int val);
	void setDescription(QString str);
    void setProgress(qint64 fraction, qint64 total);
    void useCancelButton(bool use);
	int GetValue();

private:
    void SetupUI(bool autoshow);
	void SetupConnections();
	QHBoxLayout* horizontalLayout;
	QProgressBar* progressBar;
	QPushButton* cancelButton;
};
 
