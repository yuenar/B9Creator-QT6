/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    dialog
 * 文件名:     dlgcalbuildtable.h
 * 模块功能:   构建平台校准对话框头文件，定义构建平台校准相关类和接口
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
#include "b9terminal.h"

namespace Ui {
class dlgCalBuildTable;
}

class dlgCalBuildTable : public QDialog
{
    Q_OBJECT
    
public:
    explicit dlgCalBuildTable(B9Terminal* pTerminal, QWidget *parent = 0);
    ~dlgCalBuildTable();
    
public slots:
    void findHome();
    void goZero();
    void raiseUp();
    void done();
    void onResetComplete();
    void onMotionComplete();

    void on_Step1(bool checked);
    void on_Step2(bool checked);
    void on_Step3();
    void on_Step4();
    void on_Step5(bool checked);
    void on_Step6(bool checked);
    void on_Step7();
    void on_Step8(bool checked);

private:
    Ui::dlgCalBuildTable *ui;
    B9Terminal* m_pTerminal;
    bool bFindingHome;

protected:
    void closeEvent ( QCloseEvent * e );
};

 
