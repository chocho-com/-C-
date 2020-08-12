#include<stdio.h>
#include<stdlib.h>

#define OVERFLOW -10000
#define OK 1
#define ERROR 0
typedef int Status;
typedef int QElemType;
//-----队列的链式存储结构-----
typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;
typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

//-----基本操作-----
Status InitQueue(LinkQueue *Q);              //初始化
Status EnQueue(LinkQueue *Q, QElemType e);   //入队
Status DeQueue(LinkQueue *Q, QElemType *e);  //出队
QElemType GetHead(LinkQueue Q);              //获取队头元素
void print(LinkQueue Q);                     //打印

void main()
{
	LinkQueue Q;
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

	//出队测试
	DeQueue(&Q, &e);
	printf("\n出队元素%d:", e);
	print(Q);

	//获取队头元素测试
	printf("\n队头元素为%d\n", GetHead(Q));
}

Status InitQueue(LinkQueue *Q)
{
	//1.构建空队列
	(*Q).front = (*Q).rear = (QueuePtr)malloc(sizeof(QNode));

	//2.头结点置空
	(*Q).front->next = NULL;

	return OK;
}

Status EnQueue(LinkQueue *Q, QElemType e)
{
	QueuePtr node = NULL;

	//1.创建新结点
	node = (QueuePtr)malloc(sizeof(QNode));
	node->data = e;
	node ->next = NULL;

	//2.入队
	(*Q).rear->next = node;
	(*Q).rear = node;

	return OK;
}

Status DeQueue(LinkQueue *Q, QElemType *e)
{
	QueuePtr p = NULL;

	//1.检查队空
	if((*Q).front == (*Q).rear)
	{
		printf("\n队空\n");
		return ERROR;
	}

	//2.出队
	p = (*Q).front->next;
	*e = p->data;
	(*Q).front->next = p->next;

	//3.最后一个元素被删除时，队头=队尾
	if((*Q).rear == p)
	{
		(*Q).rear = (*Q).front;
	}

	return OK;
}

QElemType GetHead(LinkQueue Q)
{
	if(Q.front != Q.rear)
	{
		return Q.front->next->data;
	}
	else
	{
		printf("\n队空\n");
		return OVERFLOW;
	}
}

void print(LinkQueue Q)
{
	QueuePtr p = Q.front->next;

	if(Q.front == Q.rear)
	{
		printf("\n队空\n");
	}
	else
	{
		printf("\nQ->[");
		while(p != NULL)
		{
			printf("->%d", p->data);
			p = p->next;
		}
		printf(" ]\n");
	}
}