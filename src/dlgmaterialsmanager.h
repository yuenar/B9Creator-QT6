/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    dialog
 * 文件名:     dlgmaterialsmanager.h
 * 模块功能:   材料管理器对话框头文件，定义材料管理相关类和接口
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
#include <QStyledItemDelegate>
#include "b9matcat.h"


class MaterialsTableItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    MaterialsTableItemDelegate(QObject *parent = 0);
    ~MaterialsTableItemDelegate();

    virtual QWidget *createEditor( QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index ) const;
    virtual void setModelData ( QWidget *editor, QAbstractItemModel *model, const QModelIndex &index ) const;
};


namespace Ui {
class DlgMaterialsManager;
}

class DlgMaterialsManager : public QDialog
{
    Q_OBJECT

public:
    explicit DlgMaterialsManager(B9MatCat *pCatalog, QWidget *parent = 0);
    ~DlgMaterialsManager();

public slots:

    void setXY(int iXY){fillData(m_pCatalog->getCurMatIndex(),iXY);}

private slots:

    void on_comboBoxMaterial_currentIndexChanged(int index);

    void on_comboBoxXY_currentIndexChanged(int index);

    void on_pushButtonDelete_clicked();

    void on_pushButtonAdd_clicked();

    void on_buttonBoxSaveCancel_accepted();

    void on_pushButtonDuplicate_clicked();

    void on_buttonBoxSaveCancel_rejected();

    void on_doubleSpinBox_valueChanged(double arg1);

    void on_spinBoxNumberOfAttachLayers_valueChanged(int arg1);

private:
    Ui::DlgMaterialsManager *ui;
    void setUp();
    void fillData(int iMatIndex, int iXYIndex);
    void stuffData();
    void updateEnabledStates();
    void addMaterial(int iMatIndex);
    void removeMaterial(int iMatIndex);
    B9MatCat* m_pCatalog;
    bool m_bLoading;
};
 
