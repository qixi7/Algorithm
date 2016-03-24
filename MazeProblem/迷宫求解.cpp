#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define M 10
#define N 10
typedef struct
{
	int x,y;
	char dir;
}Element;//定义迷宫元素类型，包含x,y坐标，以及方向dir
typedef struct STACK
{
	Element out;
	struct STACK *next;
}STACK,*LSTACK;//定义链栈
typedef struct
{
	int x;
	int y;
}ZB;//定义坐标类型,包含x,y坐标
void InitStack(LSTACK &S)//构造空栈
{   
	S=NULL;
}
int Empty(LSTACK S)//判断空栈
{
	if(S==NULL) 
		return 1;
	else
		return 0;
}
int Push(LSTACK &S , Element e)//进栈操作
{
	LSTACK top;
	top=(LSTACK)malloc(sizeof(STACK));
	top->out=e;
	top->next=S;
	S=top;
	return 1;
} 
int Pop(LSTACK &S,Element &e)  //栈顶元素出栈
{
	LSTACK top;
	e=S->out;
	top=S;
	S=S->next;
	free(top);
	return 1;

}
void CreatMG(int MG[M][N])//构造迷宫
{
	int i,j;
	int m,n;
	printf("请输入迷宫的行数: ");
	scanf("%d",&m);
	printf("请输入迷宫的列数: ");
	scanf("%d",&n);
	printf("请输入你的迷宫(1为墙，0为路，用空格隔开):\n");
	for( i = 1; i <= m; i++ )              //这两个for循环用来初始化迷宫
		for( j = 1 ; j <= n ; j++ )
			scanf("%d",&MG[i][j]);
	printf("你输入的迷宫为:\n");
	for( i = 0;i <= m + 1; i++ )          //这两个for循环用来加外墙 
	{
		MG [i][0] = 1 ;
		MG [i][n + 1] = 1;
	}
	for( j = 0 ; j <= n + 1 ; j++ )
	{
		MG[0][j] = 1;
		MG[m + 1][j] = 1;
	}
	for( i = 0 ; i <= m + 1 ; i++ ) //这两个for循环用来输出迷宫
	{
		for(j=0;j<=n+1;j++)
			printf("%d ",MG[i][j]); 
		printf("\n");
	}
}
int OutMG(ZB start, ZB end,int MG[M][N],int Move[4][2])        //解迷宫函数
{
	int h,k,x_next,y_next,dir;           
	Element e1,e2;
	LSTACK S1,S2;                  //定义两个栈，逆序用。S1放路径，S2用以逆序
	InitStack(S1);
	InitStack(S2);           
	e1.x=start.x; 
	e1.y=start.y;            
	h=e1.x;                 
	k=e1.y;
	e1.dir=-1;                   //令起点位置的方向为-1,以便于方向探索操作
	Push(S1,e1);                 //若有出路，起点应为路径之一
	while(!Empty(S1))
	{
		Pop(S1,e1);
		dir=e1.dir+1;
		while(dir<4)
		{
			x_next=h+Move[dir][0];
			y_next=k+Move[dir][1];
			if(MG[x_next][y_next]==2)
			{

				e1.x=h;
				e1.y=k;
				e1.dir=dir;
				MG[h][k]=3;
				h=x_next;
				k=y_next;
				dir=-1;
				Pop(S1,e1);
			}
			if(x_next==end.x&&y_next==end.y&&MG[x_next][y_next]==0)   
			{
				e1.x=h;
				e1.y=k;
				e1.dir=dir;
				Push(S1,e1);
				e1.x=x_next;
				e1.y=y_next;
				e1.dir=66;
				Push(S1,e1);
				while(!Empty(S1))
				{
					Pop(S1,e2);
					Push(S2,e2);
				}
				printf("dir：0为右，1为下，2为左，3为上.\n");
				printf("迷宫出路为:\n");
				while(!Empty(S2))
				{
					Pop(S2,e2);
					printf("(%d,%d,%d)",e2.x,e2.y,e2.dir);
				}
				return 0;
			}
			if(MG[x_next][y_next]==0)
			{
				MG[x_next][y_next]=2;
				e1.x=h;
				e1.y=k;
				e1.dir=dir;
				Push(S1,e1);
				h=x_next;
				k=y_next;
				dir=-1;
			}
			dir++;
		}
	}
	printf("没有出路啊！\n");
	return 0;
}
void main()
{
	ZB start,end;
	int Move[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	int MG[M][N];
	CreatMG(MG);
	printf("请输入迷宫入口坐标<逗号隔开>:\n");
	scanf("%d,%d",&start.x,&start.y);
	printf("请输入迷宫出口坐标<逗号隔开>:\n");
	scanf("%d,%d",&end.x,&end.y);
	OutMG(start,end,MG,Move);
}