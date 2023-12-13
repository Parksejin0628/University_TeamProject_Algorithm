#pragma once
#include"ProgramBase.h"
#include"Unit_algorithm.h"

typedef struct Trap {
    bool isExist;//트랩 존재하는지 안하는지
    int damage;//트랩 데미지
    int upgrade;//업그레이드 정보
    int upgraseCost;//업그레이드 비용
    int xpos; //트랩 좌표
    int ypos;
    Shape shape;//트랩 모양
}Trap;

struct Trap;

int TrapSignal();//트랩 설치 시그널
Trap InitTrap(int xpos, int ypos);//트랩 설치
void TrapUpgrade(Trap* trap); //함정 업그레이드 damage = (int)(damage*1.3) 비용은 (int)(damage*1.3) 이것 만큼