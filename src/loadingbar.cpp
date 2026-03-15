/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    utils
 * 文件名:     loadingbar.cpp
 * 模块功能:   加载进度条实现文件，包含进度条的具体实现
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#include "loadingbar.h"

////////////////////////////////////////
//Public
/////////////////////////////////////
LoadingBar::LoadingBar() : QDialog(NULL)
{
    SetupUI(true);
	SetupConnections();
}
LoadingBar::LoadingBar(int min, int max, bool autoshow) : QDialog(NULL)
{
    SetupUI(autoshow);
	setMax(max);
	setMin(min);
	SetupConnections();
}
LoadingBar::~LoadingBar()
{
}
///////////////////////////////////////
//Public Slots
//////////////////////////////////////
void LoadingBar::setProgress(qint64 fraction, qint64 total)
{
    progressBar->setMaximum(total);
    progressBar->setValue(fraction);
}

void LoadingBar::setMax(int max)
{
	progressBar->setMaximum(max);
}
void LoadingBar::setMin(int min)
{
	progressBar->setMinimum(min);
}
void LoadingBar::setValue(int val)
{
	progressBar->setValue(val);
}
void LoadingBar::setDescription(QString str)
{
	this->setWindowTitle(str);
}
void LoadingBar::useCancelButton(bool use)
{
    if(!use)
    {
        //if(horizontalLayout->findChild<QPushButton *>("pushButton"))
            horizontalLayout->removeWidget(cancelButton);
            cancelButton->hide();
    }
    else
    {
        //if(!horizontalLayout->findChild<QPushButton *>("pushButton"))
            horizontalLayout->addWidget(cancelButton);
            cancelButton->show();
    }
}

int LoadingBar::GetValue()
{
	return progressBar->value();
}

///////////////////////////////////
//Private
////////////////////////////////////
void LoadingBar::SetupUI(bool autoshow)
{
    setWindowFlags ( Qt::CustomizeWindowHint | Qt::WindowTitleHint);
	resize(364, 41);
	this->setMaximumHeight(41);
	 
	horizontalLayout = new QHBoxLayout(this);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    progressBar = new QProgressBar(this);
    progressBar->setObjectName(QString::fromUtf8("progressBar"));
    progressBar->setValue(24);

    horizontalLayout->addWidget(progressBar);

    cancelButton = new QPushButton(this);
    cancelButton->setObjectName(QString::fromUtf8("pushButton"));
	cancelButton->setText("Cancel");

    horizontalLayout->addWidget(cancelButton);


	setModal(true);
    if(autoshow)
        show();//创建时便自动展示
}
	

void LoadingBar::SetupConnections()
{
	QObject::connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
}
