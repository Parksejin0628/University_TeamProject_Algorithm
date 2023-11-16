#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
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
//�������� ����
int stagestep = 1;
//���� ��ǥ - �ʺ��߰� �ؾ� ������ �̹��� �ǵ���� ����... ž��� �ʿ� ���� ����?
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

};
void InitGame() {
    int difficultySelection;
    while (1) {
        printf("���̵��� �����ϼ���\n");
        printf("Easy : 1, Normal : 2, Hard : 3, Hell : 4\n");
        scanf("%d", &difficultySelection);
        player.Seed = SEED_INIT;
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
            printf("�߸��� �Է��Դϴ�.\n");
            printf("�ùٸ� �Է��� �ٽ� �Է��Ͻʽÿ�\n");
        }
    }
}
int TrapSignal() {//Ʈ�� ��ġ ��ȣ�� ����
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
Trap InitTrap() { //��ȣ�� �´� Ʈ�� ����
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
void EnemySpawn() { //�� ���� �����Լ�
    //���� ��ġ ���� �ʿ�
    Enemy enemy;
    enemy.shape = Circle;
    if (stagestep == 1) {//wave ���� ��� �� ������ ����
        enemy.HP = 3;
    }
}
void EnemyMove() { //�� ���� �̵��Լ�
    //�˰��� �ľ��ؼ� ���� �����ڿ� �̵� ->input���� ���� ������?
}
void EnemyDamage(Enemy* enemy, Trap* trap) {//�� ������ ������ �������� �������� �Դ´�.
    if (isCrashWithTrap(enemy, trap)) {
        enemy->HP -= trap->damage;
    }
}
bool isCrashWithPlayer(Enemy* enemy, Player* player) {
    if ((player->nexus.xpos == enemy->xpos) && (player->nexus.ypos == enemy->ypos))
        return true;
    return false;
}
bool isCrashWithTrap(Enemy* enemy, Trap* trap) {
    if ((enemy->xpos == trap->xpos) && (enemy->ypos == trap->ypos))
        return true;
    return false;
}
void TrapUpgrade() {//���׷��̵� �˰��� ���
}
void PlayerHPDecrease(Enemy* enemy, Player* player) {
    if (isCrashWithPlayer(enemy, player))
        player->HP--;
}
void IsNextStage() {
    stagestep++;
}
void InitNexus() {
    player.nexus.xpos = NEXUS_XPOS;
    player.nexus.ypos = NEXUS_YPOS;
}
int main() {

}
//���� ���� �� ���� malloc free��ߵǳ�?, wave�� stage�������� �����, DPS�ϱ� delay�� �ִ°��� ������� �ǰ�->�� ���� �ӵ��� ����ؾ� �ɱ�?