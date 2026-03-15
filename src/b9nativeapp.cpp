/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    core
 * 文件名:     b9nativeapp.cpp
 * 模块功能:   原生应用程序类实现文件，包含应用程序主类的具体实现
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#include <QWidget>
#include "b9nativeapp.h"


//在任何平台上调用这个函数它是安全的。但这将只在Mac上运行有效果。
void B9NativeApp::set_smaller_text_osx(QWidget *w)
{
    return; //不使用小字体现在...
    if(w==0)return;

    //缺省情况下，所有这些尺寸属性被未设置。
    //如果有任何一个已被设置，我们就单独处理这个部件。
    if (!w->testAttribute(Qt::WA_MacMiniSize) &&
        !w->testAttribute(Qt::WA_MacSmallSize) &&
        !w->testAttribute(Qt::WA_MacNormalSize))
    {
        //这个小部件是默认的的若干文本尺寸过大类型之一吗
        if (w->inherits("QLabel") ||
            w->inherits("QLineEdit") ||
            w->inherits("QTextEdit") ||
            w->inherits("QComboBox") ||
            w->inherits("QCheckBox") ||
            w->inherits("QRadioButton") ||
            w->inherits("QAbstractItemView"))
            //其他人可以在这里添加...
        {
            // 使文本的“正常”的大小
            w->setAttribute(Qt::WA_MacMiniSize);
        }
        else if( w->inherits("QPushButton") )
            // 其他人可以在这里添加...
        {
            // 使文本的“正常”的大小
            w->setAttribute(Qt::WA_MacMiniSize);
        }
    }
}

bool B9NativeApp::event(QEvent* event)
{
    if( event->type() == QEvent::FileOpen)
    {
        //TODO使用此为Mac-OS文件关联。
        //pMain->openJob(static_cast<QFileOpenEvent*>(event)->file());
        return true;
    }
    return QApplication::event(event);
}

