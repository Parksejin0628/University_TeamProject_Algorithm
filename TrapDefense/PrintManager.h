#pragma once
#include"ProgramBase.h"

enum Color
{
	COLOR_BLACK = 0, COLOR_BLUE, COLOR_GREEN, COLOR_BLUEGREEN, COLOR_RED, COLOR_PURPLE, COLOR_YELLOW, COLOR_WHITE,
	COLOR_GRAY, COLOR_LIGHTBLUE, COLOR_LIGHTGREEN, COLOR_LIGHTBLUEGREEN, COLOR_LIGHTRED, COLOR_LIGHTPURPLE, COLOR_LIGHTYELLOW, COLOR_LIGHTWHITE
};

typedef COORD Position;

static void SetColor(unsigned short color);	//����� ���� ��ȭ��Ű�� �Լ�
static void Goto_xy(short x, short y);	//��� ���� �κ��� x, y�κ����� �ű�, ��������� (0, 0)�̴�. ����� �����ϸ� ���ϴ�.
static void PrintShape(short x, short y, char shape, unsigned short color);	//�ܼ��� x, y��ǥ�� color ������ shape�� ���