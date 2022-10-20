////串
//#include"M.h"
//void getNext(string s, int * next)//获取next数组
//{
//	next[0] = 0;
//	int j = 0;//前缀的末尾
//	int i = 1;//后缀的末尾
//	for (int i = 1; i <s.size(); ++i)
//	{
//		while (s[i] != s[j] && j > 0)
//		{
//			//此时表示前缀的末尾的值与后缀的末尾的值不相同
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
//				//比完了
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
//	return -1;//没找到
//}
//int main()
//{
//	string s = "aabaaf";
//	string t = "aabaabaaf";
//	int next[10] = { 0 };
//	getNext(s, next);
//	//打印next数组
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