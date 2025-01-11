#include<stdio.h>
#include<stdlib.h>
//�ڽӾ���ṹ
typedef char VertexType;
typedef int EdgeType;
 
#define MAX 10
#define INFINITY 65535
#define TRUE 1
#define FALSE 0
typedef int Boole;  //�������� �洢TRUE FALSE
Boole visited[MAX];    //���ʱ�־���� 
 
typedef struct
{
	VertexType vexs[MAX];   //����� 
	EdgeType arc[MAX][MAX];   //�ڽӾ��� �ɿ����߱�   
	int numVertexes,numEdges;
	int GraphType;  //ͼ������  ����0,����1	
}MGraph;
 
//����ͼ   ����ͼ������ͼ 
void create(MGraph *G)
{
	int i,j,k,w;
	printf("�����붥�����ͱ���:\n");
	scanf("%d%d",&G->numVertexes,&G->numEdges);
	fflush(stdin);
	for(i=0;i<G->numVertexes;i++)     //���������
	{ 
		printf("\n��%d������",i+1);
		scanf("%c",&G->vexs[i]);
		getchar();
	}
	
	for(i=0;i<G->numVertexes;i++)   //�����ʼ�� 
		for(j=0;j<G->numVertexes;j++)
			G->arc[i][j]=INFINITY;
			
	for(k=0;k<G->numEdges;k++)
	{
		printf("����ߣ�Vi,Vj�������±�i,j��Ȩw(�ո����)��");
		scanf("%d%d%d",&i,&j,&w);
		G->arc[i][j]=w;
		if(G->GraphType==0)      //��ʱΪ����ͼ   ����ͼ������������ֻ����һ�д�������� 
		G->arc[j][i]=G->arc[i][j];
	}			 
} 
 
void Output(MGraph *G)     //����ڽӾ��� 
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
 
 
 
 
/*������ȱ���*/
 
 
 
//������ȵݹ��㷨
void DFS(MGraph G,int i)
{
	int j;
	visited[i]=TRUE;   //�����ʵı�� 
	printf("%c->",G.vexs[i]);
	for(j=0;j<G.numVertexes;j++)
	{
		if(G.arc[i][j]==1&&!visited[j])   //��(i,j)������j����δ�����ʣ��ݹ� 
			DFS(G,j);
	} 
}
 
//������ȱ���
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
	printf("��������ͼ������(����ͼ0/����ͼ1)��");
	scanf("%d",&G.GraphType);
	create(&G);	
	printf("�ڽӾ����������£�\n");
	Output(&G);
	printf("\n");
	DFStraverse(G);
	printf("\nͼ�������");
	return 0;	 
}
