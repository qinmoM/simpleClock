#pragma once

#include "Watches.h"

class WatchesMedia : public Watches
{
protected:
	Sound sound;													// ��Ч����
	int second;														// ��ǰ����,�����ж��Ƿ���Ҫ������Ч
protected:
	WatchesMedia(int x, int y, int radius);							// �������캯��,��ֹ�ⲿֱ�Ӵ�������
public:
	static WatchesMedia* create(int x, int y, int radius);			// ����һ��ʱ�Ӷ���
	virtual void soundTick() const;									// ���ŵδ���,Ĭ���ǲ���һ����Ч�ļ�
	virtual void drawTick() const override;							// ���ݵ�ǰʱ�����
	virtual void eventTick();										// �¼�������
public:
	virtual ~WatchesMedia();										// ��������,ж����Ч��Դ
};

