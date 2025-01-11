#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct node           //这个结构体是栈中的每一块区域的内容，每块内容需要有有效数据和执行下一个区域的指针域 
{
	int data;
	struct node *pnext;
}node,*pnode;

typedef struct stack          //这个结构体定义的是栈本身，栈必须有头部和底部 
{
	pnode ptop;
	pnode pbottom;
}stack,*pstack;

void init(pstack ps)   //初始化栈（创建栈） 
{
	ps->ptop = (pnode)malloc(sizeof(node));  //先让头指针指向栈内的原始区域，这个原始区域就是栈内最底部的区域，后面插入新的区域的时候 
	                                        //都是在原始区域上面插入的，且有效数据都是放到新区域里面的，原始区域啥都没有 
	if(NULL == ps->ptop)
	{
		printf("动态内存分配失败\n");
		exit(-1);
	}
	else
	{
		ps->pbottom = ps->ptop;       //此时栈内只有一块原始区域，先让头尾指针都指向这块原始区域， 
		ps->ptop->pnext = NULL;      //这里是初始化原始区域的指针域，目的是为了后来输出栈的时候以指针域为空作为条件来停止输出 
	}
} 

void push(pstack ps, int val)  //压栈 
{
	pnode pnew = (pnode)malloc(sizeof(node));  //因为栈内的每一块区域都要指向他下面的那块区域，所以每一块区域都要是指针结构体 
	pnew->data = val;                          //把有效数据放入栈内一块区域的数据域 
	pnew->pnext = ps->ptop;              //这里是让新区域的指针域指向没加入新区域时的最顶部的区域，这个最顶部的区域就是ptop目前所指向的区域 
	ps->ptop = pnew;                //由于创建了一个新的区域在最顶上，所以要让ptop指向最顶上的那块区域，也就是pnew
	
	return;           
} 

void output(pstack ps)    //遍历栈 
{
	pnode p = ps->ptop;     //不能通过直接输出ptop的数据域来输出，因为这样在ptop往下移的过程中上面的区域就会遗失，
							//相当于在删除栈，所以需要一个中间指针 
	while(p != ps->pbottom)  //只要p和pbottom不等，就还没有到栈的底部，就继续输出 
	{
		printf("%d", p->data);
		p = p->pnext;
	}
	printf("\n"); 
}

bool empty(pstack ps)  //检查栈是否为空 
{
	if(ps->ptop == ps->pbottom)   //如果ptop和pbottom相等了，就说明ptop已经移过了，已经没有区域可以出栈了 
		return true;
	else
		return false;
}

bool pop(pstack ps, int *pval)   //出栈（出栈只是输出栈内某一块区域的值），这里只输出最顶上那块区域的值 
{
	if(empty(ps))        //这里先判断是否出栈成功，由于ps原本保存的就是s的地址，所以这里发送ps就可以了 
	{
		return false;	
	} 
	else
	{
		pnode r = ps->ptop; //需要一个中间指针指向最顶部的区域，然后让ptop往下移一个区域，再释放r 
		*pval = r->data;        //把这块区域的有效数据返回给主函数（通过指针直接修改主函数变量的值） 
		ps->ptop = r->pnext;     //让ptop指向下面那一块区域 
		free(r);              //释放r所指向的那块区域的内存 
		r = NULL;          //释放r本身 
		
		return true;
	}
} 

void clear(pstack ps) //清空栈，回到初始化后的栈的情况（删除入栈的操作）
{					//思路就是多次执行出栈的操作 
	if(empty(ps))        //先判断如果栈是空的，就不用清空了 
		return;
	else
	{
		pnode p = ps->ptop;  //需要两个指针，q指针要指向p指针指向区域的下面那个，确保释放p所指向的区域的内存后还能找到下面的那个区域 
		pnode q = NULL;       //清空要从顶部开始删除，所以先让p指向顶部区域 
		
		while(p != ps->pbottom)  //当p与pbottom相等时，则所有的新创建的栈就已经清空了，只剩下原始区域了 
		{
			q = p->pnext;         //每次循环都先让q指向p下面的那个区域，先保存好下一个区域的地址 
			free(p);             //然后再放心删掉p所指向的那块区域 
			p = q;               //然后让p等于q，这样p就可以指向下一个区域了 
		}
		ps->ptop = ps->pbottom;  //由于83行的if已经确定栈不为空了，所以最后记得让ptop指回原始区域 
	}
} 

int main(void)
{
	stack s;   //定义一个栈 
	int val;   //用来存放出栈时返回的有效数据 
	 
	init(&s);    //初始化栈 
	push(&s, 1);    //压栈 
	push(&s, 2);
	output(&s);	 //遍历，查看栈内每一个区域的数据域 
	clear(&s);  //清空栈 
	
	if(pop(&s, &val))   //出栈，对栈内的某一个区域进行出栈，即删掉那块区域
	{
		printf("出栈成功，出栈的元素是%d\n", val);
	}
	else
	{
		printf("出栈失败\n");
	}
	
	return 0;
}
