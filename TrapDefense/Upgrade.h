#pragma once

#include"ProgramBase.h"

int bigger(int arr1, int arr2) //ū �� ��
{
    return (arr1 > arr2) ? arr1 : arr2;
}

//shape�� ���� ����
#define TRIANGLE 1
#define RECTANGLE 2
#define HEXAGON 3
#define STAR 4 
#define Circle 5

//Trap����ü�� �̷���� ���Ḯ��Ʈ�� ���������ϸ� ������
typedef struct Trap {
    int damage;
    int xpos;
    int ypos;
    int shape;
    int up_value;
    int up_cost;
}Trap;

//���� ���׷��̵�� ����ϴ� ���� ���� (���� ����)
int info_up_cost[5][5];

//���� ���׷��̵�� ��� ���� (���� ����)
int info_up_value[5][5];

//01���湮�� �˰���
int bag_zeroone(int n, int M, int** bag, Trap trap[], bool* selectedTraps)