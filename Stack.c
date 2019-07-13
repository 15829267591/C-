#include "Stack.h"
#include <assert.h>
void StackInit(Stack* pStack)
{
	pStack->top = 0;
}
void StackDestroy(Stack* pStack)
{
	pStack->top = 0;
}
void StackPush(Stack* pStack, StackDataType data)
{
	assert(pStack->top < MAX_SIZE);
	pStack->array[pStack->top++] = data;
}
void StackPop(Stack* pStack)
{
	assert(pStack->top > 0);
	pStack->top--;
}
StackDataType getTop(Stack* pStack)
{
	assert(pStack->top > 0);
	return pStack->array[pStack->top-1];
}
int getSize(Stack* pStack)
{
	return pStack->top;
}
int StackIsEmpty(Stack* pStack)
{
	return pStack->top <= 0;
}
int StackIsFull(Stack* pStack)
{
	return pStack->top >= MAX_SIZE;
}