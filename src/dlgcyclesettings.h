/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    dialog
 * 文件名:     dlgcyclesettings.h
 * 模块功能:   循环设置对话框头文件，定义循环设置相关类和接口
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
class DlgCycleSettings;
}

class DlgCycleSettings : public QDialog
{
    Q_OBJECT
    
public:
    explicit DlgCycleSettings(PCycleSettings *pSettings, QWidget *parent = 0);
    ~DlgCycleSettings();
    
private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void on_pushButtonRestoreDefaults_clicked();

private:
    Ui::DlgCycleSettings *ui;
    PCycleSettings* m_pSettings;
    void updateDialog();
    void stuffSettings();
};
 