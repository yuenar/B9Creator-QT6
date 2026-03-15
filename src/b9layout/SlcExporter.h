/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    b9layout
 * 文件名:     SlcExporter.h
 * 模块功能:   SLC导出器头文件，定义SLC文件导出相关类和接口
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期:  2026-03-15
 *    修改内容:  迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#pragma once

// STL相关头文件
#include <fstream>    // 文件流
#include <string>     // 字符串

// 注释掉的命名空间使用
//using namespace std;

// SlcExporter类 - SLC文件导出器
class SlcExporter
{
public:
	SlcExporter(std::string filename);    // 构造函数，指定文件名
	~SlcExporter(void);    // 析构函数
	bool SuccessOpen(){return opened;}    // 检查文件是否成功打开

	void WriteHeader(bool unitsINCH = false, bool unitsMM = true, std::string headerstring = "");    // 写入文件头
	void WriteReservedSpace();    // 写入保留空间
	void WriteSampleTableSize(char ntables);    // 写入采样表大小
	void WriteSampleTable(float minz, float layerthick, float linewidthcomp, float reserved = 0.0);    // 写入采样表
	void WriteNewSlice(float zaltitude, unsigned int numboundries);    // 写入新切片
	void WriteBoundryHeader(unsigned int numvertices, unsigned int numgaps);    // 写入边界头
	void WriteBoundryVert(float xcord, float ycord);    // 写入边界顶点

private:
	// 私有成员变量
	std::string filename;    // 文件名
	std::ofstream outfile;    // 输出文件流
	bool opened;    // 文件打开状态标志
};

 
