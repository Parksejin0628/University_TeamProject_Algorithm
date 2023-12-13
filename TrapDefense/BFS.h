#pragma once

#include "ProgramBase.h"



// 변수 선언
static int DIRECTION_OFFSETS[NUM_DIRECTIONS][2] = {
	{0, -1},		// 0 (상)
	{1, 0},			// 1 (우)
	{0, 1},			// 2 (하)
	{-1, 0}			// 3 (좌)
};

//맵의 좌표

enum PosStatus { NOT_VISIT = 0, VISIT = 1 };

int is_movable(Field maze[WIDTH][HEIGHT], int visited[WIDTH][HEIGHT], MapPosition pos);
MapPosition findPath(Field field[WIDTH][HEIGHT], MapPosition start, MapPosition end);
