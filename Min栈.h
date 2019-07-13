#pragma once

#include "Stack.h"
#include <assert.h>

//��Сջ
// ��ʼ��
// Push/Pop/Top/Min	Ҫ�� O(1)
typedef struct MinStack {
	Stack stackNormal;   //������������
	Stack stackMin;		 //���浱ǰ��С��
}MinStack;

void MinStackInit(MinStack* pMS);
void MinStackPush(MinStack* pMS, StackDataType data);
void MinStackPop(MinStack* pMS);
StackDataType MinStackTop(MinStack* pMS);
StackDataType MinStackMin(MinStack* pMS);
void TestMinStack();


