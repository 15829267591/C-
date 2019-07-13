#include"面试题二.h"

void QueueSInit(QueueS* pQS)
{
	StackInit(&(pQS->stack1));
	StackInit(&(pQS->stack2));
}
void QueueSPush(QueueS* pQS, StackDataType data)
{
	 //无脑入栈1
	StackPush(&(pQS->stack1), data);
}
void QueueSPop(QueueS* pQS)
{
	if (StackIsEmpty(&(pQS->stack2))) {
		while (!(StackIsEmpty(&(pQS->stack1)))) {
			StackDataType s1 = getTop(&(pQS->stack1));
			StackPush(&(pQS->stack2), s1);
			StackPop(&(pQS->stack1));
		}
	}
	StackPop(&(pQS->stack2));
}
StackDataType QueueSFront(QueueS* pQS)
{
	if (StackIsEmpty(&(pQS->stack2))) {
		while (!(StackIsEmpty(&(pQS->stack1)))) {
			StackDataType s1 = getTop(&(pQS->stack1));
			StackPush(&(pQS->stack2), s1);
			StackPop(&(pQS->stack1));
		}
	}
	return getTop(&(pQS->stack2));
}

void TestQueueS()
{
	QueueS	qs;
	QueueSInit(&qs);

	for (int i = 0; i < 10; i++) {
		QueueSPush(&qs, i);
	}

	for (int i = 0; i < 10; i++) { 
		printf("%d\n", QueueSFront(&qs));
		QueueSPop(&qs);
	}
}