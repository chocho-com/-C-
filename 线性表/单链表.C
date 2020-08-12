#include<stdio.h>
#include<stdlib.h>

#define OVERFLOW -10000
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;
//-----单链表的存储结构-----
typedef struct LNode
{
	ElemType data;         //数据域
	struct LNode *next;    //指针域
}LNode, *LinkList;

//-----单链表的基本操作-----
Status InitList(LinkList *L);                       //初始化
Status GetElem(LinkList L, int i, ElemType *e);     //取值
LNode *LocateElem(LinkList L, ElemType e);          //查找
Status ListInsert(LinkList *L, int i, ElemType e);  //插入
Status ListDelete(LinkList *L, int i);              //删除
void print(LinkList L);                             //打印
void CreateList_H(LinkList *L, int n);              //头插法创建单链表
void CreateList_T(LinkList *L, int n);              //尾插法创建单链表

void main()
{
	LinkList L;
	ElemType e;

	//初始化测试
	InitList(&L);

	//创建测试
	printf("\n请输入5个数:\n");
	CreateList_T(&L, 5);
	print(L);

	//插入测试
	ListInsert(&L, 2, 100);
	print(L);

	//取值测试
	GetElem(L, 3, &e);
	printf("\n位序为%d的值为%d\n", 3, e);

	//查找测试
	printf("\n值为5的元素地址为@%d\n", LocateElem(L, 5));

	//删除测试
	ListDelete(&L, 2);
	printf("\n删除位序为2的元素:");
	print(L);
}

Status InitList(LinkList *L)
{
	//1.分配头结点空间
	(*L) = (LinkList)malloc(sizeof(LNode));
	if((*L) == NULL)
	{
		printf("\nError:内存分配失败！\n");
		exit(OVERFLOW);
	}

	//2.置空指针域
	(*L)->next = NULL;

	return OK;
}

//-----时间复杂度O(n)
Status GetElem(LinkList L, int i, ElemType *e)
{
	LinkList p = L->next;
	int j = 0;

	//1.遍历表L，计数器++
	while(p != NULL && j < i-1)
	{
		p = p->next;
		j++;
	}

	//2.检查i值合法性
	if(p == NULL || j >= i)
	{
		return ERROR;
	}

	//3.取值
	*e = p->data;

	return OK;
}

//-----时间复杂度O(n)
LNode *LocateElem(LinkList L, ElemType e)
{
	LinkList p = L->next;

	//1.遍历查找元素
	while(p != NULL && p->data != e)
	{
		p = p->next;
	}

	//2.没有找到元素则地址为NULL
	return p;
}

//-----时间复杂度O(n)
Status ListInsert(LinkList *L, int i, ElemType e)
{
	int j = 1;
	LinkList p = (*L)->next;
	LinkList node = NULL;

	//1.遍历表L，计数器++
	while(p != NULL && j < i-1)
	{
		p = p->next;
		j++;
	}

	//2.检查i值合法性
	if(p == NULL || j >= i)
	{
		return ERROR;
	}

	//3.创建新结点
	node  = (LinkList)malloc(sizeof(LNode));
	if(node == NULL)
	{
		printf("\nError:内存分配失败！\n");
		exit(OVERFLOW);
	}
	node->data = e;

	//4.插入元素
	node->next = p->next;
	p->next = node;

	return OK;
}

//-----时间复杂度O(n)
Status ListDelete(LinkList *L, int i)
{
	int j = 0;
	//这里保留的是需要删除结点的前驱
	LinkList p = (*L);
	LinkList q = NULL;

	//1.遍历表L，计数器++
	while(p->next != NULL && j < i-1)
	{
		p = p->next;
		j++;
	}

	//2.检查i值合法性
	if(p->next == NULL || j >= i)
	{
		return ERROR;
	}

	//3.删除元素
	q = p->next;
	p->next = q->next;

	//4.释放空间
	free(q);

	return OK;
}

void print(LinkList L)
{
	LinkList p = L;
	//空表
	if(p->next == NULL)
	{
		printf("\n空表\n");
	}
	else
	{
		printf("\n");
		while(p->next != NULL)
		{
			p = p->next;
			printf("->%d", p->data);
		}
		printf("\n");
	}
}

//-----时间复杂度O(n)
void CreateList_H(LinkList *L, int n)
{
	LinkList node = NULL;
	int i;
	
	for(i = 0; i < n; i++)
	{
		//1.创建新结点
		node = (LinkList)malloc(sizeof(LNode));
		//2.头插
		scanf("%d", &node->data);
		node->next = (*L)->next;
		(*L)->next = node;
	}
}

//-----时间复杂度O(n)
void CreateList_T(LinkList *L, int n)
{
	LinkList node = NULL;
	LinkList p = (*L);
	int i;
	
	for(i = 0; i < n; i++)
	{
		//1.创建新结点
		node = (LinkList)malloc(sizeof(LNode));
		//2.尾插
		scanf("%d", &node->data);
		node->next = NULL;
		p->next = node;
		p = node;
	}
}
