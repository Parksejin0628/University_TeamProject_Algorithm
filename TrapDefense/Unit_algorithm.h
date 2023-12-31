﻿#pragma once
#include"ProgramBase.h"
#include"GameManager.h"
#include"BFS.h"
//플레이어 정보



void UnitMove(Field maze[WIDTH][HEIGHT], MapPosition* start, MapPosition* end); //기본 적 움직임->BFS로 최단거리, 보스는 다르게 움직임->BFS + 함정에 덜맞게
void UnitDamage(Unit* enemy, Trap* trap);//적과 함정의 위치 비교후, Trap->damage만큼 HP감소, HP<=0이하로 떨어지면 isActive = false
bool isCrashWithPlayer(Unit* enemy, Player* player);//플레이어 본진과 같은 좌표에 있는지 판단
bool isCrashWithTrap(Unit* enemy, Trap* trap);//함정의 위치와 적의 위치가 같은 위치에 있는지 판단
void PlayerHPDecrease(Unit* enemy, Player* player);
