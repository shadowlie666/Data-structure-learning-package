# include <stdio.h>
# include <malloc.h>

typedef struct queue //���нṹ�壬Ҫ�� 
{
	int *phead;   //phead��Ϊ��̬�����ָ�룬����ָ����������ж�̬�ڴ�ռ� 
	int front;    //���е�ͷ 
	int rear;     //���е�β 
}queue;

void init(queue *pq)   //��ʼ�����У�������front��rear�ı�Ŷ�Ϊ��һ������ı�� 
{
	pq->phead = (int*)malloc(sizeof(int)*6);  //����ٶ�����6���ɴ�����ݵĿռ䣨ʵ��ֻ��������ã� 
	pq->front = 0;
	pq->rear = 0;    
}

bool full(queue *pq)  //�ж϶����Ƿ������������һ���ڴ�ռ䲻���ã�����ֻҪrear + 1%6 == front��˵���������� 
{
	if((pq->rear + 1)%6 == pq->front)
		return true;
	else
		return false;
}

bool input(queue *pq, int val)  //��� 
{
	if(full(pq))
	{
		return false;
	}
	else
	{
		pq->phead[pq->rear] = val;    //��Ӵ�β���룬ͨ��phead[���]�ķ�ʽȥѰ����һ���ڴ�ռ� 
		pq->rear = (pq->rear + 1)%6;  //�ǵø���rear�ı�� 
		return true;
	}
}

void traverse(queue *pq)  //�������� 
{
	int i = pq->front;   //������ǰ����ǲ��ܶ�ԭ�����ݽṹ�����޸ģ����Բ���ֱ����front 
	while(i != pq->rear)  
	{
		printf("%d", pq->phead[i]);
		i = (i+1)%6;
	}
	return;
}

bool empty(queue *pq)  //�ж϶����Ƿ�Ϊ�գ����ǿ�front��rear�ı�Ŵ�С�Ƿ���ͬ 
{
	if(pq->front == pq->rear)
		return true;
	else
		return false;
}

bool output(queue *pq, int *pval)   //���� 
{
	if(empty(pq))
	{
		return false;
	}
	else
	{
		*pval = pq->phead[pq->front];   //���Ӵ�ͷ�������ȱ���������ǿ��������Ч���ݣ��ٸ���front�ı�Ŵ�С 
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
