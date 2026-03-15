/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    core
 * 文件名:     mainwindow.cpp
 * 模块功能:   主窗口类实现文件，包含应用程序主窗口的具体实现
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "OS_Wrapper_Functions.h"
#include "b9printermodelmanager.h"
#include "b9updatemanager.h"
#include "b9supportstructure.h"
#include "b9layout/b9layoutprojectdata.h"
#include <QDebug>

// B9Creator版本信息定义
#define B9CVERSION "Version 1.6.0     Copyright 2013 B9Creations, LLC     www.b9creator.com\n "

// MainWindow构造函数 - 初始化主窗口
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // 设置应用程序身份信息
    QCoreApplication::setOrganizationName("B9Creations, LLC");      // 设置组织名称
    QCoreApplication::setOrganizationDomain("b9creator.com");        // 设置组织域名
    QCoreApplication::setApplicationName("B9Creator");              // 设置应用程序名称

    ui->setupUi(this);    // 设置UI界面
    this->setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);    // 设置窗口为固定大小

    // 创建日志文件管理器 - 总是在主窗口构造时设置
    pLogManager = new LogFileManager(CROSS_OS_GetDirectoryFromLocationTag("DOCUMENTS_DIR") + "/B9Creator_LOG.txt", "B9Creator Log Entries");
    m_bOpenLogOnExit = false;    // 初始化退出时打开日志标志
    
    // 输出程序启动信息和相关目录信息
    qDebug() << "Program Start";
    qDebug() << "Relevent Used Application Directories";
    qDebug() << "   EXECUTABLE_DIR: " << CROSS_OS_GetDirectoryFromLocationTag("EXECUTABLE_DIR");    // 可执行文件目录
    qDebug() << "   APPLICATION_DIR: " << CROSS_OS_GetDirectoryFromLocationTag("APPLICATION_DIR");  // 应用程序目录
    qDebug() << "   TEMP_DIR: " << CROSS_OS_GetDirectoryFromLocationTag("TEMP_DIR");                // 临时文件目录
    qDebug() << "   DOCUMENTS_DIR: " << CROSS_OS_GetDirectoryFromLocationTag("DOCUMENTS_DIR");      // 文档目录

    // 创建更新管理器
    m_pUpdateManager = new B9UpdateManager(this);

    // 注释掉的版本迁移功能 - 用于处理从先前安装版本的文件移动、删除等操作
    //m_pUpdateManager->TransitionFromPreviousVersions();

    // 注释掉的自动更新检查调度 - 在1秒后自动检查更新
    //QTimer::singleShot(1000,m_pUpdateManager,SLOT(AutoCheckForUpdates()));


    // 创建打印机型号管理器 - 不导入定义，使用默认打印机
    pPrinterModelManager = new b9PrinterModelManager(this);
    // 注释掉的打印机定义导入功能
    //pPrinterModelManager->ImportDefinitions(CROSS_OS_SPOT + "/B9Printer.DEF")    // 导入打印机定义
    //pPrinterModelManager->ImportMaterials();    // 导入材料信息（查看mat文件和用户注册表）

    // 导入预制的STL文件用于支撑结构
    B9SupportStructure::ImportAttachmentDataFromStls();    // 从STL文件导入附件数据
    B9SupportStructure::FillRegistryDefaults();    // 如果需要，填充注册表默认值

    // 创建终端对象
    pTerminal = new B9Terminal();
    pTerminal->setEnabled(true);    // 启用终端

    // 连接终端信号到状态栏
    connect(pTerminal, SIGNAL(updateConnectionStatus(QString)), ui->statusBar, SLOT(showMessage(QString)));

    ui->statusBar->showMessage(MSG_SEARCHING);    // 在状态栏显示搜索消息

    // 创建各个功能模块窗口
    pMW1 = new B9Layout(0);    // 创建布局窗口
    pMW2 = new B9Slice(0,pMW1);    // 创建切片窗口，传入布局窗口作为参数
    pMW3 = new B9Edit(0);      // 创建编辑窗口
    pMW4 = new B9Print(pTerminal, 0);    // 创建打印窗口，传入终端作为参数

    // 创建压缩打印作业对象
    m_pCPJ = new CrushedPrintJob;

    // 连接各窗口的隐藏信号到对应的处理槽函数
    connect(pMW1, SIGNAL(eventHiding()), this, SLOT(handleW1Hide()));    // 布局窗口隐藏信号
    connect(pMW2, SIGNAL(eventHiding()), this, SLOT(handleW2Hide()));    // 切片窗口隐藏信号
    connect(pMW3, SIGNAL(eventHiding()), this, SLOT(handleW3Hide()));    // 编辑窗口隐藏信号
    connect(pMW4, SIGNAL(eventHiding()), this, SLOT(handleW4Hide()));    // 打印窗口隐藏信号
}

// MainWindow析构函数 - 清理资源
MainWindow::~MainWindow()
{
    delete m_pCPJ;    // 删除压缩打印作业对象
    delete pTerminal;    // 删除终端对象

    // 如果设置了退出时打开日志，则在文件夹中打开日志文件
    if(m_bOpenLogOnExit)
        pLogManager->openLogFileInFolder();    // 查看日志文件的位置
    delete pLogManager;    // 删除日志管理器，清理所有已记录的消息
    delete ui;    // 删除UI对象
    delete pPrinterModelManager;    // 清空打印机模型管理器
    B9SupportStructure::FreeAttachmentData();    // 释放附件数据
    
    // 删除各功能模块窗口
    delete pMW1;    // 删除布局窗口
    delete pMW2;    // 删除切片窗口
    delete pMW3;    // 删除编辑窗口
    delete pMW4;    // 删除打印窗口

    qDebug() << "Program End";    // 输出程序结束信息
}

// 显示启动画面
void MainWindow::showSplash()
{
    if(m_pSplash != NULL){
        // 在启动画面上显示版本信息，底部居中对齐，使用橙色文字
        m_pSplash->showMessage(B9CVERSION, Qt::AlignBottom|Qt::AlignCenter, QColor(255,130,36));
        m_pSplash->show();    // 显示启动画面
        // 1秒后自动隐藏启动画面
        QTimer::singleShot(1000, this, SLOT(hideSplash()));
    }
}

// 显示关于对话框
void MainWindow::showAbout()
{
    if(m_pSplash != NULL){
        // 在启动画面上显示版本信息，底部居中对齐，使用橙色文字
        m_pSplash->showMessage(B9CVERSION, Qt::AlignBottom|Qt::AlignCenter, QColor(255,130,36));
        m_pSplash->show();    // 显示启动画面
    }
}

// 显示布局窗口
void MainWindow::showLayout()
{
    emit on_commandLayout_clicked(true);    // 发出布局命令点击信号
}

// 显示切片窗口
void MainWindow::showSlice()
{
    emit on_commandSlice_clicked(true);    // 发出切片命令点击信号
}

// 显示编辑窗口
void MainWindow::showEdit()
{
    // 直接显示编辑窗口，不需要按钮切换
    pMW3->show();    // 显示编辑窗口
}

// 显示打印窗口
void MainWindow::showPrint()
{
    emit on_commandPrint_clicked();    // 发出打印命令点击信号
}

// 显示日志并退出
void MainWindow::showLogAndExit()
{
    m_bOpenLogOnExit = true;    // 设置退出时打开日志标志
    close();    // 关闭主窗口
}

// 显示终端窗口
void MainWindow::showTerminal()
{
    pTerminal->showIt();    // 显示终端界面
}

// 显示构建平台校准对话框
void MainWindow::showCalibrateBuildTable()
{
    // 检查是否已连接打印机
    if(!pTerminal->isConnected()){
        QMessageBox::information(this, "Printer Not Found", "You must be connected to the printer to Calibrate", QMessageBox::Ok);
        return;
    }

    // 创建并显示构建平台校准对话框
    dlgCalBuildTable dlgCalBT(pTerminal);
    dlgCalBT.exec();
}

// 显示投影机校准对话框
void MainWindow::showCalibrateProjector()
{
    // 检查是否已连接打印机
    if(!pTerminal->isConnected()){
        QMessageBox::information(this, "Printer Not Found", "You must be connected to the printer to Calibrate", QMessageBox::Ok);
        return;
    }

    // 创建并显示投影机校准对话框
    dlgCalProjector dlgCalProj(pTerminal);
    dlgCalProj.exec();
}

// 显示材料目录对话框
void MainWindow::showCatalog()
{
    pTerminal->dlgEditMatCat();    // 调用终端的材料目录编辑对话框
}

// 显示打印周期设置对话框
void MainWindow::showPrinterCycles()
{
    pTerminal->dlgEditPrinterCycleSettings();    // 调用终端的打印周期设置对话框
}

// 显示帮助信息
void MainWindow::showHelp()
{
    m_HelpSystem.showHelpFile("index.html");    // 显示帮助文件
}

// 关闭事件处理 - 隐藏所有子窗口并接受关闭事件
void MainWindow::closeEvent(QCloseEvent *event)
{
    // 隐藏所有功能模块窗口
    pMW1->hide();    // 隐藏布局窗口
    pMW2->hide();    // 隐藏切片窗口
    pMW3->hide();    // 隐藏编辑窗口
    pMW4->hide();    // 隐藏打印窗口
    pTerminal->hide();    // 隐藏终端窗口
    event->accept();    // 接受关闭事件
}

// 处理布局窗口隐藏事件
void MainWindow::handleW1Hide()
{
    this->show();    // 显示主窗口
    ui->commandLayout->setChecked(false);    // 取消布局按钮选中状态
}

// 处理切片窗口隐藏事件
void MainWindow::handleW2Hide()
{
    this->show();    // 显示主窗口
    ui->commandSlice->setChecked(false);    // 取消切片按钮选中状态
}

// 处理编辑窗口隐藏事件
void MainWindow::handleW3Hide()
{
    this->show();    // 显示主窗口
    // 注释掉的编辑按钮状态重置
    //ui->commandEdit->setChecked(false);
}

// 处理打印窗口隐藏事件
void MainWindow::handleW4Hide()
{
    this->show();    // 注释说明，如果没有隐藏主窗口同时显示该窗口
    ui->commandPrint->setChecked(false);    // 取消打印按钮选中状态
    pLogManager->setPrinting(false);    // 设置打印状态为false
    pTerminal->setIsPrinting(false);    // 设置终端打印状态为false
    CROSS_OS_DisableSleeps(false);    // 返回系统屏保恢复正常
}

// 检查更新
void MainWindow::CheckForUpdates()
{
    m_pUpdateManager->PromptDoUpdates();    // 提示用户进行更新
}

// 打开布局文件
void MainWindow::OpenLayoutFile(QString file)
{
    showLayout();    // 显示布局窗口
    pMW1->ProjectData()->Open(file);    // 在布局窗口中打开文件
}

// 打开作业文件
void MainWindow::OpenJobFile(QString file)
{
    AttemptPrintDialogWithFile(file);    // 尝试使用文件打开打印对话框
}


// 布局命令点击事件处理
void MainWindow::on_commandLayout_clicked(bool checked)
{
    if(checked) {
        pMW1->show();    // 显示布局窗口
        this->hide();    // 注释说明，如果没有隐藏主窗口同时显示该窗口
    }
    else 
        pMW1->hide();    // 隐藏布局窗口
}

// 切片命令点击事件处理
void MainWindow::on_commandSlice_clicked(bool checked)
{
    if(checked) {
        pMW2->show();    // 显示切片窗口
        this->hide();    // 注释说明，如果没有隐藏主窗口同时显示该窗口
    }
    else 
        pMW2->hide();    // 隐藏切片窗口
}

// 打印命令点击事件处理
void MainWindow::on_commandPrint_clicked()
{
    pMW1->hide();    // 隐藏布局窗口
    pMW2->hide();    // 隐藏切片窗口
    pMW3->hide();    // 隐藏编辑窗口
    pMW4->show();    // 显示打印窗口
}

// 尝试使用文件打开打印对话框
void MainWindow::AttemptPrintDialogWithFile(QString openFile)
{
    /////////////////////////////////////////////////
    // 打开 .b9j文件
    m_pCPJ->clearAll();    // 清空压缩打印作业

    QFile file(openFile);
    // 尝试加载CPJ文件
    if(!m_pCPJ->loadCPJ(&file)) {
        QMessageBox msgBox;
        msgBox.setText("Error Loading File.  Unknown Version?");    // 文件加载错误提示
        msgBox.exec();
        return;
    }
    
    m_pCPJ->showSupports(true);    // 显示支撑结构
    int iXYPixelMicrons = m_pCPJ->getXYPixelmm()*1000;    // 获取XY像素尺寸（微米）
    
    // 检查打印机连接状态和像素尺寸匹配
    if(pTerminal->isConnected() && iXYPixelMicrons != (int)pTerminal->getXYPixelSize()){
        QMessageBox msgBox;
        msgBox.setText("WARNING");    // 警告标题
        msgBox.setInformativeText("The XY pixel size of the selected job file ("+QString::number(iXYPixelMicrons)+" 祄) does not agree with the Printer's calibrated XY pixel size ("+QString::number(pTerminal->getXYPixelSize())+" 祄)!\n\n"
                                  "Printing will likely result in an object with incorrect scale and/or apsect ratio.\n\n"
                                  "Do you wish to continue?");    // 警告信息
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        int ret = msgBox.exec();
        if(ret==QMessageBox::No) return;    // 用户选择不继续则返回
    }

    // 创建打印准备对话框
    m_pPrintPrep = new DlgPrintPrep(m_pCPJ, pTerminal, this);
    connect(m_pPrintPrep, SIGNAL(accepted()), this, SLOT(doPrint()));    // 连接接受信号到打印槽函数
    m_pPrintPrep->exec();    // 显示对话框
}

// 执行打印操作
void MainWindow::doPrint()
{
    // 打印使用由向导设置的变量...
    this->hide();    // 注释说明，如果没有隐藏主窗口同时显示该窗口
    pMW4->show();    // 显示打印窗口
    pLogManager->setPrinting(false);    // 设置为true以停止打印时抓取日志
    pTerminal->setIsPrinting(true);    // 设置终端打印状态为true
    CROSS_OS_DisableSleeps(true);    // 禁用像屏幕保护程序 - 和电源选项
    
    // 调用打印窗口的3D打印函数，使用打印准备向导设置的参数
    pMW4->print3D(m_pCPJ, 0, 0, 
                  m_pPrintPrep->m_iTbaseMS,      // 基础层曝光时间
                  m_pPrintPrep->m_iToverMS,      // 覆盖层曝光时间
                  m_pPrintPrep->m_iTattachMS,    // 附件层曝光时间
                  m_pPrintPrep->m_iNumAttach,    // 附件层数量
                  m_pPrintPrep->m_iLastLayer,    // 最后一层号
                  m_pPrintPrep->m_bDryRun,       // 是否为试运行
                  m_pPrintPrep->m_bDryRun,       // 是否使用主显示器
                  m_pPrintPrep->m_bMirrored);    // 是否镜像

    return;
}
