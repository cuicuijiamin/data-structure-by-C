#include"M.h"
typedef char TElementType;
typedef struct BiTNode
{
	TElementType data;
	struct BiTNode * lchild, *rchild;
}BiTNode,*BiTree;

//二叉树的遍历
void preOrderTree(BiTree T)
{
	if (T == nullptr)return;
	cout << T->data;
	preOrderTree(T->lchild);
	preOrderTree(T->rchild);
}
void inOrderTree(BiTree T)
{
	if (T == nullptr)return;
	inOrderTree(T->lchild);
	cout << T->data;
	inOrderTree(T->rchild);
}
void postOrderTree(BiTree T)
{
	if (T == nullptr)return;
	postOrderTree(T->lchild);
	postOrderTree(T->rchild);
	cout << T->data;
}
void levelPrint(BiTree T)//层次遍历
{
	queue<BiTNode *> q;
	q.push(T);//根节点入队
	while (!q.empty())
	{
		BiTNode * temp = q.front();
		cout << temp->data;
		q.pop();
		if (temp->lchild)
			q.push(temp->lchild);
		if (temp->rchild)
			q.push(temp->rchild);
	}
}

//二叉树的创建
void createBiTree(BiTree & T)
{
	char ch;
	cin >> ch;
	if (ch == '#')
	{ 
		T = nullptr; 
		return;
	}
	//以先序的形式去创建
	T = new BiTNode;
	T->data = ch;
	createBiTree(T->lchild);
	createBiTree(T->rchild);
	
}
//二叉树的复制
void copyBiTree(BiTree & T, BiTree & newT)
{
	if (T == nullptr)
	{
		newT = nullptr;
		return;
	}
	newT = new BiTNode;
	newT->data = T->data;
	copyBiTree(T->lchild, newT->lchild);
	copyBiTree(T->rchild, newT->rchild);
}
//二叉树的深度
int getTreeDepth(BiTree T)
{
	if (T == nullptr)return 0;
	int d1 = getTreeDepth(T->lchild);
	int d2 = getTreeDepth(T->rchild);
	return max(d1, d2) + 1;
}
//二叉树节点总数
int getTreeNode(BiTree T)
{
	if (T == nullptr) return 0;
	int n1=getTreeNode(T->lchild);
	int n2=getTreeNode(T->rchild);
	return n1 + n2 + 1;
}
//二叉树叶子节点总数
int getTreeLeaveNode(BiTree T)
{
	if (T == nullptr) return 0;
	if (T->lchild == nullptr&&T->rchild == nullptr) return 1;
	int n1 = getTreeLeaveNode(T->lchild);
	int n2 = getTreeLeaveNode(T->rchild);
	return n1 + n2;
}
int main()
{
	BiTree T;
	createBiTree(T);//先序遍历序列：GEA#B##C##FD###

	cout << "二叉树的深度为:" << getTreeDepth(T)<<endl;//4
	cout << "二叉树节点总数为:" << getTreeNode(T)<<endl;//7
	cout << "二叉树叶子节点总数:" << getTreeLeaveNode(T)<<endl;//3
	//打印
	preOrderTree(T);
	putchar('\n');
	inOrderTree(T);
	putchar('\n');
	BiTree T2;
	copyBiTree(T, T2);
	postOrderTree(T2);
	putchar('\n');
	levelPrint(T);
	putchar('\n');
	return  0;
}

