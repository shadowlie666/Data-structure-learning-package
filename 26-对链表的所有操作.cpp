#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node
{
	int data;    //������������ÿ���ڵ����Ч���ݵ� 
	struct node *pnext;     //���ָ��洢������һ���ڵ�ĵ�ַ 
};

struct node* createlist(void)     //�����б��ý����������Ĳ��� 
{
	int i, val, n;
	struct node *phead1 = (struct node*)malloc(sizeof(struct node));
	struct node *pone = phead1;  //��������ͷָ����ͷ�����ȣ�������ͷ���ָ���׽ڵ㡢�м�ڵ㡢β�ڵ㣬��������ͷָ����൱�ڷ������нڵ��� 
	pone->pnext = NULL;   //��ʼ��ͷ���ĵ�ַ�򣬺���������ָ����һ�ڵ� 
	
	printf("��������Ҫ���ɵ��б������");
	scanf("%d", &n);
	
	for(i=0; i<n; i++)
	{
		printf("�������%d���ڵ�����ݣ�", i+1);
		scanf("%d", &val);
		
		struct node* pnew = (struct node*)malloc(sizeof(struct node));  
		pnew->data = val;      //�����ݷ����½ڵ��������ע��ͷ����ǲ������Ч���ݵģ���һ����Ч���ݷ����׽ڵ� 
		pone->pnext = pnew;    //��ͷ����ָ����ָ���׽ڵ㣬�����Ϳ���ͨ��ͷ����ҵ��׽ڵ��� 
		pnew->pnext = NULL;    //���׽ڵ��ָ����Ϊ�գ���һ��ѭ��ʱ������ָ����һ���ڵ� 
		pone = pnew;	      //�������׽ڵ��Ϊ��һ��ѭ����ͷ��㣬������һ��ѭ����ʱ��pnew�����׽ڵ�����Ǹ��ڵ� 
	}  //Ҳ�������ѭ��pone��ͷ��㣬pnew���׽ڵ㣬�´�ѭ����ʱ��pone�ͱ���׽ڵ㣬pnew�����׽ڵ����һ���ڵ� 
	return phead1;      //���Ǿ��γɵ�phead1=pone->pnew1->pnew2.....->β�ڵ�  ������ 
}

void outputlist(struct node *phead2)    //���������Ҫ�������ݸ������� 
{
	struct node *p = phead2->pnext; //����������һ��ָ��ָ��ͷ������һ���ڵ�Ҳ�����׽ڵ㣬��Ϊ���ֱ����pָ��ͷ���Ļ������������ʱ�� 
	while(NULL != p)                //�������ͷ������һ���ڵ�Ҳ�����׽ڵ�����ݣ������׽ڵ��ǲ������Ч���ݵģ�����pӦ��ָ��ͷ��� 
	{
		printf("%d", p->data);     //��һ��ѭ�����ͷ������һ���ڵ�Ҳ�����׽ڵ����Ч���� (ͷ������ͷָ�룬�������)
		p = p->pnext;      //ÿ��ѭ������pָ����һ���ڵ㣬����һ���ڵ�ĵ�ַ�Ѿ�������ÿһ���ڵ�ĵ�ַ���� 
	}
	return;
}

bool isemptylist(struct node *phead3)  //�ж������Ƿ�Ϊ�գ������ж��Ƿ������Ч���ݣ������Ƿ�����׽ڵ㣬Ҳ����ͷ����ָ�����Ƿ���ָ���׽ڵ� 
{
	if(phead3->pnext == NULL)   
		return true;
	else
		return false;
}

int lenlist(struct node *phead4) //���������� 
{
	int len;
	struct node* p = phead4->pnext; 
	while(NUll != p)  //���������һ����ֻ�������ﲻ������ݶ�����һ������һֱ��һ 
	{
		len++;
		p = p->pnext;
	}
	return len;
}

void sortlist(struct node *phead5)  //����������
{
	int i, k, t;
	struct node *p, q;
	int len = lenlist(phead5);
	                                //���µ�����ԭ����ʵ����ð������ֻ�ǲ���ֱ�Ӷ�ȡ���ݣ���Ҫ����ָ������ȡ 
	for(i=0, p=phead5->pnext; i<len-1; i++, p = p->pnext) //����ð�������˼�룬ÿ�αȽ�����´�ѭ����Ҫ�ٱȽ�һ���� 
	{
		for(k=0, q=p->pnext; k<len-1-i; k++, q=q->pnext) //ÿ��ѭ����ʱ��k���Ǵ�i���Ǹ��±꿪ʼһֱ�ӵ�len��Ȼ��Ƚ�k��k+1 
		{                           //���������ָ�벻��ͬʱָ�������ڵ㣬����Ҫ����pq�ֱ�ָ�������ڵ����Ƚϣ���ôq��Ӧ��ָ��p��ָ�����һ���ڵ� 
			if(p->data > q->data)
			{
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
		}
	}
	return phead5;
} 

bool insertlist(struct node *phead6, int pos, int val) //�ӵ�pos��ǰ���������val��ע���ǵ�pos����pos�����±꣩ 
{
	int i = 0;
	struct node *p = phead6;
	
	while(NULL != p && i<pos-1) //������Ҫ������ڵ㵽�������ڵ�֮ǰ�����while��Ŀ�ľ�����pָ�������ڵ㣬ͬʱi��ֵҲ�ǵ�����ڵ���±�5 
	{
		p = p->pnext;
		i++;                     //���к�i��ֵ�����pos-1 
	}
	
	if(i>pos-1 || NULL == p) //�涨���ֻ��5���ڵ㣬���ܲ���һ���ڵ㵽���߸��ڵ�֮ǰ����Ϊ���������ڵ㶼û�� 
	{
		return false;    //��������pos���Ϸ��������Ǹ�while�ǲ�����ĳ����ģ���Ϊ�����Ǹ�whileִ�����p����ָ��һ�������� 
	}                 //Ҳ����p����Ѿ�ָ�������һ���ڵ㣬����������while����������Ǵ��ڵ� 
	
	struct node *pnew = (struct node*)malloc(sizeof(struct node));  //Ϊ������Ǹ��ڵ�����ڴ�ռ� 
	if(NULL == pnew)
	{
		printf("�����½ڵ�ʧ��");
		exit(-1); 
	}	
	pnew->data = val;
	pnew->pnext = p->pnext; //���½ڵ�ָ���һ���ڵ㣬����ǰһ���ڵ�ָ���½ڵ� 
	p->pnext = pnew;//ע��˳���ܷ����������ǰһ���ڵ�ָ���½ڵ㣬��ô��һ���ڵ�ĵ�ַ�ͻᶪʧ������Ӧ�������½ڵ�ָ���һ���ڵ� 
	
	return true;
}

bool deletelist(struct node phead7, int pos)  //����ɾ����pos���ڵ�����Ǹ��ڵ� 
{
	int i = 0;
	struct node *p = phead7;
	
	while(NULL != p->pnext && i<pos-1)  //���while��������pָ����Ҫɾ�����Ǹ��ڵ� 
	{							//(�������Ǹ�����ڵ㲻һ�����������Ǹ����ж�pָ��Ľڵ��Ƿ�Ϊ�գ��������ж�p��ָ��ڵ����һ���Ƿ�Ϊ��)
		p = p->pnext;
		i++;                    
	}
	
	if(i>pos-1)  //���ifҲ������ȷ���û�������Ϣ�Ϸ��� 
	{
		return false;    
	}    
	struct node *q = p->pnext;        
	p->pnext = p->pnext->pnext;   //��������Ѿ���������ɾ��һ���ڵ��� 
	free(q);         //֮������Ҫ��һ��ָ���������ΪҪ�����ָ��ָ����Ҫɾ�����Ǹ��ڵ㣬ȥ������ڵ�ɾ�� 
	q = NULL;	
}

int main(void)
{
	struct node *phead = NULL;    //����ͷָ��ֻ��һ��ָ�����ã�û�д�����ݣ��ʲ��÷��䶯̬�ڴ� 
	
	phead = createlist();
	      
	outputlist(phead);
	
	if(isemptylist(phead))
		printf("����Ϊ��\n");
	else
		printf("�������ɹ�\n");
		
	int len = lenlist(phead);
	printf("����ĳ�����%d", len);
	
	phead = sortlist(phead); 
	
	insertlist(phead, 3, 66);
	
	return 0;
} 
