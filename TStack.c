#include "TStack.h"
#include <assert.h>
#include "Stack.h"
#include <stdio.h>
void TStackInit(TStack* pTS)
{
	if (pTS == NULL) {
		return;
	}
	pTS->capacity = 10;
	pTS->array = (int*)malloc(sizeof(int)*pTS->capacity);
	pTS->top1 = 0;
	pTS->top2 = pTS->capacity - 1;
}
void TStackDestroy(TStack* pTS)
{
	assert(pTS);
	pTS->capacity = 0;
	pTS->top1 = 0;
	pTS->top2 = 0;
	free(pTS->array);
	pTS->array = NULL;
}
void ExpanfIfRequired(TStack* pTS)
{
	//断言
	assert(pTS);
	//栈1指针没有超过栈2指针，不需要扩容
	if (pTS->top1 <= pTS->top2) {
		return;
	}
	//扩容
	int newCapacity = (pTS->capacity) * 2;
	int* newArray = (int*)malloc(sizeof(int)*newCapacity);
	//判断新数组空间是否开辟成功
	assert(newArray);
	//进行数据搬移
	for (int i = 0; i < pTS->top1; i++) {
		newArray[i] = pTS->array[i];
	}
	//栈2进行搬移 [top1, capcacity）,原数组
	for (int j = pTS->top1; j < pTS->capacity; j++) {
		int k = j + pTS->capacity;
		newArray[k] = pTS->array[j];
	}
	//更新数组
	pTS->top2 += pTS->capacity;
	pTS->capacity = newCapacity;

	//销毁原数组
	free(pTS->array);
	pTS->array = newArray;
}
void Push_1(TStack* pTS, int data)
{
	ExpanfIfRequired(pTS);
	pTS->array[pTS->top1] = data;
	pTS->top1++;
}
void Push_2(TStack* pTS, int data)
{
	ExpanfIfRequired(pTS);
	pTS->array[pTS->top2] = data;
	pTS->top2--;
}
void Pop_1(TStack* pTS)
{
	pTS->top1--;
}
void Pop_2(TStack* pTS)
{
	pTS->top2++;
}
int Top_1(TStack* pTS)
{
	return pTS->array[pTS->top1 - 1];
}
int Top_2(TStack* pTS)
{
	return pTS->array[pTS->top2 + 1];
}
int Size_1(TStack* pTS)
{
	return pTS->top1;
}
int Size_2(TStack* pTS)
{
	return pTS->capacity - (pTS->top2) - 1;
}

void TestTStack()
{
	TStack stack;
	TStackInit(&stack);

	Push_1(&stack, 1);
	Push_1(&stack, 2);
	Push_1(&stack, 3);
	Push_1(&stack, 4);
	Push_1(&stack, 5);
	Push_1(&stack, 6);
	Push_1(&stack, 7);

	Push_2(&stack, 101);
	Push_2(&stack, 102);
	Push_2(&stack, 103);
	for (int i = 0; i < (&stack)->capacity; i++) {
		printf("%d ",(&stack)->array[i]);
	}
	printf("\n");
	// 触发扩容
	Push_2(&stack, 104);
	Push_2(&stack, 105);

	for (int i = 0; i < (&stack)->capacity; i++) {
		printf("%d ", (&stack)->array[i]);
	}
}