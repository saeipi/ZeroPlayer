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

#include <iostream>
using namespace std;
//Ҫ����c���Ժ���
extern "C"{
	#include <libavcodec/avcodec.h>
}
//Ԥ����ָ����
#pragma comment(lib,"avcodec.lib")
int main(int argc,char *argv[])
{
	//��ʾffmpeg�ı�������
	cout << "Test FFmpeg.club" << endl;
#ifdef _WIN32 //32λ��64λ win
    #ifdef _WIN64 //64λ win
        cout << "Windows X64" << endl;
    #else
        cout << "Windows X86" << endl;
    #endif
#else
	cout << "Linux" << endl;
#endif
	cout << avcodec_configuration() << endl;
	getchar();
	return 0;
}
