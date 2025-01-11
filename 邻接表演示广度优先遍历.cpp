//图的操作
#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAX_NUM 20

typedef int Status;
typedef int QElemType;
typedef char VexType;

typedef  struct EdgeNode{
	int adjvex;            //定点的位置 
	struct EdgeNode *next;//下一个定点的位置 
}EdgeNode,*EdgeLink;//建立邻接表 

typedef struct Vex{
	VexType data;      //顶点的数据 
	EdgeNode *firstEdge;//指向第一条邻节点的指针 
}VexNode,AdjList[MAX_NUM];//建立顶点数组； //结构数组 

typedef struct{
	AdjList adjlist;
	int vexNum,edgeNum;//定点数和边的数目 
}ALGraph; //图的邻接表存储结构

//队列的存储结构 图的广度搜索

typedef struct Node{
	QElemType data;
	struct Node *next;
	
}QNode,*QueuePtr; 

typedef struct{
	QueuePtr front;
	QueuePtr rear; 
}LinkQueue;

//初始化队列

Status InitQueue(LinkQueue *Q)
{
	Q->front = Q->rear = (QNode*)malloc(sizeof(QNode));
	if(Q->front)
	{
		Q->front->next = NULL;
		return OK;
	 } 
 } 
 
 
//判断是否为空

Status IsEmpty(LinkQueue Q)
{
	if(Q.front->next == NULL)
	{
		return TRUE;
	}
	else return FALSE;
 } 
//入队

Status EnQueue(LinkQueue *Q, QElemType e)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if(p)
	{
		p->data = e;
		p->next= NULL;
		Q->rear->next = p;
		Q->rear = p;
		return OK;
	}
	else return ERROR;

} 

//出队(带有头结点)

Status DeQueue(LinkQueue *Q, QElemType *e)
{
	QueuePtr q;
	if(Q->front==Q->rear)return ERROR;
	q = Q->front->next;
	*e = q->data;
	Q->front->next = q->next;
	if(Q->rear = q)
	{
		Q->rear = Q->front;
	}
	free(q);
	return OK; 
	
} 


//创建图（邻接表表示）(无向图)
Status CreateGraph(ALGraph *G)
{
	
	int i,j,k;
	EdgeLink e;
	printf("请输入顶点数和变数\n"); 
	scanf("%d %d",&G->vexNum,&G->edgeNum);
//	scanf("%d",&G->edgeNum);
	getchar();//吃掉回车
	//请输入个顶点的数据 
	printf("请输入各顶点的数据:\n");
	for(i=0;i<G->vexNum;i++)//初始化顶点数组 
	{
		scanf("%c",&G->adjlist[i].data);
		if(G->adjlist[i].data=='\n')
		{
			i--;
			continue;	
		}
		G->adjlist[i].firstEdge=NULL; 
	 } 
	//
	printf("请输入顶点（vi,vj)边定点的序号\n");
	
	for(k=0;k<G->edgeNum;k++)
	{
		scanf("%d %d",&i,&j);
	//	scanf("%d",&j);
		e = (EdgeLink)malloc(sizeof(EdgeNode));
		e->adjvex = j;
		e->next = G->adjlist[i].firstEdge ;
		G->adjlist[i].firstEdge = e;
		e = (EdgeLink)malloc(sizeof(EdgeNode));
		e->adjvex=i;
		e->next = G->adjlist[j].firstEdge;
		G->adjlist[j].firstEdge = e;
		
	}
	return OK;	
 } 
 
int visited[MAX_NUM];    //用于记录遍历状态

//广度 ：先访问完这个顶点的所有邻接点，再进入下一个顶点 
Status BFSTraverse(ALGraph G)
{
	
	int i;
	EdgeLink p;   //顶点 
	LinkQueue Q;  //创建队列 
	InitQueue(&Q);  //初始化队列 
	for(i=0;i<MAX_NUM;i++)
	{
		visited[i] = FALSE;
	}
	for(i=0;i<G.vexNum;i++) //逐个遍历所有的点 
	{
		if(!visited[i])
		{
			visited[i] = TRUE;  //记录这个顶点已经遍历 
			printf("%c",G.adjlist[i].data); //输出顶点信息 
			EnQueue(&Q, i); //将队列和顶点编号发送，让这个编号的顶点入队 
			while(!IsEmpty(Q))  //只要队列不为空都要去继续遍历剩下的顶点 
			{
				DeQueue(&Q, &i);  //发送队列和顶点编号，让这个编号的顶点出队 
				p = G.adjlist[i].firstEdge;  //p指向这个顶点的第一个邻接点 
				while(p)
				{
					if(!visited[p->adjvex]) //只要visited记录遍历状态表中显示它未遍历 
					{
						visited[p->adjvex] = TRUE; //记录这个顶点的邻接点已经遍历 
						printf("%c",G.adjlist[p->adjvex].data); //输出邻接点信息 
						EnQueue(&Q, p->adjvex); //记得遍历了这个点后要把这个点出队 

					}
					p = p->next; //p指向这个顶点的下一个邻接点 
				}
				
				
			}
		}
	}
	return OK;
	 
	
}
int main()
{
    ALGraph G;
    CreateGraph(&G);
    printf("\n广度优先遍历:");
    BFSTraverse(G);
    printf("\n");
}

