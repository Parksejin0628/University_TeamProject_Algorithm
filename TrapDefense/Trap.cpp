#include"Trap.h"

extern Player player;

Trap InitTrap(int xpos, int ypos) { //신호에 맞는 트랩 생성 ,//생성후 playerSeed를 TRAP_SET_UP_SEED만큼 감소//플레이어 한테 입력 좌표 입력받기
    int trapSignal = TrapSignal();
    player.TrapSeed--;//Trap Seed 감소
    Trap trap;
    switch (trapSignal) {
    case 1:
        trap = { TRAP_TEAR1, true, CIRCLE_TRAP_DAMAGE,1, 1,(int)(CIRCLE_TRAP_DAMAGE *1.3),xpos, ypos};
        break;
    case 2:
        trap = { TRAP_TEAR2, true, TRIANGLE_TRAP_DAMAGE,2, 1,(int)(TRIANGLE_TRAP_DAMAGE *1.3),xpos, ypos};
        break;
    case 3:
        trap = { TRAP_TEAR3, true, DIAMOND_TRAP_DAMAGE,3, 1,(int)(DIAMOND_TRAP_DAMAGE * 1.3), xpos, ypos };
        break;
    case 4:
        trap = { TRAP_TEAR4, true,  STAR_TRAP_DAMAGE,4, 1,(int)(STAR_TRAP_DAMAGE * 1.3), xpos, ypos };
    }
    return trap;
}
int TrapSignal() { //기획안 참고하여 확률에 따른 함정 설치
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
void TrapUpgrade(Trap* trap) { // 0 1 배낭 알고리즘 적용 안한거
    if (player.Gold<(int)(trap->upgradeCost)) { //플레이어가 가진 골드의 수가 필요한 골드의 양보다 작으면
        fprintf(stderr, "골드가 부족합니다.");
    }
    else {
        player.Gold -= (int)(trap->upgradeCost);
        trap->upgrade++;
        trap->damage = (int)(trap->damage * 1.3);
        trap->upgradeCost = (int)(trap->upgradeCost * 1.3);
    }
}
