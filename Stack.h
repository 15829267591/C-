#pragma once

#define MAX_SIZE 100
typedef char StackDataType;
typedef struct Stack {
	StackDataType array[MAX_SIZE];
	int top;   //��ʾ��ǰ����
}Stack;

// ��ʼ��/����
// ����ֻ�ܴ�ջ����/ɾ��ֻ��ɾ��ջ����/�飨ֻ�ܲ鿴ջ��Ԫ�أ�
// ���� / �Ƿ�� / �Ƿ���
// �� -> ˳����β��
// ɾ -> ˳����βɾ

void StackInit(Stack* pStack);
void StackDestroy(Stack* pStack);
void StackPush(Stack* pStack, StackDataType data);
void StackPop(Stack* pStack);
StackDataType getTop(Stack* pStack);
int getSize(Stack* pStack);
int StackIsEmpty(Stack* pStack);
int StackIsFull(Stack* pStack);