//逻辑结构：线性结构
//存储结构：线性存储
//数据之间有线性关系
#include"M.h"
typedef int ElementType;
struct sqList
{
	ElementType* pList;
	int length;
	int maxSize;
}ml;


void initList(struct sqList& list);
void destroyList(struct sqList& list);
void clearList(struct sqList& list);
ElementType getElem(struct sqList& list, int index);
int findElem(struct sqList& list, ElementType elem);
void deleteElem(struct sqList& list, ElementType deleteNum);
void alter(struct sqList& list, int index, ElementType alterNum);
void expand(struct sqList& list, int size);
void insertElem(struct sqList& list, int index, ElementType insertNum);
void show(struct sqList& list);

void initList(struct sqList &list)
{
	list.length = 0;
	list.maxSize = 0;
	list.pList = nullptr;
}


void destroyList(struct sqList &list)
{
	delete []list.pList;
}

void clearList(struct sqList& list)
{
	list.length = 0;
}

ElementType getElem(struct sqList& list, int index)
{
	return list.pList[index];
}

int findElem(struct sqList& list,ElementType elem)
{
	//返回首次出现elem的位子---不存在则返回-1
	int left = 0;
	int right = list.length-1;
	while (left < right)
	{
		int mid = left + (right - left) / 2;
		if (list.pList[mid] >= elem)//一定在mid左边
			right = mid;
		else
			left = mid + 1;
	}
	if (list.pList[left] == elem) return left;
	else return  -1;
}

void deleteElem(struct sqList& list, ElementType deleteNum)
{
	int temp = findElem(list,deleteNum);//找到
	for(int i=temp+1;i<list.length;++i)
	{
		list.pList[i - 1] = list.pList[i];
	}
	list.length--;
}

void alter(struct sqList& list,int index, ElementType alterNum)
{
	list.pList[index] = alterNum;
}

void expand(struct sqList& list,int size)
{
	while (list.maxSize < size)
	{
		list.maxSize += (list.maxSize / 2) > 1 ? (list.maxSize / 2) : 1;
	}
	//容量改变——重新分配内存
	ElementType* h = new ElementType[list.maxSize];
	for (int i = 0; i < list.length; ++i)
	{
		h[i] = list.pList[i];//放进大空间中
	}
	delete []list.pList;
	list.pList = h;
}

void insertElem(struct sqList& list,int index, ElementType insertNum)
{
	if (list.length +1>list.maxSize)expand(list,list.length+1);
	for (int i = list.length-1; i >= index; --i)
	{
		list.pList[i + 1] = list.pList[i];
	}
	list.pList[index] = insertNum;
	list.length++;
}

void show(struct sqList& list)
{
	printf("length=%d\n", list.length);
	for (int i = 0; i < list.length; ++i)
		printf("pList[%d]=%d\n", i, list.pList[i]);
}





int main()
{
	initList(ml);
	for (int i = 0; i < 10; ++i)
	{
		insertElem(ml, i,i * 2);
	}
	show(ml);
	printf("=================================");
	alter(ml, 5, 666);
	show(ml);
	printf("=================================");
	deleteElem(ml, 4);
	show(ml);
	printf("=================================");
	int i = findElem(ml, 0);
	printf("i=%d\n", i);

	clearList(ml);
	destroyList(ml);
	return 0;
}
