#include <stdio.h>  
#include <stdlib.h>  
#define  MaxVertices 100
typedef struct node{   //边表,存储边的信息 
   int adjvex;  //指向的下一个顶点的编号 
   node* next;  //指向的下一个顶点的地址 
}EdgeNode;  
  
typedef struct{     //顶点表  
   int vertex;    //存储该顶点的编号 
   EdgeNode* edgenext;  //记录与它有连接的顶点的地址 
}VertexNode;  
  
typedef VertexNode AdjList[MaxVertices];  //命名一个保存图的数组，每一个数组元素就是一个顶点，存储了顶点的信息  
  										//AdjList a等价于struct VertexNode a[MaxVertices]
typedef struct{   
    AdjList adjlist; //创建保存图的数组 
    int n,e;  //n为当前图的顶点数，e为当前图的边数 
}AdjMatrix;  

void CreateGraph(AdjMatrix* G)  //创建图 
{  
    int i,j,k,w,v;  
    EdgeNode *s;  
    printf("输入顶点数和边数（中间以空格分开）：");  
    scanf("%d%d",&G->n,&G->e);  
  
    printf("建立顶点表\n"); 
    for (i=0;i<G->n;i++)  
    {  
		getchar(); 
		printf("请输入第%d个顶点的信息:",i+1);
		G->adjlist[i].vertex=getchar();
		G->adjlist[i].edgenext=NULL;  
    }  
    printf("建立边表\n");  
    for (k=0;k<G->e;k++)  
    {  
       printf("输入有连接的顶点序号：");  
       scanf("%d%d",&i,&j);  
       i-=1; 
       s=(EdgeNode*)malloc(sizeof(EdgeNode));  //G是图的数组，这里是存储边的信息，两者数据类型不一样，所以这里需要一个中间变量s来存储边的信息 
       s->adjvex=j; //存放下一个节点编号 
       s->next=G->adjlist[i].edgenext;  //存放下一个节点的地址 
       G->adjlist[i].edgenext=s;  //将这个边的信息存储回图G中   
    }  
}   
void DispGraph(AdjMatrix *G) //遍历图 
{
	int i;
	for (i=0;i<G->n;i++)  
    {  
        printf("%d->",i+1);  
        while(1)  
        {             
			if(G->adjlist[i].edgenext==NULL)
            {
            	printf("^");
				break;	
			}
            printf("%d->",G->adjlist[i].edgenext->adjvex);  
            G->adjlist[i].edgenext=G->adjlist[i].edgenext->next;  
 
        }  
        printf("\n");  
    }  
} 
int main()  
{  
   AdjMatrix* G= (AdjMatrix*)malloc(sizeof(AdjMatrix));  
   CreateGraph(G);  
   DispGraph(G); 
}

