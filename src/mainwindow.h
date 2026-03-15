/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    core
 * 文件名:     mainwindow.h
 * 模块功能:   主窗口类头文件，定义应用程序主窗口界面
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/
#pragma once


#include <QMainWindow>
#include <QCloseEvent>
#include <QScreen>
#include <QGuiApplication>
#include <QSplashScreen>
#include "logfilemanager.h"
#include "b9layout/b9layout.h"
#include "b9slice/b9slice.h"
#include "b9edit/b9edit.h"
#include "b9print.h"
#include "b9terminal.h"
#include "helpsystem.h"
#include "dlgprintprep.h"
#include "dlgcalbuildtable.h"
#include "dlgcalprojector.h"

class b9PrinterModelManager;
class B9UpdateManager;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void handleW1Hide();
    void handleW2Hide();
    void handleW3Hide();
    void handleW4Hide();


    void CheckForUpdates();
    void OpenLayoutFile(QString file);
    void OpenJobFile(QString file);

    void showLogAndExit();
    void showTerminal();
    void showCalibrateBuildTable();
    void showCalibrateProjector();
    void showCatalog();
    void showPrinterCycles();
    void showLayout();
    void showSlice();
    void showEdit();
    void showPrint();

    void AttemptPrintDialogWithFile(QString openFile);

    void showAbout();
    void setSplash(QSplashScreen * splash){m_pSplash = splash;}
    void showSplash();
    void hideSplash(){if(m_pSplash!=NULL)m_pSplash->hide();}

private slots:
    void on_commandLayout_clicked(bool checked);
    void on_commandSlice_clicked(bool checked);
    void on_commandEdit_clicked(bool checked);
    void on_commandPrint_clicked();
    void showHelp();
    void doPrint();

private:

    void closeEvent ( QCloseEvent * event );
    Ui::MainWindow *ui;
    LogFileManager *pLogManager;
    bool m_bOpenLogOnExit;
    HelpSystem m_HelpSystem;
    B9UpdateManager *m_pUpdateManager;
    QSplashScreen * m_pSplash;
    B9Layout *pMW1;
    B9Slice *pMW2;
    B9Edit *pMW3;
    B9Print *pMW4;
    CrushedPrintJob *m_pCPJ;
    B9Terminal *pTerminal;
    DlgPrintPrep* m_pPrintPrep;
    b9PrinterModelManager* pPrinterModelManager;
};

 
