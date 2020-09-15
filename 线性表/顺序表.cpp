#include<cstdio>
#include<iostream>
#define MaxSize 50
#define ElemType int

using namespace std;

//顺序表结构
typedef struct{
	ElemType data[MaxSize];
	int length;
} SqList;

//在第i个位置插入
bool Insert(SqList &L, int i, ElemType e){
	if(i < 1 || i > L.length + 1)
		return false;
	if(L.length >= MaxSize)
		return false;
	for(int j = L.length; j >= i; j--)
		L.data[j] = L.data[j - 1];
	L.data[i - 1] = e;
	L.length++;
	return true;
}

//删除第i个位置元素
bool Delete(SqList &L, int i, ElemType &e){
	if(i < 1 || i > L.length)
		return false;
	e = L.data[i - 1];
	for(int j = i; j < L.length; j++)
		L.data[j-1] = L.data[j];
	L.length--;
	return true;
}

//按值查找
int Locate(SqList L, ElemType e){
	for(int i = 0; i < L.length; i++)
		if(L.data[i] == e)
			return i+1;
	return -1;
}

int main(int argc, char const *argv[]){
	SqList L;
	int d;
	for(int i = 0; i < 5; i++)
		L.data[i] = i+1;
	L.length = 5;
	Insert(L, 2, 2);
	Delete(L, 2, d);
	printf("%d\n", Locate(L, 6));
	for(int i = 0; i < L.length; i++)
		printf("%d ", L.data[i]);
	return 0;
}