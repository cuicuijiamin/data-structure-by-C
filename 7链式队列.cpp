//队列结构——链式结构
#include"M.h"
const int INF = 1000000;
typedef int ElementType;
typedef struct Node
{
	ElementType data;
	struct Node * next;
}QNode;
typedef struct
{
	QNode * head;
	QNode * back;//保存尾指针
}LinkQueue;

void initQueue(LinkQueue &Q);
bool queueEmpty(LinkQueue & Q);
void destoryQueue(LinkQueue & Q);
void clearQueue(LinkQueue & Q);
int queueLength(LinkQueue & Q);
ElementType getTop(LinkQueue & Q);
void push(LinkQueue & Q, ElementType e);
void pop(LinkQueue & Q);
void queueTraverse(LinkQueue & Q);

void initQueue(LinkQueue &Q)
{
	Q.head = Q.back = new QNode;
	if (Q.head == nullptr)
	{
		printf("内存分配失败！\n");
	}
	Q.head->next = nullptr;
}
bool queueEmpty(LinkQueue & Q)
{
	if (Q.head->next == nullptr)
		return true;
	return false;
}
void destoryQueue(LinkQueue & Q)
{
	clearQueue(Q);
	delete Q.head;
	Q.head = Q.back = nullptr;
	printf("队列完成销毁\n");
}
void clearQueue(LinkQueue & Q)
{
	if (queueEmpty(Q))
	{
		printf("队列不需要清理，本来就是空的\n");
		return;
	}
	QNode * p = Q.head->next;//首元节点
	QNode * q;
	while (p)
	{
		q = p->next;
		delete p;
		p = q;
	}
	Q.back = Q.head;
	Q.head->next = nullptr;
}
int queueLength(LinkQueue & Q)
{
	int len = 0;
	QNode * p = Q.head;
	while (p->next)
	{
		len++;
		p = p->next;
	}
	return len;
}
ElementType getTop(LinkQueue & Q)
{
	if (queueEmpty(Q))
		return INF;//返回无效值
	else
		return Q.head->next->data;
}
void push(LinkQueue & Q, ElementType e)
{
	//入队
	if (Q.back == nullptr)
	{
		printf("队列没有初始化,不允许插入\n");
		return;
	}
	QNode * temp = new QNode;
	temp->data = e;
	Q.back->next = temp;
	temp->next = nullptr;
	Q.back = temp;
}
void pop(LinkQueue & Q)
{
	if (queueEmpty(Q))
	{
		printf("弹出失败\n");
		return;
	}
	QNode * temp = Q.head->next;//要删的
	Q.head->next = temp->next;
	delete temp;
}
void queueTraverse(LinkQueue & Q)
{

	printf("=================================\n");
	if (queueEmpty(Q))
		printf("队列为空，没有元素！\n");
	else
	{
		printf("从队头开始依次为：\n");
		QNode * temp = Q.head->next;//头节点
		while (temp)
		{
			printf("%d---", temp->data);
			temp = temp->next;
		}
		printf("结束\n");
	}
	printf("=================================\n");

}

int main()
{
	LinkQueue Q;
	initQueue(Q);//初始化
	queueTraverse(Q);
	for (int i = 0; i < 5; ++i)
	{
		push(Q, i * 10 + 1);
	}
	pop(Q);
	printf("现在队列的长度为：%d\n", queueLength(Q));
	queueTraverse(Q);
	printf("队头元素为：%d\n", getTop(Q));
	clearQueue(Q);
	destoryQueue(Q);
	return 0;
}


// 链队例题
// #include<iostream>
// using namespace std;
// typedef struct Node
// {
// 	int data;
// 	struct Node * next;
// } QNode, *QueueList;

// void init(QueueList & Q)
// {
// 	Q = new QNode;//头节点
// 	Q->next = NULL;
// }

// void push(QueueList & Q, int data)
// {
// 	QNode * q = Q;
// 	QNode * temp = new QNode;
// 	temp->data = data;
// 	if (!Q->next)
// 	{
// 		//插入第一个节点
// 		q->next = temp;
// 		temp->next = temp;
// 	}
// 	else
// 	{
// 		temp->next = q->next->next;
// 		q->next->next = temp;
// 		q->next = temp;
// 	}
// }

// void pop(QueueList & Q)
// {
// 	QNode * temp = Q->next->next;//要删除的节点
// 	if (temp == Q->next)//要删除的是尾节点
// 	{
// 		delete temp;
// 		Q->next = NULL;
// 		return;
// 	}
// 	Q->next->next = temp->next;
// 	delete temp;
// }

// void show(QueueList & Q)
// {
// 	if (Q->next == NULL)
// 	{
// 		printf("队列已经为空！\n");
// 		return;
// 	}
// 	QNode * h = Q->next->next;//记录队头
// 	QNode * p = Q->next->next;//队头
// 	do
// 	{
// 		printf("%d ", p->data);
// 		p = p->next;
// 	} while (p!= h);
// 	printf("\n");
// }
// int main()
// {
// 	QueueList Q;
// 	init(Q);//初始化操作
// 	int n;
// 	cin >> n;
// 	int data;
// 	while (n--)
// 	{
// 		cin >> data;
// 		push(Q, data);
// 	}
// 	int m;
// 	cin >> m;
// 	while (m--)
// 	{
// 		pop(Q);
// 	}
// 	show(Q);
// 	return 0;
// }
