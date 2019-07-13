#include "Queue.h"
#include<assert.h>

//初始化
void QueueInit(Queue* pQueue)
{
	pQueue->front = pQueue->rear = NULL;
}

//创建一个节点
static QNode* CreateNode(QDataType data)
{
	QNode * newNode = (QNode *)malloc(sizeof(QNode));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

//销毁
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

//插入(尾插)
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

//删除(头删)
void QueuePop(Queue* pQueue)
{
	assert(pQueue);
	assert(pQueue->front != NULL);
	QNode* del;
	del = pQueue->front;
	pQueue->front = pQueue->front->next;
	free(del);
}
//查看队列中元素个数
int QueueSize(Queue* pQueue)
{
	int count = 0;
	QNode* cur;
	for (cur = pQueue->front; cur != NULL; cur = cur->next) {
		count++;
	}
	return count;
}
//查看队首元素
QDataType QueueFront(Queue* pQueue)
{
	assert(pQueue != NULL);			// 地址需要有效
	assert(pQueue->front != NULL);	// 队列为空，不支持
	return pQueue->front->data;
}
//查看队列是否为空
int QueueEmpty(Queue* pQueue)
{
	return pQueue->front == NULL;
}