#include "WatchesMedia.h"

WatchesMedia::WatchesMedia(int x, int y, int radius) : Watches(x, y, radius)
{
	second = 0;
	sound = LoadSound("res/tick.wav");
	image = LoadTexture("res/clock.png");
}

WatchesMedia* WatchesMedia::create(int x, int y, int radius)
{
	return new WatchesMedia(x, y, radius);
}

void WatchesMedia::soundTick() const
{
	PlaySound(sound);
}

void WatchesMedia::drawTick() const
{
	if (WindowShouldClose())
	{
		throw "Window is Close!";
	}

	drawTable();
	drawPointer();

	//time_t now = time(nullptr);
	//tm* localTime = localtime(&now);
	//
	//float secondAngle = (localTime->tm_sec % 60) * 6.0f; // ÿ��6��
	//float minuteAngle = (localTime->tm_min % 60) * 6.0f + secondAngle / 60.0f; // ÿ����6��
	//float hourAngle = (localTime->tm_hour % 12) * 30.0f + minuteAngle / 12.0f; // ÿСʱ30��
	//
	//// ��������
	//DrawLineV(position, Vector2{ position.x + radius * cosf(secondAngle * PI / 180.0f),
	//	position.y - radius * sinf(secondAngle * PI / 180.0f) }, RED);
	//
	//// ���Ʒ���
	//DrawLineV(position, Vector2{ position.x + radius * 0.8f * cosf(minuteAngle * PI / 180.0f),
	//	position.y - radius * 0.8f * sinf(minuteAngle * PI / 180.0f) }, GREEN);
	//
	//// ����ʱ��
	//DrawLineV(position, Vector2{ position.x + radius * 0.6f * cosf(hourAngle * PI / 180.0f),
	//	position.y - radius * 0.6f * sinf(hourAngle * PI / 180.0f) }, BLUE);
}

void WatchesMedia::drawTable() const
{

	// ������Բ// ����·ʱ,����ʾ��Բ
	DrawRing(position, static_cast<float>(radius / 2.5) + lineSize / 2.0f,
		static_cast<float>(radius) / 2.5f - lineSize / 2.0f, 0.0f, 360.0f,
		static_cast<int>(0.25 * radius + 1), color);

	float w = static_cast<float>(image.width);
	float h = static_cast<float>(image.height);
	float r = static_cast<float>(radius);
	float length = static_cast<float>(radius * 2 / SQRT2);
	// ���Ʊ���ͼ��
	if (image.width >= image.height)
	{
		DrawTexturePro(image, Rectangle{ (w - h) / 2, 0, h, h },
			Rectangle{ position.x - length / 2, position.y - length / 2, length, length}, Vector2{ 0, 0 }, 0, WHITE);
	}
	else
	{
		RaylibTools::DrawTexture(image, position.x - r, position.y - r, r * 2 / image.width);
		//DrawTexturePro(image, Rectangle{ 0, 0, w, h },
		//	Rectangle{ position.x - r, position.y - r, position.x, position.y }, Vector2{ 0, 0 }, 0, WHITE);
	}
	// ������Բ
	DrawRing(position, static_cast<float>(radius) + lineSize / 2.0f,
		static_cast<float>(radius) - lineSize / 2.0f, 0.0f, 360.0f,
		static_cast<int>(0.25 * radius + 1), color);

	// �������ĵ�
	DrawCircleV(position, static_cast<float>(lineSize * 2), color);

	// Բ��ÿ�����ӻ��ƶ�Ӧ����·
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

void WatchesMedia::eventTick()
{
	// ����ʱ��
	time_t data = time(NULL);
	struct tm* time = localtime(&data);

	if (time->tm_sec != second)
	{
		second = time->tm_sec;  // ���µ�ǰ����
		soundTick();  // ������Ч
	}
}

WatchesMedia::~WatchesMedia()
{
	UnloadSound(sound);  // ж����Ч��Դ
}
