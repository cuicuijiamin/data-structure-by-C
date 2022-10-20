//队列结构——顺序队列
//循环队列：重复利用空间
//#include"M.h"
//typedef int ElementType;
//const int MAXSIZE = 100;//队列
//const int INF = 1000000;
//typedef struct 
//{
//	ElementType * base;
//	int h;//队头下标
//	int b;//队尾下标
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
//	if (Q.base == nullptr)printf("分配失败，请检查计算机内存\n");
//	Q.b = Q.h =0;//代表空
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
//	return false;//判空
//}
//bool queueFull(sqQueue & Q)
//{
//	if ((Q.b+1)%MAXSIZE==Q.h)
//		return true;//队列满了
//	return false;
//}
//int queueLength(sqQueue & Q)
//{
//	return (Q.b + MAXSIZE - Q.h) % MAXSIZE;
//}
//void push(sqQueue & Q,ElementType data)//入队
//{
//	if (queueFull(Q))
//	{
//		printf("已经满了，不准插入\n");
//		return;
//	}
//	Q.base[Q.b] = data;
//	Q.b = (Q.b + 1) % MAXSIZE;
//
//}
//void pop(sqQueue & Q)//出队
//{
//	if (queueEmpty(Q))
//	{
//		printf("队列空了，没有出队元素\n");
//		return;
//	}
//	Q.h = (Q.h + 1) % MAXSIZE;
//}
//ElementType getTop(sqQueue & Q)//获取队头元素
//{
//	if (queueEmpty(Q))
//	{
//		printf("抱歉没有队头元素可以获取\n");
//		return INF;//返回一个无效值
//	}
//	return Q.base[Q.h];
//}
//void queueTraverse(sqQueue & Q)
//{
//	if (queueEmpty(Q))
//	{
//		printf("队列当中没有元素\n");
//		return;
//	}
//	int temp = Q.h;
//	printf("================================\n");
//	printf("从队头开始依次为：\n");
//	while (temp != Q.b)
//	{
//		printf("%d---", Q.base[temp]);
//		temp = (temp + 1) % MAXSIZE;
//	}
//	printf("结束");
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
//	printf("目前的队列长度是：%d\n", queueLength(Q));
//
//	pop(Q);
//	queueTraverse(Q);
//	printf("队头元素是：%d", getTop(Q));
//
//	clearQueue(Q);
//	destoryQueue(Q);
//}
