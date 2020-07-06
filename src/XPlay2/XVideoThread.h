/*******************************************************************************
**                                                                            **
**                     Jiedi(China nanjing)Ltd.                               **
**	               �������Ĳܿ����˴��������Ϊѧϰ�ο�                       **
*******************************************************************************/

/*****************************FILE INFOMATION***********************************
**
** Project       : FFmpeg
** Description   : FFMPEG��Ŀ����ʾ��
** Contact       : xiacaojun@qq.com
**        ����   : http://blog.csdn.net/jiedichina
**		��Ƶ�γ�
**�����ƿ���	http://study.163.com/u/xiacaojun
**��Ѷ����		https://jiedi.ke.qq.com/
**csdnѧԺ		http://edu.csdn.net/lecturer/lecturer_detail?lecturer_id=961
**51ctoѧԺ	    http://edu.51cto.com/lecturer/index/user_id-12016059.html
**�������µ�ffmpeg�汾 http://www.ffmpeg.club
**
**   ffmpeg+qt������ ѧԱȺ ��462249121 ����Ⱥ���ش���ͽ���
**   ΢�Ź��ں�  : jiedi2007
**		ͷ����	 : �Ĳܿ�
**
*******************************************************************************/
//������������������ ѧԱ��Ⱥ462249121���ش���ͽ���




#pragma once

///�������ʾ��Ƶ
struct AVPacket;
struct AVCodecParameters;
class XDecode;
#include <list>
#include <mutex>
#include <QThread>
#include "IVideoCall.h"
#include "XDecodeThread.h"
class XVideoThread:public XDecodeThread
{
public:

	//����pts��������յ��Ľ�������pts >= seekpts return true ������ʾ����
	virtual bool RepaintPts(AVPacket *pkt, long long seekpts);
	//�򿪣����ܳɹ��������
	virtual bool Open(AVCodecParameters *para,IVideoCall *call,int width,int height);
	void run();
	XVideoThread();
	virtual ~XVideoThread();
	//ͬ��ʱ�䣬���ⲿ����
	long long synpts = 0;

	void SetPause(bool isPause);
	bool isPause = false;
protected:
	IVideoCall *call = 0;
	std::mutex vmux;


};

