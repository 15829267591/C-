#pragma once

#define MAX_SIZE 100
typedef char StackDataType;
typedef struct Stack {
	StackDataType array[MAX_SIZE];
	int top;   //表示当前个数
}Stack;

// 初始化/销毁
// 增（只能从栈顶）/删（只能删除栈顶）/查（只能查看栈顶元素）
// 个数 / 是否空 / 是否满
// 增 -> 顺序表的尾插
// 删 -> 顺序表的尾删

void StackInit(Stack* pStack);
void StackDestroy(Stack* pStack);
void StackPush(Stack* pStack, StackDataType data);
void StackPop(Stack* pStack);
StackDataType getTop(Stack* pStack);
int getSize(Stack* pStack);
int StackIsEmpty(Stack* pStack);
int StackIsFull(Stack* pStack);