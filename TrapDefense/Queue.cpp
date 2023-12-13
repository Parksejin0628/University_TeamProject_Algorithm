#pragma once
#include "Queue.h"


void initQueue(Queue *queue)
{
  queue->front = queue->rear = NULL;
  queue->count = 0;  // 큐 안의 노드 개수를 0으로 설정
}


int isEmpty(Queue *queue) 
{
  return queue->count == 0;  // 큐안의 노드 개수가 0이면 빈 상태
}
 
void enqueue(Queue *queue, MapPosition data)
{
  Node *newNode = (Node *)malloc(sizeof(Node)); // newNode 생성
  newNode->data = data;
  newNode->next = NULL;

  if (isEmpty(queue))  // 큐가 비어있을 때
  {
    queue->front = newNode;   
  }
  else  // 비어있지 않을 때
  {
    queue->rear->next = newNode;  //맨 뒤의 다음을 newNode로 설정
  }
  queue->rear =  newNode;  //맨 뒤를 newNode로 설정  
  queue->count++;  //큐안의 노드 개수를 1 증가
}

MapPosition dequeue(Queue *queue)
{
  MapPosition data;
  MapPosition empty = {};
  Node *ptr;
  if (isEmpty(queue))  //큐가 비었을 때
  {
    printf("Error : Queue is empty!\n");
    return empty;
  }
  ptr = queue->front;  //맨 앞의 노드 ptr 설정 
  data = ptr->data;  // return 할 데이터 
  queue->front = ptr->next;  //맨 앞은 ptr의 다음 노드로 설정
  free(ptr);  // ptr 해제 
  queue->count--;  //큐의 노드 개수를 1 감소
  
  return data;
}
