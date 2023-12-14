#include"GameManager.h"

Field field[FIELD_HEIGHT][FIELD_WIDTH];
Player player;
bool isBuildTurn = true;
Unit unitQueue[MAX_ENEMY];


void PlayInGame()
{
	bool defenseStart = false;
	double frameStart = clock();
	static int frontIndex = 0;
	static int rearIndex = -1;
	int X = 0;
	int Y = 0;
	Unit nowUnit;
	int temp = 0;

	InitGame();

	while (1)
	{
		UpdateScreen();
		if (isBuildTurn)
		{
			UpdateScreen();
			Goto_xy(60, 0);
			printf("�Է¿Ϸ� %d, %d", player.cursorX, player.cursorY);

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
				//�� �ѱ��
				break;
			case VK_Q:
				if (field[player.cursorY - 2][player.cursorX].type == NONE && player.BarricadeSeed > 0)
				{
					field[player.cursorY - 2][player.cursorX].type = BLOCK;
					player.BarricadeSeed -= 1;
				}
				//�ٸ�����Ʈ ��ġ
				break;
			case VK_W:
				if (field[player.cursorY - 2][player.cursorX].type == NONE && player.TrapSeed > 0)
				{
					field[player.cursorY - 2][player.cursorX].trap = InitTrap(player.cursorX, player.cursorY - 2);
					field[player.cursorY - 2][player.cursorX].type = field[player.cursorY - 2][player.cursorX].trap.type;
				}
				//Ÿ�� ��ġ
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
				for (int i = frontIndex; i <= rearIndex; i++)
				{
					nowUnit = unitQueue[i % MAX_ENEMY];
					X = nowUnit.xpos;
					Y = nowUnit.ypos;
					field[Y + field[Y][X].nextY][X + field[Y][X].nextX].unit = nowUnit;
					unitQueue[i % MAX_ENEMY].xpos = X + field[Y][X].nextX;
					unitQueue[i % MAX_ENEMY].ypos = Y + field[Y][X].nextY;
					if (field[Y][X].trap.isExist == true)
					{
						field[Y][X].type = field[Y][X].trap.type;
					}
					else
					{
						field[Y][X].type = NONE;
					}
					if (field[Y + field[Y][X].nextY][X + field[Y][X].nextX].trap.isExist == 1)
					{
						unitQueue[i % MAX_ENEMY].HP -= field[Y + field[Y][X].nextY][X + field[Y][X].nextX].trap.damage;
					}
					else if (field[Y + field[Y][X].nextY][X + field[Y][X].nextX].type == BASE)
					{
						unitQueue[i % MAX_ENEMY].HP = -1;
						player.HP -= 1;
						if (player.HP <= 0)
						{
							UpdateScreen();
							exit(1);
						}
					}
					if (unitQueue[i % MAX_ENEMY].HP > 0)
					{
						field[Y + field[Y][X].nextY][X + field[Y][X].nextX].type = ENEMY;
					}
					else if (unitQueue[i % MAX_ENEMY].HP <= 0)
					{
						++frontIndex;
						player.deadUnitCount++;
						if (player.deadUnitCount >= player.maxUnitCount)
						{
							isBuildTurn = true;
							player.BarricadeSeed += 10;
							player.TrapSeed += 5;
						}
					}
					
					
					/*
					Goto_xy(70, i+3);
					printf("help me %3d %3d %3d", i, frontIndex, rearIndex);
					Goto_xy(0, 30);
					for (int y = 0; y < FIELD_HEIGHT; y++)
					{
						for (int x = 0; x < FIELD_WIDTH; x++)
						{
							printf("%d ", field[y][x].type);
						}
						printf("\n");
					}
					*/
				}
				//UpdateScreen();
				if (player.nowUnitCount < player.maxUnitCount)
				{ 
					player.nowUnitCount++;
					unitQueue[++rearIndex % MAX_ENEMY] = UnitSpawn(player.stage);
					X = unitQueue[rearIndex % MAX_ENEMY].xpos;
					Y = unitQueue[rearIndex % MAX_ENEMY].ypos;
					field[Y][X].unit = unitQueue[rearIndex % MAX_ENEMY];
					field[Y][X].type = ENEMY;
					
					
				}
				frameStart = clock();
				
			}
		}
	}


}

void InitGame()
{
	player.HP = 5;
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
	/*
	if (stage % 5 == 0)
	{
		player.maxUnitCount = 1;
		findBossPath(field, field[0][9], field[24][12]);
	}*/
	//else
	//{
		player.maxUnitCount = ENEMY_INIT_NUMBER + stage / 3;
		BFS();
	//}
	player.nowUnitCount = 0;
	player.deadUnitCount = 0;

}

Unit UnitSpawn(int stagestep) { //�� ���� �����Լ�, //�������� ������ �޾ƿ;� �Ѵ�.
	//���� ���������� 5�ǹ�� ���������� ���� �� �Ѹ�����
	/*if (stagestep % 5 == 0) {
		Unit boss = { ENEMY_HP + stagestep,ENEMY_SPAWN_XPOS, ENEMY_SPAWN_YPOS,true,true };
		return boss;
	}*/
	//else {
		Unit enemy = {};
		enemy.HP = ENEMY_HP + stagestep - 1;
		enemy.isActive = true;
		enemy.isBoss = false;
		enemy.xpos = ENEMY_SPAWN_XPOS; //���⼭ ��ġ����
		enemy.ypos = ENEMY_SPAWN_YPOS;
		return enemy;
	//}
}

void BFS()
{
	Position queue[100] = {};
	Position nowPos = { 12, 24 };
	bool isCheck[FIELD_HEIGHT][FIELD_WIDTH] = { false };
	int frontIndex = -1;
	int rearIndex = -1;

	

	queue[++frontIndex % 100] = { 12, 24 };
	isCheck[nowPos.Y][nowPos.X] = true;
	field[24][12].nextX = 0;
	field[24][12].nextY = 1;

	
	

	while (frontIndex != rearIndex)
	{
		nowPos = queue[++rearIndex % 100];
		if (nowPos.X + 1 < FIELD_WIDTH && isCheck[nowPos.Y][nowPos.X+1] == false && field[nowPos.Y][nowPos.X + 1].type != BLOCK)
		{
			queue[++frontIndex % 100] = { (short)(nowPos.X + 1), nowPos.Y };
			isCheck[nowPos.Y][nowPos.X + 1] = true;
			field[nowPos.Y][nowPos.X + 1].nextX = -1;
			field[nowPos.Y][nowPos.X + 1].nextY = 0;
		}
		if (nowPos.X - 1 >= 0 && isCheck[nowPos.Y][nowPos.X - 1] == false && field[nowPos.Y][nowPos.X - 1].type != BLOCK)
		{
			queue[++frontIndex % 100] = { (short)(nowPos.X - 1), nowPos.Y };
			isCheck[nowPos.Y][nowPos.X - 1] = true;
			field[nowPos.Y][nowPos.X - 1].nextX = 1;
			field[nowPos.Y][nowPos.X - 1].nextY = 0;
		}
		if (nowPos.Y + 1 < FIELD_HEIGHT && isCheck[nowPos.Y + 1][nowPos.X] == false && field[nowPos.Y + 1][nowPos.X].type != BLOCK)
		{
			queue[++frontIndex % 100] = { (short)(nowPos.X), (short)(nowPos.Y + 1) };
			isCheck[nowPos.Y + 1][nowPos.X] = true;
			field[nowPos.Y + 1][nowPos.X].nextX = 0;
			field[nowPos.Y + 1][nowPos.X].nextY = -1;
		}
		if (nowPos.Y - 1 >=  0 && isCheck[nowPos.Y - 1][nowPos.X] == false && field[nowPos.Y - 1][nowPos.X].type != BLOCK)
		{
			queue[++frontIndex % 100] = { (short)(nowPos.X), (short)(nowPos.Y - 1) };
			isCheck[nowPos.Y - 1][nowPos.X] = true;
			field[nowPos.Y - 1][nowPos.X].nextX = 0;
			field[nowPos.Y - 1][nowPos.X].nextY = 1;
		}

	}
	
	
	
}