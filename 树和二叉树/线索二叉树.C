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
	struct BiThrNode *lchild;
	struct BiThrNode *rchild;
	int LTag;               //左标志-前驱
	int RTag;               //右标志-后继
}BiThrNode, *BiThrTree;
BiThrTree pre;              //前驱指针
//-----二叉树的链式存储-----
typedef struct BiTNode
{
	TElemType data;           //数据域
	struct BiTNode *lchild;   //左孩子指针
	struct BiTNode *rchild;   //右孩子指针
}BiTNode, *BiTree;

//-----链式二叉树的基本操作-----
void InitBiThrTree(BiThrTree *T, BiTree BT);          //初始化线索二叉树
void Visit(BiThrTree *node);                          //访问结点
//-----前序-----
void PreThreading(BiThrTree T);                       //前序线索化
void PreOrderThreading(BiThrTree *Thrt, BiThrTree T); //带头结点的前序线索化
void PreOrderTraverse_Thr(BiThrTree T);                //遍历前序线索二叉树
//-----中序-----
void InThreading(BiThrTree T);                        //中序线索化
void InOrderThreading(BiThrTree *Thrt, BiThrTree T);  //带头结点的中序线索化
void InOrderTraverse_Thr(BiThrTree T);                //遍历中序线索二叉树
//-----后序-----
void PostThreading(BiThrTree T);                      //后序线索化
void PostOrderThreading(BiThrTree *Thrt, BiThrTree T);//带头结点的后序线索化
void PostOrderTraverse_Thr(BiThrTree T);                //遍历后序线索二叉树
//----二叉树的基本操作-----
void InitBiTree(BiTree *T);                 //构造空二叉树
void CreateBiTree(BiTree *T);               //创建二叉树

void main()
{
	BiTree BT;
	BiThrTree T;
	BiThrTree head;    //头结点

	//创建二叉树
	//测试数据:1 2 3 0 0 4 5 0 0 0 6 7 0 0 0
	InitBiTree(&BT);
	printf("\n请前序输入二叉结点的值:\n");
	CreateBiTree(&BT);

	//测试创建线索二叉树
	InitBiThrTree(&T, BT);

	//测试前序线索化
	PreOrderThreading(&head, T);
	PreOrderTraverse_Thr(head);
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
		
		//4.前序线索化
		PreThreading(T);

		//5.实现双向线索链表
		pre->rchild = (*Thrt);
		pre->RTag = IS_NULL;
		(*Thrt)->rchild = pre;
	}
}

void PreThreading(BiThrTree T)
{ 
	if(T)
	{
		//1.左孩子为空，加上左线索
		if(!T->lchild)
		{
			T->LTag = IS_NULL;
			T->lchild = pre;
		}
		else
		{
			T->LTag = NO_NULL;
		}
		//2.右孩子为空，则加上右线索
		if(!pre->rchild)
		{
			pre->RTag = IS_NULL;
			pre->rchild = T;
		}
		else
		{
			T->RTag = NO_NULL;
		}
		pre = T;

		//3.遍历左子树
		PreThreading(T->lchild);
		//4.遍历右子树
		PreThreading(T->rchild);
	}
}

void PreOrderTraverse_Thr(BiThrTree T)
{
	BiThrTree p = T->lchild;

	while(p!=T)
	{
		//1.访问结点
		Visit(&p);

		//2.遍历左子树
		while(p->LTag = NO_NULL)
		{
			p = p->lchild;
		}
		//3.访问后继
		while(p->RTag == NO_NULL && p->rchild != T)
		{
			p = p->rchild;
			Visit(&p);
		}

		//4.转向右子树
		p = p->rchild;
	}
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

		//5.实现双向线索链表
		pre->rchild = (*Thrt);
		pre->RTag = IS_NULL;
		(*Thrt)->rchild = pre;
	}
}

void InOrderTraverse_Thr(BiThrTree T)
{
	BiThrTree p = T->lchild;

	while(p!=T)
	{
		//1.遍历左子树
		while(p->LTag = NO_NULL)
		{
			p = p->lchild;
		}
		//2.访问结点
		Visit(&p);

		//3.访问后继
		while(p->RTag == NO_NULL && p->rchild != T)
		{
			p = p->rchild;
			Visit(&p);
		}

		//4.转向右子树
		p = p->rchild;
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
			T->RTag = NO_NULL;
		}
		pre = T;

		//4.遍历右子树
		InThreading(T->rchild);
	}
}

void PostOrderThreading(BiThrTree *Thrt, BiThrTree T)
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
		
		//4.后序线索化
		PostThreading(T);

		//5.实现双向线索链表
		pre->rchild = (*Thrt);
		pre->RTag = IS_NULL;
		(*Thrt)->rchild = pre;
	}
}

void PostOrderTraverse_Thr(BiThrTree T)
{
	BiThrTree p = T->lchild;

	while(p!=T)
	{
		//1.遍历左子树
		while(p->LTag = NO_NULL)
		{
			p = p->lchild;
		}
		//2.访问后继
		while(p->RTag == NO_NULL && p->rchild != T)
		{
			p = p->rchild;
			Visit(&p);
		}

		//3.访问结点
		Visit(&p);

		//4.转向右子树
		p = p->rchild;
	}
}

void PostThreading(BiThrTree T)
{ 
	if(T)
	{
		//1.遍历左子树
		InThreading(T->lchild);
		//2.遍历右子树
		InThreading(T->rchild);

		//3.左孩子为空，则加上左线索
		if(!T->lchild)
		{
			T->LTag = IS_NULL;
			T->lchild = pre;
		}
		else
		{
			T->LTag = NO_NULL;
		}
		//4.右孩子为空，则加上右线索
		if(!pre->rchild)
		{
			pre->RTag = IS_NULL;
			pre->rchild = T;
		}
		else
		{
			T->RTag = NO_NULL;
		}
		pre = T;
	}
}

void Visit(BiThrTree *node)
{
	printf(" %d", (*node)->data);
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
