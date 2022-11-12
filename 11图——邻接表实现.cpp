#include"M.h"
const int MAXNUM = 100;
typedef char VerTexType;
typedef int ArcType;
typedef struct ArcNode
{
	int adjvex;
	struct ArcNode * next;
	ArcType info;//权值
}ArcNode;
typedef struct VNode
{
	VerTexType data;
	ArcNode * firstarc;
}VNode;
typedef struct Graph
{
	VNode v[MAXNUM];
	int vexnum, arcnum;
}ALGraph;


int LocateVex(ALGraph G, VerTexType num)
{
	for (int i = 0; i < G.vexnum; ++i)
	{
		if (G.v[i].data == num)
			return i;
	}
	return -1;
}
void createUDG(ALGraph &G)//创建有向图G
{
	cout << "请输入要创建的图的总顶点数与总边数：" << endl;
	cin >> G.vexnum >> G.arcnum;

	cout << "请输入各个顶点值:" << endl;
	for (int i = 0; i < G.vexnum; ++i)
	{
		cin >> G.v[i].data;//输入
		G.v[i].firstarc = nullptr;
	}
	cout << "请输入构成每条边的两个顶点" << endl;
	for (int i = 0; i < G.arcnum; ++i)
	{
		VerTexType v1, v2;
		cin >> v1 >> v2;
		int t1 = LocateVex(G, v1);
		int t2 = LocateVex(G, v2);
		if (t1 == -1 || t2 == -1)
		{
			cout << "请检查输入的顶点是否正确,创建无向图失败" << endl;
			return;
		}

		ArcNode *newArc = new ArcNode;//分配空间
		//newArc->info = val;
		newArc->adjvex = t2;
		newArc->next = G.v[t1].firstarc;
		G.v[t1].firstarc = newArc;
	}
}


void FindInDegree(ALGraph G, int indegree[])
{
	//获取每个顶点得入度
	for (int i = 0; i < G.vexnum; ++i)//先便利所有顶点
	{
		ArcNode * p = G.v[i].firstarc;
		while (p != nullptr)
		{
			int k = p->adjvex;
			indegree[k]++;
			p = p->next;
		}
	}
}
//拓扑排序
int topo[MAXNUM];
void TopologicalSort(ALGraph G, int topo[])
{
	int indegree[MAXNUM];
	memset(indegree, 0, sizeof(indegree));
	FindInDegree(G, indegree);
	stack<int>st;
	for (int i = 0; i < G.vexnum; ++i)
	{
		if (!indegree[i])st.push(i);
	}
	int m = 0;//对输出顶点计数
	cout << "拓扑排序序列：" << endl;
	while (!st.empty())
	{
		int t = st.top();
		cout << G.v[t].data << "\t";
		st.pop();
		++m;
		ArcNode * p = G.v[t].firstarc;
		while (p != nullptr)
		{
			int k = p->adjvex;
			--indegree[k];
			if (indegree[k] == 0)st.push(k);//入队
			p = p->next;
		}
	}
	if (m < G.vexnum) printf("由拓扑排序得该图有回路\n");
	else printf("由拓扑排序得该图无回路\n");
}
int main()
{
	//freopen("in2.txt", "r", stdin);
	//freopen("out2.txt", "w", stdout);
	ALGraph G;
	createUDG(G);
	TopologicalSort(G, topo);
	return 0;
}