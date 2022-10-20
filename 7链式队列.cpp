////���нṹ������ʽ�ṹ
//#include"M.h"
//const int INF = 1000000;
//typedef int ElementType;
//typedef struct Node
//{
//	ElementType data;
//	struct Node * next;
//}QNode;
//typedef struct
//{
//	QNode * head;
//	QNode * back;//����βָ��
//}LinkQueue;
//
//void initQueue(LinkQueue &Q);
//bool queueEmpty(LinkQueue & Q);
//void destoryQueue(LinkQueue & Q);
//void clearQueue(LinkQueue & Q);
//int queueLength(LinkQueue & Q);
//ElementType getTop(LinkQueue & Q);
//void push(LinkQueue & Q, ElementType e);
//void pop(LinkQueue & Q);
//void queueTraverse(LinkQueue & Q);
//
//void initQueue(LinkQueue &Q)
//{
//	Q.head = Q.back = new QNode;
//	if (Q.head == nullptr)
//	{
//		printf("�ڴ����ʧ�ܣ�\n");
//	}
//	Q.head->next = nullptr;
//}
//bool queueEmpty(LinkQueue & Q)
//{
//	if (Q.head->next == nullptr)
//		return true;
//	return false;
//}
//void destoryQueue(LinkQueue & Q)
//{
//	clearQueue(Q);
//	delete Q.head;
//	Q.head = Q.back = nullptr;
//	printf("�����������\n");
//}
//void clearQueue(LinkQueue & Q)
//{
//	if (queueEmpty(Q))
//	{
//		printf("���в���Ҫ�����������ǿյ�\n");
//		return;
//	}
//	QNode * p = Q.head->next;//��Ԫ�ڵ�
//	QNode * q;
//	while (p)
//	{
//		q = p->next;
//		delete p;
//		p = q;
//	}
//	Q.back = Q.head;
//	Q.head->next = nullptr;
//}
//int queueLength(LinkQueue & Q)
//{
//	int len = 0;
//	QNode * p = Q.head;
//	while (p->next)
//	{
//		len++;
//		p = p->next;
//	}
//	return len;
//}
//ElementType getTop(LinkQueue & Q)
//{
//	if (queueEmpty(Q))
//		return INF;//������Чֵ
//	else
//		return Q.head->next->data;
//}
//void push(LinkQueue & Q, ElementType e)
//{
//	//���
//	if (Q.back == nullptr)
//	{
//		printf("����û�г�ʼ��,���������\n");
//		return;
//	}
//	QNode * temp = new QNode;
//	temp->data = e;
//	Q.back->next = temp;
//	temp->next = nullptr;
//	Q.back = temp;
//}
//void pop(LinkQueue & Q)
//{
//	if (queueEmpty(Q))
//	{
//		printf("����ʧ��\n");
//		return;
//	}
//	QNode * temp = Q.head->next;//Ҫɾ��
//	Q.head->next = temp->next;
//	delete temp;
//}
//void queueTraverse(LinkQueue & Q)
//{
//
//	printf("=================================\n");
//	if (queueEmpty(Q))
//		printf("����Ϊ�գ�û��Ԫ�أ�\n");
//	else
//	{
//		printf("�Ӷ�ͷ��ʼ����Ϊ��\n");
//		QNode * temp = Q.head->next;//ͷ�ڵ�
//		while (temp)
//		{
//			printf("%d---", temp->data);
//			temp = temp->next;
//		}
//		printf("����\n");
//	}
//	printf("=================================\n");
//
//}
//
//int main()
//{
//	LinkQueue Q;
//	initQueue(Q);//��ʼ��
//	queueTraverse(Q);
//	for (int i = 0; i < 5; ++i)
//	{
//		push(Q, i * 10 + 1);
//	}
//	pop(Q);
//	printf("���ڶ��еĳ���Ϊ��%d\n", queueLength(Q));
//	queueTraverse(Q);
//	printf("��ͷԪ��Ϊ��%d\n", getTop(Q));
//	clearQueue(Q);
//	destoryQueue(Q);
//	return 0;
//}


//��������
//#include<iostream>
//using namespace std;
//typedef struct Node
//{
//	int data;
//	struct Node * next;
//} QNode, *QueueList;
//
//void init(QueueList & Q)
//{
//	Q = new QNode;//ͷ�ڵ�
//	Q->next = NULL;
//}
//
//void push(QueueList & Q, int data)
//{
//	QNode * q = Q;
//	QNode * temp = new QNode;
//	temp->data = data;
//	if (!Q->next)
//	{
//		//�����һ���ڵ�
//		q->next = temp;
//		temp->next = temp;
//	}
//	else
//	{
//		temp->next = q->next->next;
//		q->next->next = temp;
//		q->next = temp;
//	}
//}
//
//void pop(QueueList & Q)
//{
//	QNode * temp = Q->next->next;//Ҫɾ���Ľڵ�
//	if (temp == Q->next)//Ҫɾ������β�ڵ�
//	{
//		delete temp;
//		Q->next = NULL;
//		return;
//	}
//	Q->next->next = temp->next;
//	delete temp;
//}
//
//void show(QueueList & Q)
//{
//	if (Q->next == NULL)
//	{
//		printf("�����Ѿ�Ϊ�գ�\n");
//		return;
//	}
//	QNode * h = Q->next->next;//��¼��ͷ
//	QNode * p = Q->next->next;//��ͷ
//	do
//	{
//		printf("%d ", p->data);
//		p = p->next;
//	} while (p!= h);
//	printf("\n");
//}
//int main()
//{
//	QueueList Q;
//	init(Q);//��ʼ������
//	int n;
//	cin >> n;
//	int data;
//	while (n--)
//	{
//		cin >> data;
//		push(Q, data);
//	}
//	int m;
//	cin >> m;
//	while (m--)
//	{
//		pop(Q);
//	}
//	show(Q);
//	return 0;
//}