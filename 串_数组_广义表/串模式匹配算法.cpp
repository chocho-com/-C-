#include<stdio.h>
#include<stdlib.h>

#define MAXLEN 255
//-----串的定长顺序存储结构-----
//字符串从array[1]开始存储,array[0]闲置不用
typedef struct
{
	char ch[MAXLEN+1];
	int length;
}String;

int Index_BF(String S, String T, int pos);    //BF算法
int Index_KMP(String S, String T, int pos);   //KMP算法

void main()
{
	
}

int Index_BF(String S, String T, int pos)
{
	int i = pos;      //S串当前位置
	int j = 1;        //T串当前位置


	//1.遍历串
	while(i <= S.length && j <= T.length)
	{
		//2.相等，则继续比较
		if(S.ch[i] == T.ch[j])
		{
			i++;
			j++;
		}
		else
		{
		//3.不相等，指针回溯
			i = (i-(j-1))+1;
			j = 1;
		}
	}

	if(j > T.length)
	{
		//4.匹配成功
		return i-T.length;
	}
	else
	{
		//5.匹配失败
		return 0;
	}
}

int Index_KMP(String S, String T, int pos)
{
	int i = pos;      //S串当前位置
	int j = 1;        //T串当前位置


	//1.遍历串
	while(i <= S.length && j <= T.length)
	{
		//2.相等，则继续比较
		if(S.ch[i] == T.ch[j] || j == 0)
		{
			i++;
			j++;
		}
		else
		{
		//3.不相等，指针滑动
			j = next[j];
			
		}
	}

	if(j > T.length)
	{
		//4.匹配成功
		return i-T.ch[1];
	}
	else
	{
		//5.匹配失败
		return 0;
	}
}