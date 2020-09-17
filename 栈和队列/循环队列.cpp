#include<iostream>
#include<cstdio>
#include<cstdlib>
#define ElemType int
#define MaxSize 50

using namespace std;

typedef struct CircularQueue
{
	ElemType data[MaxSize];
	int front, rear;
	int size;  //第二种判满的方法
	bool tag;  //第三种判满的方法
} CQueue;

//初始化
void InitializeCQueue(CQueue &q){
	q.front = q.rear = 0;
	q.size = 0;
	q.tag = true;
}

//判满1
bool isFull1(CQueue q){
	if((q.rear + 1) % MaxSize == q.front)
		return true;
	else
		return false;
}

//判满2
bool isFull2(CQueue q){
	if(q.size == MaxSize)
		return true;
	else
		return false;
}

//判满3
bool isFull3(CQueue q){
	if(q.front == q.rear && q.tag == true)
		return true;
	else
		return false;
}

//判空1
bool isEmpty1(CQueue q){
	if(q.rear == q.front)
		return true;
	else
		return false;
}

//判空2
bool isEmpty2(CQueue q){
	if(q.size == 0)
		return true;
	else
		return false;
}

//判空3
bool isEmpty3(CQueue q){
	if(q.front == q.rear && q.tag == false)
		return true;
	else
		return false;
}

//入队1
bool EnQueue1(CQueue &q, ElemType e){
	if(isFull1(q))
		return false;
	q.data[q.rear] = e;
	q.rear = (q.rear + 1) % MaxSize;
	return true;
}

//入队2
bool EnQueue2(CQueue &q, ElemType e){
	if(isFull2(q))
		return false;
	q.data[q.rear] = e;
	q.rear = (q.rear + 1) % MaxSize;
	q.size ++;
	return true;

}

//入队3
bool EnQueue3(CQueue &q, ElemType e){
	if(isFull3(q))
		return false;
	q.data[q.rear] = e;
	q.rear = (q.rear + 1) % MaxSize;
	if(q.front == q.rear)
		tag = true;
	return true;
}

//出队1
bool DeQueue(CQueue & q, ElemType & e){
	if(isEmpty1(q))
		return false;
	e = q.data[q.front];
	q.front = (q.front + 1) % MaxSize;
	return true;
}

//出队2
bool DeQueue(CQueue & q, ElemType & e){
	if(isEmpty2(q))
		return false;
	e = q.data[q.front];
	q.front = (q.front + 1) % MaxSize;
	q.size--;
	return true;
}

//出队3
bool DeQueue(CQueue & q, ElemType & e){
	if(isEmpty1(q))
		return false;
	e = q.data[q.front];
	q.front = (q.front + 1) % MaxSize;
	if(q.front == q.rear)
		tag = false;
	return true;
}

int main(int argc, char const *argv[])
{
	//测试
	return 0;
}