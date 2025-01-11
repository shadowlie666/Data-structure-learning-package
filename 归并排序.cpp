//�ݹ����������ʵ��
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
//�ϲ������������У����鲢��
// A�� ���ϲ������У������������У�����һ��
// Temp�� �����ռ�
// L: �����������±�
// R: �ұ���������±꣬
// RightEnd�� �ұ������յ��±�
void Merge(int A[], int Temp[], int L, int R, int RightEnd)
{
    int LeftEnd = R-1;
    int p=L,i;
    int num=RightEnd-L+1;
 
    //�Ⱥϲ�������еĳ��ȵĸ�����Ԫ��
    while(L<=LeftEnd&&R<=RightEnd)
	{ //���ѭ��ִ�����������������һ����һ���Ѿ�����յ�temp��ȥ�� 
        if(A[L]<=A[R])
            Temp[p++]=A[L++]; //��ִ��temp[p]�ĸ�ֵ����ִ��p++ 
        else
            Temp[p++]=A[R++];
    }
    //����ʱm_sort���õ�������������ڵ����������ʱ���ȷ�����Ԫ�ع��������ٷ�����Ԫ�ع�������ÿ������Ԫ�أ������ݹ�ʱ���������ٵ����
	//�������ģ������ڲ�������Ĺ����У���������������ڲ�һ��������ģ���Ϊ�����ڲ�Ҳ���Ⱦ������������������ϲ����γɵģ��������ﲻ���� 
	//�����黹����������ʣ�࣬������Ҫ�����������ʣ�µ�Ԫ������ֱ�ӽӵ�temp������У�ע�⣬��Ȼ��ʣ�µģ�˵����ЩԪ�ض�һ������һ�������ڵ�
	//����Ԫ�ض�Ҫ����Ϊ���ǱȽ����������ͷԪ�أ�С�ķ���temp����ı���������ʣ�µ�һ�����Ǳ�temp�д�ģ�����С�Ķ��ŵ�temp��ȥ�� 
    //�ж������������黹��ʣ��
    while(L<=LeftEnd)
        Temp[p++]=A[L++];
    //�ж�������Ҳ����黹��ʣ��
    while(R<=RightEnd)
        Temp[p++]=A[R++];
    // �������ռ��е�ֵ������ԭ�б��У��������
    for(i=0;i<num;i++,RightEnd--) //Ҫ��RightEnd��ʼ��ֵ����Ϊ����ÿ����������鶼�Ǵ�0�±꿪ʼ�ģ���L�ֱ��Ĺ��ˣ�����ֻ�ܴ�RightEnd��ʼ��ֵ 
        A[RightEnd]=Temp[RightEnd]; //���ǵðѸ�������temp�е�Ԫ�ط��ص�������arr�� 
}
 
 
//�ݹ���m_sort���ݹ�鲢Merge
void m_sort(int* arr, int* temp, int L, int right_end)
{
    int center;
    if(L<right_end)
	{
        center = (L+right_end)/2;
        m_sort(arr,temp,L,center);
        m_sort(arr,temp,center+1,right_end); //ע�������ϸ�ڣ�center+1�������Ļ��ڵݹ�����в���ִ��46�У�ֱ��������44������ʱ��46�еĵݹ���� 
        Merge(arr,temp,L,center+1,right_end); //�����һ��ִ����46��ʱ��L��0��rightend��1�������center��0�������ڼ���ִ��47��ʱ�����͵ĺ����� 
    } 										 //�βξ���1��1������47�еĵݹ�ִ��ʱ�ͻ���Ϊ������44���������޷��ݹ飬�����ֱ��ִ��48�д��� 
}											//�����ͱ�����46�еݹ�ִ����ִ��47�У�ִ��47��ʱ�ֵݹ�ִ��47�У�47�еݹ�ִ������ִ��47�е���ѭ�� 
 
//�鲢����
void merge_Sort(int* arr,int length)
{
    int *temp=(int* )malloc(length*sizeof(int));  //���붯̬�ڴ棬ȷ����������Ҳ��ʹ�����ռ� 
    if(temp==NULL){                              //ȷ������ɹ�����ֹ�ڴ治��ȴ����ִ�г�����ɻ������� 
        return;
    }
    m_sort(arr,temp,0,length-1);      //���ʹ��������飬�������飬�����Ԫ���±꣬���ұ�Ԫ���±� 
    free(temp);               //�ͷŸ�������ָ��tempִ�е�������ڴ� 
    temp=NULL;      //�ͷ�ָ��temp���� 
}
 
 
//��ӡԪ��
void printArr(int *arr,int length)
{
    for(int i=0;i<length;i++){
        printf("%d\n",arr[i]);
    }
}
 
 
int main()
{
    int arr[10]={3,5,2,10,8,9,6,4,7,1};
    int length = strlen(arr);  //��ȡ���鳤�� 
    merge_Sort(arr,length);  //���͵��������ַarr���������溯����arr������޸ľ���ֱ�Ӷ�arr�����ˣ�����Ҫ����ֵ   
    printArr(arr,length);
    return 0;
}

