#pragma once
#include"ProgramBase.h"

//플레이어 관련
#define EASY_PLAYER_HP 99
#define NORMAL_PLAYER_HP 60
#define HARD_PLAYER_HP 30
#define HELL_PLAYER_HP 1
//재화 관련
#define SEED_INIT 500 //함정 설치가능한 재화
//함정 관련
#define TRIANGLE_TRAP_DAMAGE 3
#define RECTANGLE_TRAP_DAMAGE 4
#define HEXAGON_TRAP_DAMAGE 6
#define STAR_TRAP_DAMAGE 10
#define TRAP_SET_UP_SEED 30//함정 설치 비용
//적 유닛 관련
#define Enemy_HP 3 //적 유닛 초기 hp
//본진 좌표 관련
#define NEXUS_XPOS 0
#define NEXUS_YPOS 0

typedef struct Nexus {
    int xpos;
    int ypos;
}Nexus;
//플레이어 관련 정보
typedef struct Player {
    int HP;
    int Seed;
    int Gold;
    Nexus nexus;
}Player;
Player player;
typedef enum {
    TRIANGLE,
    RECTANGLE,
    HEXAGON,
    STAR,
    Circle
} Shape;
typedef struct Trap {
    int damage;
    int xpos;
    int ypos;
    Shape shape;
}Trap;
typedef struct Enemy {
    int HP;
    int xpos;
    int ypos;
    Shape shape;
}Enemy;
typedef struct EnemySpawner {
    int empty;
}EnemySpawner;

void InitGame();
int TrapSignal();//트랩 설치 신호를 보냄
Trap InitTrap();//신호에 맞는 트랩 생성
void EnemySpawn(); //적 유닛 생성함수
void EnemyMove(); //적 유닛 이동함수
void EnemyDamage(Enemy* enemy, Trap* trap);//적 유닛이 함정을 지나가면 데미지를 입는다.
bool isCrashWithPlayer(Enemy* enemy, Player* player);
bool isCrashWithTrap(Enemy* enemy, Trap* trap);
void TrapUpgrade(); //업그레이드 알고리즘 사용
void PlayerHPDecrease(Enemy* enemy, Player* player);
void IsNextStage();
void InitNexus();