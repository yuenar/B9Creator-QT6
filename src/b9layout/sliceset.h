/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    b9layout
 * 文件名:     sliceset.h
 * 模块功能:   切片集合类头文件，定义切片管理相关类和接口
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/
#pragma once


#include <vector>
#include <list>
#include <queue>
#include <QDebug>
#include <QFuture>
#include <QImage>

class Slice;
class B9ModelInstance;
class CrushedPrintJob;
class SliceContext;


struct SliceRequest
{
    double altitude;
    int layerIndx;
};


class SliceSet
{
public:
    SliceSet(B9ModelInstance* pParentInstance);
	~SliceSet();

    //指向“父模板”的拷贝指针
    B9ModelInstance* pInstance;

    std::queue<SliceRequest> SliceRequests;
    std::queue<Slice*> SlicedSlices;
    std::queue<Slice*> RasturizedSlices;
    std::queue<Slice*> CompressedSlices;

    std::vector< QFuture<void> > workerThreads;

    SliceContext* raster;

    void QueNewSlice(double realAltitude, int layerIndx);
    void SetSingleModelCompressHint(bool hint);
    Slice* ParallelCreateSlices(bool &slicesInTransit,CrushedPrintJob* toJob);




    void ComputeSlice(Slice* slice);
    void RasterizeSlice(Slice* slice);
    void SubtractVoidFromFill(QImage *img);
    void AddSliceToJob(Slice *rasSlice, CrushedPrintJob* job);



private:
    void SetupFutureWorkers();
    void SetupRasturizer();

    QMutex mutex;
    bool singleModelCompression;


};
 