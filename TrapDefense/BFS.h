#pragma once

#include "ProgramBase.h"

//맵의 좌표

enum PosStatus { NOT_VISIT = 0, VISIT = 1 };

int is_movable(Field maze[WIDTH][HEIGHT], int visited[WIDTH][HEIGHT], MapPosition pos);
MapPosition findPath(Field field[WIDTH][HEIGHT], MapPosition start, MapPosition end);
