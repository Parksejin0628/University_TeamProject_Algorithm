#pragma once

#include "ProgramBase.h"

//맵의 좌표

enum PosStatus { NOT_VISIT = 0, VISIT = 1 };

int is_movable(Field maze[FIELD_HEIGHT][FIELD_WIDTH], int visited[FIELD_HEIGHT][FIELD_WIDTH], Field pos);
void findPath(Field map[FIELD_HEIGHT][FIELD_WIDTH], Field start, Field end);
