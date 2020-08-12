#include<stdio.h>
#include<stdlib.h>

#define OVERFLOW -10000
#define MAXSIZE 100
#define OK 1
#define ERROR 0
typedef int Status;
typedef int QElemType;
//-----队列的顺序存储结构-----
typedef struct 
{
	QElemType *base;
	int front;             //头指针
	int rear;              //尾指针
}SqQueue;

//-----基本操作-----
Status InitQueue(SqQueue *Q);             //初始化
int QueueLength(SqQueue Q);               //元素个数
Status EnQueue(SqQueue *Q, QElemType e);  //入队
Status DeQueue(SqQueue *Q, QElemType *e); //出队
QElemType GetHead(SqQueue Q);             //获取队头元素
void print(SqQueue Q);                    //打印

void main()
{
	SqQueue Q;
	int i;
	QElemType e;

	//初始化测试
	InitQueue(&Q);

	//入队测试
	for(i = 0; i < 10; i++)
	{
		EnQueue(&Q, i);
	}
	print(Q);

	//元素个数测试
	printf("\n队列共有%d个元素\n", QueueLength(Q));

	//出队测试
	DeQueue(&Q, &e);
	printf("\n出队元素%d:", e);
	print(Q);

	//获取队头元素测试
	printf("\n队头元素为%d\n", GetHead(Q));
}

Status InitQueue(SqQueue *Q)
{
	//1.分配数组空间
	(*Q).base = (QElemType *)malloc(sizeof(QElemType)*MAXSIZE);
	if((*Q).base == NULL)
	{
		printf("\n分配内存失败!\n");
		exit(OVERFLOW);
	}

	//2.初始化指针
	(*Q).front = 0;
	(*Q).rear = 0;

	return OK;
}

int QueueLength(SqQueue Q)
{
	return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

Status EnQueue(SqQueue *Q, QElemType e)
{
	//1.检查队满
	if(((*Q).rear+1)%MAXSIZE == (*Q).front)
	{
		printf("\n队满\n");
		return ERROR;
	}

	//2.入队
	(*Q).base[(*Q).rear] = e;
	(*Q).rear = ((*Q).rear+1)%MAXSIZE;

	return OK;
}

Status DeQueue(SqQueue *Q, QElemType *e)
{
	//1.检查队空
	if((*Q).front == (*Q).rear)
	{
		printf("\n队空\n");
		return ERROR;
	}

	//2.出队
	*e = (*Q).base[(*Q).front];
	(*Q).front = ((*Q).front+1)%MAXSIZE;

	return OK;
}

QElemType GetHead(SqQueue Q)
{
	if(Q.front != Q.rear)
	{
		return Q.base[Q.front];
	}
	else
	{
		printf("\n队空\n");
		return OVERFLOW;
	}
}

void print(SqQueue Q)
{
	int i = Q.front;

	if(Q.front == Q.rear)
	{
		printf("\n队空\n");
	}
	else
	{
		printf("\nfront->[");
		while(i != Q.rear)
		{
			printf(" %d", Q.base[i]);
			i = (i+1)%MAXSIZE;
		}
		printf(" ]<-rear\n");
	}
}