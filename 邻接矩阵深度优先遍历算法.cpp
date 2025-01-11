#include<stdio.h>
#include<stdlib.h>
//邻接矩阵结构
typedef char VertexType;
typedef int EdgeType;
 
#define MAX 10
#define INFINITY 65535
#define TRUE 1
#define FALSE 0
typedef int Boole;  //布尔类型 存储TRUE FALSE
Boole visited[MAX];    //访问标志数组 
 
typedef struct
{
	VertexType vexs[MAX];   //顶点表 
	EdgeType arc[MAX][MAX];   //邻接矩阵 可看作边表   
	int numVertexes,numEdges;
	int GraphType;  //图的类型  无向0,有向1	
}MGraph;
 
//构造图   有向图和无向图 
void create(MGraph *G)
{
	int i,j,k,w;
	printf("请输入顶点数和边数:\n");
	scanf("%d%d",&G->numVertexes,&G->numEdges);
	fflush(stdin);
	for(i=0;i<G->numVertexes;i++)     //建立顶点表
	{ 
		printf("\n第%d个顶点",i+1);
		scanf("%c",&G->vexs[i]);
		getchar();
	}
	
	for(i=0;i<G->numVertexes;i++)   //矩阵初始化 
		for(j=0;j<G->numVertexes;j++)
			G->arc[i][j]=INFINITY;
			
	for(k=0;k<G->numEdges;k++)
	{
		printf("输入边（Vi,Vj）的上下标i,j和权w(空格隔开)：");
		scanf("%d%d%d",&i,&j,&w);
		G->arc[i][j]=w;
		if(G->GraphType==0)      //此时为无向图   有向图与无向的区别就只是这一行代码的有无 
		G->arc[j][i]=G->arc[i][j];
	}			 
} 
 
void Output(MGraph *G)     //输出邻接矩阵 
{
	int i,j,count=0;
	for(i=0;i<G->numVertexes;i++)
		printf("\t%c",G->vexs[i]);
	printf("\n");
	for(i=0;i<G->numVertexes;i++)
	{
		printf("%4c",G->vexs[i]);
		for(j=0;j<G->numVertexes;j++)
		{	
			
				printf("\t%d",G->arc[i][j]);
				count++;
				if(count%G->numVertexes==0)
				printf("\n");	
		} 
    }	 
 } 
 
 
 
 
/*深度优先遍历*/
 
 
 
//深度优先递归算法
void DFS(MGraph G,int i)
{
	int j;
	visited[i]=TRUE;   //被访问的标记 
	printf("%c->",G.vexs[i]);
	for(j=0;j<G.numVertexes;j++)
	{
		if(G.arc[i][j]==1&&!visited[j])   //边(i,j)存在且j顶点未被访问，递归 
			DFS(G,j);
	} 
}
 
//深度优先遍历
void DFStraverse(MGraph G)
{
	
	int i;
	for(i=0;i<G.numVertexes;i++)
		visited[i]=FALSE;
	for(i=0;i<G.numVertexes;i++)
			if(!visited[i])
				DFS(G,i);		
				
} 
 
 
int main()
{
	MGraph G;
	int i,j;
	printf("输入生成图的类型(无向图0/有向图1)：");
	scanf("%d",&G.GraphType);
	create(&G);	
	printf("邻接矩阵数据如下：\n");
	Output(&G);
	printf("\n");
	DFStraverse(G);
	printf("\n图遍历完毕");
	return 0;	 
}
