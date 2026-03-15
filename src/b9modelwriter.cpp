/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    model
 * 文件名:     b9modelwriter.cpp
 * 模块功能:   模型写入器实现文件，包含模型数据写入的具体实现
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#include "b9modelwriter.h"
#include "b9layout/triangle3d.h"
#include <QDebug>

B9ModelWriter::B9ModelWriter(QString filename, bool &readyWrite, QObject *parent) :
    QObject(parent)
{
    triCount = 0;


    binOUT.setFileName(filename);
    readyWrite = binOUT.open(QIODevice::WriteOnly | QIODevice::Truncate);

    if(readyWrite)
    {
        binStream.setDevice(&binOUT);
        binStream.setByteOrder(QDataStream::LittleEndian);
        WriteHeader(0);//初始化完成时首部没有任何三角数据。
    }
}


B9ModelWriter::~B9ModelWriter()
{
    if(binOUT.isOpen())
        binOUT.close();
}



void B9ModelWriter::WriteHeader(quint32 triCount)
{
    unsigned int i;
    quint8 emptyByte1 = 'B';
    quint8 emptyByte2 = '9';

    //给头部写80字节
    for(i = 0; i < 80; i++)
    {
        if(i%2)
            binStream << emptyByte1;
        else
            binStream << emptyByte2;
    }

    binStream << quint32(triCount);
}

void B9ModelWriter::WriteNextTri(Triangle3D* pTri)
{
    float nx = pTri->normal.x();
    float ny = pTri->normal.y();
    float nz = pTri->normal.z();

    float x0 = pTri->vertex[0].x();
    float y0 = pTri->vertex[0].y();
    float z0 = pTri->vertex[0].z();

    float x1 = pTri->vertex[1].x();
    float y1 = pTri->vertex[1].y();
    float z1 = pTri->vertex[1].z();

    float x2 = pTri->vertex[2].x();
    float y2 = pTri->vertex[2].y();
    float z2 = pTri->vertex[2].z();


    binOUT.write((char*)&nx,4);
    binOUT.write((char*)&ny,4);
    binOUT.write((char*)&nz,4);
    binOUT.write((char*)&x0,4);
    binOUT.write((char*)&y0,4);
    binOUT.write((char*)&z0,4);
    binOUT.write((char*)&x1,4);
    binOUT.write((char*)&y1,4);
    binOUT.write((char*)&z1,4);
    binOUT.write((char*)&x2,4);
    binOUT.write((char*)&y2,4);
    binOUT.write((char*)&z2,4);

    //属性字节计数器（可能不太常用）
    binStream << quint16(0);

    triCount++;
}


void B9ModelWriter::Finalize()
{
    binOUT.seek(80);
    binStream << quint32(triCount);

}




















