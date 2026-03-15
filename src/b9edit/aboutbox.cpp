/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    b9edit
 * 文件名:     aboutbox.cpp
 * 模块功能:   关于对话框实现文件，定义关于对话框相关类和接口
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/
#include "aboutbox.h"
#include "ui_aboutbox.h"

aboutbox::aboutbox(QWidget *parent, Qt::WindowFlags flags) :
    QWidget(parent, flags),
    ui(new Ui::aboutbox)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog| Qt::WindowTitleHint);


}

aboutbox::~aboutbox()
{
    delete ui;
}




void aboutbox::setText(QString content)
{

    ui->textBrowser->setText(content);

}
