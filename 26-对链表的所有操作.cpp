#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node
{
	int data;    //这个是用来存放每个节点的有效数据的 
	struct node *pnext;     //这个指针存储的是下一个节点的地址 
};

struct node* createlist(void)     //创建列表不用接收主函数的参数 
{
	int i, val, n;
	struct node *phead1 = (struct node*)malloc(sizeof(struct node));
	struct node *pone = phead1;  //这里是让头指针与头结点相等，后面让头结点指向首节点、中间节点、尾节点，这样返还头指针就相当于返回所有节点了 
	pone->pnext = NULL;   //初始化头结点的地址域，后面再让他指向下一节点 
	
	printf("请输入需要生成的列表个数：");
	scanf("%d", &n);
	
	for(i=0; i<n; i++)
	{
		printf("请输入第%d个节点的数据：", i+1);
		scanf("%d", &val);
		
		struct node* pnew = (struct node*)malloc(sizeof(struct node));  
		pnew->data = val;      //将数据放入新节点的数据域，注意头结点是不存放有效数据的，第一个有效数据放在首节点 
		pone->pnext = pnew;    //让头结点的指针域指向首节点，这样就可以通过头结点找到首节点了 
		pnew->pnext = NULL;    //让首节点的指针域为空，下一次循环时再让他指向下一个节点 
		pone = pnew;	      //这里让首节点成为下一次循环的头结点，这样下一次循环的时候pnew就是首节点后面那个节点 
	}  //也就是这次循环pone是头结点，pnew是首节点，下次循环的时候pone就变成首节点，pnew就是首节点的下一个节点 
	return phead1;      //于是就形成的phead1=pone->pnew1->pnew2.....->尾节点  的链条 
}

void outputlist(struct node *phead2)    //输出链表不需要返还数据给主函数 
{
	struct node *p = phead2->pnext; //这里是先让一个指针指向头结点的下一个节点也就是首节点，因为如果直接让p指向头结点的话，下面输出的时候 
	while(NULL != p)                //输出的是头结点的下一个节点也就是首节点的数据，但是首节点是不存放有效数据的，所以p应该指向头结点 
	{
		printf("%d", p->data);     //第一次循环输出头结点的下一个节点也就是首节点的有效数据 (头结点就是头指针，两个相等)
		p = p->pnext;      //每次循环都让p指向下一个节点，而下一个节点的地址已经保存在每一个节点的地址域了 
	}
	return;
}

bool isemptylist(struct node *phead3)  //判断链表是否为空，就是判断是否存在有效数据，就是是否存在首节点，也就是头结点的指针域是否有指向首节点 
{
	if(phead3->pnext == NULL)   
		return true;
	else
		return false;
}

int lenlist(struct node *phead4) //计算链表长度 
{
	int len;
	struct node* p = phead4->pnext; 
	while(NUll != p)  //与输出链表一样，只不过这里不输出内容而是让一个变量一直加一 
	{
		len++;
		p = p->pnext;
	}
	return len;
}

void sortlist(struct node *phead5)  //对链表排序
{
	int i, k, t;
	struct node *p, q;
	int len = lenlist(phead5);
	                                //以下的排序原理其实就是冒泡排序，只是不能直接读取数据，需要借助指针来读取 
	for(i=0, p=phead5->pnext; i<len-1; i++, p = p->pnext) //按照冒泡排序的思想，每次比较完后下次循环都要少比较一个数 
	{
		for(k=0, q=p->pnext; k<len-1-i; k++, q=q->pnext) //每次循环的时候，k都是从i的那个下标开始一直加到len，然后比较k和k+1 
		{                           //但是这里的指针不能同时指向两个节点，所以要利用pq分别指向两个节点来比较，那么q就应该指向p所指向的下一个节点 
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

bool insertlist(struct node *phead6, int pos, int val) //从第pos个前面插入数据val（注意是第pos个，pos不是下标） 
{
	int i = 0;
	struct node *p = phead6;
	
	while(NULL != p && i<pos-1) //比如你要插入个节点到第六个节点之前，这个while的目的就是让p指向第五个节点，同时i的值也是第五个节点的下标5 
	{
		p = p->pnext;
		i++;                     //运行后i的值会等于pos-1 
	}
	
	if(i>pos-1 || NULL == p) //规定如果只有5个节点，则不能插入一个节点到第七个节点之前，因为连第六个节点都没有 
	{
		return false;    //如果输入的pos不合法，上面那个while是不会检测的出来的，因为上面那个while执行完后p可能指向一个空区域， 
	}                 //也就是p如果已经指向了最后一个节点，但是仍满足while条件的情况是存在的 
	
	struct node *pnew = (struct node*)malloc(sizeof(struct node));  //为插入的那个节点分配内存空间 
	if(NULL == pnew)
	{
		printf("创建新节点失败");
		exit(-1); 
	}	
	pnew->data = val;
	pnew->pnext = p->pnext; //让新节点指向后一个节点，再让前一个节点指向新节点 
	p->pnext = pnew;//注意顺序不能反，如果先让前一个节点指向新节点，那么后一个节点的地址就会丢失，所以应该先让新节点指向后一个节点 
	
	return true;
}

bool deletelist(struct node phead7, int pos)  //就是删除第pos个节点后面那个节点 
{
	int i = 0;
	struct node *p = phead7;
	
	while(NULL != p->pnext && i<pos-1)  //这个while是用来让p指向你要删除的那个节点 
	{							//(与上面那个插入节点不一样的是上面那个是判断p指向的节点是否为空，这里是判断p所指向节点的下一个是否为空)
		p = p->pnext;
		i++;                    
	}
	
	if(i>pos-1)  //这个if也是用来确保用户输入信息合法的 
	{
		return false;    
	}    
	struct node *q = p->pnext;        
	p->pnext = p->pnext->pnext;   //这个语句就已经可以做到删除一个节点了 
	free(q);         //之所以需要另一个指针变量是因为要让这个指针指向需要删除的那个节点，去把这个节点删除 
	q = NULL;	
}

int main(void)
{
	struct node *phead = NULL;    //这里头指针只起一个指向作用，没有存放数据，故不用分配动态内存 
	
	phead = createlist();
	      
	outputlist(phead);
	
	if(isemptylist(phead))
		printf("链表为空\n");
	else
		printf("链表创建成功\n");
		
	int len = lenlist(phead);
	printf("链表的长度是%d", len);
	
	phead = sortlist(phead); 
	
	insertlist(phead, 3, 66);
	
	return 0;
} 
