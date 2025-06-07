#pragma once

#include "Watches.h"
#include "RaylibTools.h"

#ifndef SQRT2
	#define SQRT2 1.41421356237f	// �������2
#endif

class WatchesMedia : public Watches
{
protected:
	Sound sound;													// ��Ч����
	int second;														// ��ǰ����,�����ж��Ƿ���Ҫ������Ч
	Texture2D image;												// ͼ�����,���ڼ���ʱ��ͼ��
protected:
	WatchesMedia(int x, int y, int radius);							// �������캯��,��ֹ�ⲿֱ�Ӵ�������
public:
	static WatchesMedia* create(int x, int y, int radius);			// ����һ��ʱ�Ӷ���
	virtual void soundTick() const;									// ���ŵδ���,Ĭ���ǲ���һ����Ч�ļ�
	virtual void drawTick() const override;							// ���ݵ�ǰʱ�����
	virtual void drawTable() const override;						// ����ʱ�ӱ���
	virtual void eventTick();										// �¼�������
public:
	virtual ~WatchesMedia();										// ��������,ж����Ч��Դ
};

