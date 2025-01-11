# include <stdio.h>

typedef int a;   //这个意思也是给int一个新名字叫a，别忘记分号                                                          （第一种方法） 

typedef struct student  //这里就是给一个结构体命名，如果结构体名字太长后面写起来会很麻烦，所以这里给他一个新名字         （第二种方法） 
{						//方法就是在结构体前面加typedef，然后在结构体后面的分号前加上它的新名字 
	int id;
	char name[100];	
}st, st[max];

typedef struct lol       																								//（第三种方法） 
{
	int yingxiong;    //结构体最后加了*号就表示指针，比如这里o就等价于struct lol * 
}*o; //这里说明这是一个指针结构体就行了，上面取名字lol的时候不用加*，因为lol是一个名字不是一个变量 

typedef struct fas                                                                                                       //（第四种方法） 
{
	int p;              
}*as, fa;               //结构体最后的分号前可以写两个，这样fa也可以等价于 struct fas,  而as仍等价于struct fas *      

int main(void)
{
	a k;   //等价于int k      对应第一种 
	 
	st i;  //等价于struct student i				对应第二种	
	st l;  //等价于struct student l[max] 
	
	o q;   //等价于struct lol *q            对应第三种 
	 
	as p;   //等价于struct fas *p         对应第四种 
	fa j;   //等价于struct fas j 
	
	return 0;
}
