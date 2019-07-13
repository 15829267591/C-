#pragma once


//一个数组实现两个栈

//两边往中间生长的方式
typedef struct TStack {
	int  *array;
	int	 top1;
	int  top2;
	int capacity;
}TStack;

void TStackInit(TStack* pTS);
void TStackDestroy(TStack* pTS);
void ExpanfIfRequired(TStack* pTS);
void Push_1(TStack* pTS, int data);
void Push_2(TStack* pTS, int data);
void Pop_1(TStack* pTS);
void Pop_2(TStack* pTS);
int Top_1(TStack* pTS);
int Top_2(TStack* pTS);
int Size_1(TStack* pTS);
int Size_2(TStack* pTS);

void TestTStack();