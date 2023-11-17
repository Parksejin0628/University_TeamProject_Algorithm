#pragma once
#include"ProgramBase.h"

//�÷��̾� ����
#define EASY_PLAYER_HP 99
#define NORMAL_PLAYER_HP 60
#define HARD_PLAYER_HP 30
#define HELL_PLAYER_HP 1
//��ȭ ����
#define SEED_INIT 500 //���� ��ġ������ ��ȭ
//���� ����
#define TRIANGLE_TRAP_DAMAGE 3
#define RECTANGLE_TRAP_DAMAGE 4
#define HEXAGON_TRAP_DAMAGE 6
#define STAR_TRAP_DAMAGE 10
#define TRAP_SET_UP_SEED 30//���� ��ġ ���
//�� ���� ����
#define Enemy_HP 3 //�� ���� �ʱ� hp
//���� ��ǥ ����
#define NEXUS_XPOS 0
#define NEXUS_YPOS 0

typedef struct Nexus {
    int xpos;
    int ypos;
}Nexus;
//�÷��̾� ���� ����
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
int TrapSignal();//Ʈ�� ��ġ ��ȣ�� ����
Trap InitTrap();//��ȣ�� �´� Ʈ�� ����
void EnemySpawn(); //�� ���� �����Լ�
void EnemyMove(); //�� ���� �̵��Լ�
void EnemyDamage(Enemy* enemy, Trap* trap);//�� ������ ������ �������� �������� �Դ´�.
bool isCrashWithPlayer(Enemy* enemy, Player* player);
bool isCrashWithTrap(Enemy* enemy, Trap* trap);
void TrapUpgrade(); //���׷��̵� �˰��� ���
void PlayerHPDecrease(Enemy* enemy, Player* player);
void IsNextStage();
void InitNexus();