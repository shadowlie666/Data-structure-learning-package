#include <stdio.h>  
#include <stdlib.h>  
#define  MaxVertices 100
typedef struct node{   //�߱�,�洢�ߵ���Ϣ 
   int adjvex;  //ָ�����һ������ı�� 
   node* next;  //ָ�����һ������ĵ�ַ 
}EdgeNode;  
  
typedef struct{     //�����  
   int vertex;    //�洢�ö���ı�� 
   EdgeNode* edgenext;  //��¼���������ӵĶ���ĵ�ַ 
}VertexNode;  
  
typedef VertexNode AdjList[MaxVertices];  //����һ������ͼ�����飬ÿһ������Ԫ�ؾ���һ�����㣬�洢�˶������Ϣ  
  										//AdjList a�ȼ���struct VertexNode a[MaxVertices]
typedef struct{   
    AdjList adjlist; //��������ͼ������ 
    int n,e;  //nΪ��ǰͼ�Ķ�������eΪ��ǰͼ�ı��� 
}AdjMatrix;  

void CreateGraph(AdjMatrix* G)  //����ͼ 
{  
    int i,j,k,w,v;  
    EdgeNode *s;  
    printf("���붥�����ͱ������м��Կո�ֿ�����");  
    scanf("%d%d",&G->n,&G->e);  
  
    printf("���������\n"); 
    for (i=0;i<G->n;i++)  
    {  
		getchar(); 
		printf("�������%d���������Ϣ:",i+1);
		G->adjlist[i].vertex=getchar();
		G->adjlist[i].edgenext=NULL;  
    }  
    printf("�����߱�\n");  
    for (k=0;k<G->e;k++)  
    {  
       printf("���������ӵĶ�����ţ�");  
       scanf("%d%d",&i,&j);  
       i-=1; 
       s=(EdgeNode*)malloc(sizeof(EdgeNode));  //G��ͼ�����飬�����Ǵ洢�ߵ���Ϣ�������������Ͳ�һ��������������Ҫһ���м����s���洢�ߵ���Ϣ 
       s->adjvex=j; //�����һ���ڵ��� 
       s->next=G->adjlist[i].edgenext;  //�����һ���ڵ�ĵ�ַ 
       G->adjlist[i].edgenext=s;  //������ߵ���Ϣ�洢��ͼG��   
    }  
}   
void DispGraph(AdjMatrix *G) //����ͼ 
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

