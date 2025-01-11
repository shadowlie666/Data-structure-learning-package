#include<stdio.h>
#include<stdlib.h>

typedef struct ENode{
	int adjVex;
	int w;//Ȩֵ
	struct ENode* nextArc; 
}ENode;

typedef struct LGraph{
	int n;//������ 
	int e;//���� 
	ENode** a;
}LGraph; 

void Init(LGraph* g,int nSize)   //�ڽӱ��ʼ�� 
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



int Exist(LGraph* g,int u,int v)//����ĳ�����Ƿ����ͼ�� 
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
 

//����� 
void Insert(LGraph* g,int u,int v,int w) //uv֮��ıߣ�ȨֵΪw 
{
	if(u<0||v<0||u>g->n-1||v>g->n-1||u==v)
	{
		printf("����ı߲��淶\n");
		return ;
	}
		
	
	if(Exist(g,u,v)){
		printf("����ı��Ѵ���\n");
		return ;
	}
		

	ENode* p = (ENode*)malloc(sizeof(ENode));
	p->adjVex = v;
	p->w = w;
	p->nextArc = g->a[u];//���ڱ����ǰ�� 
	g->a[u] = p;
	g->e++;
	
	
	printf("����ߣ�%d -- %d\n",u,v);
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
		g->a[u] = p->nextArc;//���ɾ�����������һ�����
		
	free(p);
	g->e--;
	
	printf("ɾ���ߣ�%d -- %d\n",u,v);
	return; 
 } 
 
 
//�����ڽӱ� 
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


//��ӡ���еı� 
void Display(LGraph* g)
{
	int i;
	
	for(i = 0;i<g->n;i++)
	{
		ENode* p = g->a[i];
		while(p)
		{
			printf("�ߣ�%d--%d\n",i,p->adjVex);
			p = p->nextArc;
		}
	}
}

//������ȱ��� 
void DFS(LGraph* g,int *visit,int v)
{
	printf("Node: %d\n",v);  //���������Ϣ 
	ENode* p = g->a[v];  //��pָ��ǰ��ű�ʾ�Ķ����ͷ��� 
	visit[v] =1;
	for(;p;p = p->nextArc)  //ֻҪ�ڽӱ���ָ��������һ���ڵ�ĵ�ַ���ͻ�һֱѭ����ȥ 
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
		visit[i]= 0;  //Ĭ�����ж���δ���� 
	
	for(i = 0;i<g->n;i++) 
	{
		if(visit[i]==0) 
			DFS(g,visit,i);
	}
	free(visit);
 } 


//���½�Ϊ��������
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

