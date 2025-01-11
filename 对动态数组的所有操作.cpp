# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>  //�������������ִ�е�60�е�exit������ 

void chushihua (struct as *pas, int length);    //��������䶯̬�ڴ� 
bool append(struct as *pas, int val);			//����̬����ĩβ���Ԫ�أ�ֻ����ӵ�ĩβ�� 
bool insert(struct as *pas, int pos, int val);     //�������м����Ԫ�� 
bool delete(struct as *pas, int pos, int *val);    //ɾ�������е�Ԫ�� 
int get();
bool empty(struct as *pas);      //�ж϶�̬�����Ƿ񴴽��ɹ� 
bool extend(struct as *pas);     //�ж��Ƿ���Ҫ�ӳ���̬���鳤�� 
void sort(struct as *pas);     //�������ڵ�Ԫ�ؽ������� 
void show(struct as *pas);      //������� 
int inversion(struct as *pas);  //���������ڵ�Ԫ�� 

struct as
{
	int *pone;    //������ǵ�һ������ռ�ĵ�ַ,��һ������ռ��ڴ����int���͵���Ч���� 
	int len;      //�����������ĳ��� 
	int youxiao;	//��������������Ч���ȣ���Щ�ռ���ܻ�û������ 
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
		printf("ɾ���ɹ�\n");
		printf("ɾ����Ԫ���ǣ�%d\n", val); 
	}
	else
	{
		printf("ɾ��ʧ��"); 
	}
	
	show(&as);
	inversion(&as);
	printf("���ú������������:\n");
	show(&as);
	sort(&as);
	show(&as);
	
	return 0;
}

void chushihua (struct as *pas, int length)   //pas���յ����������еĽṹ�����as�ĵ�ַ��length��ʾ��������ĳ��� 
{
	pas->pone = (int*)malloc(sizeof(int)*length);  //�����ṹ���ڵ�ָ��pone��ָ�����еĶ�̬�ڴ�ռ��� 
	if(NULL == pas->pone)    //�ж϶�̬�ڴ��Ƿ񴴽��ɹ� 
	{
		printf("��̬�ڴ����ʧ��\n");
		exit(-1);   //��ֹ�������򣬲�����ֹ���� 
	}
	else
	{
		pas->len = length;  //�������鳤�� 
		pas->youxiao = 0;	//��ʼ������Ԫ��Ϊ0 
	} 
	return;
}

bool empty(struct as *pas)
{
	if(0 ==pas->youxiao)    //�жϳ�ʼ������Ԫ��ֵΪ0�Ƿ�ɹ� 
		return true;
	else
		return false;
}

void show(struct as *pas)
{
	if(empty(pas))   //���ж�������û�и�����Ԫ�� 
	{
		printf("����Ϊ��\n");
	}
	else
	{
		for(int i=0; i<pas->youxiao; i++)   //��Ϊ�еĿռ���ܻ�û����Ч���֣�����Ӧ������Ч���� 
		{
			printf("%d  ", pas->pone[i]);
		}
		printf("\n");
	}
	return;
}

bool extend(struct as *pas)
{
	if (pas->youxiao == pas->len)   //��Ч����=��󳤶ȵĻ��Ͳ����ӳ����� 
		return true;
	else
	    return false;
}

bool insert(struct as *pas, int pos, int val) //pas��������������ĵ�ַ�����ڽ������������ϵ 
{												//pos��Ԫ��Ҫ�����λ�ã�����pos=3���ǲ嵽������Ԫ��ǰ�棩��val�ǲ���Ԫ�ص����� 
	int i;
	
	if(extend(pas))   //���ж���������û�� 
		return false;
	if (pos<1 || pos>pas->youxiao+1)  //Ȼ���жϲ����λ���Ƿ�Ϸ� 
		return false;
		
	for(i=pas->youxiao-1; i>pos-1; i--)   //
	{
		pas->pone[i+1] = pas->pone[i];
	}
	pas->pone[pos-1] = val; 
	pas->youxiao++;   //�����Ǹ�����Ч���ȵ���ֵ 
	return true;   //�����������ж��Ƿ����ɹ� 
}

void sort(struct as *pas)   //ð������ 
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

int inversion(struct as *pas)   //������Ԫ�ط����� 
{
	int i = 0;
	int j = pas->youxiao-1;
	int t; 
	
	while(i<j)   //ֻҪ��û�н��������м�������Ԫ�أ��ͼ���ѭ������ 
	{
		t = pas->pone[i];               //����ͷβ����Ԫ�أ����������м�Գƽ��� 
		pas->pone[i] = pas->pone[j];
		pas->pone[j] = t;
		++i;
		--j;
	}
	return;
}

bool append(struct as *pas, int val)
{
	if(extend(pas))   //��ȷ����̬�ڴ�ռ仹û���� 
		return false;
	else
		pas->pone[pas->youxiao] = val; //pone����������пռ�ĵ�ַ��pas->youxiao�����ǰ���Ч����val�ӵ����һ������Ԫ�صĺ��� 
		pas->youxiao++;  //�ǵø�����Ч���ȵ����� 
		return true;
}

bool delete(struct as *pas, int pos, int *pval)  //ɾ��Ԫ�� ��pas�����Ͷ�̬�ڴ�ռ䱣����ϵ 
{												//pos��ʾ��Ҫɾ���ڼ���Ԫ�أ�pval����������ɾ�����Ǹ�Ԫ�ر����������ʲô  
	int i;
	
	if(empty(pas))   //��ȷ�������ڴ�����ЧԪ�� 
		return false;
	if (pos<1 || pos>pas->youxiao)  //ͬʱɾ����λ�õ��ǺϷ�λ�� 
		return ture;
	
	*pval = pas->pone[pos-1];	
	for(i=pos; i<pas->youxiao; i++)   //������ɾ��Ԫ�صĺ�����ЩԪ����ǰŲ 
	{
		pas->pone[i-1] = pas->pone[i];
	}	
	pas->youxiao--;  //�ǵø�����Ч�������� 
	return true;
}


