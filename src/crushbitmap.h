/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    utils
 * 文件名:     crushbitmap.h
 * 模块功能:   位图压缩头文件，定义位图压缩相关类和接口
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/
#pragma once


#include <QPixmap>
#include <QBitArray>
#include <QFile>


enum SupportType {st_CIRCLE, st_SQUARE, st_TRIANGLE, st_DIAMOND};

/******************************************************
SimpleSupport用于存储和绘制简单
支撑结构在动态切片分解
******************************************************/
class SimpleSupport {
public:
	SimpleSupport(QPoint point, SupportType type=st_CIRCLE, int size = 10, int start=0, int end=0) {mPoint = point; mType=type; mSize=size; mStart=start; mEnd=end;}
	SimpleSupport(SupportType type=st_CIRCLE, int size = 32) {mPoint = QPoint(16,16); mType=type; mSize=size; mStart=0; mEnd=0;}
	~SimpleSupport() {}

	void streamOutSupport(QDataStream* pOut);
	void streamInSupport(QDataStream* pIn);

    void draw(QImage* pImg);  // 渲染支撑到图像上
	void setType(SupportType type){mType = type;}
	void setPoint(QPoint point){mPoint = point;}
	void setSize(int size){mSize = size;}
	void setStart(int start){mStart = start;}
	void setEnd(int end){mEnd = end;}
	int getStart(){return mStart;}
	int getEnd(){return mEnd;}
	QPoint getPoint(){return mPoint;}
	QImage getCursorImage();

private:
	QPoint mPoint;
	SupportType mType;
	int mSize;
	int mStart;
	int mEnd;

};


/******************************************************
CrushedBitMap（位图）使用的比特流压缩技术
减少所需的存储单色的量
图像，其中大面积的黑色和白色像素是
典型地组合在一起。
******************************************************/
class CrushedPrintJob;
class CrushedBitMap {
public:
    CrushedBitMap() {mIndex = 0; uiWhitePixels=0;m_bIsBaseLayer=false; m_iWidth=0; m_iHeight=0;}
	CrushedBitMap(QImage* pImage);
	CrushedBitMap(QPixmap* pPixmap);
    ~CrushedBitMap(){}
    friend class CrushedPrintJob;

private:
	bool crushSlice(QImage* pImage);
	bool crushSlice(QPixmap* pPixmap);
	void inflateSlice(QImage* pImage, int xOffset = 0, int yOffset = 0, bool bUseNaturalSize = false);
	bool saveCrushedBitMap(const QString &fileName);
	void streamOutCMB(QDataStream* pOut);
	bool loadCrushedBitMap(const QString &fileName);
	void streamInCMB(QDataStream* pIn);
	uint getWhitePixels(){return uiWhitePixels;}
	QRect getExtents(){return mExtents;}
	int getWidth() {return m_iWidth;}
	void setWidth(int width){m_iWidth = width;}
	int getHeight() {return m_iHeight;}
	void setHeight(int height){m_iHeight = height;}
	void setIsBaseLayer(bool isBL){m_bIsBaseLayer=isBL;}
	bool isWhitePixel(QPoint qPoint);
	
	QBitArray mBitarray;
	int mIndex;
	uint uiWhitePixels;
	bool pixelIsWhite(QImage* pImage, unsigned uCurPos);
	void setWhiteImagePixel(QImage* pImage, unsigned uCurPos);	
	int computeKeySize(unsigned uData);
	void pushBits(int iValue, int iBits);
	int  popBits(int iBits);
	QRect mExtents;
	int m_iWidth, m_iHeight, m_xOffset, m_yOffset;
	bool m_bIsBaseLayer;
};
/******************************************************
CrushedPrintJob管理所有被压垮的位图图像
片构成的打印作业。
******************************************************/
class CrushedPrintJob {
public:
	CrushedPrintJob();
	~CrushedPrintJob() {}

    void clearAll(int iLayers = 0);    // 删除所有切片，并将所有变量重置


    int getTotalLayers() {return mSlices.size() + mBase;}  // 总层数，包括基部支座偏移层
    uint getTotalWhitePixels() {return mTotalWhitePixels;} // 返回所有白色像素（较快）
    uint getTotalWhitePixels(int iFirst, int iLast); // 求和的白色像素的层的范围（较慢）
    bool loadCPJ(QFile* pFile); // 返回false如果未知版本或打开错误
    bool saveCPJ(QFile* pFile); //如果无法写入文件则返回错误。

    void setBase(int iBase) {mBase = iBase;}  // 设置基本僵持偏移层
    void setFilled(int iFilled) {mFilled = iFilled; if(mFilled>mBase)mFilled=mBase;} // 其中，范围都充满了基本偏移层数
	int  getBase() {return mBase;}
	int  getFilled() {return mFilled;}

    void showSupports(bool bShow) {mShowSupports = bShow;}  // 将支持渲染标志
	bool renderingSupports() {return mShowSupports;}

    QString getVersion(){return mVersion;}  // 版本文件加载和保存
    QString getName(){return mName;}        // 短文件名
    QString getDescription(){return mDescription;}  // 职位描述
    QString getXYPixel(){return mXYPixel;}          // 以毫米为单位的XY像素大小，缩放目的，设置切片
    double getXYPixelmm(){return mXYPixel.toDouble();}
    QString getZLayer(){return mZLayer;}            // 以毫米为单位的Z层的厚度，扩大规模的目的，设置切片
    double getZLayermm(){return mZLayer.toDouble();}

	void setVersion(QString s){mVersion = s;}
	void setName(QString s){mName = s;}
	void setDescription(QString s){mDescription = s;}
	void setXYPixel(QString s){mXYPixel = s;}
	void setZLayer(QString s){mZLayer = s;}

    // 渲染当前切片 (m_CurrentSlice)居中 (通过偏移量控制)到 pImage
    // 如果bUseNaturalSize，有一个替代pImage大小以这片的大小（偏移量，可能会导致削波！）
    // 扩充的原始图像，然后渲染支持，填补基地范围，等等。
	void inflateCurrentSlice(QImage* pImage, int xOffset = 0, int yOffset = 0, bool bUseNaturalSize = false);
    void inflateSlice(int sliceIndex, QImage* pImage, int xOffset = 0, int yOffset = 0, bool bUseNaturalSize = false);

	void preoSlice(QImage* pImage,int xOffset = 0, int yOffset = 0, bool bUseNaturalSize = false);

    //尝试与pImage存储在m_CurrentSlice压碎版本替换当前切片。如果需要调整作业的宽度和高度
    bool crushCurrentSlice(QImage* pImage);
    bool crushSlice(int sliceIndex, QImage* pImage);

    // 试图切碎和追加pImage到的CBM阵列
    bool addImage(QImage* pImage);

    // 用于“当前”功能内部位置函数调用：m_CurrentSlice
    int getCurrentSlice() {return m_CurrentSlice;}
	void setCurrentSlice(int iSlice) {m_CurrentSlice = iSlice;}

    // 管理支撑
	void AddSupport(int iEndSlice, QPoint qCenter, int iSize = 10, SupportType eType=st_CIRCLE, int fastmode = true);
    bool DeleteSupport(int iSlice, QPoint qCenter, int iRadius = 0);
    void DeleteAllSupports(){mSupports.clear();}

private:
    CrushedBitMap* getCBMSlice(int i);  //获取基于零的索引位CBM
    bool isWhitePixel(QPoint qPoint, int iSlice = -1);

    // 工程文件载入与保存
	void streamInCPJ(QDataStream* pIn);
	void streamOutCPJ(QDataStream* pOut);

    QList <CrushedBitMap> mSlices;   // 切片，不包括基本偏移层
    QList <SimpleSupport> mSupports; // 支撑将被渲染
    void addCBM(CrushedBitMap mCBM){mSlices.append(mCBM);}
	uint mTotalWhitePixels;
	QString mVersion, mName, mDescription, mXYPixel, mZLayer;
	QString mReserved1, mReserved2, mReserved3, mReserved4, mReserved5;
	bool mShowSupports;
    qint32 mBase, mFilled;  // 基层的数量和填充的基底层的数量
	CrushedBitMap mBaseLayer;
	int m_CurrentSlice;
	QRect mJobExtents;
	int m_Width, m_Height;
};

 