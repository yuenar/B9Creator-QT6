/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    b9slice
 * 文件名:     b9slice.h
 * 模块功能:   切片模块头文件，定义切片处理相关类和接口
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
#include <QHideEvent>
#include "../b9layout/b9layout.h"

namespace Ui {
class B9Slice;
}

class B9Slice : public QMainWindow
{
    Q_OBJECT

public:
    explicit B9Slice(QWidget *parent = 0, B9Layout* Main = 0);
    ~B9Slice();


signals:
    void eventHiding();


public slots:
    void LoadLayout();
    void Slice();


private:
    void hideEvent(QHideEvent *event);
    void showEvent(QHideEvent *event);
    Ui::B9Slice *ui;
    B9Layout* pMain;

    QString currentLayout;
};

 
