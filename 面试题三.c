#include "面试题三.h"
#include "Queue.h"
void QStackInit(QStack* pQS)
{
	QueueInit(&pQS->q1);
	QueueInit(&pQS->q2);
}
void QStackDestroy(QStack* pQS)
{
	QueueDestroy(&pQS->q1);
	QueueDestroy(&pQS->q2);
}
void QStackPush(QStack* pQS, QDataType data)
{
	QueuePush(&(pQS->q1), data);
}
void QStackPop(QStack* pQS)
{
	Queue *pEmpty = &(pQS->q1);
	Queue *pNotEmpty = &(pQS->q2);
	if (QueueEmpty(pNotEmpty)) {
		pEmpty =&(pQS->q2);
		pNotEmpty = &(pQS->q1);
	}
	while (QueueSize(pNotEmpty) > 1) {
		QDataType q1 = QueueFront(pNotEmpty);
		QueuePush(pEmpty, q1);
		QueuePop(pNotEmpty);
	}
	QueuePop(pNotEmpty);
}
QDataType QStackTop(QStack* pQS)
{
	Queue *pEmpty = &(pQS->q1);
	Queue *pNotEmpty = &(pQS->q2);
	if (QueueEmpty(pNotEmpty)) {
		pEmpty = &(pQS->q2);
		pNotEmpty = &(pQS->q1);
	}
	while (QueueSize(pNotEmpty) > 1) {
		QDataType q1 = QueueFront(pNotEmpty);
		QueuePush(pEmpty, q1);
		QueuePop(pNotEmpty);
	}
	return QueueFront(pNotEmpty);
}

void TestQStack()
{
	/*
	QStack	*stack;	// 指针 vs 指针指向的空间	(野指针)
	QSInit(stack);
	*/

	QStack	stack;
	QStackInit(&stack);

	for (int i = 0; i < 5; i++) {
		QStackPush(&stack, i);
		printf("压入了 %d, Top = %d\n", i, QStackTop(&stack));
	}

	for (int i = 0; i < 3; i++) {
		QStackPop(&stack);
		printf("Top = %d\n", QStackTop(&stack));
	}

	for (int i = 0; i < 2; i++) {
		QStackPush(&stack, i + 10);
		printf("压入了 %d, Top = %d\n", i + 10, QStackTop(&stack));
	}
}