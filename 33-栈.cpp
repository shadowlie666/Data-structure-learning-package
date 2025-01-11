#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct node           //����ṹ����ջ�е�ÿһ����������ݣ�ÿ��������Ҫ����Ч���ݺ�ִ����һ�������ָ���� 
{
	int data;
	struct node *pnext;
}node,*pnode;

typedef struct stack          //����ṹ�嶨�����ջ����ջ������ͷ���͵ײ� 
{
	pnode ptop;
	pnode pbottom;
}stack,*pstack;

void init(pstack ps)   //��ʼ��ջ������ջ�� 
{
	ps->ptop = (pnode)malloc(sizeof(node));  //����ͷָ��ָ��ջ�ڵ�ԭʼ�������ԭʼ�������ջ����ײ������򣬺�������µ������ʱ�� 
	                                        //������ԭʼ�����������ģ�����Ч���ݶ��Ƿŵ�����������ģ�ԭʼ����ɶ��û�� 
	if(NULL == ps->ptop)
	{
		printf("��̬�ڴ����ʧ��\n");
		exit(-1);
	}
	else
	{
		ps->pbottom = ps->ptop;       //��ʱջ��ֻ��һ��ԭʼ��������ͷβָ�붼ָ�����ԭʼ���� 
		ps->ptop->pnext = NULL;      //�����ǳ�ʼ��ԭʼ�����ָ����Ŀ����Ϊ�˺������ջ��ʱ����ָ����Ϊ����Ϊ������ֹͣ��� 
	}
} 

void push(pstack ps, int val)  //ѹջ 
{
	pnode pnew = (pnode)malloc(sizeof(node));  //��Ϊջ�ڵ�ÿһ������Ҫָ����������ǿ���������ÿһ������Ҫ��ָ��ṹ�� 
	pnew->data = val;                          //����Ч���ݷ���ջ��һ������������� 
	pnew->pnext = ps->ptop;              //���������������ָ����ָ��û����������ʱ��������������������������ptopĿǰ��ָ������� 
	ps->ptop = pnew;                //���ڴ�����һ���µ���������ϣ�����Ҫ��ptopָ����ϵ��ǿ�����Ҳ����pnew
	
	return;           
} 

void output(pstack ps)    //����ջ 
{
	pnode p = ps->ptop;     //����ͨ��ֱ�����ptop�����������������Ϊ������ptop�����ƵĹ��������������ͻ���ʧ��
							//�൱����ɾ��ջ��������Ҫһ���м�ָ�� 
	while(p != ps->pbottom)  //ֻҪp��pbottom���ȣ��ͻ�û�е�ջ�ĵײ����ͼ������ 
	{
		printf("%d", p->data);
		p = p->pnext;
	}
	printf("\n"); 
}

bool empty(pstack ps)  //���ջ�Ƿ�Ϊ�� 
{
	if(ps->ptop == ps->pbottom)   //���ptop��pbottom����ˣ���˵��ptop�Ѿ��ƹ��ˣ��Ѿ�û��������Գ�ջ�� 
		return true;
	else
		return false;
}

bool pop(pstack ps, int *pval)   //��ջ����ջֻ�����ջ��ĳһ�������ֵ��������ֻ�������ǿ������ֵ 
{
	if(empty(ps))        //�������ж��Ƿ��ջ�ɹ�������psԭ������ľ���s�ĵ�ַ���������﷢��ps�Ϳ����� 
	{
		return false;	
	} 
	else
	{
		pnode r = ps->ptop; //��Ҫһ���м�ָ��ָ�����������Ȼ����ptop������һ���������ͷ�r 
		*pval = r->data;        //������������Ч���ݷ��ظ���������ͨ��ָ��ֱ���޸�������������ֵ�� 
		ps->ptop = r->pnext;     //��ptopָ��������һ������ 
		free(r);              //�ͷ�r��ָ����ǿ�������ڴ� 
		r = NULL;          //�ͷ�r���� 
		
		return true;
	}
} 

void clear(pstack ps) //���ջ���ص���ʼ�����ջ�������ɾ����ջ�Ĳ�����
{					//˼·���Ƕ��ִ�г�ջ�Ĳ��� 
	if(empty(ps))        //���ж����ջ�ǿյģ��Ͳ�������� 
		return;
	else
	{
		pnode p = ps->ptop;  //��Ҫ����ָ�룬qָ��Ҫָ��pָ��ָ������������Ǹ���ȷ���ͷ�p��ָ���������ڴ�����ҵ�������Ǹ����� 
		pnode q = NULL;       //���Ҫ�Ӷ�����ʼɾ������������pָ�򶥲����� 
		
		while(p != ps->pbottom)  //��p��pbottom���ʱ�������е��´�����ջ���Ѿ�����ˣ�ֻʣ��ԭʼ������ 
		{
			q = p->pnext;         //ÿ��ѭ��������qָ��p������Ǹ������ȱ������һ������ĵ�ַ 
			free(p);             //Ȼ���ٷ���ɾ��p��ָ����ǿ����� 
			p = q;               //Ȼ����p����q������p�Ϳ���ָ����һ�������� 
		}
		ps->ptop = ps->pbottom;  //����83�е�if�Ѿ�ȷ��ջ��Ϊ���ˣ��������ǵ���ptopָ��ԭʼ���� 
	}
} 

int main(void)
{
	stack s;   //����һ��ջ 
	int val;   //������ų�ջʱ���ص���Ч���� 
	 
	init(&s);    //��ʼ��ջ 
	push(&s, 1);    //ѹջ 
	push(&s, 2);
	output(&s);	 //�������鿴ջ��ÿһ������������� 
	clear(&s);  //���ջ 
	
	if(pop(&s, &val))   //��ջ����ջ�ڵ�ĳһ��������г�ջ����ɾ���ǿ�����
	{
		printf("��ջ�ɹ�����ջ��Ԫ����%d\n", val);
	}
	else
	{
		printf("��ջʧ��\n");
	}
	
	return 0;
}
