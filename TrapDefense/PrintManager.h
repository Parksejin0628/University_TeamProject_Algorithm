#pragma once
#include"ProgramBase.h"
#include"GameManager.h"

#define TILESIZE 2

enum Color
{
	COLOR_BLACK = 0, COLOR_BLUE, COLOR_GREEN, COLOR_BLUEGREEN, COLOR_RED, COLOR_PURPLE, COLOR_YELLOW, COLOR_WHITE,
	COLOR_GRAY, COLOR_LIGHTBLUE, COLOR_LIGHTGREEN, COLOR_LIGHTBLUEGREEN, COLOR_LIGHTRED, COLOR_LIGHTPURPLE, COLOR_LIGHTYELLOW, COLOR_LIGHTWHITE
};

typedef COORD Position;

void SetColor(unsigned short color);	//����� ���� ��ȭ��Ű�� �Լ�
void Goto_xy(short x, short y);	//��� ���� �κ��� x, y�κ����� �ű�, ��������� (0, 0)�̴�. ����� �����ϸ� ���ϴ�.
void PrintShape(short x, short y, Unit unit, unsigned short color);	//�ܼ��� x, y��ǥ�� color ������ shape�� ���
void UpdateScreen();