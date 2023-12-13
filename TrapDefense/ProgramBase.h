#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#include<Windows.h>
#include<conio.h>

//플레이어 관련
#define EASY_PLAYER_HP 99
#define NORMAL_PLAYER_HP 60
#define HARD_PLAYER_HP 30
#define HELL_PLAYER_HP 1

//플레이어 관련 재화
#define INIT_TRAP_SEED 3 //초기 함정 설치 개수
#define INIT_BARRICADE_SEED 5//초기 바리케이드 개수
#define INIT_GOLD 0 //초기 골드

//본진 위치
#define NEXUS_XPOS -20
#define NEXUS_YPOS -20

//스테이지 정보
int stagestep = 1;
//스테이지는 아마 GameManager에서 건드릴것 같습니다.
//-----------------------------------------//
// GameManager에서 쓸 것들?

//함정 기본 데미지
#define CIRCLE_TRAP_DAMAGE 3
#define TRIANGLE_TRAP_DAMAGE 4
#define DIAMOND_TRAP_DAMAGE 6
#define STAR_TRAP_DAMAGE 10

//적 체력 관련
#define ENEMY_HP 3 //적 초기 체력 hp
#define ENEMY_INIT_NUMBER 10 //적 초기 숫자

//적 스폰 위치
#define ENEMY_SPAWN_XPOS 0
#define ENEMY_SPAWN_YPOS 0

//적 최대 숫자
#define MAX_ENEMY 100

typedef enum {
    WALL,
    CIRCLE,//함정모양
    TRIANGLE,
    DIAMOND,
    STAR,
    DOUBLEDIAMOND,//보스 모양
    SQUARE//적 모양
} Shape;
#pragma warning(disable:4996)