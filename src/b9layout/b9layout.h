/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    b9layout
 * 文件名:     b9layout.h
 * 模块功能:   布局管理模块头文件，定义了B9Layout主窗口类和相关接口
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#pragma once


#include <QtGui>
#include "ui_b93dmain.h"
#include "worldview.h"


class B9LayoutProjectData;
class WorldView;
class ModelData;
class B9ModelInstance;
class SliceDebugger;
class B9SupportStructure;

class B9Layout : public QMainWindow
{
	Q_OBJECT

public:
    B9Layout(QWidget *parent = 0, Qt::WindowFlags flags = Qt::Window);
    ~B9Layout();
    std::vector<B9ModelInstance*> GetAllInstances();
    std::vector<B9ModelInstance*> GetSelectedInstances();
    std::vector<ModelData*> GetAllModelData(){return ModelDataList;}
    B9LayoutProjectData* ProjectData(){return project;}

signals:
    void eventHiding();


public slots:

    //调试面板
	void OpenDebugWindow();

    //文件
	void New();
    QString Open(bool withoutVisuals = false);
	void Save();
	void SaveAs();

    //界面
    void OnChangeTab(int idx);
    Q_INVOKABLE void SetXYPixelSizePreset(int index);
	void SetZLayerThickness(QString thick);
	void SetProjectorX(QString);
	void SetProjectorY(QString);
    void SetProjectorPreset(int index);
    void SetZHeight(QString z);
    void SetAttachmentSurfaceThickness(QString num);
    void UpdateBuildSpaceUI();
    void UpdateExtentsUI();

    void BuildInterface();

    void UpdateInterface();//sets the translation interface fields acourding to what instance/instances are selected.
	void PushTranslations();
    void OnModelSpinSliderChanged(int val);//when the spin slider changes value by the user.
    void OnModelSpinSliderReleased();
	void LockScale(bool lock);

    //工具
    void SetTool(QString toolname);//calls the functions below

    //模型工具面板
    void SetToolModelSelect();
    void SetToolModelMove();
    void SetToolModelSpin();
    void SetToolModelOrientate();
    void SetToolModelScale();

    //支撑工具面板
    void SetToolSupportModify();
    void SetToolSupportAdd();
    void SetToolSupportDelete();

    void ExitToolAction();//使用退出了鼠标按下工具的动作。
    //轮廓辅助
    void OnToggleContourAid(bool tog);
    bool ContourAidEnabled();

    //X射线视觉效果
    void OnToggleXRay(bool tog);
    void OnXRayChange(int val);
    bool XRayEnabled();
    float XRayPercentage();

    //支撑隐藏
    bool HidingSupports();
    void OnToggleSupportHiding(bool tog);

    //模型
    B9ModelInstance* AddModel(QString filepath = "", bool bypassVisuals = false);
	void RemoveAllInstances();
    void CleanModelData();//清除任何不具有实例的modeldata！
	void AddTagToModelList(QListWidgetItem* item);

    B9ModelInstance* FindInstance(QListWidgetItem* item);//给定一个项目，你可以找到一个连接的实例
	//selection
    void RefreshSelectionsFromList();//搜索所有活动列表项，并选择其相应的实例;
    void Select(B9ModelInstance* inst);//选择给定的实例
    void DeSelect(B9ModelInstance* inst);//取消选择给定的实例
    void SelectOnly(B9ModelInstance* inst);//取消选择一切，只选择实例
    void DeSelectAll();//取消选择所有实例
	void SetSelectionPos(double x, double y, double z, int axis = 0);
    void SetSelectionRot(QVector3D newRot);
    void SetSelectionScale(double x, double y, double z, int axis = 0);
    void SetSelectionFlipped(bool flipped);
	void DropSelectionToFloor();
    void ResetSelectionRotation();
    void DuplicateSelection();
    void DeleteSelection();//删除任何选择 - 支撑或实例..
	void DeleteSelectedInstances();

    //支撑模块
    void SetSupportMode(bool tog);//设置的一切行动进行编辑支持选定的实例。
                            //任一标签被点击或菜单项时 - 一个选定实例可以假定
    void FillSupportList();//添加元素添加到列表
    void UpdateSupportList();//在列表中选择正确的元素根据实际脱选
    B9SupportStructure* FindSupportByName(QString name);
    void RefreshSupportSelectionsFromList();//当用户在支持列表中选择东西时调用
    void SelectSupport(B9SupportStructure* sup);
    void SelectOnly(B9SupportStructure* sup);//消选择一切，只选择实例
    std::vector<B9SupportStructure*>* GetSelectedSupports();
    bool IsSupportSelected(B9SupportStructure* sup);
    void DeSelectSupport(B9SupportStructure* sup);
    void DeSelectAllSupports();
    void DeleteSelectedSupports();//调用自删除按钮。
    void DeleteSupport(B9SupportStructure* pSup);
    void MakeSelectedSupportsVertical();
    void MakeSelectedSupportsStraight();

    //支撑（面板）接口
    void OnSupport_Top_AttachType_Changed(bool updateInterface = true);
    void OnSupport_Top_Radius_Changed(bool updateInterface = true);
    void OnSupport_Top_Length_Changed(bool updateInterface = true);
    void OnSupport_Top_Penetration_Changed(bool updateInterface = true);
    void OnSupport_Top_AngleFactor_Changed(bool updateInterface = true);
    void OnSupport_Mid_AttachType_Changed(bool updateInterface = true);
    void OnSupport_Mid_Radius_Changed(bool updateInterface = true);
    void OnSupport_Bottom_AttachType_Changed(bool updateInterface = true);
    void OnSupport_Bottom_Radius_Changed(bool updateInterface = true);
    void OnSupport_Bottom_Length_Changed(bool updateInterface = true);
    void OnSupport_Bottom_Penetration_Changed(bool updateInterface = true);
    void OnSupport_Bottom_AngleFactor_Changed(bool updateInterface = true);

    //底盘
    void OnBasePlatePropertiesChanged();


    void PushSupportProperties();//填充支撑性能相关的数据。
    void PushBasePlateProperties();
    void ResetSupportLight();//连接到按钮
    void ResetSupportMedium();//连接到按钮
    void ResetSupportHeavy();//连接到按钮
    void FillSupportParamsWithDefaults();

    //如果我们在支撑模态下编辑它，则返回一个有效实例。
    B9ModelInstance* SupportModeInst();

    //切片
    bool SliceWorld();//提示用户切片到视界再到不同的格式。
    bool SliceWorldToJob(QString filename);//切片全视界到Job文件
    bool SliceWorldToSlc(QString filename);//切片全视界到Slc文件
    void CancelSlicing(); //连接到进度条停止切片。

    //导出
    void PromptExportToSTL();//整个布局导出到STL文件。
        bool ExportToSTL(QString filename);



    //事件
	void keyPressEvent(QKeyEvent * event );
	void keyReleaseEvent(QKeyEvent * event );
    void mouseReleaseEvent(QMouseEvent * event);
    void mousePressEvent(QMouseEvent * event);

private:
    Ui::B9Layout ui;
	WorldView* pWorldView;
    QSlider* pXRaySlider;
    B9LayoutProjectData* project;


    public:
    std::vector<ModelData*> ModelDataList;

    bool cancelslicing;

    //支撑模态
    B9ModelInstance* currInstanceInSupportMode;
    bool oldModelConstricted;//当过于接近地面升高模型在支撑模态下。
    QVector3D oldPan;
    QVector3D oldRot;
    float oldZoom;
    QString oldTool;
    bool useContourAid;
    bool useXRayVision;
    float xRayPercentage;
    bool hideSupports;
    std::vector<B9SupportStructure*> currSelectedSupports;//当前所选支撑。



    void hideEvent(QHideEvent *event);
    void showEvent(QShowEvent *event);
    void closeEvent(QCloseEvent * event );
    void contextMenuEvent(QContextMenuEvent *event);
};
 