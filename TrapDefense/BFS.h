#pragma once

#include "ProgramBase.h"
#include "Unit_algorithm.h"

#define NUM_DIRECTIONS 4
#define HEIGHT 25
#define WIDTH 25
#define INF 999999

// 변수 선언
static int DIRECTION_OFFSETS[NUM_DIRECTIONS][2] = {
	{0, -1},		// 0 (상)
	{1, 0},			// 1 (우)
	{0, 1},			// 2 (하)
	{-1, 0}			// 3 (좌)
};

// //맵의 좌표
// typedef struct MapPositionType
// {
// 	int x;				
// 	int y;				
// 	int direction;
// } MapPosition;

enum PosStatus { NOT_VISIT = 0, VISIT = 1 };

typedef struct Field {
	Trap trap;
	Enemy enemy;
	int direction;
	int X;
	int Y;
	int nextX;
	int nextY;
	int moveCount;
}Field;

int is_movable(Field maze[WIDTH][HEIGHT], int visited[WIDTH][HEIGHT], Field pos);

Field findPath(Field map[WIDTH][HEIGHT], Field start, Field end);
