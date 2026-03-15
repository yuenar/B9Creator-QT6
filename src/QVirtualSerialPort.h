/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    utils
 * 文件名:     QVirtualSerialPort.h
 * 模块功能:   虚拟串口头文件，定义虚拟串口相关类和接口
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#pragma once
#include <QSerialPort>
#include <QTimer>
class QVirtualSerialPort :
	public QSerialPort
{
	Q_OBJECT
public:
	QVirtualSerialPort(QObject *parent);
	QByteArray readAll();
	qint64 write(const QByteArray &data);
	bool open(OpenMode mode);
	void startWatchDogTimer();
	bool isOpen(){return true;}
	~QVirtualSerialPort(void);
	
	// 重写setDataTerminalReady方法，虚拟串口不需要硬件控制
	bool setDataTerminalReady(bool set) { Q_UNUSED(set); return true; }
private:
	QByteArray m_Bufbytes;
	QTimer *timer;
	QString projectorPower;
public slots:
	void emitReadReady();
	void watchDog();
};

