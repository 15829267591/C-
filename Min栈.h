#pragma once

#include "Stack.h"
#include <assert.h>

//最小栈
// 初始化
// Push/Pop/Top/Min	要求 O(1)
typedef struct MinStack {
	Stack stackNormal;   //保存正常序列
	Stack stackMin;		 //保存当前最小数
}MinStack;

void MinStackInit(MinStack* pMS);
void MinStackPush(MinStack* pMS, StackDataType data);
void MinStackPop(MinStack* pMS);
StackDataType MinStackTop(MinStack* pMS);
StackDataType MinStackMin(MinStack* pMS);
void TestMinStack();


