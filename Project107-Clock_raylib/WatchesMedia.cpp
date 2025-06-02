#include "WatchesMedia.h"

WatchesMedia::WatchesMedia(int x, int y, int radius) : Watches(x, y, radius)
{
	second = 0;
	sound = LoadSound("res/tick.wav");
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
