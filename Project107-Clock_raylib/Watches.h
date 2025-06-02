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
	virtual void drawTick() const;							// 根据当前时间绘制
	virtual void drawTable() const;							// 绘制表盘
	virtual void drawPointer() const;						// 绘制指针
	void setLine(int size);									// 设置线条粗细,默认是2
	void setColor(Color color);								// 设置颜色,默认是黑
	Vector2 getPosition() const;							// 获取位置
public:
	virtual ~Watches() = default;							// 析构函数
};

