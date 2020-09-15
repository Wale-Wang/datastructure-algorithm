#include<iostream>
#include<cstdio>
#include<cstdlib>
#define ElemType int

using namespace std;

typedef struct CNode{
	ElemType data;
	struct CNode *next;
} CNode, *CLinkList;

//头插
CLinkList HeadInsert(CLinkList &L){
	L = (CLinkList)malloc(sizeof(CNode));
	L->next = L;
	CNode *p;
	ElemType e;
	scanf("%d", &e);
	while(e != -1){
		p = (CNode*)malloc(sizeof(CNode));
		p->data = e;
		p->next = L->next;
		L->next = p;
		scanf("%d", &e);
	}
	return L;
}

//尾插
CLinkList TailInsert(CLinkList &L){
	L = (CLinkList)malloc(sizeof(CNode));
	L->next = L;
	CNode *p, *t;
	t = L;
	ElemType e;
	scanf("%d", &e);
	while(e != -1){
		p = (CNode*)malloc(sizeof(CNode));
		p->data = e;
		p->next = t->next;
		t->next = p;
		t = p;
		scanf("%d", &e);
	}
	return L;
}

//按序号查找
CNode* GetElemByNumber(CLinkList L, int i){
	CNode *p = L->next;
	int cnt = 1;
	while(cnt < i && p != L){
		p = p->next;
		cnt++;
	}
	return p;
}

//按值查找
CNode* GetElemByValue(CLinkList L, ElemType e){
	CNode *p = L->next;
	while(p != L && p->data != e)
		p = p->next;
	return p;
}

//求表长
int GetLength(CLinkList L){
	int cnt = 0;
	CNode *p = L->next;
	while(p != L){
		p = p->next;
		cnt++;
	}
	return cnt;
}
//前插(在第i个元素前面插入)
CLinkList PreInsert(CLinkList &L, int i, ElemType e){
	CNode *p = GetElemByNumber(L, i);
	CNode *n = (CNode*)malloc(sizeof(CNode));
	n->data = e;
	n->next = p->next;
	p->next = n;
	ElemType t = p->data;
	p->data = n->data;
	n->data = t;
	return L;
}
//后插(在第i-1个元素后面插入)
CLinkList PostInsert(CLinkList &L, int i, ElemType e){
	CNode *p = GetElemByNumber(L, i - 1);
	CNode *n = (CNode*)malloc(sizeof(CNode));
	n->data = e;
	n->next = p->next;
	p->next = n;
	return L;
}

//找到第i个元素删除
CLinkList PreDelete(CLinkList &L, int i, ElemType &e){
	CNode *p = GetElemByNumber(L, i);
	e = p->data;
	CNode *t = p->next;
	p->data = t->data;
	p->next = t->next;
	free(t);
	return L;
}
//后删
CLinkList PostDelete(CLinkList &L, int i, ElemType &e){
	CNode *p = GetElemByNumber(L, i - 1);
	CNode *t = p->next;
	e = t->data;
	p->next = t->next;
	free(t);
	return L;
}

//打印
void Print(CLinkList L){
	CNode *p = L->next;
	while(p != L){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}


int main(int argc, char const *argv[]){
	/* code */
	int e1, e2;
	CLinkList L1, L2;
	HeadInsert(L1);
	TailInsert(L2);
	Print(L1);
	Print(L2);
	printf("%d\n", GetElemByNumber(L1, 4)->data);
	printf("%d\n", GetElemByValue(L2, 4)->data);
	printf("%d\n", GetLength(L1));
	printf("%d\n", GetLength(L2));
	PreInsert(L1, 3, 7);
	PostInsert(L2, 3, 7);
	Print(L1);
	Print(L2);
	PreDelete(L1, 3, e1);
	PostDelete(L2, 3, e2);
	Print(L1);
	Print(L2);
	printf("%d %d", e1, e2);
	return 0;
}