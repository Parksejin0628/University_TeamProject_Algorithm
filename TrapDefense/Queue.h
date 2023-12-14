#pragma once
#include "ProgramBase.h"
#include "BFS.h"

typedef struct Node 
{
  Field data;
  Node *next;
}Node;

typedef struct Queue
{
  Node *front;
  Node *rear;
  int count; // 큐 안의 노드 개수 
}Queue;

void initQueue(Queue* queue);
int isEmpty(Queue* queue);
void enqueue(Queue* queue, Field data);
Field dequeue(Queue* queue);
