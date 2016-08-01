#include <stdio.h>
#define MAXVEX 30                        //最大顶点数30
#define MAX 666                          //令无穷大为666，便于操作
typedef struct  
{
	char vexs [MAXVEX];                   //顶点集合
	int arc[MAXVEX][MAXVEX];              //邻接矩阵
	int Vex_num,Edge_num;                 //顶点数和边数
}MGraph;                                //图结构
void CreatMGraph(MGraph *G)             //图的创建函数
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
/*--------------------------下为核心算法------------------------*/
void ShortestPath_DJ(MGraph G,int v0,int P[MAXVEX],int D[MAXVEX])
{                   
	int v;                                        //1
	int w;                                        //2
	int k,min;                                    //3
	int final[MAXVEX]; //4 该数组为标记变量数组,作用见上分析
	for (v = 0; v < G.Vex_num; v++)        //5 初始化各变量
	{                                          //6
		final[v] = 0;                             //7
		D[v] = G.arc[v0][v];                      //8
		P[v] = 0;                                 //9
	}                                          //10
	D[v0] = 0;                                 //11
	final[v0] = 1;                             //12
	for (v = 1; v < G.Vex_num; v++)       //13 此处开始主要循环
	{                                          //14
		min = MAX;                                //15
		for (w = 0; w < G.Vex_num; w++)  //16 寻找离初始顶点最近的顶点    
		{                                        //17   
			if (!final[w] && D[w] < min)          //18
			{                                     //19
				k = w;                             //20
				min = D[w];                //21 点V(w)离V(0)更近
			}                                    //22
		}                                        //23
		final[k] = 1;                    //24 将已找到最近的顶点标记
		for (w = 0; w < G.Vex_num; w++)  //25 这是个确认循环，很关键
		{                                        //26
			if (!final[w] && (min + G.arc[k][w] < D[w])) //27
			{                                            //28
				D[w] = min + G.arc[k][w];      //29 修改当前路径
				P[w] = k;                      //30
			}                                  //31
		}                                      //32 
	}                                       //33 
}                                           //34
/*--------------------主函数----------从来打酱油-----------*/
int main(void)                
{
	int v;
	int P[MAXVEX];
	int D[MAXVEX];
	MGraph G;
	CreatMGraph(&G);
	ShortestPath_DJ(G,0,P,D); //注意第二个参数，代表从0顶点开始寻找
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
