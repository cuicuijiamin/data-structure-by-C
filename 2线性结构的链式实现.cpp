//逻辑结构：线性结构
//存储结构：链式存储——单链表
#include"M.h"
typedef struct Data
{
	int age;
	string name;
	Data(int x=0,string y="")
	{
		age = x;
		name = y;
	}
	struct Data& operator =(const struct Data &other)
	{
		age = other.age;
		name = other.name;
		return *this;
	}
	friend ostream& operator<<(ostream& output,const struct Data D)//注意：重载输入输出必须使用友元
	{
		output << "age=" << D.age << "  name=" << D.name << endl;
		return output;
	}
}ElementType;

typedef struct Node
{
	ElementType data;
	struct Node * next;

}LNode,*LinkList;

void initList(LinkList& L);//
void destoryList(LinkList& L);
void clearList(LinkList& L);
int getListLen(const LinkList& L);//
LNode * getListElem(const LinkList& L,int i);//
int insertElem(LinkList& L,int i,ElementType insertNum);//
int deleteElem(LinkList& L, int i);//
int alterElem(LinkList& L, int i,ElementType alterNum);//
void show(const LinkList& L);//

void initList(LinkList& L)
{
	LNode* h = new LNode;//开辟头节点内存
	h->next = nullptr;//头节点指向为空
	L = h;//L就是头指针——代表的是整个链表
}

void destoryList(LinkList& L)
{
   clearList(L);
   delete L;//删除头节点
   L = nullptr;//把头节点置空
}

void clearList(LinkList& L)
{
	LNode* p = L->next;//首元节点
	LNode* q;
	while (p)
	{
		q = p->next;
		delete p;
		p = q;
	}
	L->next = nullptr;
}

int getListLen(const LinkList& L)
{
	LNode* p = L->next;//指向的是首元节点
	int len=0;
	while (p)
	{
		len++;
		p = p->next;
	}
	return len;//长度是不包含头节点的
}

LNode * getListElem(const LinkList& L,int i)
{
	//要获取第i个位子的节点 i=0为头节点
	LNode* p = L;//指向的是头节点
	int j = 0;
	while (p&&j<i)
	{
		p = p->next;
		j++;
	}
	//跳出循环：找完了或者找到了
	if (!p || i < 0)
	{
		cout << "没有找到i位置的元素,请您重新确定要查找的位置" << endl;
	}
	return p;
}

int insertElem(LinkList& L, int i, ElementType insertNum)
{
	//在i前面插入元素
	LNode* p = new LNode;
	p->data = insertNum;//要插入的节点

	LNode* temp = getListElem(L,i-1);

	p->next = temp->next;
	temp->next = p;
	return TRUE;
}

int alterElem(LinkList& L, int i,ElementType alterNum)
{
	LNode * p=getListElem(L, i);
	p->data = alterNum;
	return TRUE;
}

int deleteElem(LinkList& L, int i)
{
	LNode* p = getListElem(L, i - 1);
	LNode* temp = p->next;
	p->next = p->next->next;
	delete temp;
	return TRUE;
}

void show(const LinkList& L)
{
	printf("===========================\n");
	LNode* p = L->next;
	while (p)
	{
		cout << p->data;
		p = p->next;
	}
	printf("===========================\n\n");
}


int main()
{
	//测试
	LinkList L;//单链表表名  同时也是头指针
	initList(L);
	
	insertElem(L, 1, ElementType(10, "sj"));
	insertElem(L, 1, ElementType(12, "sakd"));
	insertElem(L, 1, ElementType(134, "dcr"));
	insertElem(L, 1, ElementType(34, "ewwc"));

	show(L);
	
	deleteElem(L, 2);
	show(L);

	alterElem(L, 1, ElementType(666,"sawwwwwwwwwww"));
	show(L);

	printf("%d\n", getListLen(L));
	
	show(L);

	destoryList(L);
	return 0;
}

// 链表的连接例题
// #include<iostream>
// using namespace std;
// typedef struct Node
// {
// 	int data;
// 	struct Node * next;
// } LNode, *LinkList;

// void init(LinkList & L, int len)
// {
// 	L = new LNode;
// 	L->next = NULL;
// 	LNode * p = L;
// 	int data;

// 	for (int i = 0; i<len; ++i)
// 	{
// 		cin >> data;
// 		LNode * q = new LNode;
// 		q->next = NULL;
// 		q->data = data;
// 		p->next = q;
// 		p = q;
// 	}
// }

// void show(LinkList & L)
// {
// 	LNode * p = L->next;
// 	while (p)
// 	{
// 		printf("%d ", p->data);
// 		p = p->next;
// 	}
// 	printf("\n");
// }

// void insertLNode(LinkList &C, LNode * p)//q节点后面插入p
// {
// 	p->next = C->next;
// 	C->next = p;
// }

// void link(LinkList & A, LinkList & B, LinkList & C)
// {
// 	LNode * ta = A->next;//A的首元
// 	LNode * tb = B->next;
// 	while (ta && tb)//有一方为空则跳出
// 	{
// 		if (ta->data<tb->data)
// 		{
// 			LNode * temp = ta->next;
// 			//头插ta
// 			insertLNode(C, ta);
// 			ta = temp;
// 		}
// 		else if (tb->data<=ta->data)
// 		{
// 			LNode * temp = tb->next;
// 			insertLNode(C, tb);
// 			tb = temp;
// 		}
// 	}
// 	while (ta)
// 	{
// 		LNode * temp = ta->next;
// 		insertLNode(C, ta);
// 		ta = temp;
// 	}
// 	while (tb)
// 	{
// 		LNode * temp = tb->next;
// 		insertLNode(C, tb);
// 		tb = temp;
// 	}
// }
// void destory(LinkList & A, LinkList & B, LinkList & C)
// {
// 	//删除A B的头节点
// 	delete A;
// 	delete B;

// 	//删除C链表
// 	LNode * p = C;
// 	LNode * q;
// 	while (p)
// 	{
// 		q = p->next;
// 		delete p;
// 		p = q;
// 	}
// }
// int main()
// {
// 	int a, b;
// 	cin >> a >> b;
// 	LinkList A;
// 	LinkList B;
// 	init(A, a);
// 	init(B, b);

// 	LinkList C;
// 	init(C, 0);
// 	link(A, B, C);
// 	show(C);

// 	//释放开辟的内存
// 	destory(A, B, C);
// 	return 0;
// }
