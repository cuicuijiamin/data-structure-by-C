#include"M.h"
const int MAXNUM = 100;
typedef char VerTexType;
typedef int ArcType;
typedef struct ArcNode
{
	int adjvex;
	struct ArcNode * next;
	ArcType info;//Ȩֵ
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
void createUDG(ALGraph &G)//��������ͼG
{
	cout << "������Ҫ������ͼ���ܶ��������ܱ�����" << endl;
	cin >> G.vexnum >> G.arcnum;

	cout << "�������������ֵ:" << endl;
	for (int i = 0; i < G.vexnum; ++i)
	{
		cin >> G.v[i].data;//����
		G.v[i].firstarc = nullptr;
	}
	cout << "�����빹��ÿ���ߵ���������" << endl;
	for (int i = 0; i < G.arcnum; ++i)
	{
		VerTexType v1, v2;
		cin >> v1 >> v2;
		int t1 = LocateVex(G, v1);
		int t2 = LocateVex(G, v2);
		if (t1 == -1 || t2 == -1)
		{
			cout << "��������Ķ����Ƿ���ȷ,��������ͼʧ��" << endl;
			return;
		}

		ArcNode *newArc = new ArcNode;//����ռ�
		//newArc->info = val;
		newArc->adjvex = t2;
		newArc->next = G.v[t1].firstarc;
		G.v[t1].firstarc = newArc;
	}
}


void FindInDegree(ALGraph G, int indegree[])
{
	//��ȡÿ����������
	for (int i = 0; i < G.vexnum; ++i)//�ȱ������ж���
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
//��������
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
	int m = 0;//������������
	cout << "�����������У�" << endl;
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
			if (indegree[k] == 0)st.push(k);//���
			p = p->next;
		}
	}
	if (m < G.vexnum) printf("����������ø�ͼ�л�·\n");
	else printf("����������ø�ͼ�޻�·\n");
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