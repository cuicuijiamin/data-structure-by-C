//��������ʵ�ֹ�������
#include"M.h"
typedef int TElementType;
typedef struct tree
{
	TElementType data;//Ȩֵ
	int parent, lchild, rchild;//�������е��±�
}HTNode,*HuffmanTree;
void select(HuffmanTree HT, int r, int & s1, int & s2)
{
	//��HT��[1,r]��ȥѰ�ҵ�һС��ڶ�С�ģ�����ֵ��s1,s2

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
	int m = 2 * n - 1;//����ô����ڵ�
	HT = new HTNode[m + 1];//�±��1��ʼ��0����
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
		select(HT, i - 1, s1, s2);//�ҳ�s1��s2
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
	//��ȡHT[i]�Ĺ���������
	string res = "";
	while (HT[i].parent)//������ڵ�������ѭ��
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