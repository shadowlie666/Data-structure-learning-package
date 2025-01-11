#include<stdio.h>
#include<stdlib.h>
#define MaxVertices 100 //假设包含100个顶点
#define MaxWeight 32767 //不邻接时为32767，但输出时用 "∞"
typedef struct{ //包含权的邻接矩阵的的定义
    int Vertices[MaxVertices];  //储存顶点编号的数组（顶点表） 
    int Edge[MaxVertices][MaxVertices]; //储存边的权信息的数组 
    int numV; //当前的顶点数
    int numE; //当前的边数
}AdjMatrix;

void CreateGraph(AdjMatrix *G) //图的生成函数
{ 
    int n,e,vi,vj,w,i,j;
    printf("请输入图的顶点数和边数（以空格分隔）：");
    scanf("%d%d",&n,&e);
    G->numV=n;
	G->numE=e;
    for(i=0;i<n;i++) //图的初始化
        for(j=0;j<n;j++)
            {  
            if(i==j)
                G->Edge[i][j]=0;       //有向图对角线上的(横纵坐标相同，两个一样的顶点之间)的值为0 
            else 
                G->Edge[i][j]=32767;   //其余点先默认为无穷（即两个点之间没有弧） 
            }
        for(i=0;i<G->numV;i++) //将顶点编号存入数组中
        { 
            printf("请输入第%d个顶点的信息(整型):",i+1);
            scanf("%d",&G->Vertices[i]);
        }
    printf("\n");

    for(i=0;i<G->numE;i++)
    { 
        printf("请输入边的信息i,j,w(以空格分隔):");
        scanf("%d%d%d",&vi,&vj,&w);   //vi，vj表示的是边连接的两个顶点，w表示的是边的权（无向图中边没有权，只要有边w就为1） 

    	//G->Edge[vi-1][vj-1]=w;//① 
        G->Edge[vj-1][vi-1]=w;//②
        //无向图具有对称性的规律，通过①②实现,无向图一次要输两个值，即12之间有边，则arcs[1][2]和arcs[2][1]的值都为1 
        //有向图不具备此性质，所以只需要①
    }
}
void DispGraph(AdjMatrix G) //输出邻接矩阵的信息
{ 
    int i,j;
    printf("\n输出顶点的信息（整型）:\n");  //先输出顶点编号 
    for(i=0;i<G.numV;i++)
        printf("%8d",G.Vertices[i]);

    printf("\n输出邻接矩阵:\n");
    printf("\t"); //水平制表 
    for(i=0;i<G.numV;i++)
        printf("%8d",G.Vertices[i]);

    for(i=0;i<G.numV;i++)
    { 
        printf("\n%8d",i+1);
        for(j=0;j<G.numV;j++)
        { 
        if(G.Edge[i][j]==32767) 
        //两点之间无连接时权值为默认的32767，
        //在无向图中一般用"0"表示，在有向图中一般用"∞",
        //这里为了方便统一输出 "∞"
            printf("%8s", "∞");
        else
            printf("%8d",G.Edge[i][j]);
        }
        printf("\n");   
    }
}
int main()
{ 
    AdjMatrix G;
    CreateGraph(&G);
    DispGraph(G);
}
