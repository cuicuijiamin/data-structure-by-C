////栈结构——顺序栈
//#include"M.h"
//#define INF 10000000
//#define INIT_SIZE 100
//typedef int ElementType;
//typedef struct
//{
//	ElementType* base;//栈底
//	ElementType* top;//栈底
//	int stackSize;//栈的空间
//}SqStack;
//void initStack(SqStack& S)
//{
//	S.base = new ElementType[INIT_SIZE];//
//	if (!S.base)cout << "内存分配失败，请检查计算机内存" << endl;
//	S.top = S.base;//指向相同，代表是空
//}
//void destoryStack(SqStack& S)
//{
//	delete []S.base;
//	S.base = nullptr;//置空
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
//	ElementType* temp = new ElementType[size];//新的大空间分配
//	int len = S.top - S.base;
//	for (int i = 0; i < len; ++i)
//	{
//		temp[i] = S.base[i];
//	}
//	delete []S.base;//删除原来的小内存
//	S.base = temp;
//	S.top = S.base + len;
//}
//void push(SqStack& S,int insertNum)
//{
//	if (S.top - S.base == S.stackSize)//满了
//	{
//		expand(S);
//	}
//	//插入
//	*S.top = insertNum;
//	S.top++;
//}
//void pop(SqStack& S)
//{
//	//弹出
//	if (stackEmpty(S))
//	{
//		cout << "栈已经空了，没办法再进行删除" << endl;
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
//		push(S, i);//插入
//	}
//	stackTraverse(S);
//	pop(S);//删除
//	stackTraverse(S);
//}

//迷宫问题的实现
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
//	if (b.x < 0 || b.x >= MAXR || b.y < 0 || b.y >= MAXC || arr[b.x][b.y] == 1 )//越界或撞墙
//	{
//		printf("走(%d %d)走不通\n", b.x, b.y);
//		return;
//	}
//	if (b.x == e.x && b.y == e.y)
//	{
//		ans++; 
//		printf("走(%d %d)到终点\n", b.x, b.y);
//		return;
//	}
//	printf("走(%d %d)\n", b.x, b.y);
//	if (arr[b.x - 1][b.y] == 0 && !vis[b.x - 1][b.y])
//	{
//		vis[b.x-1][b.y] = 1;
//		dfs(pos(b.x - 1, b.y), e);//上
//		vis[b.x - 1][b.y] = 0;
//	}
//	if (arr[b.x][b.y+1] == 0 && !vis[b.x][b.y+1])
//	{
//		vis[b.x][b.y+1] = 1;
//		dfs(pos(b.x, b.y+1), e);//右
//		vis[b.x][b.y+1] = 0;
//	}
//	if (arr[b.x + 1][b.y] == 0 && !vis[b.x + 1][b.y])
//	{
//		vis[b.x + 1][b.y] = 1;
//		dfs(pos(b.x + 1, b.y), e);//下
//		vis[b.x + 1][b.y] = 0;
//	}
//	if (arr[b.x][b.y-1] == 0 && !vis[b.x][b.y - 1])
//	{
//		vis[b.x][b.y - 1] = 1;
//		dfs(pos(b.x, b.y-1), e);//左
//		vis[b.x][b.y - 1] = 0;
//	}
//	return;
//}
//int main()
//{
//	pos begin(0, 1);//迷宫的起点
//	pos end(1, 4);//迷宫的终点
//	vis[0][1] = 1;
//	dfs(begin,end);
//	printf("%d", ans);
//
//	return 0;
//}