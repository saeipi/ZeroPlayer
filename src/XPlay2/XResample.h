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
struct AVCodecParameters;
struct AVFrame;
struct SwrContext;
#include <mutex>
class XResample
{
public:

	//����������������һ�³��˲�����ʽ�����ΪS16 ,���ͷ�para
	virtual bool Open(AVCodecParameters *para,bool isClearPara = false);
	virtual void Close();

	//�����ز������С,���ܳɹ�����ͷ�indata�ռ�
	virtual int Resample(AVFrame *indata, unsigned char *data);
	XResample();
	~XResample();

	//AV_SAMPLE_FMT_S16
	int outFormat = 1;
protected:
	std::mutex mux;
	SwrContext *actx = 0;
};

