/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    utils
 * 文件名:     QVirtualSerialPort.cpp
 * 模块功能:   虚拟串口实现文件，包含虚拟串口的具体实现
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/

#include "QVirtualSerialPort.h"

QVirtualSerialPort::QVirtualSerialPort(QObject *parent):QSerialPort(parent)
{
	setPortName(QLatin1String("virtual"));
	projectorPower="P0\n";
}


QVirtualSerialPort::~QVirtualSerialPort(void)
{
}

QByteArray QVirtualSerialPort::readAll()
{
//	QByteArray bytes("abc");
	QByteArray bytes = m_Bufbytes;
	m_Bufbytes.clear();
	return bytes; 
}
qint64 QVirtualSerialPort::write(const QByteArray &data)
{
	QString strCmd = QString(data);
	if(strCmd =="R\n")
	{
		m_Bufbytes.append("R0\n");
		m_Bufbytes.append("X1\n");
	}else if(strCmd=="P1\n"){
		projectorPower="P1\n";
	}
	else if(strCmd=="S\n"){
		m_Bufbytes.append("S100\n");
		m_Bufbytes.append("F\n");
	}else if(strCmd=="B0\n"){
		m_Bufbytes.append("F\n");
	}
	else if(strCmd=="N0\n"){
		m_Bufbytes.append("F\n");
	}
	else{
		m_Bufbytes.append(data);
	}
	QTimer::singleShot(100, this, SLOT(emitReadReady()));
	return data.length(); 
}
bool QVirtualSerialPort::open(OpenMode mode)
{
	write("V1 1 2\n");
	write("WB9C1\n");
	startWatchDogTimer();
	return isOpen();
}
void QVirtualSerialPort::emitReadReady()
{
	emit readyRead();
}
void QVirtualSerialPort::startWatchDogTimer()
{
    // 看门狗每10秒唤醒（调用）一次
	timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(watchDog()));
    timer->start(2000);
   // QTimer::start(2000, this, SLOT(watchDog())); // 每10秒检查一次
}
void QVirtualSerialPort::watchDog()
{
	write(projectorPower.toLatin1());
}
