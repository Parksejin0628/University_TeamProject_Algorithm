#include"GameManager.h"

Field field[FIELD_HEIGHT][FIELD_WIDTH];
Player player;
bool isBuildTurn = true;

void PlayInGame()
{
	int temp = 0;

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
				if (player.cursorY - 1 > MIN_CURSOR_Y && player.cursorY - 1 < MAX_CURSOR_Y)
				{
					player.cursorY--;
				}
				break;
			case VK_DOWN:
				if (player.cursorY + 1 > MIN_CURSOR_Y && player.cursorY + 1 < MAX_CURSOR_Y)
				{
					player.cursorY++;
				}
				break;
			case VK_LEFT:
				if (player.cursorX - 1 > MIN_CURSOR_Y && player.cursorX - 1 < MAX_CURSOR_Y)
				{
					player.cursorX--;
				}
				break;
			case VK_RIGHT:
				if (player.cursorX + 1 > MIN_CURSOR_Y && player.cursorX + 1 < MAX_CURSOR_Y)
				{
					player.cursorX++;
				}
				break;
			case VK_SPACE:
				isBuildTurn = false;
				//턴 넘기기
				break;
			case VK_Q:
				//바리게이트 설치
				break;
			case VK_W:
				//타일 설치
				break;
			}
		}
		else
		{

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
	player.stage = 1;
	player.cursorX = 10;
	player.cursorY = 10;

	for (int y = 0; y < FIELD_HEIGHT; y++)
	{
		for (int x = 0; x < FIELD_WIDTH; x++)
		{
			field[y][x].type = NONE;
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
		if (GetAsyncKeyState(VK_Q) && keydown_space == false)
		{
			keydown_q = true;
			return VK_Q;
		}
		else if (!GetAsyncKeyState(VK_Q))
		{
			keydown_q = false;
		}
		if (GetAsyncKeyState(VK_W) && keydown_space == false)
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