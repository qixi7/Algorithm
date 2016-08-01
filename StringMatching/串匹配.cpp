#include <stdio.h>
#include <string.h>
#define MAX 100
int Index (char S[],char T[],int pos,int S_length,int T_length)
{
	int i = pos;
	int j = 0;
	while (i < S_length && j < T_length)
	{
		if(S[i] == T[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j >= T_length)
	{
		return i - T_length+1;
	}
	else
	{
		return 0;
	}
	
}
int replacestring(char S[],char T[],char C[],int S_length,int T_length)
{
	int i,now_pos;
	int static later_pos = 0;
	now_pos = Index(S,T,later_pos,S_length,T_length);
	if (now_pos == 0)
	{
		return 0;
	}
	else
	{
		for(i = 0;i < T_length; i++)
		{
			S[now_pos-1] = C[i];
			now_pos++;
		    later_pos = now_pos - 1;
	    }
		if (later_pos > S_length)
		{
			return 0;
	    }
		else
		{
			replacestring(S,T,C,S_length,T_length);
			return 0;
		}
		return 0;
	}
}
int main(void)
{
	char S[MAX],T[MAX],C[MAX];
	int m,n;
	printf("输入主串S:");
	gets(S);
	printf("输入子串T:");
	gets(T);
	printf("输入替代串C:");
	gets(C);
	m = strlen(S);
	n = strlen(T);
	replacestring(S,T,C,m,n);
	puts(S);
}