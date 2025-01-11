# include <stdio.h>   //静态树程序演示 
# include <malloc.h>

struct bintree //树的一个节点分为三部分：左指针，右指针，数据域 
{
	char data;
	struct bintree *pleft;
	struct bintree *pright;
};

struct bintree * createtree(void)
{
	struct bintree *pa = (struct bintree *)malloc(sizeof(struct bintree));  //创建树的五个节点，因为要保证函数执行完毕树的节点仍然存在 
	struct bintree *pb = (struct bintree *)malloc(sizeof(struct bintree));  //所以要用动态内存 
	struct bintree *pc = (struct bintree *)malloc(sizeof(struct bintree));
	struct bintree *pd = (struct bintree *)malloc(sizeof(struct bintree));
	struct bintree *pe = (struct bintree *)malloc(sizeof(struct bintree));
	
	pa->data = 'a';  //给数据域赋值 
	pb->data = 'b';
	pc->data = 'c';
	pd->data = 'd';
	pe->data = 'e';
	
	pa->pleft = pb;  //设定每个节点的指针域 
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

void fronttraverse(struct bintree * ptop)  //先访问根节点，先序遍历左节点，再先序遍历右节点 
{
	if(NULL != ptop)
	{
		printf("%c", ptop->data);
		fronttraverse(ptop->pleft);
		fronttraverse(ptop->pright);
	}
}

void middletraverse(struct bintree *ptop) //先中序遍历左节点，访问根节点，再中序遍历右节点 
{
	if(NULL != ptop)
	{
		middletraverse(ptop->pleft);
		printf("%c", ptop->data);
		middletraverse(ptop->pright);
	}
}

void behindtraverse(struct bintree *ptop) //先后序遍历左节点，后序遍历右节点，再访问根节点 
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
