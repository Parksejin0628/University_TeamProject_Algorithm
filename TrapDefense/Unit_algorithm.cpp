#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
//플레이어 관련
#define EASY_PLAYER_HP 99
#define NORMAL_PLAYER_HP 60
#define HARD_PLAYER_HP 30
#define HELL_PLAYER_HP 1

//재화 관련
#define SEED_INIT 500 //함정 설치가능한 재화
#define GOLD_INIT 0 //함정 업그레이드 가능한 재화
#define REWARD_GOLD 10//적 처리시 골드 보상
#define REWARD_SEED 10//적 처리시 확률적으로 SEED 획득한 양
#define RANDOM_REWARD_SEED 50//Seed 확률 랜덤으로 획득 50퍼로 임의로 설정

//함정 관련
#define TRIANGLE_TRAP_DAMAGE 3
#define RECTANGLE_TRAP_DAMAGE 4
#define HEXAGON_TRAP_DAMAGE 6
#define STAR_TRAP_DAMAGE 10
#define TRAP_SET_UP_SEED 30//함정 설치 비용

//적 유닛 관련
#define ENEMY_HP 3 //적 유닛 초기 hp
#define ENEMY_INIT_NUMBER 10

//본진 좌표 관련
#define NEXUS_XPOS -20
#define NEXUS_YPOS -20

//스테이지 관련
int stagestep = 1;
//본진 좌표 - 너비추가 해야 될지는 이번주 피드백을 통해... 탑뷰라 필요 없을 수도?

//적 스폰 위치
#define ENEMY_SPAWN_XPOS 20
#define ENEMY_SPAWN_YPOS 20

//메인함수 Enemy 타입 배열 생성위해 만듦
#define MAX_ENEMY 100
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
    int damage;//트랩 데미지
    int upgrade;//트랩의 업그레이드 단계
    int xpos;
    int ypos;
    Shape shape;
}Trap;

typedef struct Enemy {
    int HP;
    int value;//적이 3라운드마다 hp가 상승하기 때문에 value로 지정
    int xpos;
    int ypos;
    Shape shape;
    bool isActive;
}Enemy;

typedef struct EnemySpawner {
    int xpos;
    int ypos;
};
void InitGame() {
    int difficultySelection;

    while (1) {
        printf("난이도를 선택하세요\n");
        printf("Easy : 1, Normal : 2, Hard : 3, Hell : 4\n");
        scanf("%d", &difficultySelection);
        player.Seed = SEED_INIT;
        player.Gold = GOLD_INIT;

        if (difficultySelection >= 1 && difficultySelection <= 4) {
            switch (difficultySelection) {
            case 1:
                player.HP = EASY_PLAYER_HP;
                break;
            case 2:
                player.HP = NORMAL_PLAYER_HP;
                break;
            case 3:
                player.HP = HARD_PLAYER_HP;
                break;
            case 4:
                player.HP = HELL_PLAYER_HP;
                break;
            }
            InitNexus();
            break;
        }
        else {
            printf("잘못된 입력입니다.\n");
            printf("올바른 입력을 다시 입력하십시오\n");
        }
    }
}

void InitNexus() {
    player.nexus.xpos = NEXUS_XPOS;
    player.nexus.ypos = NEXUS_YPOS;
}

int TrapSignal() {//트랩 설치 신호를 보냄, 기획안 확률대로 함정 생성
    int randomValue = rand() % 100 + 1;

    if (randomValue <= 45)
        return 1;
    else if (randomValue <= 80)
        return 2;
    else if (randomValue <= 95)
        return 3;
    else
        return 4;
}
Trap InitTrap() { //신호에 맞는 트랩 생성
    int trapSignal = TrapSignal();
    Trap trap;
    switch (trapSignal) {
    case 1:
        trap = { TRIANGLE_TRAP_DAMAGE ,TRIANGLE };
        break;
    case 2:
        trap = { RECTANGLE_TRAP_DAMAGE,RECTANGLE };
        break;
    case 3:
        trap = { HEXAGON_TRAP_DAMAGE,HEXAGON };
        break;
    case 4:
        trap = { STAR_TRAP_DAMAGE,STAR };
    }
    return trap;
}
Enemy EnemySpawn() { //적 유닛 생성함수
    //스폰 위치 지정 필요, 입력이랑 말 맞춰야 되야 겠지?
    for (int i = 0; i < ENEMY_INIT_NUMBER + ((stagestep - 1) / 3) * 5;  i++) {
        Enemy enemy;
        enemy.shape = Circle;
        enemy.HP = ENEMY_HP + stagestep - 1;
        enemy.isActive = true;
        return enemy;
    }
    
}
//
void EnemyMove() { //적 유닛 이동함수
    //알고리즘 파악해서 방향 설정뒤에 이동 ->input에서 하지 않을까?
}

bool isCrashWithPlayer(Enemy*enemy,Player* player) { //적과 본진 충돌
    if ((player->nexus.xpos == enemy->xpos) && (player->nexus.ypos == enemy->ypos))
        return true;
    return false;
}

void PlayerHPDecrease(Enemy* enemy, Player* player) {
    if (isCrashWithPlayer(enemy, player))
        player->HP--;
}

bool isCrashWithTrap(Enemy* enemy, Trap* trap) {//적과 함정 출돌
    if ((enemy->xpos == trap->xpos) && (enemy->ypos == trap->ypos))
        return true;
    return false;
}

void EnemyDamage(Enemy* enemy, Trap* trap) {//적 유닛이 함정을 지나가면 데미지를 입는다.
    if (isCrashWithTrap(enemy, trap)) {
        enemy->HP -= trap->damage;
        if (enemy->HP <= 0) {
            enemy->isActive = false;
            player.Gold += REWARD_GOLD;
            SeedReward();
        }
    }
}

void TrapUpgrade() {//업그레이드 알고리즘 사용

}


void SeedReward() { //확률적으로 Seed 획득이라 임의로 50으로 설정함
    int randomValue = rand() % 100 + 1;

    if (randomValue <= RANDOM_REWARD_SEED) {
        player.Seed += REWARD_SEED;
    }
}

//int main() {
//    srand(time(NULL));
//    Enemy enemies[MAX_ENEMY];
//    while (/*게임이 돌아가는 동안*/) {
//        for (int i = 0; i < ENEMY_INIT_NUMBER + ((stagestep - 1) / 3) * 5; i++) {
//            if (enemies[i].isActive) {
//            // 렌더링.. 
//            }
//        }
//    }
//}
