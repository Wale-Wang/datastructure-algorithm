#include <iostream>
#include <cstdlib>
#include <cstdio>
#define ElemType int

using namespace std;

typedef struct qNode
{
	ElemType data;
	struct qNode *next;
} LiQNode;

typedef struct
{
	LiQNode *front, *rear;
} LiQueue;

//初始化
void InitializeLiQueue(LiQueue & q){
	q.front = q.rear = (LiQNode*)malloc(sizeof(LiQNode));
	q.front->next  =NULL;
}

//判空
bool isEmpty(LiQueue q){
	if(q.front == q.rear)
		return true;
	else
		return false;
}

//入队
void EnQueue(LiQueue &q, ElemType e){
	LiQNode *s = (LiQNode*)malloc(sizeof(LiQNode));
	s->data  =e;
	s->next = NULL;
	q.rear->next = s;
	q.rear = s;
}

//出队
void DeQueueu(LiQNode & q, ElemType & e){
	LiQNode *t = q.front->next;
	e = t->data;
	q.front->next = t->next;
	if(q.rear == t)
		q.rear = q.front;
	free(t);
}

int main(int argc, char const *argv[])
{
	//测试
	return 0;
}