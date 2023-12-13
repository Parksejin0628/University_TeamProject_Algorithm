#pragma once
#include"ProgramBase.h"
#include "BFS.h"
#include "Queue.h"

int min(int a, int b);

//구한 경로를 (2, 2) (1, 2) (0, 2)처럼 출력하는 함수
//아직 경로 반환을 어떻게 할지 고민중이라서 임시로 넣어둠
void printPath(int path[WIDTH][HEIGHT]);

void bossPath(Field field[WIDTH][HEIGHT], int path[WIDTH][HEIGHT]);

// BFS 후 행렬경로를 이용하여 보스 경로 구하기
MapPosition findBossPath(Field field[WIDTH][HEIGHT], MapPosition start, MapPosition end);
