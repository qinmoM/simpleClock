#include "Watches.h"

Watches::Watches(int x, int y, int radius) : radius(radius), lineSize(2), color(BLACK)
{
	position.x = static_cast<float>(x);
	position.y = static_cast<float>(y);
}

Watches* Watches::create(int x, int y, int radius)
{
	return new Watches(x, y, radius);
}

void Watches::drawTick() const
{
	if (WindowShouldClose())
	{
		throw "Window is Close!";
	}
	drawTable();
	drawPointer();
}

void Watches::drawTable() const
{
	// 绘制外圆
	DrawRing(position, static_cast<float>(radius) + lineSize / 2.0f,
		static_cast<float>(radius) - lineSize / 2.0f, 0.0f, 360.0f,
		static_cast<int>(0.25 * radius + 1), color);

	// 绘制内圆
	DrawRing(position, static_cast<float>(radius / 2.5) + lineSize / 2.0f,
		static_cast<float>(radius) / 2.5f - lineSize / 2.0f, 0.0f, 360.0f,
		static_cast<int>(0.25 * radius + 1), color);

	// 绘制中心点
	DrawCircleV(position, static_cast<float>(lineSize * 2), color);

	// 圆周每个格子绘制对应的纹路
	int x, y;
	for (int i = 0; i < 60; i++)
	{
		x = static_cast<int>(position.x + 0.89 * radius * std::sinf(i * 2 * PI / 60));
		y = static_cast<int>(position.y - 0.89 * radius * std::cosf(i * 2 * PI / 60));
		if (!(i % 15))
		{
			int s = radius / 30;
			Rectangle rect = { static_cast<float>(x - s), static_cast<float>(y - s), s * 2.0f, s * 2.0f };
			DrawRectangleRec(rect, color);
		}
		else if (!(i % 5))
		{
			DrawCircle(x, y, static_cast<float>(lineSize * 2.5), color);
		}
		else
		{
			x = static_cast<int>(position.x + 0.9 * radius * std::sinf(i * 2 * PI / 60));
			y = static_cast<int>(position.y - 0.9 * radius * std::cosf(i * 2 * PI / 60));
			DrawCircle(x, y, static_cast<float>(lineSize), color);
		}
	}
}

void Watches::drawPointer() const
{
	// 加载时间
	time_t data = time(NULL);
	struct tm* time = localtime(&data);

	// 计算弧度的xy等
	int secX = static_cast<int>(0.8f * radius * std::sinf(time->tm_sec * 2 * PI / 60));
	int secY = static_cast<int>(-0.8f * radius * std::cosf(time->tm_sec * 2 * PI / 60));
	int minX = static_cast<int>(0.65f * radius * std::sinf(time->tm_min * 2 * PI / 60));
	int minY = static_cast<int>(-0.65f * radius * std::cosf(time->tm_min * 2 * PI / 60));
	int hourX = static_cast<int>(0.45f * radius * std::sinf((time->tm_hour * 5 + time->tm_min / 12.0f) * 2 * PI / 60));
	int hourY = static_cast<int>(-0.45f * radius * std::cosf((time->tm_hour * 5 + time->tm_min / 12.0f) * 2 * PI / 60));

	// 绘制秒针
	DrawLineEx({ position.x + secX, position.y + secY },
		{ position.x - secX / 4, position.y - secY / 4 }, lineSize * 1.0f, color);
	// 绘制分针
	DrawLineEx({ position.x + minX, position.y + minY },
		{ position.x - minX / 4, position.y - minY / 4 }, lineSize * 2.0f, color);
	// 绘制时针
	DrawLineEx({ position.x + hourX, position.y + hourY },
		{ position.x - hourX / 4, position.y - hourY / 4 }, lineSize * 3.0f, color);
}

void Watches::setLine(int size)
{
	lineSize = size;
}

void Watches::setColor(Color color)
{
	this->color = color;
}

Vector2 Watches::getPosition() const
{
	return position;
}
