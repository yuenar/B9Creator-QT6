/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    dialog
 * 文件名:     dlgprintprep.h
 * 模块功能:   打印准备对话框头文件，定义打印准备对话框相关类和接口
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
class DlgPrintPrep;
}

class DlgPrintPrep : public QDialog
{
    Q_OBJECT

public:
    explicit DlgPrintPrep(CrushedPrintJob* pCPJ, B9Terminal* pTerminal, QWidget *parent = 0);
    ~DlgPrintPrep();

private slots:
    void on_comboBoxMaterial_currentIndexChanged(const QString &arg1);

    void on_pushButtonMatCat_clicked();

    void on_checkBoxMirrored_clicked(bool checked);

    void on_spinBoxLayersToPrint_valueChanged(int arg1);

    void on_pushButtonResetPrintAll_clicked();

    void updateTimes();

    void on_pushButtonStep3_clicked();

    void on_checkBoxStep2_clicked(bool checked);

    void on_checkBoxStep1_clicked(bool checked);

    void on_checkBoxStep4_clicked(bool checked);

    void on_checkBoxStep5_clicked(bool checked);

    void on_pushButtonReleaseCycle_clicked();

public:
    int m_iTattachMS;
    int m_iNumAttach;
    int m_iTbaseMS;
    int m_iToverMS;
    bool m_bMirrored;
    bool m_bDryRun;
    int m_iLastLayer;

private:
    Ui::DlgPrintPrep *ui;
    CrushedPrintJob *m_pCPJ;
    B9Terminal *m_pTerminal;
    bool m_bInitializing;
};

 