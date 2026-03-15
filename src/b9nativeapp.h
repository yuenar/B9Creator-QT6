/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    core
 * 文件名:     b9nativeapp.h
 * 模块功能:   原生应用程序类头文件，定义应用程序主类和接口
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/
#pragma once
#include <QApplication>
#include "mainwindow.h"
#include "OS_Wrapper_Functions.h"

class B9NativeApp : public QApplication
{
public:
    B9NativeApp(int &argc, char **argv) : QApplication(argc, argv)
    {
        mainWindow = new MainWindow;
        this->argc = argc;

        for(int i = 0; i < argc; i++)
            this->argv.push_back(QString::fromLatin1(argv[i]));

    }
    ~B9NativeApp()
    {
        delete mainWindow;
    }

    void ProccessArguments()
    {
    #ifdef Q_OS_WIN
        if(argc > 1)
        {
            QString openFile;
            //有时一个文件可能无法在case引用
            for(int i = 1; i < argc; i++)
            {
                openFile += argv[i];
                openFile += " ";
            }
            openFile = openFile.trimmed();


            if(QFileInfo(openFile).completeSuffix().toLower() == "b9l")
            {
                mainWindow->OpenLayoutFile(openFile);
            }
            else if(QFileInfo(openFile).completeSuffix().toLower() == "b9j")
            {
                mainWindow->OpenJobFile(openFile);
            }
        }
    #endif

    }




    MainWindow* mainWindow;



    virtual bool notify(QObject *receiver, QEvent *event)
    {
        if (event->type() == QEvent::Polish &&
            receiver &&
            receiver->isWidgetType())
        {
            set_smaller_text_osx(reinterpret_cast<QWidget *>(receiver));
        }

        return QApplication::notify(receiver, event);
    }
private:

    int argc;
    QStringList argv;


    void set_smaller_text_osx(QWidget *w);



protected:
   bool event(QEvent * event);//对于Mac OS X文件关联。

};
 
