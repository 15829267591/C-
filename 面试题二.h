#pragma once
#include "Stack.h"
typedef  struct QueueS {
	Stack stack1;
	Stack stack2;
}QueueS;

void QueueSInit(QueueS* pQS);				  
void QueueSPush(QueueS* pQS, StackDataType data);  
void QueueSPop(QueueS* pQS);
StackDataType QueueSFront(QueueS* pQS);
void TestQueueS();
