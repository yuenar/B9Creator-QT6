/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    utils
 * 文件名:     logfilemanager.cpp
 * 模块功能:   日志文件管理器实现文件，包含日志管理的具体实现
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#include "logfilemanager.h"
#include <QTime>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <iostream>
#include <QUrl>
#include <QDebug>
#include <QApplication>
#include <QDesktopServices>
#include "OS_Wrapper_Functions.h"

bool bGlobalPrinting;

QString sLogFileName;
void messageHandler(QtMsgType type, const char *msg)
{
    QFile outFile(sLogFileName);
    QTextStream ts;
    QString txt;
    txt = QDateTime::currentDateTime().toString("yy.MM.dd hh:mm:ss.zzz");
    switch (type) {
    case QtDebugMsg:
        if(!bGlobalPrinting){
            fprintf(stderr, "Debug: %s\n", msg);
            txt += QString("  : %1").arg(msg);
            outFile.open(QIODevice::WriteOnly | QIODevice::Append);
            ts.setDevice(&outFile);
            ts << txt << "\r\n";
            outFile.close();
        }
        break;
    case QtWarningMsg:
        fprintf(stderr, "Warning: %s\n", msg);
    break;
    case QtCriticalMsg:
        fprintf(stderr, "Critical: %s\n", msg);
    break;
    case QtFatalMsg:
        fprintf(stderr, "Fatal: %s\n", msg);
    }
    if(type== QtFatalMsg)
        abort();
}

LogFileManager::LogFileManager(QString sLogFile, QString sHeader)
{
    bGlobalPrinting = false;
    QFile::remove(sLogFile);
    sLogFileName = sLogFile;

    QFile outFile(sLogFile);
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream ts(&outFile);
    ts << sHeader << "\r\n\r\n";
    outFile.close();
/*
#ifdef _DEBUG
#else
    qInstallMsgHandler(messageHandler);
#endif
*/
}

LogFileManager::~LogFileManager()
{
    qInstallMessageHandler(0);
}

void LogFileManager::setPrinting(bool bPrinting)
{
    bGlobalPrinting = bPrinting;
}

void LogFileManager::openLogFileInFolder()
{
    QString path = CROSS_OS_GetDirectoryFromLocationTag("DOCUMENTS_DIR");
    path += "/" + sLogFileName;
    qDebug() << "Log File Location "+path;
    path = "file:///" + path;
    QDesktopServices::openUrl(QUrl(path));
}

