#include "BFS.h"


int is_movable(Field maze[FIELD_HEIGHT][FIELD_WIDTH], int visited[FIELD_HEIGHT][FIELD_WIDTH], Field pos)
{
	// 현재 위치가 미로의 범위를 벗어나는 지 확인
	if (pos.X < 0 || pos.Y < 0 || pos.X >= FIELD_WIDTH || pos.Y >= FIELD_HEIGHT)
		return (false);
	// 현재 위치가 벽이거나 이미 방문한 곳인지 확인
	if (maze[pos.Y][pos.X].trap.type == BLOCK || visited[pos.Y][pos.X] == VISIT)
		return (false);
	return (true);
}

// BFS 
void findPath(Field map[FIELD_HEIGHT][FIELD_WIDTH], Field start, Field end)
{
	static int DIRECTION_OFFSETS[NUM_DIRECTIONS][2] = {
	{0, -1},		// 0 (상)
	{1, 0},			// 1 (우)
	{0, 1},			// 2 (하)
	{-1, 0}			// 3 (좌)
	};

	for (int i = 0; i < FIELD_HEIGHT; i++)
	{
		for (int j = 0; j < FIELD_WIDTH; j++)
		{
			map[i][j].nextX = 0;
			map[i][j].nextY = 0;
			map[i][j].direction = 0;
		}
	}

	

	Queue queue;
	Field currPos;
	Field nextPos;
	int nextX;
	int nextY;
	int visited[FIELD_HEIGHT][FIELD_WIDTH] = { NOT_VISIT, };

	
	enqueue(&queue, start); // 처음 시작 위치를 큐에 넣기
	
	while (!isEmpty(&queue))
	{
		currPos = dequeue(&queue); // 큐에서 꺼내기
		if ((currPos.X == end.X) && (currPos.Y == end.Y)) 			// 도착 지점에 도달한 경우
			return;
		if (visited[currPos.Y][currPos.X] == VISIT) 	// 현재 위치를 방문했는지 확인
			continue;
		visited[currPos.Y][currPos.X] = VISIT; // 현재 위치를 VISIT 으로 변경

		while (currPos.direction < NUM_DIRECTIONS)
		{
			// 다음 좌표 설정
			nextX = currPos.X + DIRECTION_OFFSETS[currPos.direction][0];
			nextY = currPos.Y + DIRECTION_OFFSETS[currPos.direction][1];
			nextPos.X = currPos.nextX;
			nextPos.Y = currPos.nextY;
			nextPos.direction = 0;
			if (is_movable(map, visited, nextPos))
			{
				// 다음 이동 지점에 이전 이동 거리 + 1 저장
				map[nextY][nextX].moveCount = map[currPos.Y][currPos.X].moveCount + 1;

				// 다음 이동 지점을 맵의 nextX, nextY에 저장
				map[currPos.Y][currPos.X].nextX = nextX;
				map[currPos.Y][currPos.X].nextY = nextY;

				enqueue(&queue, nextPos); // 다음 이동 지점 큐에 저장
			}
			currPos.direction += 1;
		}
	}
	return;
}

