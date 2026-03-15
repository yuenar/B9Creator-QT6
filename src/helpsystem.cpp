/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    system
 * 文件名:     helpsystem.cpp
 * 模块功能:   帮助系统实现文件，包含应用程序帮助的具体实现
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#include <QtCore/QByteArray>
#include <QtCore/QDir>
#include <QtCore/QLibraryInfo>
#include <QtCore/QProcess>
#include <QMessageBox>
#include <QtDebug>
#include "helpsystem.h"

HelpSystem::HelpSystem()
    : pHelpProcess(0)
{
}

HelpSystem::~HelpSystem()
{
    if (pHelpProcess && pHelpProcess->state() == QProcess::Running) {
        pHelpProcess->terminate();
        pHelpProcess->waitForFinished();
    }
    pHelpProcess->deleteLater();
}

void HelpSystem::showHelpFile(const QString &file)
{
    if (!startHelp())return;
    QByteArray ba("SetSource ");
    ba.append("qthelp://com.b9creations.b9creator/doc/");
    pHelpProcess->write(ba + file.toLocal8Bit() + '\n');
}

bool HelpSystem::startHelp()
{
    if (!pHelpProcess) pHelpProcess = new QProcess();
    if (pHelpProcess->state() != QProcess::Running) {
        QString app = QDir::currentPath();
#if !defined(Q_OS_MAC)
        app += QLatin1String("/documentation/assistant");
#else
        app += QLatin1String("/Assistant.app/Contents/MacOS/Assistant");
#endif

        QStringList args;
        args << QLatin1String("-collectionFile")
            << QDir::currentPath() + QLatin1String("/documentation/b9creator.qhc")
            << QLatin1String("-enableRemoteControl");
qDebug() << "path to ghc: "<<app << " " << args;

        pHelpProcess->start(app, args);

        if (!pHelpProcess->waitForStarted()) {
            QMessageBox::critical(0, QObject::tr("B9Creator - 3D Printer"),
                QObject::tr("Unable to launch help system (%1)").arg(app));
            return false;
        }
    }
    return true;
}
