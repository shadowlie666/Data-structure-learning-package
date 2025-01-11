//汉诺塔，大梵天命令婆罗门把圆盘从下面开始按大小顺序重新摆放在另一根柱子上。并且规定，在小圆盘上不能放大圆盘，在三根柱子之间一次只能移动一个圆盘 

#include<stdio.h>

void Hanio_Step(int n, char A, char B, char C) //函数效果是将n个盘子从A借助B移动到c上 
{
	if (1 == n) //如果A上本来只有一个盘子，就直接移 
		printf("%c->%c\n", A, C);
	else //如果不止有一个盘子，都要按照24行注释来移动 
	{
		Hanio_Step(n-1, A, C, B); //根据24行注释，先将n-1个a上的盘子经过c移动到b上 
		printf("%c->%c\n", A, C); //然后把a上剩下的那一个移动到c上 
		Hanio_Step(n-1, B, A, C); //然后再把n-1个b上的盘子经过a移动到c上 
	}
}
int main()
{
	int n = 0;
	scanf("%d", &n);  //A柱子上盘子的个数 
	Hanio_Step(n, 'A', 'B', 'C');
	return 0;
}

//汉诺塔如何移动，其实就是先将a上的n-1个经过c移动到b上，然后把a上剩下的那一个移动到c上，然后再把b上的n-1个经过a移动到c上

