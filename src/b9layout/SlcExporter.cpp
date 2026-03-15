/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    b9layout
 * 文件名:     SlcExporter.cpp
 * 模块功能:   SLC导出器实现文件，包含SLC文件导出的具体实现
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期:  2026-03-15
 *    修改内容:  迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#include "SlcExporter.h"
#include <fstream>    // 文件流
#include <string>     // 字符串

// SlcExporter构造函数 - 初始化SLC导出器
SlcExporter::SlcExporter(std::string filename)
{
	opened = false;    // 初始化打开状态为false
	this->filename = filename;    // 设置文件名
    // 以二进制模式和截断模式打开文件
    outfile.open(filename.c_str(), std::ios_base::binary | std::ios::trunc);
	opened = outfile.is_open();    // 检查文件是否成功打开
}

// SlcExporter析构函数 - 清理资源
SlcExporter::~SlcExporter(void)
{
	outfile.close();    // 关闭文件
}

// 写入文件头 - 设置单位信息和头部字符串
void SlcExporter::WriteHeader(bool unitsINCH, bool unitsMM, std::string headerstring)
{
    // 注释掉的文件流标志设置
    //outfile.flags(std::ios_base::trunc);

	// 写入SLC版本信息
	outfile << "-SLCVER 2.0\n";
	// 写入单位信息
	if(unitsMM)
	{
		outfile << "-UNITS MM";    // 设置单位为毫米
	}
	else if(unitsINCH)
	{
		outfile << "-UNITS INCH";    // 设置单位为英寸
	}
    // 注释掉的文件流标志设置
    //outfile.flags(std::ios_base::binary);

	// 写入头部字符串
	outfile.write(headerstring.c_str(), headerstring.size());

	// 创建并写入终止序列
	char* terminationsequence = new char[3];
	terminationsequence[0] = 0x0d;    // 回车符
	terminationsequence[1] = 0x0a;    // 换行符
	terminationsequence[2] = 0x1a;    // 文件结束符

	outfile.write(terminationsequence, 3);    // 写入终止序列
	delete[] terminationsequence;    // 释放内存
}

// 写入保留空间 - 写入256个空字节
void SlcExporter::WriteReservedSpace()
{
	int i;    // 循环计数器
	char n = 0;    // 空字节
	for(i = 0; i < 256; i++)
	{
		outfile.write(&n, 1);    // 写入空字节
	}
}

// 写入采样表大小
void SlcExporter::WriteSampleTableSize(char ntables)
{
	outfile.write(&ntables, 1);    // 写入表数量
}

// 写入采样表数据
void SlcExporter::WriteSampleTable(float minz, float layerthick, float linewidthcomp, float reserved)
{
	char* p = (char*)&minz;    // 转换最小Z值为字节指针
	outfile.write(p, 4);    // 写入最小Z值
	p = (char*)&layerthick;    // 转换层厚度为字节指针
	outfile.write(p, 4);    // 写入层厚度
	p = (char*)&linewidthcomp;    // 转换线宽补偿为字节指针
	outfile.write(p, 4);    // 写入线宽补偿
	p = (char*)&reserved;    // 转换保留值为字节指针
	outfile.write(p, 4);    // 写入保留值
}

// 写入新切片信息
void SlcExporter::WriteNewSlice(float zaltitude, unsigned int numboundries)
{
	char* p = (char*)&zaltitude;    // 转换Z高度为字节指针
	outfile.write(p, 4);    // 写入Z高度
	p = (char*)&numboundries;    // 转换边界数量为字节指针
	outfile.write(p, 4);    // 写入边界数量
}

// 写入边界头信息
void SlcExporter::WriteBoundryHeader(unsigned int numvertices, unsigned int numgaps)
{
	char* p = (char*)&numvertices;    // 转换顶点数量为字节指针
	outfile.write(p, 4);    // 写入顶点数量
	p = (char*)&numgaps;    // 转换间隙数量为字节指针
	outfile.write(p, 4);    // 写入间隙数量
}

// 写入边界顶点坐标
void SlcExporter::WriteBoundryVert(float xcord, float ycord)
{
	char* p = (char*)&xcord;    // 转换X坐标为字节指针
	outfile.write(p, 4);    // 写入X坐标
	p = (char*)&ycord;    // 转换Y坐标为字节指针
	outfile.write(p, 4);    // 写入Y坐标
}
