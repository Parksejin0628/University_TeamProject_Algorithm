#pragma once
#include"ProgramBase.h"
#include"Unit_algorithm.h"
#include"PrintManager.h"

#define FIELD_WIDTH 25
#define FIELD_HEIGHT 25
#define FIELD_POSITION_X 0
#define FIELD_POSITION_Y 2

int InputManager();
void PlayInGame();
void InitGame();
void InitRound(int stage);
Unit UnitSpawn(int stagestep); //적 타입 판별

