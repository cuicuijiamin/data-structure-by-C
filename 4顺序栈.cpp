////ջ�ṹ����˳��ջ
//#include"M.h"
//#define INF 10000000
//#define INIT_SIZE 100
//typedef int ElementType;
//typedef struct
//{
//	ElementType* base;//ջ��
//	ElementType* top;//ջ��
//	int stackSize;//ջ�Ŀռ�
//}SqStack;
//void initStack(SqStack& S)
//{
//	S.base = new ElementType[INIT_SIZE];//
//	if (!S.base)cout << "�ڴ����ʧ�ܣ����������ڴ�" << endl;
//	S.top = S.base;//ָ����ͬ�������ǿ�
//}
//void destoryStack(SqStack& S)
//{
//	delete []S.base;
//	S.base = nullptr;//�ÿ�
//}
//void clearStack(SqStack& S)
//{
//	S.top = S.base;
//}
//bool stackEmpty(SqStack& S)
//{
//	if (S.top == S.base)
//		return true;
//	else
//		return false;
//}
//int stackLength(SqStack& S)
//{
//	return S.top - S.base;
//}
//int getTop(SqStack& S)
//{
//	if (!stackEmpty(S))
//		return *(S.top-1);
//	else
//		return INF;
//}
//void expand(SqStack& S)
//{
//	int size = S.stackSize + S.stackSize / 2 > 1 ? S.stackSize : 1;
//	ElementType* temp = new ElementType[size];//�µĴ�ռ����
//	int len = S.top - S.base;
//	for (int i = 0; i < len; ++i)
//	{
//		temp[i] = S.base[i];
//	}
//	delete []S.base;//ɾ��ԭ����С�ڴ�
//	S.base = temp;
//	S.top = S.base + len;
//}
//void push(SqStack& S,int insertNum)
//{
//	if (S.top - S.base == S.stackSize)//����
//	{
//		expand(S);
//	}
//	//����
//	*S.top = insertNum;
//	S.top++;
//}
//void pop(SqStack& S)
//{
//	//����
//	if (stackEmpty(S))
//	{
//		cout << "ջ�Ѿ����ˣ�û�취�ٽ���ɾ��" << endl;
//		return;
//	}
//	S.top--;
//}
//void stackTraverse(SqStack& S)
//{
//	printf("===========================\n");
//	ElementType* temp = S.base;
//	for (; temp != S.top; ++temp)
//	{
//		cout << *temp << "--";
//	}
//	printf("\n==========================\n");
//}
//int main()
//{
//	SqStack S;
//	initStack(S);
//	for (int i = 0; i < 10; ++i)
//	{
//		push(S, i);//����
//	}
//	stackTraverse(S);
//	pop(S);//ɾ��
//	stackTraverse(S);
//}

//�Թ������ʵ��
//#include"M.h"
//typedef struct Pos
//{
//	struct Pos(int x,int y):x(x),y(y){}
//	int x;
//	int y;
//}pos;
//const int MAXR = 5, MAXC = 5;
//int arr[5][5] =
//{
//	1,0,1,1,1,
//	1,0,0,0,0,
//	1,0,1,0,1,
//	1,0,1,0,0,
//	1,0,0,0,0
//};
//
//int ans = 0;
//int vis[10][10];
//void dfs(pos b,pos e)
//{
//	if (b.x < 0 || b.x >= MAXR || b.y < 0 || b.y >= MAXC || arr[b.x][b.y] == 1 )//Խ���ײǽ
//	{
//		printf("��(%d %d)�߲�ͨ\n", b.x, b.y);
//		return;
//	}
//	if (b.x == e.x && b.y == e.y)
//	{
//		ans++; 
//		printf("��(%d %d)���յ�\n", b.x, b.y);
//		return;
//	}
//	printf("��(%d %d)\n", b.x, b.y);
//	if (arr[b.x - 1][b.y] == 0 && !vis[b.x - 1][b.y])
//	{
//		vis[b.x-1][b.y] = 1;
//		dfs(pos(b.x - 1, b.y), e);//��
//		vis[b.x - 1][b.y] = 0;
//	}
//	if (arr[b.x][b.y+1] == 0 && !vis[b.x][b.y+1])
//	{
//		vis[b.x][b.y+1] = 1;
//		dfs(pos(b.x, b.y+1), e);//��
//		vis[b.x][b.y+1] = 0;
//	}
//	if (arr[b.x + 1][b.y] == 0 && !vis[b.x + 1][b.y])
//	{
//		vis[b.x + 1][b.y] = 1;
//		dfs(pos(b.x + 1, b.y), e);//��
//		vis[b.x + 1][b.y] = 0;
//	}
//	if (arr[b.x][b.y-1] == 0 && !vis[b.x][b.y - 1])
//	{
//		vis[b.x][b.y - 1] = 1;
//		dfs(pos(b.x, b.y-1), e);//��
//		vis[b.x][b.y - 1] = 0;
//	}
//	return;
//}
//int main()
//{
//	pos begin(0, 1);//�Թ������
//	pos end(1, 4);//�Թ����յ�
//	vis[0][1] = 1;
//	dfs(begin,end);
//	printf("%d", ans);
//
//	return 0;
//}