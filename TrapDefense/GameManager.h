#pragma once
#include"ProgramBase.h"
#include"Unit_algorithm.h"
#define FIELD_WIDTH 54
#define FIELD_HEIGHT 32

enum Unit { NONE = 0, 
	/* 구조물 */ BLOCK, TRAP_TEAR1, TRAP_TEAR2, TRAP_TEAR3, TRAP_TEAR4,
	/* 적 */ ENEMY, BOSS, NEXUS };

typedef struct Field
{
	Unit unit;
	Enemy enemy;
	Trap trap;
	int nextX;
	int nextY;
};

char inputManager();