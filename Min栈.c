#include "Min栈.h"
#include "Stack.h"
#include "stdio.h"

void MinStackInit(MinStack* pMS)
{
	StackInit(&(pMS->stackMin));
	StackInit(&(pMS->stackNormal));
}
void MinStackPush(MinStack* pMS, StackDataType data)
{
	//正常序列栈，正常入站即可
	StackPush(&(pMS->stackNormal), data);
	//最小栈入栈
	if (StackIsEmpty(&(pMS->stackMin))) {
		StackPush(&(pMS->stackMin), data);
		return;
	}
	if (data < getTop(&(pMS->stackMin))) {
		StackPush(&(pMS->stackMin), data);
	}
}
void MinStackPop(MinStack* pMS)
{
	if (getTop(&pMS->stackMin) == getTop(&(pMS->stackNormal))) {
		StackPop(&(pMS->stackMin));
	}
	StackPop(&(pMS->stackNormal));

}
StackDataType MinStackTop(MinStack* pMS)
{
	return getTop(&(pMS->stackNormal));
}
StackDataType MinStackMin(MinStack* pMS)
{
	return getTop(&(pMS->stackMin));
}


void TestMinStack()
{
	MinStack stack;

	MinStackInit(&stack);
	StackDataType numbers[] = { 5, 7, 4, 3, 1, 6, 2 };

	for (int i = 0; i < 7; i++) {
		MinStackPush(&stack, numbers[i]);
		printf("Top = %d, Min = %d\n", MinStackTop(&stack), MinStackMin(&stack));
	}
}