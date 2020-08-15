#include<stdio.h>
#include<stdlib.h>

typedef int TElemType;
typedef int Status;
#define OVERFLOW -10000
#define OK 1
#define ERROR 0
#define TWO_DEGREE 2
#define ONE_DEGREE 1
#define ZERO_DEGREE 0
//-----二叉树的链式存储-----
typedef struct BiTNode
{
	TElemType data;           //数据域
	struct BiTNode *lchild;   //左孩子指针
	struct BiTNode *rchild;   //右孩子指针
}BiTNode, *BiTree;
//-----链式栈的存储结构-----
typedef BiTree SElemType;
typedef struct StackNode
{
	SElemType data;
	struct StackNode *next;
}StackNode, *LinkStack;

//----二叉树的基本操作-----
void PreOrderTraverse_R(BiTree T);          //前序遍历递归算法
void PreOrderTraverse(BiTree T);            //前序遍历非递归算法
void InOrderTraverse_R(BiTree T);           //中序遍历递归算法
void InOrderTraverse(BiTree T);             //中序遍历非递归算法
void PostOrderTraverse_R(BiTree T);         //后序遍历递归算法
void PostOrderTraverse(BiTree T);           //后序遍历非递归算法
void Visit(BiTree node);                    //访问结点
void InitBiTree(BiTree *T);                 //构造空二叉树
void CreateBiTree(BiTree *T);               //创建二叉树
void CopyBiTree(BiTree T, BiTree *NewT);    //复制二叉树
int Depth(BiTree T);                        //计算二叉树的深度
int NodeCount(BiTree T);                    //统计二叉树的结点个数
int NodeCountByDegree(BiTree T, int degree);//统计二叉树的不同度的结点数
//-----链式栈的基本操作-----
Status InitStack(LinkStack *S);             //初始化
Status Push(LinkStack *S, SElemType e);     //入栈
Status Pop(LinkStack *S, SElemType *e);     //出栈
SElemType GetTop(LinkStack S);              //取栈顶元素
void print(LinkStack S);                    //打印
Status StackEmpty(LinkStack S);             //判断栈空

void main()
{
	BiTree T;
	BiTree NewT;

	//初始化测试
	InitBiTree(&T);

	//创建二叉树测试，前序输入
	//测试数据:1 2 3 0 0 4 5 0 0 0 6 7 0 0 0
	printf("\n请前序输入二叉结点的值:\n");
	CreateBiTree(&T);
	printf("\n创建二叉树……\n");
	PreOrderTraverse(T);

	//测试前序遍历
	printf("\n\n前序遍历:\n");
	PreOrderTraverse(T);

	//测试中序遍历
	printf("\n\n中序遍历:\n");
	InOrderTraverse(T);

	//测试后序遍历
	printf("\n\n后序遍历:\n");
	PostOrderTraverse(T);

	//测试复制二叉树
	InitBiTree(&NewT);
	CopyBiTree(T, &NewT);
	printf("\n\n复制后的二叉树:\n");
	PreOrderTraverse(NewT);

	//测试深度计算
	printf("\n\n二叉树T的深度为:%d\n", Depth(T));

	//测试结点数统计
	printf("\n\n二叉树T的结点数为:%d\n", NodeCount(T));
	//测试统计度为0的结点fail.....
	printf("\n\n二叉树T中度为0的结点数为:%d\n", 
		NodeCountByDegree(T, ZERO_DEGREE));
	printf("\n");

}

//-----链式二叉树的基本操作-----
void InitBiTree(BiTree *T)
{
	(*T) = NULL;
}

void CreateBiTree(BiTree *T)
{
	int num;

	scanf("%d", &num);
	if(num == 0)
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = num;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}

void PreOrderTraverse_R(BiTree T)
{
	if(T != NULL)
	{
		//1.访问结点
		Visit(T);
		//2.遍历左子树
		PreOrderTraverse_R(T->lchild);
		//3.遍历右子树
		PreOrderTraverse_R(T->rchild);
	}
}

void PreOrderTraverse(BiTree T)
{
	LinkStack S = NULL;
	BiTree p = NULL;

	InitStack(&S);
	p = T;
	while(p || !StackEmpty(S))
	{
		if(p)
		{
			//1.访问根结点
			Push(&S, p);
			Visit(p);
			//2.遍历左孩子
			p = p->lchild;
		}
		else
		{
			//3.遍历右孩子
			Pop(&S, &p);
			p = p->rchild;
		}
	}
}

void InOrderTraverse_R(BiTree T)
{
	if(T != NULL)
	{
		//1.遍历左子树
		InOrderTraverse_R(T->lchild);
		//2.访问结点
		Visit(T);
		//3.遍历右子树
		InOrderTraverse_R(T->rchild);
	}
}

void InOrderTraverse(BiTree T)
{
	LinkStack S = NULL;
	BiTree p = NULL;
	
	InitStack(&S);
	p = T;
	while(p || !StackEmpty(S))
	{
		if(p)
		{
			//1.遍历左孩子
			Push(&S, p);
			p = p->lchild;
		}
		else
		{
			//2.访问结点
			Pop(&S, &p);
			Visit(p);
			//3.遍历右孩子
			p = p->rchild;
		}
	}
}

void PostOrderTraverse_R(BiTree T)
{
	if(T != NULL)
	{
		//1.遍历左子树
		PostOrderTraverse_R(T->lchild);
		//2.遍历右子树
		PostOrderTraverse_R(T->rchild);
		//3.访问结点
		Visit(T);
	}
}

void PostOrderTraverse(BiTree T)
{
	LinkStack S1 = NULL;   //存储左孩子
	LinkStack S2 = NULL;   //存储右孩子
	BiTree p = NULL;
	
	InitStack(&S1);
	InitStack(&S2);
	p = T;
	while(p || !StackEmpty(S1))
	{
		//反向遍历左右孩子
		while(p)
		{
			//1.遍历右孩子，压入栈S1、S2
			Push(&S1, p);
			Push(&S2, p);
			p = p->rchild;
		}
		if(!StackEmpty(S1))
		{
			//2.遍历左孩子
			Pop(&S1, &p);
			p = p->lchild;
		}
	}
	while(!StackEmpty(S2))
	{
		Pop(&S2, &p);
		//3.访问结点
		Visit(p);
	}
}

void Visit(BiTree node)
{
	printf(" %d", node->data);
}

void CopyBiTree(BiTree T, BiTree *NewT)
{
	if(!T)
	{
		*NewT = NULL;
	}
	else
	{
		(*NewT) = (BiTree)malloc(sizeof(BiTNode));
		(*NewT)->data = T->data;
		CopyBiTree(T->lchild, &(*NewT)->lchild);
		CopyBiTree(T->rchild, &(*NewT)->rchild);
	}
}

int Depth(BiTree T)
{
	int l, r;

	if(!T)
	{
		return 0;
	}
	else
	{
		//左子树的深度
		l = Depth(T->lchild);
		//右子树的深度
		r = Depth(T->rchild);
		if(l > r)
		{
			return l+1;
		}
		else
		{
			return r+1;
		}
	}
}

int NodeCount(BiTree T)
{
	if(!T)
	{
		return 0;
	}
	else
	{
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
	}
}

int NodeCountByDegree(BiTree T, int degree)
{
	int l, r;
	int count;

	if(!T)
	{
		count = 0;
	}
	else
	{
		l = NodeCountByDegree(T->lchild, degree);
		r = NodeCountByDegree(T->rchild, degree);
		switch(degree)
		{
		case ZERO_DEGREE:
			count = !(l&r) ? (l+r+1) : 0;
			break;
		case ONE_DEGREE:
			count = (l^r) ? (l+r+1) : 0;
			break;
		case TWO_DEGREE:
			count = (l&r) ? (l+r+1) : 0;
			break;
		}
	}

	return count;
}

//-----链式栈的基本操作-----
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
		return NULL;
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

Status StackEmpty(LinkStack S)
{
	return (S==NULL)?OK:ERROR;
}