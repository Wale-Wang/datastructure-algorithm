#include<iostream>
#include<cstdio>
#define ElemType int

using namespace std;

//单链表结构
typedef struct LNode{
	ElemType data;
	struct LNode *next;
} LNode, *LinkList;

//头插法建立单链表
LinkList HeadInsert(LinkList &L){
	LNode *s;
	int e;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	scanf("%d", &e);
	while(e != -1){
		s = (LNode*)malloc(sizeof(LNode));
		s->data = e;
		s->next = L->next;
		L->next = s;
		scanf("%d", &e);
	}
	return L;
}

//尾插法建立单链表
LinkList TailInsert(LinkList &L){
	int e;
	L = (LinkList)malloc(sizeof(LNode));
	LNode *s, *t = L;
	scanf("%d", &e);
	while(e != -1){
		s = (LNode*)malloc(sizeof(LNode));
		s->data = e;
		t->next = s;
		t = s;
		scanf("%d", &e);
	}
	t->next = NULL;
	return L;
}

//按序号查找元素
LNode* GetElemByNumber(LinkList L, int i){
	int cnt = 1;
	LNode *p = L->next;
	if(i == 0)
		return L;
	if(i < 0)
		return NULL;
	while(p && cnt < i){
		p = p->next;
		cnt++;
	}
	return p;
}

//按值查找元素
LNode* GetElemByValue(LinkList L, ElemType v){
	LNode *p = L->next;
	while(p && p->data != v)
		p = p->next;
	return p;
}

//求表长
int GetLength(LinkList L){
	int cnt = 0;
	LNode *p = L->next;
	while(p){
		cnt++;
		p = p->next;
	}
	return cnt;
}

//前插
LinkList PreInsert(LinkList &L, int i, ElemType e){
	if(i < 1 || i > GetLength(L) + 1)
		return L;
	LNode *p = GetElemByNumber(L, i - 1);
	LNode *s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return L;
}

//后插法
LinkList PostInsert(LinkList &L, int i, ElemType e){
	if(i < 1 || i > GetLength(L) + 1)
		return L;
	LNode *p = GetElemByNumber(L, i);
	LNode *s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	ElemType t = s->data;
	s->data = p->data;
	p->data = t;
	return L;
}

//前删
LinkList PreDelete(LinkList &L, int i, ElemType &e){
	if(i < 1 || i > GetLength(L))
		return NULL;
	LNode *p = GetElemByNumber(L, i - 1);
	LNode *s = p->next;
	p->next = s->next;
	e = s->data;
	free(s);
	return L;
}

//后删
LinkList PostDelete(LinkList &L, int i, ElemType &e){
	if(i < 1 || i > GetLength(L))
		return NULL;
	LNode *p = GetElemByNumber(L, i);
	e = p->data;
	LNode *s = p->next;
	p->data = s->data;
	p->next = s->next;
	free(s);
	return L;
}

//打印链表，用于测试
void PrintList(LinkList L){
	LNode *p = L->next;
	while(p){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	/* code */
	LinkList L1, L2;
	// HeadInsert(L1);
	// PrintList(L1);
	TailInsert(L2);
	PrintList(L2);
	// LNode *p = GetElemByNumber(L2, 2);
	//LNode *p = GetElemByValue(L2, 6);
	//printf("%d", GetLength(L2));
	//PostInsert(L2, 3, 3);
	int e;
	PostDelete(L2, 2, e);
	printf("%d\n", e);
	PrintList(L2);
	return 0;
}