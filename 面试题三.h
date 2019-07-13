#pragma once
#include "Queue.h"
//��������ʵ��һ��ջ
typedef  struct QStack {
	Queue q1;
	Queue q2;
}QStack;

void QStackInit(QStack* pQS);
void QStackDestroy(QStack* pQS);
void QStackPush(QStack* pQS, QDataType data);
void QStackPop(QStack* pQS);
QDataType QStackTop(QStack* pQS);
void TestQStack();