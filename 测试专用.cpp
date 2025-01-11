# include <stdio.h>

int main(void)
{
	int i=1;
	int a[5] = {0};
	a[i++] = 1;
	
	for(i=0; i<5; i++)
	{
		printf("%d", a[i]);
	}
	
	
	return 0;
}
