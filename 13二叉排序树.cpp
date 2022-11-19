//#include"M.h"
//typedef int ElementType;
//typedef struct BSTNode
//{
//	ElementType data;
//	struct BSTNode * lchild, *rchild;
//}BSTNode,*BSTree;
//BSTNode * findBST(BSTNode* T, ElementType num)
//{
//	if (T == nullptr || T->data == num)
//		return T;
//	else if (T->data < num)
//		return findBST(T->rchild, num);
//	else if (T->data>num)
//		return findBST(T->lchild, num);
//}
//void insertBST(BSTree & T, ElementType num)
//{
//	if (!T)
//	{
//		BSTNode * s = new BSTNode;
//		s->data = num;
//		s->lchild = s->rchild = nullptr;
//		T = s;
//	}
//	else if (T->data < num)
//		insertBST(T->rchild, num);
//	else if (T->data>num)
//		insertBST(T->lchild, num);
//}
//void deleteBST(BSTree & T, ElementType num)//É¾³ý
//{
//
//}
//void createBSTree(BSTree & T)
//{
//	T = nullptr;//³õÊ¼»¯
//	ElementType num;
//	while (cin >> num)
//	{
//		insertBST(T, num);
//	}
//}
//int main()
//{
//	BSTree T;
//	createBSTree(T);
//}