# include <stdio.h>

typedef int a;   //�����˼Ҳ�Ǹ�intһ�������ֽ�a�������Ƿֺ�                                                          ����һ�ַ����� 

typedef struct student  //������Ǹ�һ���ṹ������������ṹ������̫������д��������鷳�������������һ��������         ���ڶ��ַ����� 
{						//���������ڽṹ��ǰ���typedef��Ȼ���ڽṹ�����ķֺ�ǰ�������������� 
	int id;
	char name[100];	
}st, st[max];

typedef struct lol       																								//�������ַ����� 
{
	int yingxiong;    //�ṹ��������*�žͱ�ʾָ�룬��������o�͵ȼ���struct lol * 
}*o; //����˵������һ��ָ��ṹ������ˣ�����ȡ����lol��ʱ���ü�*����Ϊlol��һ�����ֲ���һ������ 

typedef struct fas                                                                                                       //�������ַ����� 
{
	int p;              
}*as, fa;               //�ṹ�����ķֺ�ǰ����д����������faҲ���Եȼ��� struct fas,  ��as�Եȼ���struct fas *      

int main(void)
{
	a k;   //�ȼ���int k      ��Ӧ��һ�� 
	 
	st i;  //�ȼ���struct student i				��Ӧ�ڶ���	
	st l;  //�ȼ���struct student l[max] 
	
	o q;   //�ȼ���struct lol *q            ��Ӧ������ 
	 
	as p;   //�ȼ���struct fas *p         ��Ӧ������ 
	fa j;   //�ȼ���struct fas j 
	
	return 0;
}
