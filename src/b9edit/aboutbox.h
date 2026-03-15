/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    b9edit
 * 文件名:     aboutbox.h
 * 模块功能:   关于对话框头文件，定义关于对话框相关类和接口
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/
#ifndef ABOUTBOX_H
#define ABOUTBOX_H

#include <QWidget>

namespace Ui {
class aboutbox;
}

class aboutbox : public QWidget
{
    Q_OBJECT
    
public:
    explicit aboutbox(QWidget *parent = 0, Qt::WindowFlags flags = Qt::Dialog);
    ~aboutbox();
    void setText(QString content);


    Ui::aboutbox *ui;
private:

};

#endif // ABOUTBOX_H
