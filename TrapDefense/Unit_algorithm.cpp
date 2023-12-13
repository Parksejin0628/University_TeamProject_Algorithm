#pragma once
#include"Unit_algorithm.h"
int stagestep;
extern Player player

Unit UnitSpawn() { //적 유닛 생성함수, //스테이지 정보를 받아와야 한다.
    //보스 스테이지가 5의배수 스테이지에 생성 단 한마리만
    if (stagestep%5==0) {
        Unit boss = { ENEMY_HP + stagestep,ENEMY_SPAWN_XPOS, ENEMY_SPAWN_YPOS,true,true };
        return boss;
    }
    else {
        Unit enemy = {};
        enemy.HP = ENEMY_HP + stagestep - 1;
        enemy.isActive = true;
        enemy.isBoss = false;
        enemy.xpos = ENEMY_SPAWN_XPOS; //여기서 위치조정
        enemy.ypos = ENEMY_SPAWN_YPOS;
        return enemy;
    } 
}
void UnitMove(Field maze[WIDTH][HEIGHT], MapPosition* start, MapPosition* end) {
    Unit temperature;
    start->x = ENEMY_SPAWN_XPOS;
    start->y = ENEMY_SPAWN_YPOS;

    end->x = NEXUS_XPOS;
    end->y = NEXUS_YPOS;

    MapPosition path = findPath(maze, *start, *end);

    while (path.x != end->x && path.y != end->y) {
        temperature = maze[path.x][path.y].enemy;
        maze[path.x][path.y].enemy = maze[start->x][start->y].enemy;
        maze[start->x][start->y].enemy = temperature;
        start->x = path.x;
        start->y = path.y;
    }
}

bool isCrashWithPlayer(Unit*enemy,Player* player) { //적과 Goal 충돌
    if ((player->PlayerXpos == enemy->xpos) && (player->PlayerYpos == enemy->ypos))
        return true;
    return false;
}

void PlayerHPDecrease(Unit* enemy, Player* player) { //1초마다 플레이어 공격하게 설정
    static time_t attackTime = 0;
    time_t currentTime = time(NULL);
    if (currentTime - attackTime >= 1) {
        if (isCrashWithPlayer(enemy, player))
            player->HP--;
        attackTime = currentTime;
    }
}

bool isCrashWithTrap(Unit* enemy, Trap* trap) {//적과 함정 출돌
    if ((enemy->xpos == trap->xpos) && (enemy->ypos == trap->ypos))
        return true;
    return false;
}

void UnitDamage(Unit* enemy, Trap* trap) {//적 유닛이 함정을 지나가면 데미지를 입는다.
    int tempenemyHP = enemy->HP; //enemy의 체력만큼 점수 추가
    if (isCrashWithTrap(enemy, trap)) {
        enemy->HP -= trap->damage;
        if (enemy->HP <= 0) {
            enemy->isActive = false;
            if (enemy->isBoss) {
                player.Gold += 20;
                player.Score += 10;
            }
            else {
                player.Gold += 3;
                player.Score += tempenemyHP;
            }
        }
    }
}



//int main() {
//    srand(time(NULL));
//    Enemy enemies[MAX_ENEMY];
//    
//}