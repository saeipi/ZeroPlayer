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




#include "XVideoThread.h"
#include "XDecode.h"
#include <iostream>
using namespace std;
//�򿪣����ܳɹ��������
bool XVideoThread::Open(AVCodecParameters *para, IVideoCall *call,int width,int height)
{
	if (!para)return false;
	Clear();

	vmux.lock();
	synpts = 0;
	//��ʼ����ʾ����
	this->call = call;
	if (call)
	{
		call->Init(width, height);
	}
	vmux.unlock();
	int re = true;
	if (!decode->Open(para))
	{
		cout << "audio XDecode open failed!" << endl;
		re = false;
	}
	
	cout << "XAudioThread::Open :" << re << endl;
	return re;
}
void XVideoThread::SetPause(bool isPause)
{
	vmux.lock();
	this->isPause = isPause;
	vmux.unlock();
}
void XVideoThread::run()
{
	while (!isExit)
	{
		vmux.lock();
		if (this->isPause)
		{
			vmux.unlock();
			msleep(5);
			continue;
		}
		//cout << "synpts = " << synpts << " dpts =" << decode->pts << endl;
		//����Ƶͬ��
		if (synpts >0 && synpts < decode->pts)
		{
			vmux.unlock();
			msleep(1);
			continue;
		}
		AVPacket *pkt = Pop();
		bool re = decode->Send(pkt);
		if (!re)
		{
			vmux.unlock();
			msleep(1);
			continue;
		}
		//һ��send ���recv
		while (!isExit)
		{
			AVFrame * frame = decode->Recv();
			if (!frame)break;
			//��ʾ��Ƶ
			if (call)
			{
				call->Repaint(frame);
			}

		}
		vmux.unlock();
	}
}
//����pts��������յ��Ľ�������pts >= seekpts return true ������ʾ����
bool XVideoThread::RepaintPts(AVPacket *pkt, long long seekpts)
{
	vmux.lock();
	bool re = decode->Send(pkt);
	if (!re)
	{
		vmux.unlock();
		return true; //��ʾ��������
	}
	AVFrame *frame = decode->Recv();
	if (!frame)
	{
		vmux.unlock();
		return false;
	}
	//����λ��
	if (decode->pts >= seekpts)
	{
		if(call)
			call->Repaint(frame);
		vmux.unlock();
		return true;
	}
	XFreeFrame(&frame);
	vmux.unlock();
	return false;
}
XVideoThread::XVideoThread()
{
}


XVideoThread::~XVideoThread()
{

}
