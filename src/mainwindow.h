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

// Qt相关头文件包含
#include <QMainWindow>      // 主窗口基类
#include <QCloseEvent>      // 关闭事件
#include <QScreen>         // 屏幕相关
#include <QGuiApplication>  // GUI应用程序
#include <QSplashScreen>   // 启动画面

// 项目内部头文件包含
#include "logfilemanager.h"      // 日志文件管理器
#include "b9layout/b9layout.h"    // 布局模块
#include "b9slice/b9slice.h"      // 切片模块
#include "b9edit/b9edit.h"        // 编辑模块
#include "b9print.h"             // 打印模块
#include "b9terminal.h"          // 终端模块
#include "helpsystem.h"          // 帮助系统
#include "dlgprintprep.h"         // 打印准备对话框
#include "dlgcalbuildtable.h"     // 构建平台校准对话框
#include "dlgcalprojector.h"      // 投影机校准对话框

// 前向声明
class b9PrinterModelManager;  // 打印机型号管理器
class B9UpdateManager;        // 更新管理器

namespace Ui {
class MainWindow;    // UI类前向声明
}

// 主窗口类定义 - 应用程序的主界面
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);    // 构造函数
    ~MainWindow();                               // 析构函数

public slots:
    void handleW1Hide();    // 处理窗口1隐藏事件
    void handleW2Hide();    // 处理窗口2隐藏事件
    void handleW3Hide();    // 处理窗口3隐藏事件
    void handleW4Hide();    // 处理窗口4隐藏事件

    // 更新和文件操作相关槽函数
    void CheckForUpdates();        // 检查更新
    void OpenLayoutFile(QString file);   // 打开布局文件
    void OpenJobFile(QString file);       // 打开作业文件

    void showLogAndExit();         // 显示日志并退出
    
    // 显示各种功能窗口的槽函数
    void showTerminal();               // 显示终端窗口
    void showCalibrateBuildTable();     // 显示构建平台校准窗口
    void showCalibrateProjector();      // 显示投影机校准窗口
    void showCatalog();                 // 显示目录窗口
    void showPrinterCycles();           // 显示打印周期窗口
    void showLayout();                  // 显示布局窗口
    void showSlice();                   // 显示切片窗口
    void showEdit();                    // 显示编辑窗口
    void showPrint();                   // 显示打印窗口

    void AttemptPrintDialogWithFile(QString openFile);    // 尝试使用文件打开打印对话框

    void showAbout();                    // 显示关于对话框
    
    // 启动画面相关方法
    void setSplash(QSplashScreen * splash){m_pSplash = splash;}    // 设置启动画面
    void showSplash();                 // 显示启动画面
    void hideSplash(){if(m_pSplash!=NULL)m_pSplash->hide();}        // 隐藏启动画面

private slots:
    void on_commandLayout_clicked(bool checked);    // 布局命令点击事件
    void on_commandSlice_clicked(bool checked);     // 切片命令点击事件
    void on_commandPrint_clicked();                 // 打印命令点击事件
    void showHelp();                                // 显示帮助
    void doPrint();                                 // 执行打印

private:
    // 私有方法
    void closeEvent ( QCloseEvent * event );    // 关闭事件处理
    
    // 私有成员变量
    Ui::MainWindow *ui;                    // UI界面指针
    LogFileManager *pLogManager;            // 日志文件管理器指针
    bool m_bOpenLogOnExit;                 // 退出时打开日志标志
    HelpSystem m_HelpSystem;               // 帮助系统对象
    B9UpdateManager *m_pUpdateManager;     // 更新管理器指针
    QSplashScreen * m_pSplash;              // 启动画面指针
    
    // 各功能模块窗口指针
    B9Layout *pMW1;                        // 布局窗口指针
    B9Slice *pMW2;                         // 切片窗口指针
    B9Edit *pMW3;                          // 编辑窗口指针
    B9Print *pMW4;                         // 打印窗口指针
    
    // 核心数据对象指针
    CrushedPrintJob *m_pCPJ;               // 压缩打印作业指针
    B9Terminal *pTerminal;                 // 终端指针
    
    // 对话框和管理器指针
    DlgPrintPrep* m_pPrintPrep;            // 打印准备对话框指针
    b9PrinterModelManager* pPrinterModelManager;  // 打印机型号管理器指针
};

 
