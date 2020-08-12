#include<stdio.h>
#include<stdlib.h>

#define OVERFLOW -10000
#define MAXSIZE 100
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;
//-----顺序表的存储结构-----
typedef struct
{
	ElemType *elem;         //基地址
	int length;             //元素个数
}SqList;

//-----顺序表的基本操作-----
Status InitList(SqList *L);                       //初始化
Status GetElem(SqList L, int i, ElemType *e);     //取值
int LocateElem(SqList L, ElemType e);             //查找
Status ListInsert(SqList *L, int i, ElemType e);  //插入
Status ListDelete(SqList *L, int i);              //删除
void print(SqList L);                             //打印

void main()
{
	SqList L;
	int i;
	ElemType e;

	//初始化测试
	InitList(&L);

	//插入测试
	for(i = 0; i < 10; i++)
	{
		ListInsert(&L, i+1, i);
	}
	print(L);

	//取值测试
	GetElem(L, 3, &e);
	printf("\n位序为%d的值为%d\n", 3, e);

	//查找测试
	printf("\n值为5的元素位序为%d\n", LocateElem(L, 5));

	//删除测试
	ListDelete(&L, 2);
	printf("\n删除位序为2的元素:");
	print(L);
}

Status InitList(SqList *L)
{
	//1.分配数组空间
	(*L).elem = (ElemType *)malloc(sizeof(ElemType)*MAXSIZE);
	if((*L).elem == NULL)
	{
		printf("\nError:内存分配失败！\n");
		exit(OVERFLOW);
	}

	//2.初始化元素个数为0
	(*L).length = 0;

	return OK;
}

//-----时间复杂度O(1)
Status GetElem(SqList L, int i, ElemType *e)
{
	//1.检查i的合法性
	if(i < 1 || i > L.length)
	{
		printf("\nError:i值不合法！i=%d\n", i);
		return ERROR;
	}

	//2.取值
	*e = L.elem[i-1];

	return OK;
}

//-----平均查找长度ASL=(n+1)/2
//-----时间复杂度O(n)
int LocateElem(SqList L, ElemType e)
{
	int i;

	//1.遍历查找元素
	for(i = 0; i < L.length; i++)
	{
		if(L.elem[i] == e)
		{
			return i+1;
		}
	}

	//2.没有找到元素则位序为0
	return 0;
}

//-----时间复杂度O(n)
Status ListInsert(SqList *L, int i, ElemType e)
{
	int j;

	//1.检查i值的合法性
	if(i < 1 || i > (*L).length+1)
	{
		printf("\nError:i值不合法！i=%d\n", i);
		return ERROR;	
	}

	//2.检查表满
	if((*L).length == MAXSIZE)
	{
		printf("\nError:表满！\n");
		return ERROR;
	}

	//3.移动元素
	for(j = (*L).length-1; j >= i-1; j--)
	{
		(*L).elem[j+1] = (*L).elem[j];
	}

	//4.插入元素
	(*L).elem[i-1] = e;

	//5.元素个数+1
	(*L).length++;

	return OK;
}

//-----时间复杂度O(n)
Status ListDelete(SqList *L, int i)
{
	int j;

	//1.检查i值的合法性
	if(i < 1 || i > (*L).length)
	{
		printf("\nError:i值不合法！i=%d\n", i);
		return ERROR;
	}

	//2.移动元素
	for(j = i; j <= (*L).length-1; j++)
	{
		(*L).elem[j-1] = (*L).elem[j];
	}

	//3.元素个数-1
	(*L).length--;

	return OK;
}

void print(SqList L)
{
	int i;

	//空表
	if(L.length == 0)
	{
		printf("\n空表\n");
	}
	else
	{
		printf("\n");
		for(i = 0; i < L.length; i++)
		{
			printf(" %d", L.elem[i]);
		}
		printf("\n");
	}
}