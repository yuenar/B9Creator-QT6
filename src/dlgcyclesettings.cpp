/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    dialog
 * 文件名:     dlgcyclesettings.cpp
 * 模块功能:   循环设置对话框实现文件，包含循环设置的具体实现
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#include <QMessageBox>
#include <QValidator>
#include "dlgcyclesettings.h"
#include "ui_dlgcyclesettings.h"

DlgCycleSettings::DlgCycleSettings(PCycleSettings* pSettings, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgCycleSettings)
{
    ui->setupUi(this);
    m_pSettings = pSettings;
    m_pSettings->loadSettings(); // 从系统中载入
    updateDialog();
}

DlgCycleSettings::~DlgCycleSettings()
{
    delete ui;
}

void DlgCycleSettings::updateDialog()
{
    ui->spinBoxRaiseSpd1->setValue(m_pSettings->m_iRSpd1);
    ui->spinBoxLowerSpd1->setValue(m_pSettings->m_iLSpd1);
    ui->spinBoxCloseSpd1->setValue(m_pSettings->m_iCloseSpd1);
    ui->spinBoxOpenSpd1->setValue(m_pSettings->m_iOpenSpd1);

    ui->doubleSpinBoxOverlift1->setValue(m_pSettings->m_dOverLift1);
    ui->doubleSpinBoxBreathe1->setValue(m_pSettings->m_dBreatheClosed1);
    ui->doubleSpinBoxSettle1->setValue(m_pSettings->m_dSettleOpen1);

    ui->spinBoxRaiseSpd2->setValue(m_pSettings->m_iRSpd2);
    ui->spinBoxLowerSpd2->setValue(m_pSettings->m_iLSpd2);
    ui->spinBoxCloseSpd2->setValue(m_pSettings->m_iCloseSpd2);
    ui->spinBoxOpenSpd2->setValue(m_pSettings->m_iOpenSpd2);

    ui->doubleSpinBoxOverlift2->setValue(m_pSettings->m_dOverLift2);
    ui->doubleSpinBoxBreathe2->setValue(m_pSettings->m_dBreatheClosed2);
    ui->doubleSpinBoxSettle2->setValue(m_pSettings->m_dSettleOpen2);

    ui->doubleSpinBoxBTCutoff->setValue(m_pSettings->m_dBTClearInMM);

    ui->doubleSpinBoxHardZDown->setValue(m_pSettings->m_dHardZDownMM);
    ui->doubleSpinBoxZFlush->setValue(m_pSettings->m_dZFlushMM);
}

void DlgCycleSettings::stuffSettings()
{
    m_pSettings->m_iRSpd1 = ui->spinBoxRaiseSpd1->value();
    m_pSettings->m_iLSpd1 = ui->spinBoxLowerSpd1->value();
    m_pSettings->m_iCloseSpd1 = ui->spinBoxCloseSpd1->value();
    m_pSettings->m_iOpenSpd1  = ui->spinBoxOpenSpd1->value();
    m_pSettings->m_dOverLift1 = ui->doubleSpinBoxOverlift1->value();
    m_pSettings->m_dBreatheClosed1 = ui->doubleSpinBoxBreathe1->value();
    m_pSettings->m_dSettleOpen1 = ui->doubleSpinBoxSettle1->value();

    m_pSettings->m_iRSpd2 = ui->spinBoxRaiseSpd2->value();
    m_pSettings->m_iLSpd2 = ui->spinBoxLowerSpd2->value();
    m_pSettings->m_iCloseSpd2 = ui->spinBoxCloseSpd2->value();
    m_pSettings->m_iOpenSpd2  = ui->spinBoxOpenSpd2->value();
    m_pSettings->m_dOverLift2 = ui->doubleSpinBoxOverlift2->value();
    m_pSettings->m_dBreatheClosed2 = ui->doubleSpinBoxBreathe2->value();
    m_pSettings->m_dSettleOpen2 = ui->doubleSpinBoxSettle2->value();

    m_pSettings->m_dBTClearInMM = ui->doubleSpinBoxBTCutoff->value();

    m_pSettings->m_dHardZDownMM = ui->doubleSpinBoxHardZDown->value();
    m_pSettings->m_dZFlushMM = ui->doubleSpinBoxZFlush->value();
}

void DlgCycleSettings::on_buttonBox_accepted()
{
    stuffSettings();
    m_pSettings->saveSettings();
    close();
}

void DlgCycleSettings::on_buttonBox_rejected()
{
    close();
}

void DlgCycleSettings::on_pushButtonRestoreDefaults_clicked()
{
    m_pSettings->setFactorySettings();
    updateDialog();
}
