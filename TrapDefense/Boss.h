#pragma once
#include"ProgramBase.h"
#include "BFS.h"
#include "Queue.h"


//구한 경로를 (2, 2) (1, 2) (0, 2)처럼 출력하는 함수
//아직 경로 반환을 어떻게 할지 고민중이라서 임시로 넣어둠
void printPath(int path[FIELD_HEIGHT][FIELD_WIDTH]);

void bossPath(Field field[FIELD_HEIGHT][FIELD_WIDTH], int path[FIELD_HEIGHT][FIELD_WIDTH]);

// BFS 후 행렬경로를 이용하여 보스 경로 구하기
Field findBossPath(Field field[FIELD_HEIGHT][FIELD_WIDTH], Field start, Field end);
