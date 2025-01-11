//汉诺塔，大梵天命令婆罗门把圆盘从下面开始按大小顺序重新摆放在另一根柱子上。并且规定，在小圆盘上不能放大圆盘，在三根柱子之间一次只能移动一个圆盘

#include<stdio.h>

int Hanio_twice(int num)
{
	if(1 == num) //A上只有一个盘子就只用移动一次 
		return 1;
	else //A上不止一个盘子时，次数就是23行最后那个递推式 
		return 2 * Hanio_twice(num - 1) + 1;
}
int main()
{
	int num = 0;	
	scanf("%d", &num);//塔数
	int ret = Hanio_twice(num);
	printf("完成%d层的汉诺塔需要%d步\n", num, ret);
	return 0;
}

//当A上不止一个盘子时 
//汉诺塔如何移动，其实就是先将a上的n-1个经过c移动到b上，然后把a上剩下的那一个移动到c上，然后再把b上的n-1个经过a移动到c上
//所以移动次数就是第一步移动n-1个盘子的次数+第二步移动一个盘子的次数1次+第三步移动n-1个盘子的次数=f (n -1 ) + 1 + f (n - 1)= 2 * f (n - 1) +1 
