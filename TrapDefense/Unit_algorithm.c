#include"Unit_algorithm.h"


//�������� ����
int stagestep = 1;
//���� ��ǥ - �ʺ��߰� �ؾ� ������ �̹��� �ǵ���� ����... ž��� �ʿ� ���� ����?

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
        trap.damage = TRIANGLE_TRAP_DAMAGE;
        trap.shape = TRIANGLE;
        break;
    case 2:
        trap.damage = RECTANGLE_TRAP_DAMAGE;
        trap.shape = RECTANGLE;
        break;
    case 3:
        trap.damage = HEXAGON_TRAP_DAMAGE;
        trap.shape = HEXAGON;
        break;
    case 4:
        trap.damage = STAR_TRAP_DAMAGE;
        trap.shape = STAR;
    }
    trap.xpos = 0; //�� �κ� ���Ƿ� �߰��ѰŴ� �������ּ��� - ����
    trap.ypos = 0; //�� �κ� ���Ƿ� �߰��ѰŴ� �������ּ��� - ����

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

//���� ���� �� ���� malloc free��ߵǳ�?, wave�� stage�������� �����, DPS�ϱ� delay�� �ִ°��� ������� �ǰ�->�� ���� �ӵ��� ����ؾ� �ɱ�?