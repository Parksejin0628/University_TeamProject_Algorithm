#include"GameManager.h"

char inputManager()
{
	char input;

	if (kbhit())
	{
		input = getch();
		switch (input)
		{
		case 'a': //���ϴ� Ű �ְ�
			//�� �κп� ���ϴ� ��� (����� �Լ��� �����ϰ� �Լ� �� ���� ���� ��õ)
			break;
		}
		return input;
	}
}