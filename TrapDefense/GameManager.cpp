#include"GameManager.h"

Field field[FIELD_HEIGHT][FIELD_WIDTH];
Player player;
bool isBuildTurn = true;
Unit unitQueue[MAX_ENEMY];
int frontIndex = -1;
int rearIndex = -1;

void PlayInGame()
{
	bool defenseStart = false;
	double frameStart = clock();
	int X = 0;
	int Y = 0;
	Unit nowUnit;

	InitGame();
	
	while (1)
	{
		UpdateScreen();
		if (isBuildTurn)
		{

			Goto_xy(60, 0);
			printf("입력완료 %d, %d", player.cursorX, player.cursorY);

			switch (InputManager())
			{
			case VK_UP:
				if (player.cursorY - 1 >= MIN_CURSOR_Y && player.cursorY - 1 <= MAX_CURSOR_Y)
				{
					player.cursorY--;
				}
				break;
			case VK_DOWN:
				if (player.cursorY + 1 >= MIN_CURSOR_Y && player.cursorY + 1 <= MAX_CURSOR_Y)
				{
					player.cursorY++;
				}
				break;
			case VK_LEFT:
				if (player.cursorX - 1 >= MIN_CURSOR_X && player.cursorX - 1 <= MAX_CURSOR_X)
				{
					player.cursorX--;
				}
				break;
			case VK_RIGHT:
				if (player.cursorX + 1 >= MIN_CURSOR_X && player.cursorX + 1 <= MAX_CURSOR_X)
				{
					player.cursorX++;
				}
				break;
			case VK_SPACE:
				isBuildTurn = false;
				defenseStart = false;
				//턴 넘기기
				break;
			case VK_Q:
				if (field[player.cursorY-2][player.cursorX].type == NONE)
				{
					field[player.cursorY-2][player.cursorX].type = BLOCK;
				}
				//바리게이트 설치
				break;
			case VK_W:
				if (field[player.cursorY-2][player.cursorX].type == NONE)
				{
					field[player.cursorY-2][player.cursorX].trap = InitTrap(player.cursorX, player.cursorY-2);
					field[player.cursorY-2][player.cursorX].type = field[player.cursorY-2][player.cursorX].trap.type;
				}
				//타일 설치
				break;
			}
		}
		else
		{
			if (!defenseStart)
			{
				InitRound(++player.stage);
				
				defenseStart = true;
			}
			if (clock() - frameStart > FRAMETIME)
			{
				for (int i = frontIndex; i > rearIndex; i--)
				{
					nowUnit = unitQueue[i % MAX_ENEMY];
					X = nowUnit.xpos;
					Y = nowUnit.ypos;
					field[Y + field[Y][X].nextY][X + field[Y][X].nextX].unit = nowUnit;
					nowUnit.xpos = X + field[Y][X].nextX;
					nowUnit.ypos = Y + field[Y][X].nextY;
					if (field[Y][X].trap.isExist == true)
					{
						field[Y][X].type = field[Y][X].trap.type;
					}
					else
					{
						field[Y][X].type = NONE;
					}
					field[Y + field[Y][X].nextY][X + field[Y][X].nextX].type = ENEMY;
				}
				if (player.nowUnitCount < player.maxUnitCount)
				{
					player.nowUnitCount++;
					unitQueue[++frontIndex % MAX_ENEMY] = UnitSpawn(player.stage);
					X = unitQueue[frontIndex % MAX_ENEMY].xpos;
					Y = unitQueue[frontIndex % MAX_ENEMY].ypos;
					field[X][Y].unit = unitQueue[frontIndex % MAX_ENEMY];
				}
			}
		}
	}
		

}

void InitGame()
{
	player.HP = 50;
	player.TrapSeed = INIT_TRAP_SEED;
	player.BarricadeSeed = INIT_BARRICADE_SEED;
	player.Gold = INIT_GOLD;
	player.Score = 0;
	player.PlayerXpos = NEXUS_XPOS;
	player.PlayerYpos = NEXUS_YPOS;
	player.stage = 0;
	player.cursorX = 10;
	player.cursorY = 10;

	for (int y = 0; y < FIELD_HEIGHT; y++)
	{
		for (int x = 0; x < FIELD_WIDTH; x++)
		{
			field[y][x].type = NONE;
			field[y][x].X = x;
			field[y][x].Y = y;
		}
	}
	field[0][8].type = BLOCK;
	field[0][10].type = BLOCK;
	field[0][14].type = BLOCK;
	field[0][16].type = BLOCK;

	field[1][8].type = BLOCK;
	field[1][10].type = BLOCK;
	field[1][11].type = BLOCK;
	field[1][12].type = BLOCK;
	field[1][13].type = BLOCK;
	field[1][14].type = BLOCK;
	field[1][16].type = BLOCK;

	field[3][8].type = BLOCK;
	field[3][9].type = BLOCK;
	field[3][10].type = BLOCK;
	field[3][11].type = BLOCK;
	field[3][12].type = BLOCK;
	field[3][13].type = BLOCK;
	field[3][14].type = BLOCK;
	field[3][15].type = BLOCK;
	field[3][16].type = BLOCK;

	field[21][8].type = BLOCK;
	field[21][9].type = BLOCK;
	field[21][10].type = BLOCK;
	field[21][11].type = BLOCK;
	field[21][12].type = BLOCK;
	field[21][13].type = BLOCK;
	field[21][14].type = BLOCK;
	field[21][15].type = BLOCK;
	field[21][16].type = BLOCK;

	field[23][8].type = BLOCK;
	field[23][9].type = BLOCK;
	field[23][10].type = BLOCK;
	field[23][11].type = BLOCK;
	field[23][13].type = BLOCK;
	field[23][14].type = BLOCK;
	field[23][15].type = BLOCK;
	field[23][16].type = BLOCK;

	field[24][11].type = BLOCK;
	field[24][13].type = BLOCK;
	field[24][12].type = BASE;
}

int InputManager()
{
	static bool keydown_up = false;
	static bool keydown_down = false;
	static bool keydown_left = false;
	static bool keydown_right = false;
	static bool keydown_space = false;
	static bool keydown_q = false;
	static bool keydown_w = false;

	while (1)
	{
		if (GetAsyncKeyState(VK_UP) && keydown_up == false)
		{
			keydown_up = true;
			return VK_UP;
		}
		else if (!GetAsyncKeyState(VK_UP))
		{
			keydown_up = false;
		}
		if (GetAsyncKeyState(VK_DOWN) && keydown_down == false)
		{
			keydown_down = true;
			return VK_DOWN;
		}
		else if (!GetAsyncKeyState(VK_DOWN))
		{
			keydown_down = false;
		}
		if (GetAsyncKeyState(VK_LEFT) && keydown_left == false)
		{
			keydown_left = true;
			return VK_LEFT;
		}
		else if (!GetAsyncKeyState(VK_LEFT))
		{
			keydown_left = false;
		}
		if (GetAsyncKeyState(VK_RIGHT) && keydown_right == false)
		{
			keydown_right = true;
			return VK_RIGHT;
		}
		else if (!GetAsyncKeyState(VK_RIGHT))
		{
			keydown_right = false;
		}
		if (GetAsyncKeyState(VK_SPACE) && keydown_space == false)
		{
			keydown_space = true;
			return VK_SPACE;
		}
		else if (!GetAsyncKeyState(VK_SPACE))
		{
			keydown_space = false;
		}
		if (GetAsyncKeyState(VK_Q) && keydown_q == false)
		{
			keydown_q = true;
			return VK_Q;
		}
		else if (!GetAsyncKeyState(VK_Q))
		{
			keydown_q = false;
		}
		if (GetAsyncKeyState(VK_W) && keydown_w == false)
		{
			keydown_w = true;
			return VK_W;
		}
		else if (!GetAsyncKeyState(VK_W))
		{
			keydown_w = false;
		}
	}
}

void InitRound(int stage)
{

	player.stage = stage;
	
	if (stage % 5 == 0)
	{
		player.maxUnitCount = 1;
		//보스경로 넣어줘..
	}
	else
	{
		player.maxUnitCount = ENEMY_INIT_NUMBER + stage / 3;
		findPath(field, field[0][9], field[24][12]);
	}
	player.nowUnitCount = 0;
	player.deadUnitCount = 0;
}

Unit UnitSpawn(int stagestep) { //적 유닛 생성함수, //스테이지 정보를 받아와야 한다.
    //보스 스테이지가 5의배수 스테이지에 생성 단 한마리만
    if (stagestep%5==0) {
        Unit boss = { ENEMY_HP + stagestep,ENEMY_SPAWN_XPOS, ENEMY_SPAWN_YPOS,true,true };
        return boss;
    }
    else {
        Unit enemy = {};
        enemy.HP = ENEMY_HP + stagestep - 1;
        enemy.isActive = true;
        enemy.isBoss = false;
        enemy.xpos = ENEMY_SPAWN_XPOS; //여기서 위치조정
        enemy.ypos = ENEMY_SPAWN_YPOS;
        return enemy;
    } 
}