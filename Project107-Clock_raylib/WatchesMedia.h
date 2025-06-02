#pragma once

#include "Watches.h"

class WatchesMedia : public Watches
{
protected:
	Sound sound;													// 音效对象
	int second;														// 当前秒数,用于判断是否需要播放音效
protected:
	WatchesMedia(int x, int y, int radius);							// 保护构造函数,禁止外部直接创建对象
public:
	static WatchesMedia* create(int x, int y, int radius);			// 创建一个时钟对象
	virtual void soundTick() const;									// 播放滴答声,默认是播放一个音效文件
	virtual void drawTick() const override;							// 根据当前时间绘制
	virtual void eventTick();										// 事件处理函数
public:
	virtual ~WatchesMedia();										// 析构函数,卸载音效资源
};

