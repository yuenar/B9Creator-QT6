/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    dialog
 * 文件名:     dlgcalbuildtable.cpp
 * 模块功能:   构建平台校准对话框实现文件，包含构建平台校准的具体实现
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#include "dlgcalbuildtable.h"
#include "ui_dlgcalbuildtable.h"
#include <QMessageBox>

dlgCalBuildTable::dlgCalBuildTable(B9Terminal* pTerminal,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgCalBuildTable)
{
    m_pTerminal = pTerminal;
    ui->setupUi(this);
    connect(m_pTerminal, SIGNAL(HomeFound()), this, SLOT(onResetComplete()));
    connect(m_pTerminal, SIGNAL(ZMotionComplete()),this, SLOT(onMotionComplete()));

    bFindingHome = true;
    ui->checkBoxStep2->setEnabled(false);
    ui->pushButtonHomeStep3->setEnabled(false);
    ui->pushButtonZeroStep4->setEnabled(false);
    ui->checkBoxStep5->setEnabled(false);
    ui->checkBoxStep6->setEnabled(false);
    ui->pushButtonRaiseUpStep7->setEnabled(false);
    ui->checkBoxStep8->setEnabled(false);
}

dlgCalBuildTable::~dlgCalBuildTable()
{
    delete ui;
}

void dlgCalBuildTable::closeEvent(QCloseEvent *)
{
    done();
}

void dlgCalBuildTable::done()
{
    m_pTerminal->rcSendCmd("s");
    this->close();
}

void dlgCalBuildTable::on_Step1(bool checked)
{
    ui->checkBoxStep2->setEnabled(checked);
}

void dlgCalBuildTable::on_Step2(bool checked)
{
    ui->checkBoxStep1->setEnabled(!checked);
    ui->pushButtonHomeStep3->setEnabled(checked);
}

void dlgCalBuildTable::on_Step3()
{
    ui->lineEditStatus->setText("Printer in motion, please wait...");
    findHome();
    ui->checkBoxStep2->setEnabled(false);
    ui->pushButtonHomeStep3->setEnabled(false);
    ui->pushButtonZeroStep4->setEnabled(true);
    ui->checkBoxStep5->setEnabled(false);
}

void dlgCalBuildTable::on_Step4()
{
    ui->lineEditStatus->setText("Printer in motion, please wait...");
    goZero();
    ui->pushButtonZeroStep4->setEnabled(false);
    ui->checkBoxStep5->setEnabled(false);
}

void dlgCalBuildTable::on_Step5(bool checked)
{
    ui->checkBoxStep6->setEnabled(checked);
}

void dlgCalBuildTable::on_Step6(bool checked)
{
    ui->checkBoxStep5->setEnabled(!checked);
    ui->pushButtonRaiseUpStep7->setEnabled(checked);
}

void dlgCalBuildTable::on_Step7()
{
    ui->lineEditStatus->setText("Printer in motion, please wait...");
    raiseUp();
    ui->checkBoxStep6->setEnabled(false);
    ui->pushButtonRaiseUpStep7->setEnabled(false);
    ui->checkBoxStep8->setEnabled(false);
}

void dlgCalBuildTable::on_Step8(bool checked)
{
    ui->pushButtonDone->setText("Finished!");
    ui->pushButtonDone->setEnabled(checked);
}

void dlgCalBuildTable::findHome()
{    
    this->setEnabled(false);
    m_pTerminal->rcResetHomePos();
}

void dlgCalBuildTable::goZero()
{   
    m_pTerminal->rcSendCmd("v100");
    m_pTerminal->rcSendCmd("g0");
}

void dlgCalBuildTable::raiseUp()
{   
    m_pTerminal->rcSendCmd("g8135");
}


void dlgCalBuildTable::onResetComplete()
{    
    ui->lineEditStatus->setText("Ready...");
    this->setEnabled(true);
}

void dlgCalBuildTable::onMotionComplete()
{
    if(bFindingHome){bFindingHome=false;return;}
    ui->lineEditStatus->setText("Ready...");
    if(!ui->checkBoxStep5->isChecked())
        ui->checkBoxStep5->setEnabled(true);
    else
        ui->checkBoxStep8->setEnabled(true);
}
