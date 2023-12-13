#include "Boss.h"

int min(int a, int b) 
{
    return (a < b) ? a : b;
}

//구한 경로를 (2, 2) (1, 2) (0, 2)처럼 출력하는 함수
//아직 경로 반환을 어떻게 할지 고민중이라서 임시로 넣어둠
void printPath(int path[WIDTH][HEIGHT])
{
	int i = WIDTH - 1, j = HEIGHT - 1;
    while (i > 0 || j > 0) 
	{
        printf("(%d, %d) ", i, j);

        // 경로를 따라 이동
        if (path[i][j] == 1) {
            i--;
        } else {
            j--;
        }
    }
}

void bossPath(Field field[WIDTH][HEIGHT], int path[WIDTH][HEIGHT])
{
	int dp[WIDTH][HEIGHT];

	dp[0][0] = field[0][0].map;
	path[0][0] = -1; //시작위치 표시
	for (int i = 1; i < WIDTH; i++) 
	{
    	dp[i][0] = dp[i-1][0] + field[i][0].map;
		path[i][0] = 1; //위에서 왔음을 표시
    }
	for (int i = 1; i < HEIGHT; i++) 
	{
    	dp[0][i] = dp[0][i-1] + field[0][i].map;
		path[0][i]  = 0; //왼쪽에서 왔음을 표시
    }

	// dp 배열 채우기
    for (int i = 1; i < WIDTH; i++) 
	{
        for (int j = 1; j < HEIGHT; j++) 
		{
            int minVal = min(dp[i-1][j], dp[i][j-1]);
            dp[i][j] = field[i][j].map + minVal;

            // 최소값을 갖는 방향으로부터 왔음을 기록
            if (minVal == dp[i-1][j]) 
			{
                path[i][j] = 1;  // 위에서 왔음을 표시
            } 
			else
			{
                path[i][j] = 0;  // 왼쪽에서 왔음을 표시
            } 
        }
    }
}

int is_movable(Field maze[WIDTH][HEIGHT], int visited[WIDTH][HEIGHT], MapPosition pos)
{
	// 현재 위치가 미로의 범위를 벗어나는 지 확인
  if (pos.x < 0 || pos.y < 0 || pos.x >= WIDTH || pos.y >= HEIGHT)
		return (false);
	// 현재 위치가 벽이거나 이미 방문한 곳인지 확인
  if (maze[pos.y][pos.x].trap.shape == WALL || visited[pos.y][pos.x] == VISIT)
	    return (false);
	return (true);
}

// BFS 후 행렬경로를 이용하여 보스 경로 구하기
MapPosition findBossPath(Field field[WIDTH][HEIGHT], MapPosition start, MapPosition end)
{
	Queue queue;
	MapPosition currPos;
    MapPosition nextPos;
    int nextX;
    int nextY;
	int path[WIDTH][HEIGHT];
	int visited[WIDTH][HEIGHT] = {NOT_VISIT, };
	
		enqueue(&queue, start); // 처음 시작 위치를 큐에 넣기
		while (!isEmpty(&queue))
		{
			currPos = dequeue(&queue); // 큐에서 꺼내기
			if ((currPos.x = end.x) && (currPos.y == end.y)) 			// 도착 지점에 도달한 경우
			{
		    	for (int i = 0; i < WIDTH; i++)
                {
                    for (int j = 0; j < HEIGHT; j++)
                    {
						if (field[i][j].trap.shape == WALL)            //벽인경우 가중치 INF
						{
							field[i][j].map = INF;
						}
						else if (field[i][j].trap.isExist == true)
						{
                        	field[i][j].map += field[i][j].trap.damage;    //설치된 구조물의 데미지를 가중치에 추가
						}
					}
                }
				bossPath(field, path); //경로를 찾아서 path에 기록
				return currPos;
			}
			if (visited[currPos.x][currPos.y] == VISIT) 	// 현재 위치를 방문했는지 확인
				continue ;
	        visited[currPos.x][currPos.y] = VISIT; // 현재 위치를 VISIT 으로 변경
	      
		    while (currPos.direction < NUM_DIRECTIONS)
	        {
	        	// 다음 좌표 설정
	        	nextX = currPos.x + DIRECTION_OFFSETS[currPos.direction][0];
	        	nextY = currPos.y + DIRECTION_OFFSETS[currPos.direction][1];
	    		nextPos.x = nextX;
	        	nextPos.y = nextY;
	        	nextPos.direction = 0;
	        	if(is_movable(field, visited, nextPos))
				{
					// 다음 이동 지점에 이전 이동 거리 + 1 저장
					field[nextX][nextY].map = field[currPos.x][currPos.y].map + 1; 
	            	enqueue(&queue, nextPos); // 다음 이동 지점 큐에 저장
				}
	            start.direction += 1;
	        }
		}
	//도착지점에 도달하지 못한 경우 start 반환
	return start;
}
