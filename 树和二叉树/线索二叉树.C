#include<stdio.h>
#include<stdlib.h>

typedef int TElemType;
#define IS_NULL 1
#define NO_NULL 0
typedef int TElemType;
typedef int Status;
#define OVERFLOW -10000
#define OK 1
#define ERROR 0
#define TWO_DEGREE 2
#define ONE_DEGREE 1
#define ZERO_DEGREE 0
//-----二叉树的二叉线索存储结构-----
typedef struct BiThrNode
{
	TElemType data;
	struct BiThrNode *lchild, *rchild;
	int LTag, RTag;                     //左右标志
}BiThrNode, *BiThrTree;
BiThrTree pre;
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

//-----链式二叉树的基本操作-----
void InitBiThrTree(BiThrTree *T, BiTree BT);          //初始化线索二叉树
void PreThreading(BiThrTree T);                       //前序线索化
void PreOrderThreading(BiThrTree *Thrt, BiThrTree T); //带头结点的前序线索化
void InThreading(BiThrTree T);                        //中序线索化
void InOrderThreading(BiThrTree *Thrt, BiThrTree T);  //带头结点的中序线索化
void PostThreading(BiThrTree T);                      //后序线索化
void PostOrderThreading(BiThrTree *Thrt, BiThrTree T);//带头结点的后序线索化
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

}

void InitBiThrTree(BiThrTree *T, BiTree BT)
{
	if(!BT)
	{
		*T = NULL;
	}
	else
	{
		(*T) = (BiThrTree)malloc(sizeof(BiThrNode));
		(*T)->data = BT->data;
		InitBiThrTree(&(*T)->lchild, BT->lchild);
		InitBiThrTree(&(*T)->rchild, BT->rchild);
	}
}

void PreOrderThreading(BiThrTree *Thrt, BiThrTree T)
{
	//1.创建头结点
	(*Thrt) = (BiThrTree)malloc(sizeof(BiThrNode));
	(*Thrt)->RTag = IS_NULL;
	(*Thrt)->LTag = IS_NULL;
	(*Thrt)->lchild = (*Thrt);
	(*Thrt)->rchild = (*Thrt);

	if(!T)
	{
		//2.空结点，左右指针指向自己
		(*Thrt)->lchild = (*Thrt);
	}
}

void PreThreading(BiThrTree T)
{ 
	
}

void InOrderThreading(BiThrTree *Thrt, BiThrTree T)
{
	//1.创建头结点
	(*Thrt) = (BiThrTree)malloc(sizeof(BiThrNode));
	(*Thrt)->LTag = NO_NULL;
	(*Thrt)->RTag = IS_NULL;
	(*Thrt)->rchild = (*Thrt);

	if(!T)
	{
		//2.空结点，左指针指向自己
		(*Thrt)->lchild = (*Thrt);
	}
	else
	{
		//3.左孩子指向根（即前驱）
		(*Thrt)->lchild = T;
		pre = (*Thrt);
		
		//4.中序线索化
		InThreading(T);

		pre->rchild = (*Thrt);
		pre->RTag = IS_NULL;
		(*Thrt)->rchild = pre;
	}
}

void InThreading(BiThrTree T)
{ 
	if(T)
	{
		//1.遍历左子树
		InThreading(T->lchild);

		//2.左孩子为空，则加上左线索
		if(!T->lchild)
		{
			T->LTag = IS_NULL;
			T->lchild = pre;
		}
		else
		{
			T->LTag = NO_NULL;
		}
		//3.右孩子为空，则加上右线索
		if(!pre->rchild)
		{
			pre->RTag = IS_NULL;
			pre->rchild = T;
		}
		else
		{
			T->RTag = IS_NULL;
		}

		//4.遍历右子树
		pre = T;
		InThreading(T->rchild);
	}
}

void PostOrderThreading(BiThrTree *Thrt, BiThrTree T)
{
	
}

void PostThreading(BiThrTree T)
{ 
	
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