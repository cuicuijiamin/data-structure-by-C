////��
//#include"M.h"
//void getNext(string s, int * next)//��ȡnext����
//{
//	next[0] = 0;
//	int j = 0;//ǰ׺��ĩβ
//	int i = 1;//��׺��ĩβ
//	for (int i = 1; i <s.size(); ++i)
//	{
//		while (s[i] != s[j] && j > 0)
//		{
//			//��ʱ��ʾǰ׺��ĩβ��ֵ���׺��ĩβ��ֵ����ͬ
//			j = next[j - 1];
//		}
//		if (s[i] == s[j])
//		{
//			j++;
//
//		}
//		next[i] = j;
//	}
//}
//
//int kmp(string t, string s, int * next)
//{
//	int j = 0;
//	for (int i = 0; i < t.size();)
//	{
//		if (s[j] == t[i])
//		{
//			if (j == s.size() - 1)
//			{
//				//������
//				return (int)(i - s.size() + 1);
//			}
//			j++;
//			i++;
//		}
//		else
//		{
//			j = next[j - 1];
//		}
//	}
//	return -1;//û�ҵ�
//}
//int main()
//{
//	string s = "aabaaf";
//	string t = "aabaabaaf";
//	int next[10] = { 0 };
//	getNext(s, next);
//	//��ӡnext����
//	for (int i = 0; i < s.size(); ++i)
//	{
//		printf("%d\t", next[i]);
//	}
//	printf("\n");
//
//	int ans = kmp(t, s, next);
//	printf("%d\n", ans);
//	return 0;
//}