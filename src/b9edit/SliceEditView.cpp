/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    b9edit
 * 文件名:     SliceEditView.cpp
 * 模块功能:   切片编辑视图实现文件，定义切片编辑视图相关类和接口
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/
#include <QtGui>
#include "SliceEditView.h"
#include <QClipboard>
#include <QColorDialog>
#include <QInputDialog>

/////////////////////////////////
//Public - 公共方法实现
/////////////////////////////////

// SliceEditView构造函数 - 初始化切片编辑视图
SliceEditView::SliceEditView(QWidget *parent, Qt::WindowFlags flags) : QMainWindow(parent, flags)
{
	ui.setupUi(this);    // 设置UI界面

	// 初始化成员变量
	bGrid = false;          // 网格显示标志初始化
	supportMode = false;    // 支撑模式标志初始化
	pCPJ = NULL;           // 打印作业指针初始化
	backupIndx = 0;         // 备份索引初始化
	m_xOffset = 0;         // X偏移量初始化
	m_yOffset = 0;         // Y偏移量初始化
	currSlice = 0;         // 当前切片号初始化

    // 设置窗口图标
    setWindowIcon(QIcon(":/B9JobBuilder/icons/edit.png"));
	setStatusBar(0);    // 不使用状态栏

    // 初始化绿色刷新定时器
	greenTimer.setSingleShot(true);    // 设置为单次触发
	greenTimer.setInterval(0);         // 设置间隔为0毫秒
	greenTimer.stop();                 // 停止定时器
	// 连接定时器超时信号到刷新槽函数
	QObject::connect(&greenTimer,SIGNAL(timeout()),this,SLOT(RefreshWithGreen()));

	// 创建绘制上下文对象
	pDrawingContext = new DrawingContext(this);
	pDrawingContext->pEditView = this;    // 设置绘制上下文的父视图引用
	
	// 初始化工具设置
	SetSupportTool("circle");    // 设置默认支撑工具为圆形
	SetDrawTool("penfill");      // 设置默认绘制工具为填充笔刷
	
	// Temporarily disable UI interactions
// ui.actionPrepare_Base_Gap->setEnabled(false);
	// Temporarily disable UI interactions
// ui.menuSupports->setEnabled(false);
//	
//	
// ui.scrollArea->setWidget(pDrawingContext);
// ui.scrollArea->setFocusPolicy(Qt::NoFocus);


	QObject::connect(this,SIGNAL(sliceDirtied(QImage*, int)),parent,SLOT(PatchJobData(QImage*, int)));

    //工具栏
	// Temporarily disable UI interactions
// ui.toolBar->addAction(ui.actionSupport_Mode);
// ui.toolBar->addSeparator();
//	
// ui.toolBar->addAction(ui.actionWhite_Pen);
// ui.toolBar->addAction(ui.actionBlack_Pen);
// ui.toolBar->addAction(ui.actionFlood_Fill);
// ui.toolBar->addAction(ui.actionFlood_Void);
//	
// ui.toolBar->addSeparator();
	
	// Temporarily disable UI interactions
// ui.toolBar->addAction(ui.actionCircle);
// ui.toolBar->addAction(ui.actionSquare);
// ui.toolBar->addAction(ui.actionTriangle_2);
// ui.toolBar->addAction(ui.actionDiamond);
	ShowSupportButtons(false);
}
SliceEditView::~SliceEditView()
{
}

QString SliceEditView::GetEditMode()
{
	if(supportMode)
	{
		return "Support Mode";
	}
	else
	{
		return "Image Mode";
	}

}

//public slots
void SliceEditView::TogSupportMode()
{
	
	supportMode = !supportMode;
    if(supportMode)//进入支撑模态
	{
		// Temporarily disable UI interactions
// ui.actionSupport_Mode->setText("Enter Image Mode");
// ui.menuDrawing->setEnabled(false);
// ui.menuSupports->setEnabled(true);
// ui.actionCopy->setEnabled(false);
// ui.actionPaste->setEnabled(false);
		ShowDrawButtons(false);
		ShowSupportButtons(true);
		// Temporarily disable UI interactions
// ui.actionPrepare_Base_Gap->setEnabled(true);
		SetSupportTool("currTool");
		pCPJ->showSupports(true);
		DeCompressIntoContext();
		pDrawingContext->GenerateLogicImage();
		RefreshWithGreen();
	}
    else//退出支撑模态
	{
		
		// Temporarily disable UI interactions
// ui.actionSupport_Mode->setText("Enter Support Mode");
// ui.menuDrawing->setEnabled(true);
// ui.menuSupports->setEnabled(false);
// ui.actionCopy->setEnabled(true);
// ui.actionPaste->setEnabled(true);
		ShowDrawButtons(true);
		ShowSupportButtons(false);
		// Temporarily disable UI interactions
// ui.actionPrepare_Base_Gap->setEnabled(false);
		SetDrawTool("currTool");
		pCPJ->showSupports(false);
		DeCompressIntoContext();
	}
	UpdateWidgets();
}
void SliceEditView::ReCompress()
{
	if(!supportMode)
	{
		emit sliceDirtied(&topImg,currSlice);
		modified = false;
	}
}
void SliceEditView::GoToSlice(int slicenumber)
{
    //确保切片期望值是在范围内...
	if(slicenumber > pCPJ->getTotalLayers() - 1 || slicenumber < 0)
	{
		return;
	}
	if(slicenumber != currSlice)
	{
		ClearUndoBuffer();
	}	
	
	currSlice = slicenumber;
	setWindowTitle("Slice Manager - " + GetEditMode() + ": " + QString().number(currSlice+1) + " / " + QString().number(pCPJ->getTotalLayers()));
	DeCompressIntoContext();
	
	if(supportMode)
	{
		RefreshContext(0);
	}
	else
	{
		RefreshContext(1);
	}
	
	if(!supportMode)
	{
        SaveToUndoBuffer(); //移动到一个新的切片时，始终保存其状态到此缓冲区。
	}

	greenTimer.start();
}
//从工程文件中导入并叠加图片, 在支撑模态下自下到上叠加.
void SliceEditView::DeCompressIntoContext()
{
    pCPJ->setCurrentSlice(currSlice);
	if(supportMode)
        pCPJ->showSupports(1);
	else
        pCPJ->showSupports(0);

    //要仔细检查上面的图像地址是否为0x0，我们想调整它的大小来解决“灰色窗口”
    //当第一次打开一个图片，可能会出问题。
    if(topImg.size().width() == 0)
    {
        topImg = QImage(1024,768,QImage::Format_ARGB32_Premultiplied) ;
    }



    pCPJ->inflateCurrentSlice(&topImg, m_xOffset, m_yOffset, true);
    pDrawingContext->SetUpperImg(&topImg);
	
    if(currSlice <= 0)//生成"base"图片
	{
		botImg = QImage(topImg.width(),topImg.height(),QImage::Format_RGB16);
		botImg.fill(QColor(255,255,255));
	}
	else
    {
        pCPJ->setCurrentSlice(currSlice - 1);
        pCPJ->inflateCurrentSlice(&botImg, m_xOffset, m_yOffset, true);
	}
		
	pDrawingContext->SetLowerImg(&botImg);
}
void SliceEditView::RefreshContext(bool alreadywhite)
{
	if(!alreadywhite)
		pDrawingContext->GenerateLogicImage();
	pDrawingContext->repaint();
	
}
void SliceEditView::UpdateWidgets()
{
	setWindowTitle("Slice Manager - " + GetEditMode() + ": " + QString().number(currSlice+1) + " / " + QString().number(pCPJ->getTotalLayers()));
	// Temporarily disable UI interactions
// ui.horizontalSlider->setMinimum(0);
// ui.horizontalSlider->setMaximum(pCPJ->getTotalLayers() - 1);
	// Temporarily disable UI interactions
// ui.horizontalSlider->setValue(currSlice);
}
void SliceEditView::RefreshWithGreen()
{
	if(supportMode)
	{
		pDrawingContext->GenerateGreenImage();
		pDrawingContext->repaint();
	}
}

//base
void SliceEditView::PromptBaseOptions()
{
	int baselayers;
	int fills;
	bool cont;
    baselayers = QInputDialog::getInt(this, tr("Attachment Base"),
                                          tr("Object Standoff, # of Layers:"),
                                          pCPJ->getBase(), 0, 1000, 1, &cont, windowFlags() & ~Qt::WindowContextHelpButtonHint);
    if (!cont)
		return;
    fills = QInputDialog::getInt(this, tr("Attachment Base"), tr("Filled Layers:"), pCPJ->getFilled(), 0, baselayers, 1, &cont, windowFlags() & ~Qt::WindowContextHelpButtonHint);
	if (!cont)
		return;

	PrepareBase(baselayers, fills);
}
void SliceEditView::PrepareBase(int baselayers, int filledlayers)
{
	currSlice += baselayers - pCPJ->getBase();
	
	pCPJ->setBase(baselayers);
	pCPJ->setFilled(filledlayers);
	
	GoToSlice(currSlice);
	pBuilder->SetDirty();
	UpdateWidgets();
}

//支撑
void SliceEditView::AddSupport(QPoint pos, int size, SupportType type, int fastmode)
{
	QCursor prevC = pDrawingContext->cursor();
	pDrawingContext->setCursor(QCursor(Qt::WaitCursor));
	
    pCPJ->AddSupport(currSlice - 1,pos,size,type,fastmode);
	
	DeCompressIntoContext();
	pDrawingContext->GenerateLogicImage();
	RefreshWithGreen();
	pDrawingContext->setCursor(prevC);

	pBuilder->SetDirty();
}
void SliceEditView::DeleteAllSupports()
{
	QMessageBox::StandardButton ret;
	ret = QMessageBox::warning(this, tr("Slice Manager"),
				tr("Are you sure you want to remove all supports?"),
					QMessageBox::Yes | QMessageBox::No);
	
	if(ret == QMessageBox::No)
	{
		return;
	}

	pCPJ->DeleteAllSupports();
	DeCompressIntoContext();
	pDrawingContext->GenerateLogicImage();
	RefreshWithGreen();
	pBuilder->SetDirty();
}

//撤销
void SliceEditView::ClearUndoBuffer()
{
	imgBackup.clear();
	backupIndx = -1;
}
void SliceEditView::SaveToUndoBuffer()
{
	int i;
	for(i = imgBackup.size() - 1; i > backupIndx; i--)
	{
		imgBackup.removeAt(i);
	}
    //添加到撤销列表
	imgBackup.append(topImg);
	if(imgBackup.size() > 25)
		{imgBackup.removeFirst();}
	backupIndx = imgBackup.size() - 1;
}
void SliceEditView::Undo()
{
	if(!supportMode)
	{
		if(backupIndx >= 1)
		{	
			backupIndx--;
			topImg = imgBackup[backupIndx];
			pDrawingContext->SetUpperImg(&topImg);
			RefreshContext(1);
			modified = true;
			ReCompress();
			pDrawingContext->update();
		}
	}
}
void SliceEditView::Redo()
{
	if(!supportMode)
	{
		backupIndx++;
		if(backupIndx >= imgBackup.size())
		{
			backupIndx = imgBackup.size() - 1;
			return;
		}

		topImg = imgBackup[backupIndx];
		pDrawingContext->SetUpperImg(&topImg);
		RefreshContext(1);
		modified = true;
		ReCompress();
		pDrawingContext->update();
	}
}

//剪贴板
void SliceEditView::CopyToClipboard()
{
	if(supportMode)
		return;
	QClipboard *clipboard = QApplication::clipboard();
	clipboard->setImage(topImg);
}
void SliceEditView::PasteFromClipboard()
{
	if(supportMode)
		return;

	QClipboard *clipboard = QApplication::clipboard();
	if(clipboard->image().isNull())
		return;

	modified = true;
	topImg = clipboard->image();
	pDrawingContext->SetUpperImg(&topImg);
    RefreshContext(1);//所以我们可以撤消粘贴...
    SaveToUndoBuffer();//由于图像被改变，保存到缓冲器。
	ReCompress();
}

//工具
void SliceEditView::SelectPenColor()
{
	QColor newColor = QColorDialog::getColor(Qt::white);
     if (newColor.isValid())
         pDrawingContext->SetPenColor(newColor);
}
void SliceEditView::SelectPenWidth()
{
	bool ok;
    int newWidth = QInputDialog::getInt(this, tr("Edit View"), tr("Select pen width:"), pDrawingContext->PenWidth, 1, 50, 1, &ok);
    if (ok) pDrawingContext->SetPenWidth(newWidth);

}
void SliceEditView::SetDrawTool(QString tool)
{
	PopDrawButtons();
	if(tool == "currTool")
	{
		tool = pDrawingContext->currDrawTool;
	}
	if(tool == "penfill")
	{
		pDrawingContext->SetPenColor(Qt::white);
        QPixmap bucket(":/Cursors/icons/crosshair.png","PNG");
		pDrawingContext->setCursor(QCursor(bucket));
		// Temporarily disable UI interactions
// ui.actionWhite_Pen->setChecked(true);
// ui.actionBlack_Pen->setChecked(true);
// ui.actionFlood_Fill->setChecked(true);
// ui.actionFlood_Void->setChecked(true);
	}
	
	pDrawingContext->currDrawTool = tool;
}
void SliceEditView::SetSupportTool(QString tool)
{
	PopSupportButtons();
	if(tool == "nextTool")
	{
		if(pDrawingContext->currSupportTool == "circle")
		{
			SetSupportTool("square");	
		}
		else if(pDrawingContext->currSupportTool == "square")
		{
			SetSupportTool("triangle");
		}
		else if(pDrawingContext->currSupportTool == "triangle")
		{
			SetSupportTool("diamond");	
		}
		else if(pDrawingContext->currSupportTool == "diamond")
		{
			SetSupportTool("circle");	
		}
		return;
	}
	if(tool == "currTool")
	{
		tool = pDrawingContext->currSupportTool;
	}
	if(tool == "circle")
	{
		QImage img = SimpleSupport(st_CIRCLE,pDrawingContext->supportSize).getCursorImage();
		pDrawingContext->setCursor(QCursor(QPixmap().fromImage(img)));
		// Temporarily disable UI interactions
// ui.actionCircle->setChecked(true);
// ui.actionSquare->setChecked(true);
// ui.actionTriangle_2->setChecked(true);
// ui.actionDiamond->setChecked(true);
	}

	pDrawingContext->currSupportTool = tool;
	
}
//navigation
void SliceEditView::NextSlice()
{
	GoToSlice(currSlice+1);
	// Temporarily disable UI interactions
// ui.horizontalSlider->setValue(currSlice);
}
void SliceEditView::PrevSlice()
{
	GoToSlice(currSlice-1);
	// Temporarily disable UI interactions
// ui.horizontalSlider->setValue(currSlice);
}
void SliceEditView::PgUpSlice(int increment)
{
	GoToSlice(currSlice+increment);
	// Temporarily disable UI interactions
// ui.horizontalSlider->setValue(currSlice);
}
void SliceEditView::PgDownSlice(int increment)
{
	GoToSlice(currSlice-increment);
	// Temporarily disable UI interactions
// ui.horizontalSlider->setValue(currSlice);
} 
void SliceEditView::BaseSlice()
{
	GoToSlice(0);
	// Temporarily disable UI interactions
// ui.horizontalSlider->setValue(0);
}
void SliceEditView::TopSlice()
{
	GoToSlice(pCPJ->getTotalLayers() -1);
	// Temporarily disable UI interactions
// ui.horizontalSlider->setValue(pCPJ->getTotalLayers() -1);
}

//工具栏
void SliceEditView::PopDrawButtons()//取消选中所有的绘制按钮
{
	// Temporarily disable UI actions that are missing
// ui.actionWhite_Pen->setChecked(true);
// ui.actionBlack_Pen->setChecked(false);
// ui.actionFlood_Fill->setChecked(false);
	// Temporarily disable UI interactions
// ui.actionFlood_Void->setChecked(false);
}
void SliceEditView::SetDrawButtonsEnabled(bool enabled)//取消选中所有的绘制按钮
{
	// Temporarily disable UI interactions
// ui.actionWhite_Pen->setEnabled(enabled);
// ui.actionBlack_Pen->setEnabled(enabled);
// ui.actionFlood_Fill->setEnabled(enabled);
// ui.actionFlood_Void->setEnabled(enabled);
}
void SliceEditView::ShowDrawButtons(bool show)
{

	// Temporarily disable UI interactions
// ui.actionBlack_Pen->setVisible(show);
// ui.actionWhite_Pen->setVisible(show);
// ui.actionFlood_Fill->setVisible(show);
// ui.actionFlood_Void->setVisible(show);
	

}
void SliceEditView::PopSupportButtons()//取消选中所有的支撑按钮
{
	// Temporarily disable UI interactions
// ui.actionCircle->setChecked(false);
// ui.actionSquare->setChecked(false);
// ui.actionTriangle_2->setChecked(false);
// ui.actionDiamond->setChecked(false);
}
void SliceEditView::SetSupportButtonsEnabled(bool enabled)//启用所有支撑按钮。
{
	// Temporarily disable UI interactions
// ui.actionCircle->setEnabled(enabled);
// ui.actionSquare->setEnabled(enabled);
// ui.actionTriangle_2->setEnabled(enabled);
// ui.actionDiamond->setEnabled(enabled);
}
void SliceEditView::ShowSupportButtons(bool show)//隐藏/显示所有支撑按钮
{
	// Temporarily disable UI interactions
// ui.actionCircle->setVisible(show);
// ui.actionSquare->setVisible(show);
// ui.actionTriangle_2->setVisible(show);
// ui.actionDiamond->setVisible(show);
}

////////////////////////////////
//Protected
////////////////////////////////
void SliceEditView::keyPressEvent(QKeyEvent * pEvent)
{
	
	if(pEvent->key() == Qt::Key_PageUp)
	{
		PgUpSlice(10);
	}
	else if(pEvent->key() == Qt::Key_PageDown)
	{
		PgDownSlice(10);
	}
	else if(pEvent->key() == Qt::Key_Control)
	{
		pDrawingContext->fastsupportmode = false;
	}
	else if(pEvent->key() == Qt::Key_C)
	{
		SetSupportTool("nextTool");
	}
	else if(pEvent->key() == Qt::Key_Delete)
	{
		if(supportMode)
		{
            QPixmap bucket(":/Cursors/icons/delete.png","PNG");
			pDrawingContext->setCursor(QCursor(bucket));
			pDrawingContext->deletemode = true;
		}
	}
	else if(pEvent->key() == Qt::Key_Shift)
	{
		pDrawingContext->supportSize = pDrawingContext->supportSize * 0.5;
		SetSupportTool("currTool");
	}
	else
	{
		QWidget::keyPressEvent(pEvent);
	}
}
void SliceEditView::keyReleaseEvent(QKeyEvent * pEvent)
{
	if(pEvent->key() == Qt::Key_Control)
	{
		pDrawingContext->fastsupportmode = true;
	}
	else if(pEvent->key() == Qt::Key_Shift)
	{
		pDrawingContext->supportSize = pDrawingContext->supportSize*2;
		SetSupportTool("currTool");
	}
	else if(pEvent->key() == Qt::Key_Delete)
	{
		if(supportMode)
		{
			SetSupportTool("currTool");
			pDrawingContext->deletemode = false;
		}
	}
	else
	{
		QWidget::keyPressEvent(pEvent);
	}
}

void SliceEditView::mouseReleaseEvent(QMouseEvent * pEvent)
{
	QWidget::mouseReleaseEvent(pEvent);
}

// 添加缺失的槽函数实现
void SliceEditView::updateName(QString s)
{
    if (pBuilder) {
        pBuilder->updateName(s);
    }
}

void SliceEditView::updateDescription(QString s)
{
    if (pBuilder) {
        pBuilder->updateDescription(s);
    }
}

void SliceEditView::updateXY(QString s)
{
    if (pBuilder) {
        pBuilder->updateXY(s);
    }
}

void SliceEditView::updateZ(QString s)
{
    if (pBuilder) {
        pBuilder->updateZ(s);
    }
}

void SliceEditView::ShowSliceWindow()
{
    show();
}

void SliceEditView::newJob()
{
    if (pBuilder) {
        pBuilder->newJob();
    }
}

void SliceEditView::openJob()
{
    if (pBuilder) {
        pBuilder->openJob();
    }
}

void SliceEditView::saveJob()
{
    if (pBuilder) {
        pBuilder->saveJob();
    }
}

void SliceEditView::saveJobAs()
{
    if (pBuilder) {
        pBuilder->saveJobAs();
    }
}

void SliceEditView::importSlices()
{
    if (pBuilder) {
        pBuilder->importSlices();
    }
}

void SliceEditView::ExportToFolder()
{
    if (pBuilder) {
        pBuilder->ExportToFolder();
    }
}




