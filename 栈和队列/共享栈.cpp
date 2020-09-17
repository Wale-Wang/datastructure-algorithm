#include <iostream>
#include <cstdio>
#define ElemType int 
#define MaxSize 50

using namespace std;

typedef struct 
{
	ElemType data[MaxSize];
	int top_1, top_2;
} SStack;


void InitializeSStack(SStack S){
	S.top_1 = -1;
	S.top_2 = MaxSize;
}

//判满
bool isFull(SStack S){
	if(S.top_2 - S.top_1 == 1)
		return true;
	else
		return false;
}

//S2入栈
bool Push2(SStack & S, ElemType e){
	if(isFull)
		return false;
	S.data[--S.top_2] = e;
	return true;
}

//S2出栈
bool Pop2(SStack & S, ElemType & e){
	if(S.top_2 == MaxSize)
		return false;
	e = S.data[S.top_2++];
	return true;
}

int main(int argc, char const *argv[])
{
	//测试
	return 0;
}