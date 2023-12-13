#include "Boss.h"
#include "Priority_Queue.h"

void findBossPath(Field map[FIELD_WIDTH][FIELD_HEIGHT], Field start, Field end)
{
	static int DIRECTION_OFFSETS[NUM_DIRECTIONS][2] = {
		{0, -1}, // 0 (상)
		{1, 0},	 // 1 (우)
		{0, 1},	 // 2 (하)
		{-1, 0}	 // 3 (좌)
	};

	int visited[FIELD_WIDTH][FIELD_HEIGHT] = {
		NOT_VISIT,
	};
	int distances[FIELD_WIDTH][FIELD_HEIGHT];
	Field PQF[10000];
	int PQI[10000];
	int rear = 1;

	Field currPos;
	Field nextPos;
	int nextX;
	int nextY;

	for (int i = 0; i < FIELD_WIDTH; i++)
	{
		for (int j = 0; j < FIELD_HEIGHT; j++)
		{
			map[i][j].nextX = 0;
			map[i][j].nextY = 0;
			map[i][j].direction = 0;
			distances[i][j] = INF;
		}
	}

	if (map[start.X][start.Y].type >= TRAP_TEAR1 && map[start.X][start.Y].type <= TRAP_TEAR4)
	{
		distances[start.X][start.Y] = map[start.X][start.Y].trap.damage;
	}
	else if (map[start.X][start.Y].type == BLOCK)
	{
		return;
	}
	else
	{
		distances[start.X][start.Y] = 1;
	}

	enPQ(PQF, PQI, distances[start.X][start.Y], map[start.X][start.Y], &rear);

	while (rear > 1)
	{
		currPos = popPQ(PQF, PQI, &rear);

		if ((currPos.X = end.X) && (currPos.Y == end.Y)) // 도착 지점에 도달한 경우
		{
			return;
		}
		if (visited[currPos.X][currPos.Y] == VISIT) // 현재 위치를 방문했는지 확인
		{
			continue;
		}
		visited[currPos.X][currPos.Y] = VISIT; // 현재 위치를 VISIT 으로 변경

		nextX = currPos.X;
		nextY = currPos.Y;

		while (currPos.direction < NUM_DIRECTIONS)
		{
			// 다음 좌표 설정
			nextX = currPos.X + DIRECTION_OFFSETS[currPos.direction][0];
			nextY = currPos.Y + DIRECTION_OFFSETS[currPos.direction][1];
			nextPos.X = nextX;
			nextPos.Y = nextY;
			nextPos.direction = 0;

			if (is_movable(map, visited, nextPos))
			{
				if (map[nextX][nextY].trap.isExist == true)
				{
					if (distances[nextX][nextY] > distances[nextX][nextY] + map[nextX][nextY].trap.damage)
					{
						distances[nextX][nextY] = distances[nextX][nextY] + map[nextX][nextY].trap.damage;
						map[currPos.X][currPos.Y].nextX = nextX;
						map[currPos.Y][currPos.Y].nextY = nextY;
						enPQ(PQF, PQI, distances[nextX][nextY], map[nextX][nextY], &rear);
					}
				}
				else if (map[nextX][nextY].trap.isExist == false)
				{
					if (distances[nextX][nextY] > distances[nextX][nextY] + 1)
					{
						distances[nextX][nextY] = distances[nextX][nextY] + 1;
						map[currPos.X][currPos.Y].nextX = nextX;
						map[currPos.Y][currPos.Y].nextY = nextY;
						enPQ(PQF, PQI, distances[nextX][nextY], map[nextX][nextY], &rear);
					}
				}
			}
			currPos.direction += 1;
		}
	}
}