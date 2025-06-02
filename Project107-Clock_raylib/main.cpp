#include <raylib.h>
#include <memory>
#include "Watches.h"

const int WIDTH = 860;
const int HEIGHT = 640;

int main()
{
	InitWindow(WIDTH, HEIGHT, "clock"); 
	// �����
	std::shared_ptr<Watches> watches(Watches::create(WIDTH / 2, HEIGHT / 2, 220));
	//std::shared_ptr<Watches> watches = std::make_shared<Watches>(Watches::create(WIDTH / 2, HEIGHT / 2, 220));
	while (!WindowShouldClose())
	{
		BeginDrawing();
		// ˢ�±���
		ClearBackground(WHITE);
		watches->drawTick();
		EndDrawing();
	}
	CloseWindow();
	return 0;
}