#include"GameManager.h"

Field field[FIELD_HEIGHT][FIELD_WIDTH];
Player player;

void PlayInGame()
{
	InitGame();
	UpdateScreen();
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
	}
}