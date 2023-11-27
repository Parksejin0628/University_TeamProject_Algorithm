#pragma once
#include"ProgramBase.h"

//�÷��̾� ����
#define EASY_PLAYER_HP 99
#define NORMAL_PLAYER_HP 60
#define HARD_PLAYER_HP 30
#define HELL_PLAYER_HP 1

//��ȭ ����
#define SEED_INIT 500 //���� ��ġ������ ��ȭ
#define GOLD_INIT 0 //���� ���׷��̵� ������ ��ȭ
#define REWARD_GOLD 10//�� ó���� ��� ����
#define REWARD_SEED 10//�� ó���� Ȯ�������� SEED ȹ���� ��
#define RANDOM_REWARD_SEED 50//Seed Ȯ�� �������� ȹ�� 50�۷� ���Ƿ� ����

//���� ����
#define TRIANGLE_TRAP_DAMAGE 3
#define RECTANGLE_TRAP_DAMAGE 4
#define HEXAGON_TRAP_DAMAGE 6
#define STAR_TRAP_DAMAGE 10
#define TRAP_SET_UP_SEED 30//���� ��ġ ���

//�� ���� ����
#define ENEMY_HP 3 //�� ���� �ʱ� hp
#define ENEMY_INIT_NUMBER 10

//���� ��ǥ ����
#define NEXUS_XPOS -20
#define NEXUS_YPOS -20

//�������� ����
int stagestep = 1;
//���� ��ǥ - �ʺ��߰� �ؾ� ������ �̹��� �ǵ���� ����... ž��� �ʿ� ���� ����?

//�� ���� ��ġ
#define ENEMY_SPAWN_XPOS 20
#define ENEMY_SPAWN_YPOS 20

//�����Լ� Enemy Ÿ�� �迭 �������� ����
#define MAX_ENEMY 100
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
    WALL,
    TRIANGLE,
    RECTANGLE,
    HEXAGON,
    STAR,
    Circle,
    Diamond //���� ���
} Shape;

typedef struct Trap {
    bool isExist;
    int damage;//Ʈ�� ������
    int upgrade;//Ʈ���� ���׷��̵� �ܰ�
    int xpos;
    int ypos;
    Shape shape;
}Trap;

typedef struct Enemy {
    int HP;
    int value;//���� 3���帶�� hp�� ����ϱ� ������ value�� ����
    int xpos;
    int ypos;
    Shape shape;
    bool isActive;
    bool isBoss;
}Enemy;

typedef struct EnemySpawner {
    int xpos;
    int ypos;
}EnemySpawner;

void InitGame();
int TrapSignal();//Ʈ�� ��ġ ��ȣ�� ����
Trap InitTrap();//��ȣ�� �´� Ʈ�� ����
void EnemySpawn(); //�� ���� �����Լ�
void EnemyMove(); //�� ���� �̵��Լ�
void EnemyDamage(Enemy* enemy, Trap* trap);//�� ������ ������ �������� �������� �Դ´�.
bool isCrashWithPlayer(Enemy* enemy, Player* player);
bool isCrashWithTrap(Enemy* enemy, Trap* trap);
void TrapUpgrade(); //���׷��̵� �˰����� ���
void PlayerHPDecrease(Enemy* enemy, Player* player);
void IsNextStage();
void InitNexus();