# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>  //这个工具是用来执行第60行的exit函数的 

void chushihua (struct as *pas, int length);    //给数组分配动态内存 
bool append(struct as *pas, int val);			//给动态数组末尾添加元素（只能添加到末尾） 
bool insert(struct as *pas, int pos, int val);     //在数组中间插入元素 
bool delete(struct as *pas, int pos, int *val);    //删除数组中的元素 
int get();
bool empty(struct as *pas);      //判断动态数组是否创建成功 
bool extend(struct as *pas);     //判断是否需要延长动态数组长度 
void sort(struct as *pas);     //对数组内的元素进行排序 
void show(struct as *pas);      //输出数组 
int inversion(struct as *pas);  //倒置数组内的元素 

struct as
{
	int *pone;    //保存的是第一个数组空间的地址,第一个数组空间内存的是int类型的有效数据 
	int len;      //保存的是数组的长度 
	int youxiao;	//保存的是数组的有效长度，有些空间可能还没有数据 
};

int main(void)
{
	struct as as;
	int val;
	chushihua(&as,6);
	show(&as);
	append(&as,1);
	append(&as,2);
	append(&as,3);
	append(&as,4);
	
	if(delete(&as, 4, &as))
	{
		printf("删除成功\n");
		printf("删除的元素是：%d\n", val); 
	}
	else
	{
		printf("删除失败"); 
	}
	
	show(&as);
	inversion(&as);
	printf("倒置后的数组内容是:\n");
	show(&as);
	sort(&as);
	show(&as);
	
	return 0;
}

void chushihua (struct as *pas, int length)   //pas接收的是主函数中的结构体变量as的地址，length表示创建数组的长度 
{
	pas->pone = (int*)malloc(sizeof(int)*length);  //这样结构体内的指针pone就指向所有的动态内存空间了 
	if(NULL == pas->pone)    //判断动态内存是否创建成功 
	{
		printf("动态内存分配失败\n");
		exit(-1);   //终止整个程序，不是终止函数 
	}
	else
	{
		pas->len = length;  //保存数组长度 
		pas->youxiao = 0;	//初始化所有元素为0 
	} 
	return;
}

bool empty(struct as *pas)
{
	if(0 ==pas->youxiao)    //判断初始化所有元素值为0是否成功 
		return true;
	else
		return false;
}

void show(struct as *pas)
{
	if(empty(pas))   //先判断数组有没有给赋予元素 
	{
		printf("数组为空\n");
	}
	else
	{
		for(int i=0; i<pas->youxiao; i++)   //因为有的空间可能还没有有效数字，所以应当用有效长度 
		{
			printf("%d  ", pas->pone[i]);
		}
		printf("\n");
	}
	return;
}

bool extend(struct as *pas)
{
	if (pas->youxiao == pas->len)   //有效长度=最大长度的话就不用延长数组 
		return true;
	else
	    return false;
}

bool insert(struct as *pas, int pos, int val) //pas是用来接收数组的地址，用于建立和数组的联系 
{												//pos是元素要插入的位置（比如pos=3就是插到第三个元素前面），val是插入元素的数据 
	int i;
	
	if(extend(pas))   //先判断数组满了没有 
		return false;
	if (pos<1 || pos>pas->youxiao+1)  //然后判断插入的位置是否合法 
		return false;
		
	for(i=pas->youxiao-1; i>pos-1; i--)   //
	{
		pas->pone[i+1] = pas->pone[i];
	}
	pas->pone[pos-1] = val; 
	pas->youxiao++;   //别忘记更新有效长度的数值 
	return true;   //这里是用来判断是否插入成功 
}

void sort(struct as *pas)   //冒泡排序 
{
	int i, k, t;
	for(i=0; i<(pas->youxiao)-1; i++)
	{
		for(k=0; k<(pas->youxiao)-1-i; k++)
		{
			if (pas->pone[k+1]>pas->pone[k])
			{
				t = pas->pone[k+1];
				pas->pone[k+1] = pas->pone[k];
				pas->pone[k] = t;
			}
		}
	}
	return;
}

int inversion(struct as *pas)   //将所有元素反过来 
{
	int i = 0;
	int j = pas->youxiao-1;
	int t; 
	
	while(i<j)   //只要还没有交换到最中间那俩个元素，就继续循环交换 
	{
		t = pas->pone[i];               //交换头尾两个元素，从两边向中间对称交换 
		pas->pone[i] = pas->pone[j];
		pas->pone[j] = t;
		++i;
		--j;
	}
	return;
}

bool append(struct as *pas, int val)
{
	if(extend(pas))   //先确保动态内存空间还没有满 
		return false;
	else
		pas->pone[pas->youxiao] = val; //pone保存的是所有空间的地址，pas->youxiao表明是把有效数据val加到最后一个非零元素的后面 
		pas->youxiao++;  //记得更新有效长度的数据 
		return true;
}

bool delete(struct as *pas, int pos, int *pval)  //删除元素 ，pas用来和动态内存空间保持联系 
{												//pos表示你要删除第几个元素，pval用来返回你删除的那个元素保存的数据是什么  
	int i;
	
	if(empty(pas))   //先确保数组内存在有效元素 
		return false;
	if (pos<1 || pos>pas->youxiao)  //同时删除的位置得是合法位置 
		return ture;
	
	*pval = pas->pone[pos-1];	
	for(i=pos; i<pas->youxiao; i++)   //把所有删除元素的后面那些元素往前挪 
	{
		pas->pone[i-1] = pas->pone[i];
	}	
	pas->youxiao--;  //记得更新有效长度数据 
	return true;
}


