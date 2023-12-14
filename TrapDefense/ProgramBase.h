#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#include<Windows.h>
#include<windows.h>
#include<conio.h>

//플레이어 관련
#define EASY_PLAYER_HP 99
#define NORMAL_PLAYER_HP 60
#define HARD_PLAYER_HP 30
#define HELL_PLAYER_HP 1

//플레이어 관련 재화
#define INIT_TRAP_SEED 10 //초기 함정 설치 개수
#define INIT_BARRICADE_SEED 20//초기 바리케이드 개수
#define INIT_GOLD 0 //초기 골드

//본진 위치
#define NEXUS_XPOS -20
#define NEXUS_YPOS -20

//스테이지는 아마 GameManager에서 건드릴것 같습니다.
//-----------------------------------------//
// GameManager에서 쓸 것들?

//함정 기본 데미지
#define CIRCLE_TRAP_DAMAGE 3
#define TRIANGLE_TRAP_DAMAGE 4
#define DIAMOND_TRAP_DAMAGE 6
#define STAR_TRAP_DAMAGE 10

//적 체력 관련
#define ENEMY_HP 10 //적 초기 체력 hp
#define ENEMY_INIT_NUMBER 10 //적 초기 숫자

//적 스폰 위치
#define ENEMY_SPAWN_XPOS 9
#define ENEMY_SPAWN_YPOS 0

//적 최대 숫자
#define MAX_ENEMY 100

#define NUM_DIRECTIONS 4
#define HEIGHT 30
#define WIDTH 30
#define INF 999999
//화면 관련 변수
#define MIN_CURSOR_Y 5 //최대로 올릴 수 있는 커서 y좌표
#define MAX_CURSOR_Y 23 //최대로 내릴 수 있는 커서 y좌표
#define MIN_CURSOR_X 0 //최대로 올릴 수 있는 커서 y좌표
#define MAX_CURSOR_X 25 //최대로 내릴 수 있는 커서 y좌표
#define FIELD_WIDTH 25
#define FIELD_HEIGHT 25
#define FIELD_POSITION_X 0
#define FIELD_POSITION_Y 2

//입력 관련 변수
#define VK_Q 0x51
#define VK_W 0x57
//프레임 관련 변수
#define FRAMETIME 250


typedef enum {
    WALL,
    CIRCLE,//함정모양
    TRIANGLE,
    DIAMOND,
    STAR,
    DOUBLEDIAMOND,//보스 모양
    SQUARE,//적 모양
    NEXUS,//본진 모양
    UNFILLEDSQUARE // 속이 빈 사각형, □
} Shape;

typedef enum  {
    NONE = 0,
    /* 구조물 */ BLOCK, TRAP_TEAR1, TRAP_TEAR2, TRAP_TEAR3, TRAP_TEAR4, BASE,
    /* 적 */ ENEMY, BOSS
}Type;

typedef struct Trap {
    Type type;
    bool isExist;//트랩 존재하는지 안하는지
    int damage;//트랩 데미지
    int value; //트랩 밸류
    int upgrade;//업그레이드 정보
    int upgradeCost;//업그레이드 비용
    int xpos; //트랩 좌표
    int ypos;
    Shape shape;
}Trap;

typedef struct Unit {
    int HP;
    int xpos;
    int ypos;
    bool isActive;
    bool isBoss;
}Unit;

typedef struct Field
{
    Type type;
    Trap trap;
    Unit unit;
    int direction;
    int X;
    int Y;
    int nextX;
    int nextY;
    int moveCount;
}Field;

typedef struct MapPositionType
{
    int x;
    int y;
    int direction;
} MapPosition;

typedef struct Player {
    int HP;
    int TrapSeed;//트랩 시드
    int BarricadeSeed;//바리케이드 시드
    int Gold;
    int Score;
    int PlayerXpos;
    int PlayerYpos;
    int stage;
    int cursorX;
    int cursorY;
    int nowUnitCount;
    int maxUnitCount;
    int deadUnitCount;
}Player;



#pragma warning(disable:4996)