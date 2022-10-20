////栈结构——链栈
//#include"M.h"
//typedef int ElementType;
//typedef struct Node
//{
//	ElementType data;
//	struct Node * next;//指针域
//}*StackList,StackNode;
//
//void initStack(StackList &S);
//void destoryStack(StackList &S);
//void clearStack(StackList & S);
//bool stackEmpty(StackList &S);
//void push(StackList &S, ElementType data);
//void pop(StackList &S);
//ElementType getTop(StackList & S);
//void stackTraverse(StackList &S);
//
//void initStack(StackList &S)
//{
//	S = new StackNode;
//	S->next = nullptr;//指针指向空——空栈
//}
//void destoryStack(StackList &S)
//{
//	StackNode *p = S;//头节点
//	StackNode * q;
//	while (p)
//	{
//		q = p->next;
//		delete p;
//		p = q;
//	}
//}
//void clearStack(StackList & S)
//{
//
//	StackNode * p = S->next;
//	if (p == nullptr)return;
//	StackNode * q;
//	while (p)
//	{
//		q = p->next;
//		delete p;
//		p = q;
//	}
//	S->next = nullptr;
//}
//bool stackEmpty(StackList &S)
//{
//	if (S->next == nullptr)
//		return true;
//	return false;
//}
//
//void push(StackList &S,ElementType data)//入栈
//{
//	StackNode * temp = new StackNode;
//	temp->data = data;
//	temp->next = S->next;
//	S->next = temp;
//}
//void pop(StackList &S)//出栈
//{
//	if (!stackEmpty(S))
//	{
//		StackNode * temp = S->next;
//		S->next = temp->next;
//		delete temp;
//	}
//	else
//	{
//		return;
//	}
//}
//ElementType getTop(StackList & S)
//{
//	if (!stackEmpty(S))
//		return S->next->data;
//	else
//		return -100;//意为无效值
//}
//void stackTraverse(StackList &S)
//{
//	printf("===========================\n");
//	printf("上处为栈顶，下处为栈底\n");
//	StackNode * temp = S->next;
//	while (temp)
//	{
//		printf("%d\n", temp->data);
//		temp = temp->next;
//	}
//	printf("===========================\n");
//}
//
//int main()
//{
//	StackList S;
//	initStack(S);
//	printf("%d\n", getTop(S));
//	for (int i = 0; i < 5; ++i)
//	{
//		push(S, i * 10);
//	}
//	stackTraverse(S);
//	printf("%d\n", getTop(S));
//	pop(S);
//	stackTraverse(S);
//	clearStack(S);
//	destoryStack(S);
//	return 0;
//}