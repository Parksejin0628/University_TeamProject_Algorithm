#pragma once
#include"PrintManager.h"

extern Field field[FIELD_HEIGHT][FIELD_WIDTH];


void SetColor(unsigned short color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

	return;
}

void Goto_xy(short x, short y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	Position pos = { x, y };
	SetConsoleCursorPosition(handle, pos);
}

void PrintShape(short x, short y, Shape shape, unsigned short color)
{
	SetColor(color);
	Goto_xy(x * TILESIZE, y);
	switch (shape)
	{
	case CIRCLE:
		printf("●");
		break;
	case TRIANGLE:
		printf("▲");
		break;
	case DIAMOND:
		printf("◆");
		break;
	case STAR:
		printf("★");
		break;
	case DOUBLEDIAMOND:
		printf("◈");
		break;
	case SQUARE:
		printf("■");
		break;
	case NEXUS:
		printf("※");
		break;

	}
	SetColor(COLOR_WHITE);
}

void UpdateScreen()
{
	static Field previousField[FIELD_HEIGHT][FIELD_WIDTH];
	static bool isInit = false;
	//한 번도 초기화를 안할 시
	if (!isInit)
	{
		for (int y = 0; y < FIELD_HEIGHT; y++)
		{
			for (int x = 0; x < FIELD_WIDTH; x++)
			{
				switch (field[y][x].type)
				{
				case NONE:
					PrintShape(x + FIELD_POSITION_X, y + FIELD_POSITION_Y, SQUARE, COLOR_WHITE);
					break;
				case BLOCK:
					PrintShape(x + FIELD_POSITION_X, y + FIELD_POSITION_Y, SQUARE, COLOR_GRAY);

					break;
				case TRAP_TEAR1:
					PrintShape(x + FIELD_POSITION_X, y + FIELD_POSITION_Y, CIRCLE, COLOR_BLUE);

					break;
				case TRAP_TEAR2:
					PrintShape(x + FIELD_POSITION_X, y + FIELD_POSITION_Y, TRIANGLE, COLOR_BLUE);

					break;
				case TRAP_TEAR3:
					PrintShape(x + FIELD_POSITION_X, y + FIELD_POSITION_Y, DIAMOND, COLOR_BLUE);

					break;
				case TRAP_TEAR4:
					PrintShape(x + FIELD_POSITION_X, y + FIELD_POSITION_Y, STAR, COLOR_BLUE);

					break;
				case ENEMY:
					PrintShape(x + FIELD_POSITION_X, y + FIELD_POSITION_Y, SQUARE, COLOR_RED);

					break;
				case BOSS:
					PrintShape(x + FIELD_POSITION_X, y + FIELD_POSITION_Y, DOUBLEDIAMOND, COLOR_RED);

					break;
				case BASE:
					PrintShape(x + FIELD_POSITION_X, y + FIELD_POSITION_Y, NEXUS, COLOR_YELLOW);

					break;
				}
			}
		}
	}

	for (int y = 0; y < FIELD_HEIGHT; y++)
	{
		for (int x = 0; x < FIELD_WIDTH; x++)
		{
			if (previousField[y][x].type != field[y][x].type)
			{
				previousField[y][x] = field[y][x];
				switch (field[y][x].type)
				{
				case NONE:
					PrintShape(x + FIELD_POSITION_X, y + FIELD_POSITION_Y, SQUARE, COLOR_WHITE);
					break;
				case BLOCK:
					PrintShape(x + FIELD_POSITION_X, y + FIELD_POSITION_Y, SQUARE, COLOR_GREEN);

					break;
				case TRAP_TEAR1:
					PrintShape(x + FIELD_POSITION_X, y + FIELD_POSITION_Y, CIRCLE, COLOR_BLUE);

					break;
				case TRAP_TEAR2:
					PrintShape(x + FIELD_POSITION_X, y + FIELD_POSITION_Y, TRIANGLE, COLOR_BLUE);

					break;
				case TRAP_TEAR3:
					PrintShape(x + FIELD_POSITION_X, y + FIELD_POSITION_Y, DIAMOND, COLOR_BLUE);

					break;
				case TRAP_TEAR4:
					PrintShape(x + FIELD_POSITION_X, y + FIELD_POSITION_Y, STAR, COLOR_BLUE);

					break;
				case ENEMY:
					PrintShape(x + FIELD_POSITION_X, y + FIELD_POSITION_Y, SQUARE, COLOR_RED);

					break;
				case BOSS:
					PrintShape(x + FIELD_POSITION_X, y + FIELD_POSITION_Y, DOUBLEDIAMOND, COLOR_RED);

					break;
				case BASE:
					PrintShape(x + FIELD_POSITION_X, y + FIELD_POSITION_Y, NEXUS, COLOR_YELLOW);

					break;
				}
			}
		}
	}
}

