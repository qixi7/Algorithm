#include <stdio.h>
#define MAXVEX 30
#define MAX 666
typedef struct  
{
	char vexs [MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int Vex_num,Edge_num;
}MGraph;
void CreatMGraph(MGraph *G)
{
	int i,j,k,w;
	printf("输入顶点数和边数(用逗号隔开~):\n");
	scanf("%d,%d",&G->Vex_num,&G->Edge_num);
	for (i = 0; i < G->Vex_num ; i++)
		for(j = 0; j < G->Edge_num; j++)
			G->arc[i][j] = MAX;
	for (k = 0; k < G->Edge_num; k++)
	{
		printf("请输入边vi,vj的下标i,j及所在边的权值(用逗号隔开~):\n");
		scanf("%d,%d,%d",&i,&j,&w);
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];
	}
}
void ShortestPath_DJ(MGraph G,int v0,int P[MAXVEX],int D[MAXVEX])
{
	int v,w,k,min;
	int final[MAXVEX];
	for (v = 0; v < G.Vex_num; v++)
	{
		final[v] = 0;
		D[v] = G.arc[v0][v];
		P[v] = 0;
	}
	D[v0] = 0;
	final[v0] = 1;
	for (v = 1; v < G.Vex_num; v++)
	{
		min = MAX;
		for (w = 0; w < G.Vex_num; w++)
		{
			if (!final[w] && D[w] < min)
			{
				k = w;
				min = D[w];
			}
		}
		final[k] = 1;
		for (w = 0; w < G.Vex_num; w++)
		{
			if (!final[w] && (min + G.arc[k][w] < D[w]))
			{
				D[w] = min + G.arc[k][w];
				P[w] = k;
			}
		}
	}
}
int main(void)
{
	int v;
	int v0 = 0;
	int P[MAXVEX];
	int D[MAXVEX];
	MGraph G;
	CreatMGraph(&G);
	ShortestPath_DJ(G,0,P,D);
	for(v = 1; v < G.Vex_num; v++)
	{
		printf("v0到顶点%d的最短权值为:%d\n",v,D[v]);
	}
	printf("最短路径数组为:P=");
	for(v = 0; v < G.Vex_num; v++)
	{
		printf("<%d> ",P[v]);
	}
	printf("\n");
}