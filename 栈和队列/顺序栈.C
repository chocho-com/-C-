#include<stdio.h>
#include<stdlib.h>

#define OVERFLOW -10000
#define MAXSIZE 100
#define OK 1
#define ERROR 0
typedef int SElemType;
typedef int Status;
//-----顺序栈的存储结构-----
typedef struct
{
	SElemType *base;         //栈底指针
	SElemType *top;          //栈顶元素
	int stackSize;           //栈可用容量
}SqStack;

//-----顺序栈的基本操作-----
Status InitStack(SqStack *S);           //初始化
Status Push(SqStack *S, SElemType e);   //入栈
Status Pop(SqStack *S, SElemType *e);   //出栈
SElemType GetTop(SqStack S);            //取栈顶元素
void print(SqStack S);                  //打印

void main()
{
	SqStack S;
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

	//出栈测试
	Pop(&S, &e);
	printf("\n出栈%d:", e);
	print(S);

	//取栈顶元素
	printf("\n栈顶元素为%d\n", GetTop(S));
}

Status InitStack(SqStack *S)
{
	//1.分配数组空间
	(*S).base = (SElemType*)malloc(sizeof(SElemType)*MAXSIZE);
	if((*S).base == NULL)
	{
		printf("\nError:内存分配失败！\n");
		exit(OVERFLOW);
	}

	//2.初始化指针和最大容量
	(*S).top = (*S).base;
	(*S).stackSize = MAXSIZE;

	return OK;
}

Status Push(SqStack *S, SElemType e)
{
	//1.判断栈满
	if((*S).top - (*S).base == (*S).stackSize)
	{
		printf("\n栈满\n");
		return ERROR;
	}

	//2.压栈
	*((*S).top) = e;
	(*S).top++;

	return OK;
}

Status Pop(SqStack *S, SElemType *e)
{
	//1.判断栈空
	if((*S).base == (*S).top)
	{
		printf("\n栈空\n");
		return ERROR;
	}

	//2.出栈
	--(*S).top;
	*e = *((*S).top);

	return OK;
}

SElemType GetTop(SqStack S)
{
	//1.取栈顶
	if(S.base != S.top)
	{
		S.top--;
		return *(S.top);
	}
	else
	{
		return OVERFLOW;
	}
}

void print(SqStack S)
{
	int i;

	if(S.base == S.top)
	{
		printf("\n栈空\n");
	}
	else
	{
		printf("\nbase->[");
		for(i = 0; i < S.top-S.base; i++)
		{
			printf(" %d", *(S.base+i));
		}
		printf(" ]<-top\n");
	}
}