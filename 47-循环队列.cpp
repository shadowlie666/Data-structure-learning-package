# include <stdio.h>
# include <malloc.h>

typedef struct queue //队列结构体，要背 
{
	int *phead;   //phead作为动态数组的指针，用于指向数组的所有动态内存空间 
	int front;    //队列的头 
	int rear;     //队列的尾 
}queue;

void init(queue *pq)   //初始化队列，就是让front和rear的编号都为第一个区域的编号 
{
	pq->phead = (int*)malloc(sizeof(int)*6);  //这里假定分配6个可存放数据的空间（实际只有五个能用） 
	pq->front = 0;
	pq->rear = 0;    
}

bool full(queue *pq)  //判断队列是否满，由于最后一个内存空间不能用，所以只要rear + 1%6 == front就说明队列满了 
{
	if((pq->rear + 1)%6 == pq->front)
		return true;
	else
		return false;
}

bool input(queue *pq, int val)  //入队 
{
	if(full(pq))
	{
		return false;
	}
	else
	{
		pq->phead[pq->rear] = val;    //入队从尾部入，通过phead[编号]的方式去寻找那一块内存空间 
		pq->rear = (pq->rear + 1)%6;  //记得更新rear的编号 
		return true;
	}
}

void traverse(queue *pq)  //遍历队列 
{
	int i = pq->front;   //遍历的前提就是不能对原有数据结构进行修改，所以不能直接用front 
	while(i != pq->rear)  
	{
		printf("%d", pq->phead[i]);
		i = (i+1)%6;
	}
	return;
}

bool empty(queue *pq)  //判断队列是否为空，就是看front和rear的编号大小是否相同 
{
	if(pq->front == pq->rear)
		return true;
	else
		return false;
}

bool output(queue *pq, int *pval)   //出队 
{
	if(empty(pq))
	{
		return false;
	}
	else
	{
		*pval = pq->phead[pq->front];   //出队从头部出，先保存队列中那块区域的有效数据，再更新front的编号大小 
		pq->front = (pq->front + 1)%6;	
		return true;
	}
}

int main(void)
{
	queue q;
	init(&q);
	input(&q, 1);
	input(&q, 2);
	input(&q, 3);
	input(&q, 4);
	input(&q, 5);
	input(&q, 6);
	input(&q, 7);
	traverse(&q);
	
	return 0;
}
