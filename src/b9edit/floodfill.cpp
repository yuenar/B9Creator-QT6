/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    b9edit
 * 文件名:     floodfill.cpp
 * 模块功能:   洪水填充实现文件，定义洪水填充相关类和接口
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/
#include "floodfill.h"


void floodFill(QImage* pImage, int x, int y, QColor fillColor)
{
    // 如果初始化像素已经填充颜色,则完成
    if (pImage->pixel(x,y) == fillColor.rgb()) return;

	int startcolor = pImage->pixel(x,y);

    //创建像素队列。假设最坏的情况下，图像的每个像素可能都在队列中。
	int pixelQueueSize = 0;
	int *pixelQueue= new int[pImage->width() * pImage->height()];
	
    // 添加初始化像素到队列(我们创建整数(int)的单一数组,
    // 即使我们仅仅入队两个数字. 我们把y值在
    //高16位的整数，并且把X值数据存放在在下部16位。
    // 则可能最大像素阈值为65536x65536.)
    pixelQueue[0] = (y << 16) + x;
    pixelQueueSize = 1;
  
    // 初始化像素颜色
	pImage->setPixel(x,y,fillColor.rgb());

    // 持续运行当队列中已有像素
    while (pixelQueueSize > 0){
  
        // 获取在队列中的下一个像素的x和y值
		x = pixelQueue[0] & 0xffff;
		y = (pixelQueue[0] >> 16) & 0xffff;
      
        //从队列中删除第一个像素。不是将所有的
        //队列中的像素，而是只取一个像素
        //并将其移动到开始位置（顺序无关紧要这里）。
		pixelQueueSize--;
		pixelQueue[0] = pixelQueue[pixelQueueSize];
    
        //查看图片左侧的象素是否已被绘制
        //如果没有，绘制它，并把它添加到队列。
		if (x > 0) {
		if ( pImage->pixel(x-1, y) == startcolor )
		{
			pImage->setPixel(x-1, y, fillColor.rgb());
			pixelQueue[pixelQueueSize] = (y << 16) + x-1;
			pixelQueueSize++;
		}
		}

        //查看图片底部的象素是否已被绘制
        //如果没有，绘制它，并把它添加到队列。
		if (y > 0) {
			if ( pImage->pixel(x, y-1) == startcolor )
			{
				pImage->setPixel(x, y-1, fillColor.rgb());
				pixelQueue[pixelQueueSize] = ((y-1) << 16) + x;
				pixelQueueSize++;
			}
		}
   
        //查看图片右侧的象素是否已被绘制
        //如果没有，绘制它，并把它添加到队列。
		if (x < pImage->width()-1) {
			if ( pImage->pixel(x+1, y) == startcolor )
			{
				pImage->setPixel(x+1, y, fillColor.rgb());
				pixelQueue[pixelQueueSize] = (y << 16) + x+1;
				pixelQueueSize++;
			}
		}
    
        //查看图片顶部的象素是否已被绘制
        //如果没有，绘制它，并把它添加到队列。
		if (y < pImage->height()-1) {
			if ( pImage->pixel(x, y+1) == startcolor )
			{
				pImage->setPixel(x, y+1, fillColor.rgb());
				pixelQueue[pixelQueueSize] = ((y+1) << 16) + x;
				pixelQueueSize++;
			}
		}
	}
	delete [] pixelQueue;
}
