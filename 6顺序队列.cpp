//���нṹ����˳�����
//ѭ�����У��ظ����ÿռ�
//#include"M.h"
//typedef int ElementType;
//const int MAXSIZE = 100;//����
//const int INF = 1000000;
//typedef struct 
//{
//	ElementType * base;
//	int h;//��ͷ�±�
//	int b;//��β�±�
//}sqQueue;
//
//void initQueue(sqQueue & Q);
//void clearQueue(sqQueue &Q);
//void destoryQueue(sqQueue & Q);
//bool queueEmpty(sqQueue & Q);
//bool queueFull(sqQueue & Q);
//int queueLength(sqQueue & Q);
//
//void initQueue(sqQueue & Q)
//{
//	Q.base = new ElementType[MAXSIZE];
//	if (Q.base == nullptr)printf("����ʧ�ܣ����������ڴ�\n");
//	Q.b = Q.h =0;//�����
//}
//void clearQueue(sqQueue &Q)
//{
//    Q.b = Q.h;
//}
//void destoryQueue(sqQueue & Q)
//{
//	delete[]Q.base;
//  Q.base=nullptr;
//	Q.b = Q.h=0;
//}
//bool queueEmpty(sqQueue & Q)
//{
//	if (Q.b == Q.h)
//		return true;
//	return false;//�п�
//}
//bool queueFull(sqQueue & Q)
//{
//	if ((Q.b+1)%MAXSIZE==Q.h)
//		return true;//��������
//	return false;
//}
//int queueLength(sqQueue & Q)
//{
//	return (Q.b + MAXSIZE - Q.h) % MAXSIZE;
//}
//void push(sqQueue & Q,ElementType data)//���
//{
//	if (queueFull(Q))
//	{
//		printf("�Ѿ����ˣ���׼����\n");
//		return;
//	}
//	Q.base[Q.b] = data;
//	Q.b = (Q.b + 1) % MAXSIZE;
//
//}
//void pop(sqQueue & Q)//����
//{
//	if (queueEmpty(Q))
//	{
//		printf("���п��ˣ�û�г���Ԫ��\n");
//		return;
//	}
//	Q.h = (Q.h + 1) % MAXSIZE;
//}
//ElementType getTop(sqQueue & Q)//��ȡ��ͷԪ��
//{
//	if (queueEmpty(Q))
//	{
//		printf("��Ǹû�ж�ͷԪ�ؿ��Ի�ȡ\n");
//		return INF;//����һ����Чֵ
//	}
//	return Q.base[Q.h];
//}
//void queueTraverse(sqQueue & Q)
//{
//	if (queueEmpty(Q))
//	{
//		printf("���е���û��Ԫ��\n");
//		return;
//	}
//	int temp = Q.h;
//	printf("================================\n");
//	printf("�Ӷ�ͷ��ʼ����Ϊ��\n");
//	while (temp != Q.b)
//	{
//		printf("%d---", Q.base[temp]);
//		temp = (temp + 1) % MAXSIZE;
//	}
//	printf("����");
//	printf("\n================================\n");
//}
//int main()
//{
//	sqQueue Q;
//	initQueue(Q);
//	for (int i = 0; i < 50; ++i)
//	{
//		push(Q, i * 10+1);
//	}
//	queueTraverse(Q);
//	printf("Ŀǰ�Ķ��г����ǣ�%d\n", queueLength(Q));
//
//	pop(Q);
//	queueTraverse(Q);
//	printf("��ͷԪ���ǣ�%d", getTop(Q));
//
//	clearQueue(Q);
//	destoryQueue(Q);
//}
