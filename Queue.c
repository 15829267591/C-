#include "Queue.h"
#include<assert.h>

//��ʼ��
void QueueInit(Queue* pQueue)
{
	pQueue->front = pQueue->rear = NULL;
}

//����һ���ڵ�
static QNode* CreateNode(QDataType data)
{
	QNode * newNode = (QNode *)malloc(sizeof(QNode));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

//����
void QueueDestroy(Queue* pQueue)
{
	QNode* cur;
	QNode* next;
	for (cur = pQueue->front; cur != NULL; cur = next) {
		next = cur->next;
		free(cur);
	}
	pQueue->front = pQueue->rear = NULL;
}

//����(β��)
void QueuePush(Queue* pQueue, QDataType data)
{
	QNode* newNode = CreateNode(data);
	if (pQueue->front == NULL) {
		pQueue->front = pQueue->rear = newNode;
		return;
	}
	pQueue->rear->next = newNode;
	pQueue->rear = newNode;
}

//ɾ��(ͷɾ)
void QueuePop(Queue* pQueue)
{
	assert(pQueue);
	assert(pQueue->front != NULL);
	QNode* del;
	del = pQueue->front;
	pQueue->front = pQueue->front->next;
	free(del);
}
//�鿴������Ԫ�ظ���
int QueueSize(Queue* pQueue)
{
	int count = 0;
	QNode* cur;
	for (cur = pQueue->front; cur != NULL; cur = cur->next) {
		count++;
	}
	return count;
}
//�鿴����Ԫ��
QDataType QueueFront(Queue* pQueue)
{
	assert(pQueue != NULL);			// ��ַ��Ҫ��Ч
	assert(pQueue->front != NULL);	// ����Ϊ�գ���֧��
	return pQueue->front->data;
}
//�鿴�����Ƿ�Ϊ��
int QueueEmpty(Queue* pQueue)
{
	return pQueue->front == NULL;
}