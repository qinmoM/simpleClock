#pragma once

#define  _CRT_SECURE_NO_WARNINGS

#include <raylib.h>
#include <cmath>
#include <ctime>

#ifndef PI
	#define PI 3.1415926f
#endif

class Watches
{
protected:
	Vector2 position;
	int radius;
	int lineSize;
	Color color;
protected:
	Watches(int x, int y, int radius);
public:
	static Watches* create(int x, int y, int radius);
	virtual void drawTick() const;							// ���ݵ�ǰʱ�����
	virtual void drawTable() const;							// ���Ʊ���
	virtual void drawPointer() const;						// ����ָ��
	void setLine(int size);									// ����������ϸ,Ĭ����2
	void setColor(Color color);								// ������ɫ,Ĭ���Ǻ�
	Vector2 getPosition() const;							// ��ȡλ��
public:
	virtual ~Watches() = default;							// ��������
};

