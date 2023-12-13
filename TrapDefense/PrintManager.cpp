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
	Goto_xy(x*TILESIZE, y);
	switch (shape)
	{
		

	}
	SetColor(COLOR_WHITE);
}

void UpdateScreen()
{
	static Field previousField[FIELD_HEIGHT][FIELD_WIDTH];
	for (int y = 0; y < FIELD_HEIGHT; y++)
	{
		for (int x = 0; x < FIELD_WIDTH; x++)
		{
			if (previousField[y][x].unit != field[y][x].unit)
			{
				previousField[y][x].unit = field[y][x].unit;
				if (field[y][x].unit == NONE)
				{
					PrintShape(x, y, field[y][x].unit, COLOR_WHITE);
				}
				else if (field[y][x].unit == BLOCK)
				{
					PrintShape(x, y, field[y][x].unit, COLOR_GRAY);
				}
				else if (field[y][x].unit == TRAP_TEAR1)
				{
					PrintShape(x, y, field[y][x].unit, COLOR_GRAY);
				}
				else if (field[y][x].unit == TRAP_TEAR2)
				{
					PrintShape(x, y, field[y][x].unit, COLOR_GRAY);
				}
				else if (field[y][x].unit == TRAP_TEAR3)
				{
					PrintShape(x, y, field[y][x].unit, COLOR_GRAY);
				}
				else if (field[y][x].unit == TRAP_TEAR4)
				{
					PrintShape(x, y, field[y][x].unit, COLOR_GRAY);
				}
				else if(field[y][x].unit == ENEMY)
				{
					PrintShape(x, y, field[y][x].unit, COLOR_RED);
				}
				else if (field[y][x].unit == BOSS)
				{
					PrintShape(x, y, field[y][x].unit, COLOR_BLUE);
				}
				else if (field[y][x].unit == NEXUS)
				{
					PrintShape(x, y, field[y][x].unit, COLOR_YELLOW);
				}
			}
		}
	}
}

