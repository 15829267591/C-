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

void QueueInit(Queue* pQueue);					//初始化
void QueueDestroy(Queue* pQueue);				//销毁
static QNode* CreateNode(QDataType data);		//创建一个节点
void QueuePush(Queue* pQueue, QDataType data);	//插入
void QueuePop(Queue* pQueue);					//删除
int QueueSize(Queue* pQueue);					//查看队列中元素个数
QDataType QueueFront(Queue* pQueue);					//查看队首元素
int QueueEmpty(Queue* pQueue);					//查看队列是否为空
