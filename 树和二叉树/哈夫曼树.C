#include<stdio.h>
#include<stdlib.h>

typedef int HElemType;
//-----哈夫曼树的顺序存储结构-----
//array[0]保留，前半部分为叶子结点，后半部分为非叶子结点
typedef struct
{
	HElemType weight;
	int parent;       //双亲
	int lchild;       //左孩子
	int rchild;       //右孩子
}HTNode, *HuffmanTree;

//-----哈夫曼树的基本操作-----
void CreateHuffmanTree(HuffmanTree *HT, int n);      //构造哈夫曼树
void Select(HuffmanTree HT, int n, int *s1, int *s2);//选择
void print(HuffmanTree HT, int n);                   //打印

void main()
{
	HuffmanTree HT;
	int n = 4;

	//测试哈夫曼树创建
	CreateHuffmanTree(&HT, n);
	print(HT, n);
	
}

void CreateHuffmanTree(HuffmanTree *HT, int n)
{
	int i;
	int s1 = 0, s2 = 0;    //选择出来的结点的下标

	//1.检查n的合法性
	if(n <= 1)
	{
		printf("\n分配内存输入参数不合法!\n");
		return;
	}
	//2.分配空间
	(*HT) = (HuffmanTree)malloc(sizeof(HTNode)*2*n);
	//3.指针置空
	for(i = 1; i < 2*n-1; i++)
	{
		(*HT)[i].parent = 0;
		(*HT)[i].lchild = 0;
		(*HT)[i].rchild = 0;
	}
	//4.输入叶子结点
	printf("\n输入%d个叶子结点权值：", n);
	for(i = 1; i <= n; i++)
	{
		scanf("%d", &((*HT)[i].weight));
	}

	//5.创建哈夫曼树
	for(i = n+1; i <= 2*n-1; i++)
	{
		//6.选择
		Select((*HT), i-1, &s1, &s2);
		//7.删除
		(*HT)[s1].parent = i;
		(*HT)[s2].parent = i;
		//8.合并
		(*HT)[i].lchild = s1;
		(*HT)[i].rchild = s2;
		(*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
	}
}

void Select(HuffmanTree HT, int n, int *s1, int *s2)
{
	int i;

	(*s1) = (*s2) = n;
	for(i = 1; i <= n; i++)
	{
		if(HT[(*s1)].parent == 0 && HT[i].weight<HT[(*s1)].weight)
		{
			(*s1) = i;
			continue;
		}
		if(HT[(*s2)].parent == 0 && HT[i].weight<HT[(*s2)].weight)
		{
			(*s2) = i;
			continue;
		}
	}
}

void print(HuffmanTree HT, int n)
{
	int i;

	printf("\n");
	for(i = 1; i <= 2*n-1; i++)
	{
		printf(" %d", HT[i].weight);
	}
	printf("\n");
}
