#include<cstdio>
#include<iostream>
#include<cstdlib>
#define ElemType int

using namespace std;

typedef struct DLinkNode{
	ElemType data;
	struct DLinkNode *next, *prior;
} DLNode, *DLinkList;

//头插法建立双链表
DLinkList HeadInsert(DLinkList &L){
	ElemType x;
	DLNode *s;
	L = (DLinkList)malloc(sizeof(DLNode));
	L->next = L;
	L->prior = L;
	scanf("%d", &x);
	while(x != -1){
		s = (DLNode*)malloc(sizeof(DLNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		s->prior = L;
		s->next->prior = s;
		scanf("%d", &x);
	}
	return L;
}

//尾插法建立双向链表
DLinkList TailInsert(DLinkList &L){
	DLNode *s;
	ElemType e;
	L = (DLinkList)malloc(sizeof(DLNode));
	L->next = L;
	L->prior = L;
	scanf("%d", &e);
	while(e != -1){
		s = (DLNode*)malloc(sizeof(DLNode));
		s->data = e;
		s->prior = L->prior;
		L->prior = s;
		s->next = L;
		s->prior->next = s;
		scanf("%d", &e);
	}
	return L;
}

//按序号查找元素
DLNode* GetElemByNumber(DLinkList L, int i){
	int cnt = 1;
	DLNode *p = L->next;
	while(p != L && cnt < i){
		cnt++;
		p = p->next;
	}
	return p;
}

//后插
DLinkList PostInsert(DLinkList &L, int i, ElemType e){
	DLNode *p = GetElemByNumber(L, i - 1);
	DLNode *s = (DLNode*)malloc(sizeof(DLNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	s->prior = p;
	s->next->prior = s;
	return L;
}

// 前插
DLinkList PreInsert(DLinkList &L, int i, ElemType e){
	DLNode *s = (DLNode*)malloc(sizeof(DLNode));
	DLNode *p = GetElemByNumber(L, i);
	s->data = e;
	s->prior = p->prior;
	p->prior = s;
	s->next = p;
	s->prior->next = s;
	return L;
}

//删除p
DLinkList Delete(DLinkList &L, int i, ElemType e){
	DLNode *p = GetElemByNumber(L, i);
	e = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return L;
}

//后删
DLinkList PostDelete(DLinkList &L, int i, ElemType e){
	DLNode *p = GetElemByNumber(L, i - 1);
	e = p->next->data;
	DLNode *t = p->next;
	p->next = t->next;
	t->next->prior = p;
	free(t);
	return L;
}

int main(int argc, char const *argv[]){
	int e;
	DLinkList L;
	TailInsert(L);
	//PreInsert(L, 2, 2);
	PostDelete(L, 2, e);
	DLNode *p = L->next;
	while(p && p != L){
		printf("%d ", p->data);
		p = p->next;
	}
	return 0;
}