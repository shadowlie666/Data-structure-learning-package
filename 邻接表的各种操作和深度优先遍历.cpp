#include<stdio.h>
#include<stdlib.h>

typedef struct ENode{
	int adjVex;
	int w;//权值
	struct ENode* nextArc; 
}ENode;

typedef struct LGraph{
	int n;//顶点数 
	int e;//边数 
	ENode** a;
}LGraph; 

void Init(LGraph* g,int nSize)   //邻接表初始化 
{
	int i;
	g->n = nSize;
	g->e = 0;
	g->a = (ENode**)malloc(sizeof(ENode*)*nSize);
	
	if(!g->a)
		return ;
	else{
		for(i = 0;i<nSize;i++)
			g->a[i] = NULL;
	}
}



int Exist(LGraph* g,int u,int v)//查找某条边是否存在图中 
{
	ENode* p = g->a[u];
	while(p)
	{
		if(p->adjVex == v)
			return 1;

		p = p->nextArc;
	}
	return 0;
 } 
 

//插入边 
void Insert(LGraph* g,int u,int v,int w) //uv之间的边，权值为w 
{
	if(u<0||v<0||u>g->n-1||v>g->n-1||u==v)
	{
		printf("插入的边不规范\n");
		return ;
	}
		
	
	if(Exist(g,u,v)){
		printf("插入的边已存在\n");
		return ;
	}
		

	ENode* p = (ENode*)malloc(sizeof(ENode));
	p->adjVex = v;
	p->w = w;
	p->nextArc = g->a[u];//插在表的最前面 
	g->a[u] = p;
	g->e++;
	
	
	printf("插入边：%d -- %d\n",u,v);
	return;
	
}

void Delete(LGraph* g,int u,int v)
{
	if(u<0||v<0||u>g->n-1||v>g->n-1||u==v)
		return;
	
	ENode* p = g->a[u];
	ENode* q = NULL;
	while(p&&p->adjVex != v)
	{
		q = p;
		p = p->nextArc;
	 } 
	if(!p)
		return;
	
	if(q)
		q->nextArc = p->nextArc;
	else
		g->a[u] = p->nextArc;//如果删除的是链表第一个结点
		
	free(p);
	g->e--;
	
	printf("删除边：%d -- %d\n",u,v);
	return; 
 } 
 
 
//撤销邻接表 
 void Destroy(LGraph* g)
 {
 	int i;
 	ENode *p,*q;
 	for(i = 0;i<g->n;i++)
 	{
 		p = g->a[i];
 		q = p;
 		while(p)
 		{
 			p = p->nextArc;
 			free(q);
 			q = p;
		 }
	 }
	free(g->a);
 }


//打印所有的边 
void Display(LGraph* g)
{
	int i;
	
	for(i = 0;i<g->n;i++)
	{
		ENode* p = g->a[i];
		while(p)
		{
			printf("边：%d--%d\n",i,p->adjVex);
			p = p->nextArc;
		}
	}
}

//深度优先遍历 
void DFS(LGraph* g,int *visit,int v)
{
	printf("Node: %d\n",v);  //输出顶点信息 
	ENode* p = g->a[v];  //让p指向当前编号表示的顶点的头结点 
	visit[v] =1;
	for(;p;p = p->nextArc)  //只要邻接表中指针域还有下一个节点的地址，就会一直循环下去 
	{
		if(visit[p->adjVex]==0)
			DFS(g,visit,p->adjVex);
	}
}

void DFSGraph(LGraph* g)
{
	int *visit = (int*)malloc(sizeof(int)*g->n);
	int i  = 0;
	for(;i<g->n;i++)
		visit[i]= 0;  //默认所有顶点未遍历 
	
	for(i = 0;i<g->n;i++) 
	{
		if(visit[i]==0) 
			DFS(g,visit,i);
	}
	free(visit);
 } 


//以下仅为测试内容
 int main()
 {
 	LGraph* g = (LGraph*)malloc(sizeof(LGraph));
 	Init(g,5);
 	Insert(g,1,2,3);
 	Insert(g,1,3,3);
 	Insert(g,2,4,3);
 	Insert(g,2,3,3);
 	Insert(g,4,1,3);
 	Insert(g,4,0,3);
 	Insert(g,4,0,3);
 	printf("Exist(g,1,2): %d\n",Exist(g,2,4));
 	Delete(g,1,2);
 	printf("Exist(g,1,2): %d\n",Exist(g,1,2));
 	Display(g);
 	Destroy(g);
 	
 	return 0;
 }

