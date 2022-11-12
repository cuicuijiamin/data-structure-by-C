//#include"M.h"
//const int MAXNUM = 100;
//const int INF = 0x3f3f3f3f;
//typedef char VerTexType;
//typedef int ArcType;
//
//typedef struct
//{
//	VerTexType vexs[MAXNUM];//�����
//	ArcType arcs[MAXNUM][MAXNUM];//�ڽӾ���
//	int vexnum, arcnum;
//}AMGraph;
//
////��ȡĳ�����ڶ��������е��±�ֵ
//int LocateVex(AMGraph G, VerTexType num)
//{
//	for (int i = 0; i < G.vexnum; ++i)
//	{
//		if (G.vexs[i] == num)
//			return i;
//	}
//	return -1;
//}
//void createUDN(AMGraph & G)
//{
//	cout << "������Ҫ������ͼ���ܶ��������ܱ�����" << endl;
//	cin >> G.vexnum >> G.arcnum;
//	cout << "�������������ֵ:" << endl;
//	for (int i = 0; i < G.vexnum; ++i)
//	{
//		cin >> G.vexs[i];
//	}
//	for (int i = 0; i < G.vexnum; ++i)
//	{
//		for (int j = 0; j < G.vexnum; ++j)
//			G.arcs[i][j] = INF;
//	}
//
//	cout << "�����빹��ÿ���ߵ�����������Ȩֵ:" << endl;
//	for (int i = 0; i < G.arcnum; ++i)
//	{
//		VerTexType v1, v2;
//		ArcType val;
//		cin >> v1 >> v2 >> val;
//
//		int t1 = LocateVex(G, v1);
//		int t2 = LocateVex(G, v2);
//		if (t1 == -1 || t2 == -1)
//		{
//			cout << "����������󣬴�������ͼʧ��" << endl;
//		}
//		G.arcs[t1][t2] = val;
//		G.arcs[t2][t1] = val;//��������ͼ�Ͱ����ע�͵�
//	}
//}
//
//
////Prim��С�������㷨
//struct closeedge
//{
//	VerTexType adjVex;//U�ϵ��Ǹ�����
//	ArcType lowcost;//���������������С���ϵ�Ȩֵ  �ҵ�
//}closeedge[MAXNUM];//closeedge[i]��ʾ��adjvex��i�����·��Ϊlowcost
//int Min(AMGraph G,struct closeedge * closeedge)
//{
//	int index = 0;//��ȡ��С�ߵ��±�
//	int mincost = INF;
//	for (int i = 0; i < G.vexnum; ++i)
//	{
//		if (closeedge[i].lowcost != 0 && closeedge[i].lowcost < mincost)
//		{
//			index = i;
//			mincost = closeedge[i].lowcost;
//		}
//	}
//	return index;
//}
//void MiniSpanTree_Prim(AMGraph G, VerTexType u)//u�ǳ�ʼ���㡪����㴫
//{
//	int k = LocateVex(G, u);
//	for (int i = 0; i < G.vexnum; ++i)
//	{
//		if (i != k)
//			closeedge[i] = { u, G.arcs[k][i] };//��closeedge��ʼ��Ϊ��u�ı���Ϣ
//	}
//	closeedge[k].lowcost = 0;//k�Ѿ���u�����У�Ϊ0��ζ�Ų��ٿ���
//	for (int i = 1; i < G.vexnum; ++i)
//	{
//		k = Min(G,closeedge);//��ȡ����С��closeedge[k]
//		char u0 = closeedge[k].adjVex;
//		char v0 = G.vexs[k];
//		cout << u0 << "  " << v0 << endl;
//		closeedge[k].lowcost = 0;//��k����u��
//
//		for (int j = 0; j < G.vexnum; ++j)//����ʣ���ÿ����С����Ϣ  ��Ϊk��j���±�
//		{
//			if (G.arcs[k][j] < closeedge[j].lowcost)
//				closeedge[j] = { G.vexs[k], G.arcs[k][j] };
//		}
//	}
//}
//
//
////�Ͻ�˹�����㷨
//int s[MAXNUM];//sΪ���㼯�ϣ��ڼ�������1����ʾ,���ڼ�������0����ʾ
//int d[MAXNUM];
//int path[MAXNUM];//��¼���·��
//void ShorttestPath_DIJ(AMGraph G, int v0)//v0Ϊ���  ��v0�����ඥ������·��
//{
//	int n = G.vexnum;//������Ŀ
//	for (int v = 0; v < n; ++v)
//	{
//		s[v] = false;
//		d[v] = G.arcs[v0][v];//��vΪ�յ��·������
//		if (d[v] < INF) path[v] = v0;//����·���������£���¼·����v��ǰ��
//		else path[v] = -1;
//	}
//	s[v0] = true;
//	d[v0] = 0;//��������s����
//	for (int i = 1; i < n; ++i)//ÿѭ��һ�Σ���һ��������뼯��s�У�ѭ����Ϻ����Խڵ㶼��s��������
//	{
//		int min = INF;
//	    int v;
//		for (int w = 0; w < n; ++w)//��·����̵���������¼�յ�Ϊv
//		{
//			if (!s[w] && d[w] < min)//w���ڼ����� ѡ��ǰ�����·��
//			{
//				v = w;
//				min = d[w];
//			}
//		}
//		s[v] = true;//��v���뼯����
//		for (int w = 0; w < n; ++w)//���ϸ����Ժ�d������path����ҲҪ������Ӧ�ĸ���
//		{
//			if (!s[w] && d[v] + G.arcs[v][w] < d[w])//��ǰ���Ƕ��ڲ��ڼ��ϵ��еĵ�
//			{
//				d[w] = d[v] + G.arcs[v][w];
//				path[w] = v;
//			}
//		}
//	}
//	//���
//	for (int i = 0; i < n; ++i)
//		cout << "��" << G.vexs[v0] << "��" << G.vexs[i] << "�����·��Ϊ" << d[i] << endl;
//}
//
//
//int main()
//{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
//	AMGraph G;
//	createUDN(G);
//	cout << "��С������Ϊ��" << endl;
//	MiniSpanTree_Prim(G, 'A');
//	ShorttestPath_DIJ(G, 0);
//}