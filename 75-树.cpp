# include <stdio.h>   //��̬��������ʾ 
# include <malloc.h>

struct bintree //����һ���ڵ��Ϊ�����֣���ָ�룬��ָ�룬������ 
{
	char data;
	struct bintree *pleft;
	struct bintree *pright;
};

struct bintree * createtree(void)
{
	struct bintree *pa = (struct bintree *)malloc(sizeof(struct bintree));  //������������ڵ㣬��ΪҪ��֤����ִ��������Ľڵ���Ȼ���� 
	struct bintree *pb = (struct bintree *)malloc(sizeof(struct bintree));  //����Ҫ�ö�̬�ڴ� 
	struct bintree *pc = (struct bintree *)malloc(sizeof(struct bintree));
	struct bintree *pd = (struct bintree *)malloc(sizeof(struct bintree));
	struct bintree *pe = (struct bintree *)malloc(sizeof(struct bintree));
	
	pa->data = 'a';  //��������ֵ 
	pb->data = 'b';
	pc->data = 'c';
	pd->data = 'd';
	pe->data = 'e';
	
	pa->pleft = pb;  //�趨ÿ���ڵ��ָ���� 
	pa->pright = pc;
	pb->pleft = NULL;
	pb->pright = NULL;
	pc->pleft = pd;
	pc->pright = NULL;
	pd->pleft = NULL;
	pd->pright = pe;
	pe->pleft = NULL;
	pe->pright = NULL;
	
	return pa;
}

void fronttraverse(struct bintree * ptop)  //�ȷ��ʸ��ڵ㣬���������ڵ㣬����������ҽڵ� 
{
	if(NULL != ptop)
	{
		printf("%c", ptop->data);
		fronttraverse(ptop->pleft);
		fronttraverse(ptop->pright);
	}
}

void middletraverse(struct bintree *ptop) //�����������ڵ㣬���ʸ��ڵ㣬����������ҽڵ� 
{
	if(NULL != ptop)
	{
		middletraverse(ptop->pleft);
		printf("%c", ptop->data);
		middletraverse(ptop->pright);
	}
}

void behindtraverse(struct bintree *ptop) //�Ⱥ��������ڵ㣬��������ҽڵ㣬�ٷ��ʸ��ڵ� 
{
	if(NULL != ptop)
	{
		behindtraverse(ptop->pleft);
		behindtraverse(ptop->pright);
		printf("%c", ptop->data);
	}
}

int main(void)
{
	struct bintree * ptop = createtree();
	fronttraverse(ptop);
	middletraverse(ptop);
	behindtraverse(ptop); 
	
	return 0;
}
