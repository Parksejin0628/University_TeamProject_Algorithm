#pragma once
#include"ProgramBase.h"
#include"Unit_algorithm.h"
extern int stagestep;
int TrapSignal();//트랩 설치 시그널
Trap InitTrap(int xpos, int ypos);//트랩 설치
void TrapUpgrade(Trap* trap); //함정 업그레이드 damage = (int)(damage*1.3) 비용은 (int)(damage*1.3) 이것 만큼