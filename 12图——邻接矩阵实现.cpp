#include"M.h"
const int MAXNUM = 100;
const int INF = 0x3f3f3f3f;
typedef char VerTexType;
typedef int ArcType;

typedef struct
{
	VerTexType vexs[MAXNUM];//顶点表
	ArcType arcs[MAXNUM][MAXNUM];//邻接矩阵
	int vexnum, arcnum;
}AMGraph;

//获取某个点在顶点数组中的下标值
int LocateVex(AMGraph G, VerTexType num)
{
	for (int i = 0; i < G.vexnum; ++i)
	{
		if (G.vexs[i] == num)
			return i;
	}
	return -1;
}
void createUDN(AMGraph & G)
{
	cout << "请输入要创建的图的总顶点数与总边数：" << endl;
	cin >> G.vexnum >> G.arcnum;
	cout << "请输入各个顶点值:" << endl;
	for (int i = 0; i < G.vexnum; ++i)
	{
		cin >> G.vexs[i];
	}
	for (int i = 0; i < G.vexnum; ++i)
	{
		for (int j = 0; j < G.vexnum; ++j)
			G.arcs[i][j] = INF;
	}

	cout << "请输入构成每条边的两个顶点与权值:" << endl;
	for (int i = 0; i < G.arcnum; ++i)
	{
		VerTexType v1, v2;
		ArcType val;
		cin >> v1 >> v2 >> val;

		int t1 = LocateVex(G, v1);
		int t2 = LocateVex(G, v2);
		if (t1 == -1 || t2 == -1)
		{
			cout << "顶点输入错误，创建无向图失败" << endl;
		}
		G.arcs[t1][t2] = val;
		G.arcs[t2][t1] = val;//若是有向图就把这句注释掉
	}
}


//Prim最小生成树算法
struct closeedge
{
	VerTexType adjVex;//U上的那个顶点
	ArcType lowcost;//这个顶点引出的最小边上的权值  找点
}closeedge[MAXNUM];//closeedge[i]表示从adjvex到i的最短路径为lowcost
int Min(AMGraph G,struct closeedge * closeedge)
{
	int index = 0;//获取最小边的下标
	int mincost = INF;
	for (int i = 0; i < G.vexnum; ++i)
	{
		if (closeedge[i].lowcost != 0 && closeedge[i].lowcost < mincost)
		{
			index = i;
			mincost = closeedge[i].lowcost;
		}
	}
	return index;
}
void MiniSpanTree_Prim(AMGraph G, VerTexType u)//u是初始顶点——随便传
{
	int k = LocateVex(G, u);
	for (int i = 0; i < G.vexnum; ++i)
	{
		if (i != k)
			closeedge[i] = { u, G.arcs[k][i] };//将closeedge初始化为到u的边信息
	}
	closeedge[k].lowcost = 0;//k已经在u集合中，为0意味着不再考虑
	for (int i = 1; i < G.vexnum; ++i)
	{
		k = Min(G,closeedge);//获取到最小边closeedge[k]
		char u0 = closeedge[k].adjVex;
		char v0 = G.vexs[k];
		cout << u0 << "  " << v0 << endl;
		closeedge[k].lowcost = 0;//将k加入u中

		for (int j = 0; j < G.vexnum; ++j)//更新剩余的每组最小边信息  因为k从j有新边
		{
			if (G.arcs[k][j] < closeedge[j].lowcost)
				closeedge[j] = { G.vexs[k], G.arcs[k][j] };
		}
	}
}


//迪杰斯特拉算法
int s[MAXNUM];//s为顶点集合，在集合中用1来表示,不在集合中用0来表示
int d[MAXNUM];
int path[MAXNUM];//记录最短路径
void ShorttestPath_DIJ(AMGraph G, int v0)//v0为起点  求v0到其余顶点的最短路径
{
	int n = G.vexnum;//顶点数目
	for (int v = 0; v < n; ++v)
	{
		s[v] = false;
		d[v] = G.arcs[v0][v];//以v为终点的路径长度
		if (d[v] < INF) path[v] = v0;//在有路径的条件下，记录路径的v的前驱
		else path[v] = -1;
	}
	s[v0] = true;
	d[v0] = 0;//把起点放入s集合
	for (int i = 1; i < n; ++i)//每循环一次，将一个顶点放入集合s中，循环完毕后，所以节点都在s集合中了
	{
		int min = INF;
	    int v;
		for (int w = 0; w < n; ++w)//找路径最短的那条，记录终点为v
		{
			if (!s[w] && d[w] < min)//w不在集合中 选择当前的最短路径
			{
				v = w;
				min = d[w];
			}
		}
		s[v] = true;//将v放入集合中
		for (int w = 0; w < n; ++w)//集合更新以后d数组与path数组也要进行相应的更新
		{
			if (!s[w] && d[v] + G.arcs[v][w] < d[w])//大前提是对于不在集合当中的点
			{
				d[w] = d[v] + G.arcs[v][w];
				path[w] = v;
			}
		}
	}
	//输出
	for (int i = 0; i < n; ++i)
		cout << "从" << G.vexs[v0] << "到" << G.vexs[i] << "的最短路径为" << d[i] << endl;
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	AMGraph G;
	createUDN(G);
	cout << "最小生成树为：" << endl;
	MiniSpanTree_Prim(G, 'A');
	ShorttestPath_DIJ(G, 0);
}
