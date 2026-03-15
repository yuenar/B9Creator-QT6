/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    dialog
 * 文件名:     dlgcalprojector.h
 * 模块功能:   投影仪校准对话框头文件，定义投影仪校准相关类和接口
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
class dlgCalProjector;
}

class dlgCalProjector : public QDialog
{
    Q_OBJECT
    
public:
    explicit dlgCalProjector(B9Terminal* pTerminal, QWidget *parent = 0);
    ~dlgCalProjector();
    
private:
    Ui::dlgCalProjector *ui;
    B9Terminal* m_pTerminal;

public slots:
    void findHome();
    void done();
    void onResetComplete();
    void onProjectorIsOn();
    void on_updateProjectorOutput(QString sText);
    void onStep1(bool checked);
    void onStep2(bool checked);
    void onStep3();
    void onStep4(bool checked);
    void onStep5(bool checked);
    void onStep6();

private slots:
    void on_comboBoxXPPixelSize_currentIndexChanged(int index);

protected:
    void closeEvent ( QCloseEvent * event );
};


