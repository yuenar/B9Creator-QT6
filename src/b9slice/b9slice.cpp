/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    b9slice
 * 文件名:     b9slice.cpp
 * 模块功能:   切片模块实现文件，包含切片处理的具体实现
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#include "b9slice.h"
#include "ui_b9slice.h"
#include "../b9layout/b9layoutprojectdata.h"
#include <QSettings>
#include <QMessageBox>
B9Slice::B9Slice(QWidget *parent, B9Layout* Main) :
    QMainWindow(parent),
    ui(new Ui::B9Slice)
{
    ui->setupUi(this);



    //设置厚度组合框到了reg值
    QSettings s;
    int indx;
    s.beginGroup("USERSLICE");
        indx = ui->thicknesscombo->findText(s.value("PIXEL_THICKNESS","50.8").toString());
    s.endGroup();

    if(indx != -1)
    {
        ui->thicknesscombo->blockSignals(true);
        ui->thicknesscombo->setCurrentIndex(indx);
        ui->thicknesscombo->blockSignals(false);
    }


    pMain = Main;


}

B9Slice::~B9Slice()
{
    delete ui;
}


//slots
void B9Slice::LoadLayout()
{

   pMain->New();


   //不需要视窗打开- 我们不应为显示列表分配内存
   //如果我们摆脱了切片窗口，这个功能就不需要做了

   currentLayout = pMain->Open(true);
   ui->CurrentLayout->setText(currentLayout);

   ui->xypixelsize->setText(QString().number(pMain->ProjectData()->GetPixelSize()));
   ui->imgsize->setText(QString().number(pMain->ProjectData()->GetResolution().x()) + ","
                        + QString().number(pMain->ProjectData()->GetResolution().y()));

   ui->jobname->setText(QFileInfo(currentLayout).baseName());


}


void B9Slice::Slice(){


    //检查是否有一个文件来切片...
    if(currentLayout.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("Please open a layout");
        msgBox.exec();
        return;
    }


    pMain->ProjectData()->SetJobName(ui->jobname->text());

    pMain->ProjectData()->SetJobDescription(ui->jobdesc->text());

    pMain->ProjectData()->SetPixelThickness(ui->thicknesscombo->currentText().toDouble());

    QSettings s;
    s.beginGroup("USERSLICE");
        s.setValue("PIXEL_THICKNESS",ui->thicknesscombo->currentText().toDouble());
    s.endGroup();


    pMain->SliceWorld();

}





//Events-----------------------------------------------


void B9Slice::hideEvent(QHideEvent *event)
{

    emit eventHiding();

    pMain->New();
    currentLayout = "";
    ui->CurrentLayout->setText(currentLayout);
    ui->jobdesc->setText("");
    ui->jobname->setText("");
    ui->xypixelsize->setText("");
    ui->imgsize->setText("");

    event->accept();
}
void B9Slice::showEvent(QHideEvent *event)
{

    pMain->New();
    currentLayout = "";
    ui->CurrentLayout->setText(currentLayout);
    ui->jobdesc->setText("");
    ui->jobname->setText("");
    ui->xypixelsize->setText("");
    ui->imgsize->setText("");

    event->accept();
}


