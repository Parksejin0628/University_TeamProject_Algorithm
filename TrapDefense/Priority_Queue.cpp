#include "Priority_Queue.h"
#include <math.h>

void enPQ(Field field[10000], int distances[10000], int damage, Field pos, int* rear);
Field popPQ(Field field[10000], int distances[10000], int* rear);

void enPQ(Field field[10000], int distances[10000], int damage, Field pos, int* rear)
{
	int tempIndex = *rear;

	field[*rear] = pos;
	distances[*rear] = damage;
	*rear++;

	while (distances[tempIndex] <= distances[tempIndex / 2] && tempIndex > 1 && distances[tempIndex / 2] != 0)
	{
		distances[tempIndex] = distances[tempIndex / 2];
		distances[tempIndex / 2] = damage;

		field[tempIndex] = field[tempIndex / 2];
		field[tempIndex / 2] = pos;

		tempIndex = tempIndex / 2;
	}
}

Field popPQ(Field field[10000], int distances[10000], int* rear)
{
	if (*rear == 1)
	{
		return ;
	}
	Field returnField;
	Field tempField;
	int returnDistances;
	int tempIndex = 1;
	int temp = 0;

	distances[1] = distances[--(*rear)];
	distances[*rear] = 0;
	temp = distances[1];

	returnField = field[1];
	field[1] = field[--(*rear)];
	field[*rear] = tempField;
	tempField = field[1];

	while (tempIndex * 2 <= *rear)
	{
		if (distances[tempIndex * 2] <= distances[tempIndex] && distances[tempIndex * 2 + 1] <= distances[tempIndex] && distances[tempIndex * 2] != 0 && distances[tempIndex * 2 + 1] != 0)
		{
			if (distances[tempIndex * 2] <= distances[tempIndex * 2 + 1])
			{
				distances[tempIndex] = distances[tempIndex * 2];
				distances[tempIndex * 2] = temp;

				field[tempIndex] = field[tempIndex * 2];
				field[tempIndex * 2] = tempField;

				tempIndex = tempIndex * 2;
			}
			else
			{
				distances[tempIndex] = distances[tempIndex * 2 + 1];
				distances[tempIndex * 2 + 1] = temp;

				field[tempIndex] = field[tempIndex * 2 + 1];
				field[tempIndex * 2 + 1] = tempField;

				tempIndex = tempIndex * 2 + 1;
			}
			continue;
		}
		else if (distances[tempIndex * 2] <= distances[tempIndex] && distances[tempIndex * 2] != 0)
		{
			distances[tempIndex] = distances[tempIndex * 2];
			distances[tempIndex * 2] = temp;

			field[tempIndex] = field[tempIndex * 2];
			field[tempIndex * 2] = tempField;

			tempIndex = tempIndex * 2;
			continue;
		}
		else if (distances[tempIndex * 2 + 1] <= distances[tempIndex] && distances[tempIndex * 2 + 1] != 0)
		{
			distances[tempIndex] = distances[tempIndex * 2 + 1];
			distances[tempIndex * 2 + 1] = temp;

			field[tempIndex] = field[tempIndex * 2 + 1];
			field[tempIndex * 2 + 1] = tempField;

			tempIndex = tempIndex * 2 + 1;
			continue;
		}
		else
		{
			break;
		}
	}
	return returnField;
}
