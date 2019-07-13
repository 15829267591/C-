#pragma once

typedef int QDataType;

typedef struct QNode {
	QDataType data;
	struct QNode* next;
}QNode;

typedef struct Queue {
	QNode* front;
	QNode* rear;
}Queue;

void QueueInit(Queue* pQueue);					//��ʼ��
void QueueDestroy(Queue* pQueue);				//����
static QNode* CreateNode(QDataType data);		//����һ���ڵ�
void QueuePush(Queue* pQueue, QDataType data);	//����
void QueuePop(Queue* pQueue);					//ɾ��
int QueueSize(Queue* pQueue);					//�鿴������Ԫ�ظ���
QDataType QueueFront(Queue* pQueue);					//�鿴����Ԫ��
int QueueEmpty(Queue* pQueue);					//�鿴�����Ƿ�Ϊ��
