#ifndef __RAYLIBTOOLS_HPP__
#define __RAYLIBTOOLS_HPP__

#include <raylib.h>

class RaylibTools
{
public:
	// 默认圆环颜色
	static Color colorCircleLine;
public:
	// 设置全局颜色// color: 全局颜色
	static void SetColor(Color color);


	// 绘制一个圆环// centerX, centerY: 圆心x,y坐标 radius: 圆环半径 size: 圆环线条宽度 color: 圆环颜色
	static void DrawCircleLine(int centerX, int centerY, float radius, int size, Color color);
	// 绘制相同颜色圆环// centerX, centerY: 圆心x,y坐标 radius: 圆环半径 size: 圆环线条宽度
	static void DrawCircleLine(int centerX, int centerY, float radius, int size);


	// 绘制纹理图像// texture: 纹理对象 x, y: 绘制位置 percent: 缩放比例
	static void DrawTexture(Texture2D texture, float x, float y, float percent);
};

#endif // __RAYLIBTOOLS_HPP__