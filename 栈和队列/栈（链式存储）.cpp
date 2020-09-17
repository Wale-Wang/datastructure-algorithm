/*
	栈的链式存储是使用不带头节点的单链表 
*/

#include <iostream>
#include <cstdio>
#define ElemType int

using namespace std;

typedef struct LinkNode
{
	ElemType data;
	struct LinkNode *next;
} *LinkStack;

//入栈
bool Push(LinkStack & SL, ElemType e){
	LinkStack s = (LinkStack)malloc(sizeof(struct LinkNode));
	s->data = e;
	s->next = SL->next;
	SL = s;
	return true;
}

//出栈
bool Pop(LinkStack & S, ElemType & e){
	LinkStack t = S;
	e = t->data;
	S = t->next;
	free(t);
	return true;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}