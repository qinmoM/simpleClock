#include <raylib.h>
#include <memory>
#include "Watches.h"
#include "WatchesMedia.h"

const int WIDTH = 860;
const int HEIGHT = 640;

int main()
{
	InitWindow(WIDTH, HEIGHT, "clock");  // 初始化窗口
	InitAudioDevice(); // 初始化音频设备

	// 表对象
	//std::shared_ptr<Watches> watches(Watches::create(WIDTH / 2, HEIGHT / 2, 220));
	//std::shared_ptr<Watches> watches = std::make_shared<Watches>(Watches::create(WIDTH / 2, HEIGHT / 2, 220));
	std::unique_ptr<WatchesMedia> watchesMedia(WatchesMedia::create(WIDTH / 2, HEIGHT / 2, 220));
	while (!WindowShouldClose())
	{
		BeginDrawing();
		// 刷新背景
		ClearBackground(WHITE);
		// 绘制时钟
		watchesMedia->drawTick();
		// 播放音效
		watchesMedia->eventTick();
		EndDrawing();
	}
	CloseWindow();  // 关闭窗口
	CloseAudioDevice(); // 关闭音频设备
	return 0;
}