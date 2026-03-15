/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    b9edit
 * 文件名:     floodfill.h
 * 模块功能:   洪水填充头文件，定义洪水填充相关类和接口
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#include <QImage>
#include <QColor>

void floodFill(QImage* pImage, int xPos, int yPos, QColor fillColor = QColor(255,255,255));
