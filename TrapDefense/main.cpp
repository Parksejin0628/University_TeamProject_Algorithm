#include"ProgramBase.h"
#include"Unit_algorithm.h"
#include"PrintManager.h"
#include"GameManager.h"

int main(void)
{
	for (int y = 1; y <= 20; y++)
	{
		printf("%d", y%10);
		for (int x = 2; x <= 50; x++)
		{
			printf("%d", x%10);
		}
		printf("\n");
	}

	return 0;
}