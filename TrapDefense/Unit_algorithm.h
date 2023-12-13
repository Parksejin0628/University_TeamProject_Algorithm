#pragma once
#include"ProgramBase.h"
#include"Trap.h"
#include"BFS.h"

//플레이어 정보
typedef struct Player {
    int HP;
    int TrapSeed;//트랩 시드
    int BarricadeSeed;//바리케이드 시드
    int Gold;
    int Score;
    int PlayerXpos;
    int PlayerYpos;
}Player;

Player player = { 50,
INIT_TRAP_SEED,
INIT_BARRICADE_SEED,
INIT_GOLD,
0,
NEXUS_XPOS,
NEXUS_YPOS};


typedef struct Unit {
    int HP;//HP
    int xpos;
    int ypos;
    Shape shape;
    bool isActive;
    bool isBoss;
}Unit;

Unit UnitSpawn(); //적 타입 판별
void UnitMove(); //기본 적 움직임->BFS로 최단거리, 보스는 다르게 움직임->BFS + 함정에 덜맞게
void UnitDamage(Unit* enemy, Trap* trap);//적과 함정의 위치 비교후, Trap->damage만큼 HP감소, HP<=0이하로 떨어지면 isActive = false
bool isCrashWithPlayer(Unit* enemy, Player* player);//플레이어 본진과 같은 좌표에 있는지 판단
bool isCrashWithTrap(Unit* enemy, Trap* trap);//함정의 위치와 적의 위치가 같은 위치에 있는지 판단
void PlayerHPDecrease(Unit* enemy, Player* player);
