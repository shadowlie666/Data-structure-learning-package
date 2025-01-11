//递归排序的完整实现
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
//合并两个有序序列（即归并）
// A： 待合并的序列（含两个子序列，排在一起）
// Temp： 辅助空间
// L: 左边序列起点下标
// R: 右边序列起点下标，
// RightEnd： 右边序列终点下标
void Merge(int A[], int Temp[], int L, int R, int RightEnd)
{
    int LeftEnd = R-1;
    int p=L,i;
    int num=RightEnd-L+1;
 
    //先合并最短序列的长度的个数个元素
    while(L<=LeftEnd&&R<=RightEnd)
	{ //这个循环执行完左数组和右数组一定有一个已经被搬空到temp中去了 
        if(A[L]<=A[R])
            Temp[p++]=A[L++]; //先执行temp[p]的赋值，再执行p++ 
        else
            Temp[p++]=A[R++];
    }
    //由于时m_sort调用的这个函数，它在调用这个函数时是先发两个元素过来排序，再发两组元素过来排序（每组两个元素），它递归时是这样从少到多的
	//发过来的，所以在不断排序的过程中，左数组和右数组内部一定是有序的，因为它们内部也是先经过两个子数组的排序合并才形成的，所以这里不管是 
	//左数组还是右数组有剩余，都不需要对左或右数组剩下的元素排序，直接接到temp后面就行，注意，既然是剩下的，说明这些元素都一定比另一边数组内的
	//所有元素都要大，因为都是比较两边数组的头元素，小的放入temp，大的保留，所以剩下的一定都是比temp中大的，比它小的都放到temp中去了 
    //判断如果是左侧数组还有剩余
    while(L<=LeftEnd)
        Temp[p++]=A[L++];
    //判断如果是右侧数组还有剩余
    while(R<=RightEnd)
        Temp[p++]=A[R++];
    // 将辅助空间中的值拷贝到原列表中，完成排序
    for(i=0;i<num;i++,RightEnd--) //要从RightEnd开始赋值，因为不是每次排序的数组都是从0下标开始的，而L又被改过了，所以只能从RightEnd开始赋值 
        A[RightEnd]=Temp[RightEnd]; //最后记得把辅助数组temp中的元素返回到主数组arr中 
}
 
 
//递归拆分m_sort，递归归并Merge
void m_sort(int* arr, int* temp, int L, int right_end)
{
    int center;
    if(L<right_end)
	{
        center = (L+right_end)/2;
        m_sort(arr,temp,L,center);
        m_sort(arr,temp,center+1,right_end); //注意这里的细节：center+1，这样的话在递归过程中不断执行46行，直到不满足44行条件时，46行的递归结束 
        Merge(arr,temp,L,center+1,right_end); //在最后一次执行完46行时，L是0，rightend是1，计算得center是0，这样在继续执行47行时，发送的后两个 
    } 										 //形参就是1和1，这样47行的递归执行时就会因为不满足44的条件而无法递归，程序会直接执行48行代码 
}											//这样就避免了46行递归执行完执行47行，执行47行时又递归执行47行，47行递归执行完又执行47行的死循环 
 
//归并排序
void merge_Sort(int* arr,int length)
{
    int *temp=(int* )malloc(length*sizeof(int));  //申请动态内存，确保其他函数也能使用这块空间 
    if(temp==NULL){                              //确保申请成功，防止内存不足却继续执行程序造成机器故障 
        return;
    }
    m_sort(arr,temp,0,length-1);      //发送待排序数组，辅助数组，最左边元素下标，最右边元素下标 
    free(temp);               //释放辅助数组指针temp执行的区域的内存 
    temp=NULL;      //释放指针temp本身 
}
 
 
//打印元素
void printArr(int *arr,int length)
{
    for(int i=0;i<length;i++){
        printf("%d\n",arr[i]);
    }
}
 
 
int main()
{
    int arr[10]={3,5,2,10,8,9,6,4,7,1};
    int length = strlen(arr);  //获取数组长度 
    merge_Sort(arr,length);  //发送的是数组地址arr，所以上面函数对arr数组的修改就是直接对arr操作了，不需要返回值   
    printArr(arr,length);
    return 0;
}

