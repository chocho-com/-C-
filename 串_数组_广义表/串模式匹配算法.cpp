#include<stdio.h>
#include<stdlib.h>

#define MAXLEN 255
//-----���Ķ���˳��洢�ṹ-----
//�ַ�����array[1]��ʼ�洢,array[0]���ò���
typedef struct
{
	char ch[MAXLEN+1];
	int length;
}String;

int Index_BF(String S, String T, int pos);    //BF�㷨
int Index_KMP(String S, String T, int pos);   //KMP�㷨

void main()
{
	
}

int Index_BF(String S, String T, int pos)
{
	int i = pos;      //S����ǰλ��
	int j = 1;        //T����ǰλ��


	//1.������
	while(i <= S.length && j <= T.length)
	{
		//2.��ȣ�������Ƚ�
		if(S.ch[i] == T.ch[j])
		{
			i++;
			j++;
		}
		else
		{
		//3.����ȣ�ָ�����
			i = (i-(j-1))+1;
			j = 1;
		}
	}

	if(j > T.length)
	{
		//4.ƥ��ɹ�
		return i-T.length;
	}
	else
	{
		//5.ƥ��ʧ��
		return 0;
	}
}

int Index_KMP(String S, String T, int pos)
{
	int i = pos;      //S����ǰλ��
	int j = 1;        //T����ǰλ��


	//1.������
	while(i <= S.length && j <= T.length)
	{
		//2.��ȣ�������Ƚ�
		if(S.ch[i] == T.ch[j] || j == 0)
		{
			i++;
			j++;
		}
		else
		{
		//3.����ȣ�ָ�뻬��
			j = next[j];
			
		}
	}

	if(j > T.length)
	{
		//4.ƥ��ɹ�
		return i-T.ch[1];
	}
	else
	{
		//5.ƥ��ʧ��
		return 0;
	}
}