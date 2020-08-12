#include<stdio.h>
#include<stdlib.h>

#define OVERFLOW -10000
#define OK 1
#define ERROR 0
typedef int SElemType;
typedef int Status;
//-----链式栈的存储结构-----
typedef struct StackNode
{
	SElemType data;
	struct StackNode *next;
}StackNode, *LinkStack;

//-----链式栈的基本操作-----
Status InitStack(LinkStack *S);         //初始化
Status Push(LinkStack *S, SElemType e); //入栈
Status Pop(LinkStack *S, SElemType *e); //出栈
SElemType GetTop(LinkStack S);             //取栈顶元素
void print(LinkStack S);               //打印

void main()
{
	LinkStack S;
	int i;
	SElemType e;

	//初始化测试
	InitStack(&S);

	//入栈测试
	for(i = 0; i < 10; i++)
	{
		Push(&S, i);
	}
	print(S);

	//出栈
	Pop(&S, &e);
	printf("\n出栈元素为%d:", e);
	print(S);

	//取栈顶测试
	printf("\n栈顶元素为%d\n", GetTop(S));
}

Status InitStack(LinkStack *S)
{
	//1.创建空栈
	(*S) = NULL;
	return OK;
}

Status Push(LinkStack *S, SElemType e)
{
	LinkStack node = NULL;

	//1.创建新结点
	node  = (LinkStack)malloc(sizeof(SElemType));
	if(node == NULL)
	{
		printf("\n内存分配失败！\n");
		exit(OVERFLOW);
	}
	node->data = e;

	//入栈
	node->next = *S;
	*S = node;

	return OK;
}

Status Pop(LinkStack *S, SElemType *e)
{

	//1.判断栈空
	if(*S == NULL)
	{
		printf("\n栈空\n");
		return ERROR;
	}

	//2.出栈
	*e = (*S)->data;
	(*S) = (*S)->next;

	return OK;
}

SElemType GetTop(LinkStack S)
{
	if(S != NULL)
	{
		return S->data;
	}
	else
	{
		printf("\n栈空\n");
		return OVERFLOW;
	}
}

void print(LinkStack S)
{
	LinkStack p = S;

	if(S == NULL)
	{
		printf("\n栈空\n");
	}
	else
	{
		printf("\nS->[");
		while(p != NULL)
		{
			printf("->%d", p->data);
			p = p->next;
		}
		printf("]\n");
	}
}