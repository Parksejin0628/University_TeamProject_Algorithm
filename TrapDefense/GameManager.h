#pragma once
#include"ProgramBase.h"
#include"Unit_algorithm.h"
#include"PrintManager.h"
#include"Trap.h"
#include"Boss.h"



int InputManager();
void PlayInGame();
void InitGame();
void InitRound(int stage);
Unit UnitSpawn(int stagestep); //적 타입 판별
void BFS();
void PrintTitle();
