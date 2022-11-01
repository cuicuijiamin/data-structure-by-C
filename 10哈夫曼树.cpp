//用数组来实现哈夫曼树
#include"M.h"
typedef int TElementType;
typedef struct tree
{
	TElementType data;//权值
	int parent, lchild, rchild;//在数组中的下标
}HTNode,*HuffmanTree;
void select(HuffmanTree HT, int r, int & s1, int & s2)
{
	//从HT的[1,r]中去寻找第一小与第二小的，并赋值给s1,s2

	for (int i = 1; i <= r; ++i)
	{
		int tmp = i;
		if (HT[i].parent == 0)
		{
			if (HT[i].data < HT[s1].data)
			{
				swap(s1, s2);
				swap(s1, tmp);
			}
			else if (HT[i].data < HT[s2].data)
			{
				swap(s2, tmp);
			}
		}
	}
}
void createHuffmanTree(HuffmanTree & HT, int n)
{
	if (n <= 1)return;
	int m = 2 * n - 1;//有这么多个节点
	HT = new HTNode[m + 1];//下标从1开始，0不用
	for (int i = 1; i <= m; ++i)
	{
		HT[i].lchild = 0;
		HT[i].rchild = 0;
		HT[i].parent = 0;
	}
	HT[0].data = 10000000;
	for (int i = 1; i <= n; ++i)
	{
		cin >> HT[i].data;
	}
	for (int i = n + 1; i <= m; ++i)
	{
		int s1 = 0, s2 = 0;
		select(HT, i - 1, s1, s2);//找出s1与s2
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].parent = 0;
		HT[i].data = HT[s1].data + HT[s2].data;
	}
}
string createHuffmanCode(HuffmanTree HT, int i)
{
	//获取HT[i]的哈夫曼编码
	string res = "";
	while (HT[i].parent)//到达根节点则跳出循环
	{
		HTNode f = HT[HT[i].parent];
		if (f.lchild == i)
			res = "0" + res;
		else if (f.rchild == i)
			res = "1" + res;
		i = HT[i].parent;
	}
	return res;
}
int main()
{
	HuffmanTree HT;
	createHuffmanTree(HT, 4);//7 1 19 50
	for (int i = 1; i <= 4;++i)
		cout << createHuffmanCode(HT, i)<<endl;
	return 0;
}