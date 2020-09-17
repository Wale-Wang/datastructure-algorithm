#include <iostream>
#include <cstdio>
#define ElemType int
#define MaxSize 50

using namespace std;

typedef struct 
{
	ElemType data[MaxSize];
	int top;
} SqStack;

//初始化
void InitializeStack(SqStack & S){
	S.top = -1;
}

//判空
bool isEmpty(SqStack S){
	return S.top == -1;
}

//判满
bool isFull(SqStack S){
	return S.top == MaxSize - 1;
}

//求栈长度
int getLength(SqStack S){
	return S.top + 1;
}

//进栈
bool Push(SqStack & S, ElemType e){
	if(isFull(S))
		return false;
	S.data[++S.top] = e;
	return true;
}

//出栈
bool Pop(SqStack & S, ElemType & e){
	if(isEmpty(S))
		return false;
	e = S.data[S.top--];
	return true;
}

//读取栈顶元素
bool getTop(SqStack S, ElemType & e){
	if(isEmpty(S))
		return false;
	e = S.data[S.top];
	return true;
}

int main(int argc, char const *argv[])
{
	SqStack s;
	InitializeStack(s);
	ElemType a;
	cin>>a;
	while(a != -1){
		Push(s, a);
		cin>>a;
	}
	int temp;
	while(!isEmpty(s)){
		Pop(s, temp);
		cout<<temp<<endl;
	}
	return 0;
}