/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    print
 * 文件名:     b9print.h
 * 模块功能:   打印功能头文件，定义3D打印相关类和接口
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
#include <QDateTime>
#include <QHideEvent>
#include <QSettings>
#include "helpsystem.h"
#include "b9terminal.h"

namespace Ui {
class B9Print;
}

class B9Print : public QDialog
{
    Q_OBJECT
    
public:
    explicit B9Print(B9Terminal *pTerm, QWidget *parent = 0);
    ~B9Print();
    // 如果打印预览不打开投影机电源。如果使用PrimaryMonitor我们强制输出到主监视器
    void print3D(CrushedPrintJob *pCPJ, int iXOff, int iYOff, int iTbase, int iTover, int iTattach, int iNumAttach = 1, int iLastLayer = 0, bool bPrintPreview = false, bool bUsePrimaryMonitor = false, bool bIsMirrored = false);
    
signals:
    void eventHiding();

public slots:
    void setProjMessage(QString sText);
    QString updateTimes();

private slots:
    void showHelp();
    void on_updateConnectionStatus(QString sText);
    void on_updateProjectorOutput(QString sText);
    void on_updateProjectorStatus(QString sText);
    void on_updateProjector(B9PrinterStatus::ProjectorStatus eStatus);
    void on_signalAbortPrint();

    void exposeTBaseLayer();
    void startExposeTOverLayers();
    void exposureOfCurTintLayerFinished();
    void exposureOfTOverLayersFinished();

    void on_pushButtonPauseResume_clicked();
    void on_pushButtonAbort_clicked();
    
private slots:
    void on_pushButtonAbort_clicked(QString sAbortText);

private:
    enum {PRINT_NO, PRINT_SETUP1, PRINT_SETUP2, PRINT_RELEASING, PRINT_EXPOSING, PRINT_ABORT, PRINT_DONE};
    enum {PAUSE_NO, PAUSE_WAIT, PAUSE_YES};

    void keyPressEvent(QKeyEvent * pEvent);		// 按键事件处理
    void hideEvent(QHideEvent *event);
    void closeEvent ( QCloseEvent * event );

    double curLayerIndexMM();
    void setSlice(int iSlice);

    HelpSystem m_HelpSystem;
    Ui::B9Print *ui;

    B9Terminal* m_pTerminal;
    CrushedPrintJob* m_pCPJ;
    int m_iTbase,  m_iTover, m_iTattach, m_iNumAttach;
    int m_iXOff, m_iYOff;
    int m_iPrintState;
    int m_iCurLayerNumber;
    int m_iLastLayer;
    double m_dLayerThickness;
    int m_iPaused;
    bool m_bAbort;
    QString m_sAbortMessage;
    double m_dTintMS;
    int m_iTintNum, m_iCurTintIndex, m_iMinimumTintMS,m_iMinimumTintMSWorstCase;
    QElapsedTimer m_vClock;
    QSettings m_vSettings;

};

 
