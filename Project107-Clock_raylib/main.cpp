#include <raylib.h>
#include <memory>
#include "Watches.h"
#include "WatchesMedia.h"

const int WIDTH = 860;
const int HEIGHT = 640;

int main()
{
	InitWindow(WIDTH, HEIGHT, "clock");  // ��ʼ������
	InitAudioDevice(); // ��ʼ����Ƶ�豸

	// �����
	//std::shared_ptr<Watches> watches(Watches::create(WIDTH / 2, HEIGHT / 2, 220));
	//std::shared_ptr<Watches> watches = std::make_shared<Watches>(Watches::create(WIDTH / 2, HEIGHT / 2, 220));
	std::unique_ptr<WatchesMedia> watchesMedia(WatchesMedia::create(WIDTH / 2, HEIGHT / 2, 220));
	while (!WindowShouldClose())
	{
		BeginDrawing();
		// ˢ�±���
		ClearBackground(WHITE);
		// ����ʱ��
		watchesMedia->drawTick();
		// ������Ч
		watchesMedia->eventTick();
		EndDrawing();
	}
	CloseWindow();  // �رմ���
	CloseAudioDevice(); // �ر���Ƶ�豸
	return 0;
}